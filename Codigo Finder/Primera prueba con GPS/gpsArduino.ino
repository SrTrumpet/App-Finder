#include <TinyGPS++.h>
#include <SoftwareSerial.h>
TinyGPSPlus gps;
SoftwareSerial ss(4,3);

void setup() {
  Serial.begin(9600);
  ss.begin(9600);
  Serial.println("Esperando info de GPS");
}

void loop() {

  while (ss.available() > 0){
    gps.encode(ss.read());

    if(gps.location.isUpdated()){
      Serial.print("Latitud: ");
      Serial.println(gps.location.lat(), 6);
      Serial.print("Logitud: ");
      Serial.println(gps.location.lng(), 6);
    }

    if(gps.time.isUpdated()){
      Serial.println("Hora (UTC)=  " + String(gps.time.hour()) + " : " + String(gps.time.minute()) + " : " + String(gps.time.second()));
    }

  }

}

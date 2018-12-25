#include "IoTtalkDevice.h"

long cycleTimestamp = millis();
IoTtalkDevice IoTtalk;

void setup() {
    String DFs[] = {"D0~","D1~","D2~","D5","D6","D7","D8","A0"};
    IoTtalk.setDeviceModelName("NodeMCU");
    IoTtalk.setDeviceFeatures(DFs, 8);
    pinMode(2, OUTPUT);// D4 : on board led
    digitalWrite(2,HIGH);
    pinMode(0, INPUT_PULLUP); // D3, GPIO0: clear eeprom button

    pinMode(16, OUTPUT);// D0~
    pinMode(5, OUTPUT); // D1~
    pinMode(4, OUTPUT); // D2~
    pinMode(14, OUTPUT);// D5
    pinMode(12, OUTPUT);// D6
    pinMode(13, OUTPUT);// D7
    pinMode(15, OUTPUT);// D8
    IoTtalk.initialize();
    digitalWrite(16,LOW);
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    digitalWrite(14,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    digitalWrite(15,LOW);
}


int pinA0;
void loop() {
  String result;
  IoTtalk.loop();
    // if (millis() - cycleTimestamp > 200) {
    //
    //     pinA0 = analogRead(A0);
    //     push("A0", String(pinA0));
    //
        result = IoTtalk.pull("D0~");
        if (result != "___NULL_DATA___"){
            Serial.println ("D0~: "+result);
            if (result.toInt() >= 0 && result.toInt() <= 255) analogWrite(16, result.toInt());
        }

        result = IoTtalk.pull("D1~");
        if (result != "___NULL_DATA___"){
            Serial.println ("D1~: "+result);
            if (result.toInt() >= 0 && result.toInt() <= 255) analogWrite(5, result.toInt());
        }

        result = IoTtalk.pull("D2~");
        if (result != "___NULL_DATA___"){
            Serial.println ("D2~: "+result);
            if (result.toInt() >= 0 && result.toInt() <= 255) analogWrite(4, result.toInt());
        }
    //
    //     result = pull("D5");
    //     if (result != "___NULL_DATA___"){
    //         Serial.println ("D5: "+result);
    //         if (result.toInt() > 0 ) digitalWrite(14, 1);
    //         else digitalWrite(14, 0);
    //     }
    //
    //     result = pull("D6");
    //     if (result != "___NULL_DATA___"){
    //         Serial.println ("D6: "+result);
    //         if (result.toInt() > 0 ) digitalWrite(12, 1);
    //         else digitalWrite(12, 0);
    //     }
    //
    //     result = pull("D7");
    //     if (result != "___NULL_DATA___"){
    //         Serial.println ("D7: "+result);
    //         if (result.toInt() > 0 ) digitalWrite(13, 1);
    //         else digitalWrite(13, 0);
    //     }
    //
    //     result = pull("D8");
    //     if (result != "___NULL_DATA___"){
    //         Serial.println ("D8: "+result);
    //         if (result.toInt() > 0 ) digitalWrite(15, 1);
    //         else digitalWrite(15, 0);
    //     }
    //     cycleTimestamp = millis();
    // }

}

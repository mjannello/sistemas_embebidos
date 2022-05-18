#include <IRremote.h>
#include <IRremoteInt.h>
 
IRsend irsend;

void setup() {
  Serial.begin(9600);
}
 
void loop() {
  long code = 0x1000C;
        irsend.sendRC6(code, 20);
    Serial.println("Enviado");
    delay(100);
}

1000C

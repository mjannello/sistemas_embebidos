#include <IRremote.hpp>
#define IR_RECEIVE_PIN 7

void setup()
{
      pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
}

void loop() {
  if (IrReceiver.decode()) {
//      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
//      IrReceiver.printIRResultShort(&Serial); // optional use new print version
      IRData *decodedIRDataP = IrReceiver.read();
      uint32_t some_value = decodedIRDataP->decodedRawData;
      Serial.print(some_value);
      IrReceiver.resume(); // Enable receiving of the next value
  }
 
}

//3.6.0

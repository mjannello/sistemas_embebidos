#include <SoftwareSerial.h> // Incluimos la librería  SoftwareSerial  
#include <IRremote.hpp>
#include <String.h>

#define IR_RECEIVE_PIN 7

SoftwareSerial BT(10,11);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth
// Rx del bluetooh va al 11
//Tx del bluetooth va al 10
 
void setup()
{
    pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);

  BT.begin(9600);       // Inicializamos el puerto serie BT (Para Modo AT 2)
  Serial.begin(9600);   // Inicializamos  el puerto serie  
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver

}
 
void loop()
{

  if(BT.available())    // Si llega un dato por el puerto BT se envía al monitor serial
  {
    Serial.write(BT.read());
    
  }

  if (IrReceiver.decode()) {

//      Serial.println(IrReceiver.decodedIRData.decodedRawData);
//      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
//      IrReceiver.printIRResultShort(&Serial); // optional use new print version
      IRData *decodedIRDataP = IrReceiver.read();
      uint32_t some_value = decodedIRDataP->decodedRawData;
      char textToWrite[ 16 ];
      sprintf(textToWrite,"%lu", some_value);
      BT.write(textToWrite);
      Serial.print(some_value);
      IrReceiver.resume(); // Enable receiving of the next value
  }
  if(Serial.available())  // Si llega un dato por el monitor serial se envía al puerto BT
  {
     BT.write(Serial.read());
  }
}

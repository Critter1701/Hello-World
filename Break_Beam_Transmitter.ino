/* Break Beam code for nRF24L01 and a Nano
 *  using pin's 10 for CE, and pin 9 for CSN
 */
//    define Libraries to include
 #include <SPI.h>
 #include <nRF24L01.h>
 #include <RF24.h>

//    create an instance for radio driver
 RF24 radio(10, 9);   //  CE, CSN
 const byte addresses[][6] = {"00001", "00002"};  
 
 
 //   define led pin
 #define LEDPIN 13

//    define sensor pin
 #define SENSORPIN 4

//  craete a instance for sensor state
 int sensorState = 0, lastState = 0;    //  variable for reading the push button state

 void setup(){
//    initialize the led pin as an output
 pinMode(LEDPIN, OUTPUT);
 
//    initialize the sensor pin as an input
 pinMode(SENSORPIN, INPUT_PULLUP);
 digitalWrite(SENSORPIN, HIGH);

//    start the serial monitor
 Serial.begin(9600);
 }
 radio.begin();
 radio.openWritingPipe(addresses[1]);   //  00002
 radio.openReadingPipe(1, addresses[0]);  //  00001
 radio.setPALevel(RF24_PA_MIN);

 void loop(){
  delay(5);
  radio.stopListening();

  radio.write(sensorState, sizeof(sensorState));
  
//    read the state of the pushbutton value
 sensorState = digitalRead(SENSORPIN);
 
//    check if sensor beam has been broken, if it is, the sensorstate is low
  if(sensorState == LOW){
//    turn led on
 digitalWrite(LEDPIN, HIGH)
  }
 else  }
//    turn led off
 digitalwrite(ledPin, LOW);
 delay(5);
 
}

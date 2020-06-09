#include <SPI.h>
#include <nRF24L01p.h>

nRF24L01p transmitter(7,8);//CSN,CE

void setup(){
delay(150);
Serial.begin(115200);
SPI.begin();
SPI.setBitOrder(MSBFIRST);
transmitter.channel(90); // ตั้งช่องความถี่ให้ตรงกัน
transmitter.TXaddress("TATOM"); // ตั้งชื่อตำแหน่งให้ตรงกัน ชื่อตั้งได้สูงสุด 5 ตัวอักษร
transmitter.init();

receiver.channel(90);  // ตั้งช่องความถี่ให้ตรงกัน
receiver.RXaddress("RATOM");  // ตั้งชื่อตำแห่นงให้ตรงกัน ชื่อตั้งได้สูงสุด 5 ตัวอักษร
receiver.init();
}

String message;

void loop(){
if(receiver.available()){
 receiver.read(); // สั่งให้เริ่มอ่าน
receiver.rxPL(message); // สั่งใหอ่านเก็บไว้ที่ตัวแปร
Serial.println(message);
message="";
}
  
 transmitter.txPL("Welcome ArduinoAll"); // ค่าที่ต้องการส่ง
transmitter.send(FAST); // สั่งให้ส่งออกไป
delay(1000);
}



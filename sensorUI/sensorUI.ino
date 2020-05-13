
#include "Arduino.h"
#include <Ultrasonic.h>
Ultrasonic ultrasonic(8,9);


const int led = 7; // USR LED pin is P7
const int usr_btn = 6; // USR BTN pin is P6
volatile boolean state=HIGH; //initial value of switch pin

void pin_change(void)
{
float cmMsec, inMsec;
state=!state; //reverse state

cmMsec = ultrasonic.read(CM);// 計算距離，單位: 公分
inMsec = ultrasonic.read(INC); // 計算距離，單位: 英吋

Serial.print("CM: "); Serial.print(cmMsec);
Serial.print(", IN: "); Serial.println(inMsec);
}

void setup() {
pinMode(led, OUTPUT);
pinMode(usr_btn, INPUT_PULLUP);
attachInterrupt(usr_btn, pin_change,FALLING);
digitalWrite(led, state);
Serial.begin(9600);


}

void loop() {
if (state) {digitalWrite(led, HIGH);//turn LED on
}
else{ digitalWrite(led, LOW); //turn LED off
}
}

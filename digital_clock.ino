
#include "SevSeg.h"

#define d1 13
#define d2 12
#define d3 11
#define d4 10
#define a A0
#define b A1
#define c A2
#define d A3
#define e A4
#define f 7
#define g 6
#define dp 9
#define HOUR_BUTTON 2
#define MINUTE_BUTTON 3
#define TICK_LENGTH 250

SevSeg sevseg;

int minute = 0;
int hour = 1;
int ticks = 0;
unsigned long previousMillis = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Bootup");
  pinMode(HOUR_BUTTON, INPUT);
  pinMode(MINUTE_BUTTON, INPUT);
  
  byte numDigits = 4;
  byte digitPins[] = {d1, d2, d3, d4};
  byte segmentPins[] = {a, b, c, d, e, f, g, dp};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  checkTick();
  sevseg.setNumber(hour * 100 + minute, 3);
  sevseg.refreshDisplay(); 
}

void checkTick() {
   unsigned long currentMillis = millis();
 
   // How much time has passed, accounting for rollover with subtraction!
   if ((unsigned long)(currentMillis - previousMillis) >= TICK_LENGTH) {
      // It's time to do something!
      tick();
 
      // Use the snapshot to set track time until next event
      previousMillis = currentMillis;
   }
}

void tick() {
  Serial.println("TICK!");
  ticks = ticks + 1;
  readHourButton();
  readMinuteButton();
}

void readHourButton() {
  if (digitalRead(HOUR_BUTTON) == HIGH) {
    hourUp();
  }
}

void readMinuteButton() {
  if (digitalRead(MINUTE_BUTTON) == HIGH) {
    minuteUp();
  }
}

void hourUp() {
  Serial.print("Hour up: ");
  Serial.println(hour);
  hour = hour + 1;
  if (hour > 12) {
    hour = 1;
  }
}

void minuteUp() {
  Serial.print("Minute up: ");
  Serial.println(minute);
  minute = minute + 1;
  if (minute > 59) {
    minute = 0;
    hourUp;
  }
}


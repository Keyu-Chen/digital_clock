// Arduino Clock
//

#include "SevSeg.h"

#define d1 13
#define d2 12
#define d3 11
#define d4 10
#define dp 9
#define g 8
#define f 7
#define e 6
#define d 5
#define c 4
#define b 3
#define a 2

void setup() {
  // put your setup code here, to run once:
  pinMode(d1, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(dp, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(d4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dp, HIGH);
  digitalWrite(a, HIGH);
//  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
//  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
//  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
//  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
//  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
//  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
//  digitalWrite(g, LOW);
//  digitalWrite(d1, HIGH);
  digitalWrite(d1, LOW);
  digitalWrite(d2, HIGH);
//  digitalWrite(d2, LOW);
  digitalWrite(d3, HIGH);
//  digitalWrite(d3, LOW);
//  digitalWrite(d4, HIGH);
  digitalWrite(d4, LOW);
}

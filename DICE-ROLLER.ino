#include "pitches.h"


const int buttonPin = 2;
int buttonState = 0;

const int speaker = 8;

const int one =  13;
const int two = 12;
const int three = 11;
const int four = 10;
const int five = 9;

long randomGenerator;
int time = 0;

void setup() {
  pinMode(one, OUTPUT);
  pinMode(two, OUTPUT);
  pinMode(three, OUTPUT);
  pinMode(four, OUTPUT);
  pinMode(five, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(speaker, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {

    loopGenerator(180, NOTE_DS8);
    loopGenerator(160, NOTE_DS8);
    loopGenerator(140, NOTE_DS8);
    loopGenerator(120, NOTE_DS8);
    loopGenerator(100, NOTE_DS8);
    loopGenerator(80, NOTE_DS8);
    loopGenerator(60, NOTE_DS8);
    loopGenerator(40, NOTE_DS8);
    loopGenerator(20, NOTE_DS8);
    
    digitalWrite(one, LOW);
    digitalWrite(two, LOW);
    digitalWrite(three, LOW);
    digitalWrite(four, LOW);
    digitalWrite(five, LOW);
    time = 1000;

    randomGenerator = random(1, 5);

    if (randomGenerator == 1) {
      digitalWrite(two, HIGH);
      delay(time);
      time;
    }
    if (randomGenerator == 2) {
      digitalWrite(three, HIGH);
      digitalWrite(five, HIGH);
      delay(time);
      time;
    }
    if (randomGenerator == 3) {
      digitalWrite(one, HIGH);
      digitalWrite(two, HIGH);
      digitalWrite(four, HIGH);
      delay(time);
      time;
    }
    if (randomGenerator == 4) {
      digitalWrite(five, HIGH);
      digitalWrite(one, HIGH);
      digitalWrite(four, HIGH);
      digitalWrite(three, HIGH);
      delay(time);
      time;
    }
    if (randomGenerator == 5) {
      digitalWrite(one, HIGH);
      digitalWrite(two, HIGH);
      digitalWrite(three, HIGH);
      digitalWrite(four, HIGH);
      digitalWrite(five, HIGH);
      delay(time);
      time;
    }
    {
      digitalWrite(one, LOW);
      digitalWrite(two, LOW);
      digitalWrite(three, LOW);
      digitalWrite(four, LOW);
      digitalWrite(five, LOW);
    }

  }

}

void loopGenerator(int x, int sound) {

   for (int n = 1; n > 0; n--) {
      digitalWrite(five, HIGH);
      tone(speaker, sound);
      delay(x);
      noTone(speaker);
      digitalWrite(five, LOW);

      digitalWrite(two, HIGH);
      tone(speaker, sound);
      delay(x);
      noTone(speaker);
      digitalWrite(two, LOW);

      digitalWrite(one, HIGH);
      tone(speaker, sound);
      delay(x);
      noTone(speaker);
      digitalWrite(one, LOW);

      digitalWrite(four, HIGH);
      tone(speaker, sound);
      delay(x);
      noTone(speaker);
      digitalWrite(four, LOW);

      digitalWrite(three, HIGH);
      tone(speaker, sound);
      delay(x);
      noTone(speaker);
      digitalWrite(three, LOW);
    }
}


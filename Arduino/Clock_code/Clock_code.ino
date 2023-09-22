  int ledhours[12] = {5, 6, 7, 8, 9, 10, 11, 12, 13,23 , 22, 24}, i;
int ledmins[12] = {25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36};

#include <virtuabotixRTC.h>
virtuabotixRTC myRTC(2, 3, 4);
void turnoff() {
  for (i = 0; i < 12; i++) {
    digitalWrite(ledhours[i], LOW);
  }
}
void turnoffm() {
  for (int i = 0; i < 12; i++) {
    digitalWrite(ledmins[i], LOW);
  }
}
void setup() {
 
  for (i = 0; i < 12; i++) {
    pinMode(ledhours[i], OUTPUT);
    pinMode(ledmins[i], OUTPUT);
  }
}

void loop() {
  myRTC.updateTime();
 
  if (myRTC.hours == 1 || myRTC.hours == 13) {
    turnoff();
    digitalWrite(ledhours[0], HIGH);

  }
  else if (myRTC.hours == 2 || myRTC.hours == 14) {
    turnoff();
    digitalWrite(ledhours[1], HIGH);
  }
  else if (myRTC.hours == 3 || myRTC.hours == 15) {
    turnoff();
    digitalWrite(ledhours[2], HIGH);
  }
  else if (myRTC.hours == 4 || myRTC.hours == 16) {
    turnoff();
    digitalWrite(ledhours[3], HIGH);
  }
  else if (myRTC.hours == 5 || myRTC.hours == 17) {
    turnoff();
    digitalWrite(ledhours[4], HIGH);
  }
  else if (myRTC.hours == 6 || myRTC.hours == 18) {
    turnoff();
    digitalWrite(ledhours[5], HIGH);
  }
  else if (myRTC.hours == 7 || myRTC.hours == 19) {
    turnoff();
    digitalWrite(ledhours[6], HIGH);
  }
  else if (myRTC.hours == 8 || myRTC.hours == 20) {
    turnoff();
    digitalWrite(ledhours[7], HIGH);
  }
  else if (myRTC.hours == 9 || myRTC.hours == 21) {
    turnoff();
    digitalWrite(ledhours[8], HIGH);
  }
  else if (myRTC.hours == 10 || myRTC.hours == 22) {
    turnoff();
    digitalWrite(ledhours[9], HIGH);
  }
  else if (myRTC.hours == 11 || myRTC.hours == 23) {
    turnoff();
    digitalWrite(ledhours[10], HIGH);
  }
  else if (myRTC.hours == 12) {
    turnoff();
    digitalWrite(ledhours[11], HIGH);
  }
  if (myRTC.minutes <= 5 && myRTC.minutes >= 0) {      //minutes code
    turnoffm();
    digitalWrite(ledmins[0], HIGH);
    digitalWrite(ledmins[1], HIGH);
  }
  else if (myRTC.minutes <= 10 && myRTC.minutes >= 5) {
    turnoffm();
    digitalWrite(ledmins[1], HIGH);
    digitalWrite(ledmins[2], HIGH);
  }
  else if (myRTC.minutes <= 15 && myRTC.minutes >= 10) {
    turnoffm();
    digitalWrite(ledmins[2], HIGH);
    digitalWrite(ledmins[3], HIGH);
  }
  else if (myRTC.minutes <= 20 && myRTC.minutes >= 15) {
    turnoffm();
    digitalWrite(ledmins[3], HIGH);
    digitalWrite(ledmins[4], HIGH);
  }
  else if (myRTC.minutes <= 25 && myRTC.minutes >= 20) {
    turnoffm();
    digitalWrite(ledmins[4], HIGH);
    digitalWrite(ledmins[5], HIGH);
  }
  else if (myRTC.minutes <= 30 && myRTC.minutes >= 25) {
    turnoffm();
    digitalWrite(ledmins[5], HIGH);
    digitalWrite(ledmins[6], HIGH);
  }
  else if (myRTC.minutes <= 35 && myRTC.minutes >= 30) {
    turnoffm();
    digitalWrite(ledmins[6], HIGH);
    digitalWrite(ledmins[7], HIGH);
  }
  else if (myRTC.minutes <= 40 && myRTC.minutes >= 35) {
    turnoffm();
    digitalWrite(ledmins[7], HIGH);
    digitalWrite(ledmins[8], HIGH);
  }
  else if (myRTC.minutes <= 45 && myRTC.minutes >= 40) {
    turnoffm();
    digitalWrite(ledmins[8], HIGH);
    digitalWrite(ledmins[9], HIGH);
  }
  else if (myRTC.minutes <= 50 && myRTC.minutes >= 45) {
    turnoffm();
    digitalWrite(ledmins[9], HIGH);
    digitalWrite(ledmins[10], HIGH);
  }
  else if (myRTC.minutes <= 55 && myRTC.minutes >= 50) {
    turnoffm();
    digitalWrite(ledmins[10], HIGH);
    digitalWrite(ledmins[11], HIGH);
  }
  else if (myRTC.minutes <= 59 && myRTC.minutes >= 55) {
    turnoffm();
    digitalWrite(ledmins[11], HIGH);
    digitalWrite(ledmins[12], HIGH);
  }
  
}

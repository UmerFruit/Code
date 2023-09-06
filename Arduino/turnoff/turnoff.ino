int ledhours[12] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 22, 23, 24}, i;
int ledmins[12] = {25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36};
void setup() {
  // put your setup code here, to run once:
for(int i=0;i<12;i++){
pinMode(ledhours[i],OUTPUT);
pinMode(ledmins[i],OUTPUT);
}

}

void loop() {
 for(int i=0;i<12;i++){
 digitalWrite(ledmins[i],HIGH);
 delay(500);
 digitalWrite(ledmins[i],LOW);
 delay(500);
 }
 delay(4000);
}

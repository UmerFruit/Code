int ledhours[12] = {5, 6, 7, 8, 9, 10, 11, 12, 13,23 , 22, 24}, i;
int ledmins[12] = {25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36};
void setup() {
  // put your setup code here, to run once:
for(int i=0;i<12;i++){
pinMode(ledhours[i],OUTPUT);
pinMode(ledmins[i],OUTPUT);
}

}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=0;i<12;i++){
  digitalWrite(ledhours[i],HIGH);
  digitalWrite(ledmins[i],HIGH);
  delay(1000);
   digitalWrite(ledhours[i],LOW);
  digitalWrite(ledmins[i],LOW);
  delay(1000); 

}
}

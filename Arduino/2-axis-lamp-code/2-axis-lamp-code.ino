#include <Servo.h>  //library
Servo servox;       //x-axis servo (Servo is just a special)
Servo servoy;       //y axis servo (motor that only moves in 180˚)
int joyx = A0;      //the pin(address) the joystick x axis data goes to
int joyy = A1;      //the pin(address) the joystick y axis data goes to
int joyvalx;        //the joystick returns values b/w 0 and 1023
int joyvaly;        //for both axes these variables store those values
int dt = 15;        //delay in milliseconds
int posx = 90;      //position variable for the x motor
int posy = 90;      //position variable for the x motor
void setup() {      //void setup runs the code once              
  servox.attach(9);     //the pin(address) the x motor is connected to
  servoy.attach(10);    //the pin(address) the y motor is connected to
  Serial.begin(9600);   //initialize the serial monitor for display of output
  pinMode(joyx, INPUT); //x axis data from joystick declared input for the CPU
  pinMode(joyy, INPUT); //x axis data from joystick declared input for the CPU
  servox.write(posx);   //initialize positions of both servos to
  servoy.write(posy);   //mid points
}
void loop() {           //void loop repeatedly runs the code
  joyvalx = analogRead(joyx); //read the values from the joystick axes
  joyvaly = analogRead(joyy); //it will be between 0 and 1023
  while (joyvalx > 900) {    
    servox.write(posx);   //since the motor moves in 180˚ the numbers assigned can be 
    if (posx <= 180) {    //between 0 and 180 as 1 for each degree
      posx = posx + 10;   //so as long as the joystick is pushed the servos keep   
      delay(100);         //rotating 10˚ and delay so the motor doesnt move too fast
    }                     //cuz the cpu is super fast and the motor can break
    else             //aaaa so tricky part here but idk how to explain it in comments 
    {                //so just ask if really wanna know
      posx = posx - 10;   //it aint that tricky but yea GL if u wanna figure it
    }                     //out yourself
    joyvalx = analogRead(joyx); //read the value again otherwise infinite loop
  }
  while (joyvalx < 750) { //one loop to make it go forward and this one to make it
    servox.write(posx);   //go backwards
    if (posx >= 0) {      //same thing here as the joystick is pushed in opposite
      posx = posx - 10;   //direction the servos keep rotating
      delay(100);
    }
    else                  //again tricky part
    {
      posx = posx + 10;
    }
    joyvalx = analogRead(joyx);
  }
  while (joyvaly > 950) {   //repeat both loops for y axis
    servoy.write(posy);
    if (posy <= 180) {
      posy = posy + 10;
      delay(100);
    }
    else
    {
      posy = posy - 10;
    }
    joyvaly = analogRead(joyy);
  }
  while (joyvaly < 700) {
    servoy.write(posy);
    if (posy >= 0) {
      posy = posy - 10;
      delay(100);
    }
    else
    {
      posy = posy + 10;
    }
    joyvaly = analogRead(joyy);
  }
  delay(dt);
}

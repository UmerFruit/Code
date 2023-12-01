//First, we will declare some integers to for the pin values
const int redLED = 2;
const int blueLED = 3;
const int greenLED = 4;
const int yellowLED = 5;

const int redButton = 9;
const int blueButton = 8;
const int greenButton = 7;
const int yellowButton = 6;

//place where you declare the LEDs and buttons as input or output
//connects them to Arduino so it knows how to manipulate 
void setup()
{
  //Set LED pins as outputs (only displays light)
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  
  //Set Buttons as inputs (controls if you whacked the "mole")
  pinMode(redButton, INPUT);
  pinMode(blueButton, INPUT);
  pinMode(greenButton, INPUT);
  pinMode(yellowButton, INPUT);
}

void loop()
{
  //Makes sure that the game ends after 10 lights are whacked
  for(int i = 0; i < 10; i++)
  {
    //Randomly turns on an LED
    digitalWrite(random(2, 6), HIGH);
    
    //Checks if any of the LEDs are on
    while(digitalRead(redLED) == HIGH || digitalRead(blueLED) == HIGH || digitalRead(greenLED) == HIGH ||digitalRead(yellowLED) == HIGH)
    {
      //Functions that turns off the randomly lit LED
      if (digitalRead(redLED) == HIGH)
      {
        // Makes sure button is pressed
        if (digitalRead(redButton) == LOW)
        {
          //Turns off LED
          digitalWrite(redLED, LOW);
        }
      }

      if (digitalRead(blueLED) == HIGH)
      {
        // Makes sure button is pressed
        if(digitalRead(blueButton) == LOW)
        {  
          //Turns off LED
          digitalWrite(blueLED, LOW);
        }
      }

      if (digitalRead(greenLED) == HIGH)
      {
        //Makes sure button is pressed
        if(digitalRead(greenButton) == LOW)
        {
          //Turns off LED
          digitalWrite(greenLED, LOW);
        }
      }

      if (digitalRead(yellowLED) == HIGH)
      {
        // Makes sure button is pressed
        if(digitalRead(yellowButton) == LOW)
        {
          //Turns off LED
          digitalWrite(yellowLED, LOW);
        }
      }
      delay(100);
    }
  }
  
  //Shows the end of the game blinks 3 times
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(redLED, HIGH);
    digitalWrite(blueLED, HIGH);
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, HIGH);

    delay(250); // Wait for 250 millisecond(s)

    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);

    delay(250); // Wait for 250 millisecond(s)
  }
}

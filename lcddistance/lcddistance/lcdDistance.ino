  /* LCD RS pin to digital pin 12
   * LCD Enable pin to digital pin 11
   * LCD D4 pin to digital pin 5
   * LCD D5 pin to digital pin 4
   * LCD D6 pin to digital pin 3
   * LCD D7 pin to digital pin 2
   * 10K Potentiometer:
   * ends to +5V and ground
   * wiper to LCD VO pin (pin 3)
   
   This example code is in the public domain.
   http://www.arduino.cc/en/Tutorial/LiquidCrystal
   */
   
  #include <LiquidCrystal.h>
  #include <Servo.h>

  Servo myservo;  // create servo object to control a servo
  // twelve servo objects can be created on most boards
  int pos = 0;    // variable to store the servo position

  int distance;
  
  LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
  int inputPin=7;
  int outputPin=6;
  void setup() {
    Serial.begin(9600);
    pinMode(inputPin, INPUT);
    pinMode(outputPin, OUTPUT); 
    lcd.begin(16, 2);
    lcd.print("Distance:");
    
    myservo.attach(9);
  }
  void write2lcd()
  {  
    digitalWrite(outputPin, LOW); 
    delayMicroseconds(2);
    digitalWrite(outputPin, HIGH); 
    delayMicroseconds(10);
    digitalWrite(outputPin, LOW); 
    distance = pulseIn(inputPin, HIGH); 
    distance= distance/58; 
    lcd.setCursor(0,0);
    lcd.print("Distance:");
    lcd.setCursor(0, 1);
    lcd.print(distance);
    delay(500); 
    lcd.clear();  
  }  
  void loop() {

    for (pos = 0; pos <= 180; pos += 10) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(20);                       // waits 15ms for the servo to reach the position
      write2lcd();
    }
    for (pos = 180; pos >= 0; pos -= 10) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(20);                       // waits 15ms for the servo to reach the position
      write2lcd();
    }
  }

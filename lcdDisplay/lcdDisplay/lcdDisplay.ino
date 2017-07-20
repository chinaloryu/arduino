  /* Lab9 - 在2x16 LCD 上显示"Hello World" 讯息 
    The circuit:
   * LCD RS pin to digital pin 12
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
   
  LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
  int inputPin=8;
  int outputPin=9;
   
  void setup() {
    lcd.begin(16, 2);
    lcd.print("Distance:");

    Serial.begin(9600);
    pinMode(inputPin, INPUT);
    pinMode(outputPin, OUTPUT);
  }
   
  void loop() {

    digitalWrite(outputPin, LOW); 
    delayMicroseconds(2);
    digitalWrite(outputPin, HIGH); 
    delayMicroseconds(10);
    digitalWrite(outputPin, LOW); 
    int distance = pulseIn(inputPin, HIGH); 
    distance= distance/58; 
    Serial.println(distance); 
    delay(50); 

    lcd.setCursor(0, 1);
   
    lcd.print(distance);
  }

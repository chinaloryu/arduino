byte DIGITAL_DISPLAY[10][8] = { 
  { 1,1,1,0,1,1,1,1 }, // = 0
  { 0,0,1,0,1,0,0,1 }, // = 1
  { 1,1,0,1,1,1,0,1 }, // = 2
  { 1,1,0,1,0,1,1,1 }, // = 3
  { 1,0,1,1,0,0,1,1 }, // = 4
  { 0,1,1,1,0,1,1,1 }, // = 5
  { 0,1,1,1,1,1,1,1 }, // = 6
  { 1,1,0,0,0,0,1,1 }, // = 7
  { 1,1,1,1,1,1,1,1 }, // = 8
  { 1,1,1,1,0,1,1,1 } // = 9
};
void setup() { 
  for(int i=4;i<=11;i++){
    pinMode(i, OUTPUT); 
  }
}
void loop() { 
  for (int k = 0; k < 10; k++) {
    int pin = 4;
    for (int s = 0; s < 8; s++) 
    {
      digitalWrite(pin, DIGITAL_DISPLAY[k][s]);
      pin++;
    }
    delay(1000); 
  }
}

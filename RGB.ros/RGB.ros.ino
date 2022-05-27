int green = 10;
int red = 11;
int blue = 9;

void setup()
{
  Serial.begin(9600);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop()
{
  for (int i = 0; i<256; i++)
  {
    analogWrite(green, i);
    analogWrite(red, i);
    analogWrite(blue, i);
    Serial.println(i);
    //delay(5);
  
  }

  for (int i = 256; i>0; i--)
  {
    analogWrite(green, i);
    analogWrite(red, i);
    analogWrite(blue, i);
    Serial.println(i);
    //delay(5);
  
  }
}

int latch = 5;
int clock = 6;
int data = 4;
byte led = 0;

void setup()
{
  pinMode(latch, OUTPUT);
  pinMode(data, OUTPUT);
  pinMode(clock, OUTPUT);
}

void loop()
{
  led = 0;
  shiftRegister();
  delay(50);
  for (int i = 0; i<8; i++)
  {
    bitSet(led, i);
    shiftRegister();
    delay(50);
  }

}

void shiftRegister()
{
  digitalWrite(latch, LOW);
  //shiftOut(data, clock, MSBFIRST, led);
  shiftOut(data, clock, LSBFIRST, led);
  digitalWrite(latch, HIGH);
}

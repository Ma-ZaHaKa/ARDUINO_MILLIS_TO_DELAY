unsigned long buffer1 = 0;

void setup()
{
  Serial.begin(9600);
}


void loop()
{
  //static unsigned long buffer1 = 0;
  int delay = 1000;
  if(DKSleep(buffer1, delay)) { Serial.println("!!!"); }
}



bool DKSleep(unsigned long& buffer, int delay_time_ms)
{
  unsigned long currentMillis = millis();
  if (currentMillis - buffer >= delay_time_ms)
  {
    buffer = currentMillis;
    return true;
  }

  return false;
}
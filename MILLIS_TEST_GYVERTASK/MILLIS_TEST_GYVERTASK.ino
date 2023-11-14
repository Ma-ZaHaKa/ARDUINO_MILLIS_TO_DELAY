void setup()
{
  Serial.begin(9600);
}


void loop()
{
  TASK(1000);
}

void TASK(int delay)
{
  static uint32_t tmr;
  if(millis() - tmr >= delay)
  {
    tmr = millis();
    Serial.println("!!!");
  }
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
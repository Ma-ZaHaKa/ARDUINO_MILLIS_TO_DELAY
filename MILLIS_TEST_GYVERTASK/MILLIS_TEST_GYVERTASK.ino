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

bool _DKSleep(float deltaTime, float waitTime, float& sleepBuffer)
{
  sleepBuffer += deltaTime;
  if (sleepBuffer >= waitTime) {
    sleepBuffer = 0.0f;
    return true;
  }
  return false;
}
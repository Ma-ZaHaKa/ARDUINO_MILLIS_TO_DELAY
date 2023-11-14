#include <Arduino.h>

unsigned long previousTime;
float delayDuration = 2.0f;
float sleepBuffer = 0.0f;

int tmp_counter = 1;

void setup()
{
  Serial.begin(9600);
  previousTime = millis();
}


void loop()
{
  unsigned long currentTime = millis();
  float deltaTime = (currentTime - previousTime) / 1000.0f;
  previousTime = currentTime;

  if (_DKSleep(deltaTime, delayDuration, sleepBuffer)) { Serial.println(("DELAY ELAPSED! x" + String(tmp_counter++))); }
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
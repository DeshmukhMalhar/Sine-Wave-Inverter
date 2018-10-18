

#include <PWM.h>


int led = 10; // the pin that the LED is attached to
int freq = 20000; //freq in Hz
void setup()
{
  InitTimersSafe(); //initialize all timers except for 0, to save time keeping functions
  Serial.begin(115200);
  Serial.println();

  FreqSet();
  DutySet();
}

void FreqSet()
{

  SetPinFrequency(led, freq);  //setting the frequency

  //      uint16_t frequency = Timer1_GetFrequency();
  //      uint16_t decimalResolution = Timer1_GetTop() + 1;
  //      uint16_t binaryResolution = GetPinResolution(led); //this number will be inaccurately low because the float is being truncated to a int

  Serial.println("Freq set!");
}

void DutySet()
{
  while (true)
  {

    //setting the duty to 50% with the highest possible resolution that
    //can be applied to the timer (up to 16 bit). 1/2 of 65536 is 32768.
    pwmWrite(led, 127);

    uint16_t frequency = Timer1_GetFrequency();
    uint16_t decimalResolution = Timer1_GetTop() + 1;
    uint16_t binaryResolution = GetPinResolution(led);
    char strOut[75];
    sprintf(strOut, "Frequency: %u Hz\r\n Number of Possible Duties: %u\r\n Resolution: %u bit\r\n", frequency, decimalResolution, binaryResolution );

    Serial.println(strOut);
    //   Serial.println("High Resolution PWM");
    //   delay(1000);
  }

}

void loop()
{ Serial.println("in loop");
}

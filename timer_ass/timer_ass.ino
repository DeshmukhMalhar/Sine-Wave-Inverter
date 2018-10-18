/* Code to pulse pin 3 with a modulated signal
  Can be used to drive an IR LED to keep a TSOP IR reciever happy
  This allows you to use a modulated reciever and a continious beam detector
  By Mike Cook Nov 2011 - Released under the Open Source licence
*/
const uint8_t PERIOD = 51;


void setup() {
  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);
  TCCR2A = _BV(COM2A0) | _BV(COM2B1) | _BV(WGM20);
  TCCR2B = _BV(WGM22) | _BV(CS22);
  OCR2A = 180;
  OCR2B = 50;

}

void loop() {
  // do something here
}

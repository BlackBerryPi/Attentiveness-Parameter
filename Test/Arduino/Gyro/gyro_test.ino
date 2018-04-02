int analogPin = A1;    // potentiometer wiper (middle terminal) connected to analog pin 3
                       // outside leads to ground and +5V
int val = 0;           // variable to store the value read

void setup()
{
  Serial.begin(9600);              // setup serial
}

void loop()
{
  val = analogRead(analogPin);
  
  Serial.println(val);
  Serial.flush();

  delay(10);
}

double doubleMap(double val, double dmax, double dmin, double toMax, double toMin) {
  return (val-dmin)/(dmax-dmin)*(toMax-toMin)+toMin;
}

double antiAlias(double val, double lastVal, double pro) {
  if(lastVal == 0) {
    lastVal = 540;
  }
  return val > lastVal*(1+pro) ? lastVal*(1*pro) : val < lastVal*(1-pro) ? lastVal*(1-pro) : val;
}

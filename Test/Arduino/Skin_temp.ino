int analogPin = A0;    // potentiometer wiper (middle terminal) connected to analog pin 3
                       // outside leads to ground and +5V
int val = 0;           // variable to store the value read
int sum = 0;
int lastVal = 540;
double vault = 0;
double result = 0;
bool flag = true;

void setup()
{
  Serial.begin(9600);              // setup serial
}

void loop()
{
  for(int i=0; i<200; i++) {
    sum += analogRead(analogPin);
  }
  
  result = sum/200.0;      // read the input pin
  
  //result = constrain(val, 480, 630);
  
  //vault = doubleMap(val, 0, 1023, 0, 5);
  //result = doubleMap(vault, 1.458, 1.85, 0, 5.9);
  if(-sum/100 > 0) {
    Serial.println(-sum/100);
  }

  sum = 0;
  //delay(500);
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

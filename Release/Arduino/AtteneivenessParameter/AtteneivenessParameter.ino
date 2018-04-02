int tempPin = A0;
int gyroXPin = A1;
int gyroYPin = A2;
int gyroZPin = A3;
                       // outside leads to ground and +5V
int val = 0;           // variable to store the value read
int gyroX = 0;
int gyroY = 0;
int gyroZ = 0;

int sum = 0;
double lastVal = 0;
double vault = 0;
double result = 0;
double divide = 20;
bool flag = true;
int gyroCount = 0;

void setup()
{
  Serial.begin(9600);              // setup serial
}

void loop()
{ 
  for(int i=0; i<200; i++) {
    sum += analogRead(tempPin);

    if(gyroCount == 20) {
      gyroX = analogRead(gyroXPin);
      gyroY = analogRead(gyroYPin);
      gyroZ = analogRead(gyroZPin);
      Serial.print(";X"+String(gyroX)+";Y"+String(gyroY)+";Z"+String(gyroZ)+";");

      gyroCount = 0;
    }
    
    //delay(5);
    gyroCount++;
  }

  if(flag) {
    lastVal = sum;
  }

  if(abs((sum-lastVal)/lastVal) > 0.3) {
    sum = lastVal;
  }

  //Serial.println(String(-sum/100));
  Serial.print(";T"+String(-sum/100)+";");
  Serial.print("R"+String(-sum/100)+";");
  Serial.flush();

  lastVal = sum;

  sum = 0;
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

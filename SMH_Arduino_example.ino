/*
 Sensor: SMH-01
 MCU: Arduino UNO
  
*/

int pin_Energy  = 2;      // D2 Power for SMH sensor
int sensorPin   = A0;     // SMH-01 analog input 0-5V
int sensorValue = 0;      // variable to store the value coming from the sensor
int Sm;
int sensorDRY = 0;        // Value in DRY Soil
int sensorWET = 194;     // Value in WET Soil 
int Available_Water = 0;
int i;


void setup() 
{
  
  Serial.begin(9600);
  
  pinMode(pin_Energy, OUTPUT);
  
  delay(1000);

}

void loop() 
{
      
  Measure_SMH();
  
  // Soil moisture calculations 
  Available_Water = map(Sm, sensorDRY, sensorWET, 0, 100);
  if (Available_Water <   0) Available_Water = 0;
  if (Available_Water > 100) Available_Water = 100;
  
  Serial.print("Raw value: ");
  Serial.println(Sm);
  Serial.print("Available Water: ");
  Serial.println(Available_Water);
  
  delay(1000);
  
}

void Measure_SMH ()
   {

    Sm = 0;
    digitalWrite(pin_Energy, HIGH);
    delay(500);

    for(i=0; i<3; i++)
       {
        sensorValue = analogRead(sensorPin);
        Sm = Sm + sensorValue;
        delay(100);
       } 
  
    digitalWrite(pin_Energy, LOW);
    Sm = Sm/3;
         
}// Measure_SMH



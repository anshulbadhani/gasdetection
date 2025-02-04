#include <MQUnifiedsensor.h>
#include <RH_ASK.h>

#define G_LED 4
#define R_LED 14
#define GAS A0

static RH_ASK driver;

void setup() {
  driver.init();
  pinMode(G_LED, OUTPUT);
  pinMode(R_LED, OUTPUT);
  pinMode(GAS, INPUT);
  Serial.begin(9600);

  if(!driver.init())
    Serial.println("Failed to init the tx");
  else
    Serial.println("Ready");
  // put your setup code here, to run once:

}
/*
 * Run this once while callibrating the sensor *
 * 
void loop() {
float sensor_volt; 
  float RS_air; //  Get the value of RS so that we can calibrate the sensor
  float R0;  // Get the value of R0 via in H2
  float sensorValue;
   
    for(int x = 0 ; x < 100 ; x++)
  {
    sensorValue = sensorValue + analogRead(A0);
  }
  sensorValue = sensorValue/100.0;
 
  sensor_volt = sensorValue/1024*5.0;
  RS_air = (5.0-sensor_volt)/sensor_volt; // omit *RL
  R0 = RS_air/6.5; // The ratio of RS/R0 is 6.5 in a clear air from Graph (Found using WebPlotDigitizer)
 
  Serial.print("sensor_volt = ");
  Serial.print(sensor_volt);
  Serial.println("V");
 
  Serial.print("R0 = ");
  Serial.println(R0);
  delay(1000);
 
}
*/

/* actual code */

#define R0 1 // right now it is set to 1 but after callibration replace with experimental value
void loop() {
  // put your main code here, to run repeatedly:

  float RS_gas = 1.0; // experimental value
  float ratio = 1.0; // experimental value
  int gasValue = analogRead(GAS);
  float sensor_volt = (float)gasValue/1024*5.0;
  RS_gas = (5.0 - sensor_volt)/sensor_volt;

  ratio = RS_gas/R0;

  char msg[16];
  snprintf(msg, sizeof(msg), "%d", sensor_volt);
  Serial.print("Gas Value: ");
  Serial.println(msg);
  driver.send((uint8_t *)msg, strlen(msg)+1);
  driver.waitPacketSent();

  delay(1000);
}

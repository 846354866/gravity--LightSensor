/*!
 * @file lightsensordread.ino
 * @brief DFRobot's get the Brightness numerical 
 * @n [Get the module here](等上架后添加商品购买链接)
 * @n This example Set the volume size and play music snippet.
 * @n [Connection and Diagram](等上架后添加wiki链接)
 *
 * @copyright	[DFRobot](http://www.dfrobot.com), 2016
 * @copyright	GNU Lesser General Public License
 *
 * @author [yangyang](971326313@qq.com)
 * @version  V1.0
 * @date  2016-09-22
 */
#include<LightSensor.h>
#define DISCOVERY_SINGLE_BUS_PIN 2
SoftwareSinglebus  mySingleBus(DISCOVERY_SINGLE_BUS_PIN);
LightSensor u(&mySingleBus,0x02);

void LightSensorCB( void* p_ ){
    LightSensor* ultra = (LightSensor*)p_;
    //int16_t data = ultra->readBrightness();
    //if(data != -1)
    //   Serial.println(data);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(100);
 u.setCB(LightSensorCB);
 u.start();
// u.modifyAddr(0x01);
}

void loop() {
  // put your main code here, to run repeatedly:
  int16_t data = u.readLeftBrightness();//get the left numerical
  delay(100); 
  int16_t data1 = u.readRightBrightness();//get the right numerical
  
  if(data != -1)
  {
    Serial.println(data);
    Serial.println(data1);
  }
  
  delay(100); 
}


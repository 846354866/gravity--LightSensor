/*!
 * @file LightSensor.h
 * @brief LightSensor
 * @n Header file for DFRobot's LightSensor
 *
 * @copyright	[DFRobot](http://www.dfrobot.com), 2016
 * @copyright	GNU Lesser General Public License
 *
 * @author [yangyang](971326313@qq.com)
 * @version  V1.0
 * @date  2016-09-22
 */
#include<LightSensor.h>
#include<Arduino.h>
int16_t LightSensor::setCB( void (*cb)( void* p_ ) )
{
    bus->registerCB( addr, cb, this );
    return 0;
}

LightSensor::LightSensor(SoftwareSinglebus *bus_,int addr_)
	:bus(bus_),addr(addr_)
{
	
}

int16_t LightSensor::start()	
{
  bus->begin();
  bus->beginTransmission(addr,WRITE);
  bus->write(REG_START);
  bus->write(0x01);
  bus->endTransmission();
  delay(1);
  return 0;
}

int16_t LightSensor::stop()
{
  char stopdata = 0x00;
  bus->beginTransmission(addr,WRITE);
  bus->write(REG_START);
  bus->write(&stopdata);
  bus->endTransmission();
  return 0;
}

int16_t LightSensor::modifyAddr(uint8_t newAddr)
{
  bus->beginTransmission(addr,WRITE);
  bus->write(REG_ADDR);
  bus->write(newAddr);
  bus->endTransmission();
  addr = newAddr;
  return 0;
}

int16_t LightSensor::readLeftBrightness()
{
	direction = REG_LEFT;
	
	return readBrightness();
}

int16_t LightSensor::readRightBrightness()
{
	direction = REG_RIGHT;
	
	return readBrightness();
}

int16_t LightSensor::readBrightness()
{
  int len = 0x02;
  
  int16_t data = -1;
  uint8_t temp = 0;
  bus->beginTransmission(addr,READ);
  bus->write(direction);///<register address
  bus->write(len); ///<read length
  bus->endTransmission();
  bus->requestFrom(addr,len);
  if(bus->available() == 0x02){
    temp = bus->read();
    data = temp<<8|(bus->read());
  }else if(bus->available() == 0x01){
    data = bus->read(); 	
  }else{
  	data = -1;
  }
  bus->endTransmission();
  return data;
}

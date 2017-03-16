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
#ifndef LightSensor_h
#define LightSensor_h

#include <SoftwareSinglebus.h>

#define REG_ADDR     0x04
#define REG_START    0x05
#define REG_LEFT	 0x0d
#define REG_RIGHT	 0x0b


class LightSensor
{
	public:
	
		/*!
		*  @brief Constructor.
		*  @param bus_  single bus .
		*  @param addr_  Register address.
		*/
		LightSensor(SoftwareSinglebus *bus_,int addr_=0x01);
		
		/*!
		*  @brief Start the ultrasonic.
		*/
		int16_t start(); 
		/*!
		*  @brief Stop the ultrasonic.
		*/
		int16_t stop(); 
		
		/*!
		*  @brief Modify the ultrasonic register address.
		*  @param id  new  register address.
		*/
		int16_t modifyAddr(uint8_t id); 
		
		/*!
		*  @brief Read the left brightness.
		*  @return the brightness between the object.
		*/
		int16_t readLeftBrightness();  
		
		/*!
		*  @brief Read the Right brightness.
		*  @return the brightness between the object.
		*/
		int16_t readRightBrightness();  
		
		/*!
		*  @brief Read brightness.
		*  @return the brightness between the object.
		*/
		int16_t readBrightness();  
		
		/*!
		*  @brief Set the interrupt the callback function.
		*  @param cb  callback function.
		*/
		int16_t setCB( void (*cb)( void* p_ ) );
	private:
		SoftwareSinglebus *bus;///<single bus.
		uint8_t addr; ///<ltrasonic register address.
		uint8_t direction;///<get the Left/Right numerical
};
#endif

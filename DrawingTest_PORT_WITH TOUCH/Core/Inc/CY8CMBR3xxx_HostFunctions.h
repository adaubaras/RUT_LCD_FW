

#if !defined(CY8CMBR3xxx_HOSTFUNCTIONS_H)
#define CY8CMBR3xxx_HOSTFUNCTIONS_H

/*******************************************************************************
* Included headers
*******************************************************************************/
#include<stdint.h>

//#include <stm32l5xx_hal_i2c.h>

/*******************************************************************************
* Data Type Definitions
*******************************************************************************/

#if !defined(CY8CMBR3xxx_DATATYPE_GUARD)
#define CY8CMBR3xxx_DATATYPE_GUARD

#define TRUE                                             (1)
#define FALSE                                            (0)

typedef unsigned char   uint8;
typedef unsigned short  uint16;
typedef unsigned long   uint32;
typedef uint8 bool;
#endif

/*Exported global variables*/
//I2C_TypeDef  hi2c1;

/*******************************************************************************
* Function Prototypes
*******************************************************************************/
bool Host_LowLevelWrite(uint8 slaveAddress, uint8 *writeBuffer, uint8 numberOfBytes);
bool Host_LowLevelRead(uint8 slaveAddress, uint8 *readBuffer, uint8 numberOfBytes);
void Host_LowLevelDelay(uint16 milliseconds);

#endif

/****************************End of File***************************************/

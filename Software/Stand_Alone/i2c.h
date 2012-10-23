
#ifndef _I2C_H
#define _I2C_H

#include <htc.h>

#define I2C_WRITE 0
#define I2C_READ 1


// i2c_Init - Initialise the i2c bus
void i2c_Init(void);

// i2c_Wait - wait for I2C transfer to finish
void i2c_Wait(void);

// i2c_Start - Start I2C communication
void i2c_Start(void);

// i2c_Restart - Re-Start I2C communication
void i2c_Restart(void);

// i2c_Stop - Stop I2C communication
void i2c_Stop(void);

// i2c_Write - Sends one byte of data
void i2c_Write(unsigned char);

// i2c_Address - Sends Slave Address and Read/Write mode
// mode is either I2C_WRITE or I2C_READ
void i2c_Address(unsigned char, unsigned char );

// i2c_Read - Reads a byte from Slave device
unsigned char i2c_Read(unsigned char);

#endif

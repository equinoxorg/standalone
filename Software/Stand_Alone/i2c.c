/*
 |  Copyright (C) 2011  Ashley Grealish - e.quinox.org
 |
 |  This program is free software: you can redistribute it and/or modify
 |  it under the terms of the GNU General Public License as published by
 |  the Free Software Foundation, either version 3 of the License, or
 |  (at your option) any later version.
 |
 |  This program is distributed in the hope that it will be useful,
 |  but WITHOUT ANY WARRANTY; without even the implied warranty of
 |  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 |  GNU General Public License for more details.
 |
 |  You should have received a copy of the GNU General Public License
 |  along with this program.  If not, see <http://www.gnu.org/licenses/>.   
*/

#include "i2c.h"

void i2c_Init(void) {

    // Initialise I2C MSSP
    // Master 100KHz
    //TRISA1 = 1; // set SCL and SDA pins as inputs
    //TRISA2 = 1;

    SSP1CON1 = 0b00101000; // I2C enabled, Master mode
    SSP1CON2 = 0x00;
    // I2C Master mode, clock = FOSC/(4 * (SSPADD + 1))
    SSP1ADD = 19; // 100Khz @ 8Mhz Fosc
    //TODO: Add Macro to define this

    SSP1STAT = 0b11000000; // Slew rate disabled

}

// i2c_Wait - wait for I2C transfer to finish

void i2c_Wait(void) {
    while ((SSP1CON2 & 0x1F) || (SSP1STAT & 0x04));
}

// i2c_Start - Start I2C communication

void i2c_Start(void) {
    i2c_Wait();
    SSP1CON2bits.SEN = 1;
}

// i2c_Restart - Re-Start I2C communication

void i2c_Restart(void) {
    i2c_Wait();
    SSP1CON2bits.RSEN = 1;
}

// i2c_Stop - Stop I2C communication

void i2c_Stop(void) {
    i2c_Wait();
    SSP1CON2bits.PEN = 1;
}

// i2c_Write - Sends one byte of data

void i2c_Write(unsigned char data) {
    i2c_Wait();
    SSP1BUF = data;
}

// i2c_Address - Sends Slave Address and Read/Write mode
// mode is either I2C_WRITE or I2C_READ

void i2c_Address(unsigned char address, unsigned char mode) {
    unsigned char l_address;

    l_address = address << 1;
    l_address += mode;
    i2c_Wait();
    SSP1BUF = l_address;
}

// i2c_Read - Reads a byte from Slave device

unsigned char i2c_Read(unsigned char ack) {
    // Read data from slave
    // ack should be 1 if there is going to be more data read
    // ack should be 0 if this is the last byte of data read
    unsigned char i2cReadData;

    i2c_Wait();
    SSP1CON2bits.RCEN = 1;
    i2c_Wait();
    i2cReadData = SSP1BUF;
    i2c_Wait();
    if (ack) SSP1CON2bits.ACKDT = 0; // Ack
    else SSP1CON2bits.ACKDT = 1; // NAck
    SSP1CON2bits.ACKEN = 1; // send acknowledge sequence

    return ( i2cReadData);
}

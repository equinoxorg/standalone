#include "rtc.h"


#define I2C_SLAVE 0b1101000                    // Slave device I2C address

#define I2C_WRITE 0
#define I2C_READ 1

// Send a command to servo ic
void rtc_word_write(unsigned char address, unsigned char data)
{
    i2c_Start();                        // send Start
    i2c_Address(I2C_SLAVE, I2C_WRITE);  // Send slave address - write operation
    i2c_Write(address);	                // Address of data
    i2c_Write(data);	                // send data
    i2c_Stop();	                        // send Stop
}

// Read a char from servo ic
unsigned char rtc_word_read(unsigned char address)
{
    unsigned char read_byte;
    // Read one byte (i.e. servo pos of one servo)
    i2c_Start();                        // send Start
    i2c_Address(I2C_SLAVE, I2C_WRITE);  // Send slave address - write operation
    i2c_Write(address);	                // Address of read location
    i2c_Restart();                      // Restart
    i2c_Address(I2C_SLAVE, I2C_READ);   // Send slave address - read operation
    read_byte = i2c_Read(0);            // Read one byte
                          // If more than one byte to be read, (0) should
                          // be on last byte only
                          // e.g.3 bytes= i2c_Read(1); i2c_Read(1); i2c_Read(0);
    i2c_Stop();                         // send Stop
    return read_byte;                   // return byte.
                                        // If reading more than one byte
                                        // store in an array
}

void rtc_time_date_read ( uint8_t* data_array ) {
    
    uint8_t i;

    i2c_Start();                        // send Start
    i2c_Address(I2C_SLAVE, I2C_WRITE);  // Send slave address - write operation
    i2c_Write(0x00);	                // Send start address
    i2c_Restart();                      // Restart
    i2c_Address(I2C_SLAVE, I2C_READ);   // Send slave address - read operation
    for (i = 0; i < 6; i++) {
        data_array[i] = i2c_Read(1);
    }
    data_array[6] = i2c_Read(0);
    i2c_Stop();
}

uint8_t bcd_to_uint8 (uint8_t in_data){
    return ( (in_data & 0x0F) + (((in_data >> 4 ) & 0x0F)*10) );
}

void rtc_get_time_date( struct tm* time_ptr ){
    uint8_t rtc_mem_array[7];

    rtc_time_date_read(&rtc_mem_array);

    time_ptr->tm_sec = bcd_to_uint8(rtc_mem_array[0] & 0b01111111);
    time_ptr->tm_min = bcd_to_uint8(rtc_mem_array[1]);
    time_ptr->tm_hour = bcd_to_uint8(rtc_mem_array[2] & 0b00111111);
    time_ptr->tm_mday = bcd_to_uint8(rtc_mem_array[4]);
    time_ptr->tm_mon = bcd_to_uint8(rtc_mem_array[5]);
    time_ptr->tm_year =  (bcd_to_uint8(rtc_mem_array[6]) + 70);

    mktime(time_ptr);

}

uint8_t rtc_get_sec (void) {
    uint8_t register_val, seconds;

    register_val = rtc_word_read(0x00); 

    seconds = register_val & 0b00001111;
    seconds += ((register_val & 0b01110000) >> 4) * 10;

    return seconds;

}


uint8_t rtc_get_min (void) {
    uint8_t register_val, mins;

    register_val = rtc_word_read(0x01); 

    mins = register_val & 0b00001111;
    mins += ((register_val & 0b01110000) >> 4) * 10;

    return mins;

}

uint8_t rtc_get_hour (void) {
    uint8_t register_val, hour;

    register_val = rtc_word_read(0x02); 

    hour = register_val & 0b00001111;
    hour += ((register_val & 0b00110000) >> 4) * 10;

    return hour;

}

uint8_t rtc_get_date (void) {
    uint8_t register_val, date;

    register_val = rtc_word_read(0x04); 

    date = register_val & 0b00001111;
    date += ((register_val & 0b00110000) >> 4) * 10;

    return date;

}

uint8_t rtc_get_month (void) {
    uint8_t register_val, month;

    register_val = rtc_word_read(0x05); 

    month = register_val & 0b00001111;
    month += ((register_val & 0b00010000) >> 4) * 10;

    return month;

}

uint16_t rtc_get_year (void) {
    uint16_t register_val, year;

    register_val = rtc_word_read(0x06); 

    year = register_val & 0b00001111;
    year += ((register_val & 0b11110000) >> 4) * 10;

    return year + 1970;
}

uint32_t time_since_epoch (void) {
    time_t epoch_time;
    struct tm time_s;

    //read_struct_tm( &time_s );
    rtc_get_time_date( &time_s );

    epoch_time = mktime( &time_s );

    return epoch_time;
}


unsigned char init_rtc(void) {
   
    i2c_Init(); // Start I2C as Master 100KHz

    //Checks that the rtc is turned on, if not returns non-zero number
    return rtc_word_read(0x00) & ~0b1000000;
}

void setup_rtc(void) {

    i2c_Init(); // Start I2C as Master 100KHz

    // Set the control register
    rtc_word_write(0x07, 0b00000000);
    //Turns the clock on
    rtc_word_write(0x00, 0x00);//, (rtc_word_read(0x00) & ~0b1000000) );
    //Turns on 24h mode
    rtc_word_write(0x02, (rtc_word_read(0x02) & ~0b0100000));
}



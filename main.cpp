#include "mbed.h"
#include "LSM6DSLSensor.h"

#define LSM6DSL_I2C_SDA_PIN PB_9
#define LSM6DSL_I2C_SCL_PIN PB_8

I2C i2c(LSM6DSL_I2C_SDA_PIN, LSM6DSL_I2C_SCL_PIN);

#define LSM6DSL_I2C_ADDRESS 0x6B  

LSM6DSLSensor acc_gyro(&i2c, LSM6DSL_I2C_ADDRESS);

PwmOut led1(PA_5); 
PwmOut led2(PA_6); 
PwmOut led3(PA_7); 

int main() {
    int32_t axes[3];

    acc_gyro.init(NULL);
    acc_gyro.enable_x(); 

    while (true) {
      
        acc_gyro.get_x_axes(axes);
       
        led1 = (float)(axes[0] + 4000) / 8000.0f; 
        led2 = (float)(axes[1] + 4000) / 8000.0f; 
        led3 = (float)(axes[2] + 4000) / 8000.0f; 
        
        wait_us(50000); 
    }
}

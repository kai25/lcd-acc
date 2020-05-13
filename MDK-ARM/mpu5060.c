#include "sd_hal_mpu6050.h"
#include "mpu5060.h"

#define ACC_K 16384.0


Accelerometer::Accelerometer(I2C_HandleTypeDef* I2Cx) {
	this->I2Cx = I2Cx;
}

void Accelerometer::init() {
	SD_MPU6050_Init(this->I2Cx, &this->mpu1, SD_MPU6050_Device_0 ,SD_MPU6050_Accelerometer_2G, SD_MPU6050_Gyroscope_250s);
}

void Accelerometer::getXYZ(double* x, double* y, double* z) {
	  SD_MPU6050_ReadAccelerometer(this->I2Cx, &this->mpu1);
	  *x = mpu1.Accelerometer_X / ACC_K;
	  *y = mpu1.Accelerometer_Y / ACC_K;
	  *z = mpu1.Accelerometer_Z / ACC_K;
}

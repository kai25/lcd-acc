#include "mpu6050_i2c.h"

class Accelerometer {
	private:
		SD_MPU6050 mpu1;
		I2C_HandleTypeDef* I2Cx;
	public:
		Accelerometer(I2C_HandleTypeDef* I2Cx);
		void init();
		void getXYZ(double* x, double* y, double* z);
};

/*
 * mpu6050.h
 *
 *  Created on: Mar 18, 2022
 *      Author: Ibrahim Ozdemir
 *      GitHub: ibrahimcahit   
 */

#ifndef INC_6050_H_
#define INC_6050_H_

#include <stdint.h>
#include "i2c.h"
#include "./mpu_defs.h"

typedef struct
{
    float AccelX_MPU6050_f32;
    float AccelY_MPU6050_f32;
    float AccelZ_MPU6050_f32;

    float GyroX_MPU6050_f32;
    float GyroY_MPU6050_f32;
    float GyroZ_MPU6050_f32;

    uint8_t CALIBRATIN_OK_u8;

} MPU6050_t;

uint8_t MPU6050_Init(I2C_HandleTypeDef *I2Cx, MPU6050_t*DataStruct);

void readMPU6050(I2C_HandleTypeDef *I2Cx, MPU6050_t*DataStruct);

void getMPU6050Gres();
void getMPU6050Ares();

void readMPU6050AccelData(I2C_HandleTypeDef *I2Cx, int16_t * destination);
void readMPU6050GyroData(I2C_HandleTypeDef *I2Cx, int16_t * destination);

void initMPU6050(I2C_HandleTypeDef *I2Cx);

void calibrateMPU6050(I2C_HandleTypeDef *I2Cx, MPU6050_t*DataStruct, float * dest1, float * dest2);

void MPU6050SelfTest(I2C_HandleTypeDef *I2Cx, float * destination);

#endif /* INC_6050_H_ */

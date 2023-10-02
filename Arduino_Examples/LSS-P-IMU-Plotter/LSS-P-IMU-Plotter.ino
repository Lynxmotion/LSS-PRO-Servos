/**
 ******************************************************************************
 * @file    DISCO_IOT_LSM6DSL_DataLogTerminal.ino
 * @author  WI6LABS from AST
 * @version V1.0.0
 * @date    7 September 2017
 * @brief   Arduino test application for the STMicrolectronics STM32 DISCO_IOT
 *          MEMS Inertial and Environmental sensor expansion board.
 *          This application makes use of C++ classes obtained from the C
 *          components' drivers.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT(c) 2017 STMicroelectronics</center></h2>
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of STMicroelectronics nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */
 
// Includes.
// https://github.com/stm32duino/LSM6DSL
#include <LSM6DSLSensor.h>

#define SerialPort Serial
#define I2C2_SCL    PB6
#define I2C2_SDA    PB7

// Components.
TwoWire dev_i2c(I2C2_SDA, I2C2_SCL);
LSM6DSLSensor AccGyr(&dev_i2c, LSM6DSL_ACC_GYRO_I2C_ADDRESS_LOW);

void setup()
{
  // Initialize serial for output.
    SerialPort.begin(115200);

  // Initialize I2C bus.
    dev_i2c.begin();

  // Initlialize components.
    AccGyr.begin();
    AccGyr.Enable_X();
    AccGyr.Enable_G();
}

void loop()
{
  // Read accelerometer and gyroscope.
    int32_t accelerometer[3];
    int32_t gyroscope[3];
    AccGyr.Get_X_Axes(accelerometer);
    AccGyr.Get_G_Axes(gyroscope);

  // Print the values for the Arduino Serial Plotter
    Serial.print("Acc_0[mg]:");     Serial.print(accelerometer[0]);   Serial.print(",");
    Serial.print("Acc_1[mg]:");     Serial.print(accelerometer[1]);   Serial.print(",");
    Serial.print("Acc_2[mg]:");     Serial.print(accelerometer[2]);   Serial.print(",");
    Serial.print("Gyr_0[mdps]:");   Serial.print(gyroscope[0]);       Serial.print(",");
    Serial.print("Gyr_1[mdps]:");   Serial.print(gyroscope[1]);       Serial.print(",");
    Serial.print("Gyr_2[mdps]:");   Serial.print(gyroscope[2]);       Serial.println();
}

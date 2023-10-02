#include<Wire.h>
TwoWire I2C(PB11, PB10);

#define Wire I2C

// MCP9805 I2C address is 0x18(24)
#define Addr 0x18

void setup()
{
  // Initialise I2C communication as MASTER
  Wire.begin();
  // Initialise Serial Communication, set baud rate = 9600 
  Serial.begin(115200);
  
  // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Select configuration register
  Wire.write(0x01);
  // Continuous conversion mode, Power-up default
  Wire.write(0x00);
  Wire.write(0x00);
  // Stop I2C Transmission
  Wire.endTransmission();
  
  // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Select resolution rgister
  Wire.write(0x08);
  // Resolution = +0.0625 / C
  Wire.write(0x03);
  // Stop I2C Transmission
  Wire.endTransmission();
}

void loop()
{
  unsigned int data[2];
  
  // Starts I2C communication
    Wire.beginTransmission(Addr);
  // Select data register
    Wire.write(0x05);
  // Stop I2C transmission
    Wire.endTransmission();
  
  // Request 2 bytes of data
    Wire.requestFrom(Addr, 2);
  
  // Read 2 bytes of data
  // temp MSB, temp LSB
    if(Wire.available() == 2)
    {
      data[0] = Wire.read();
      data[1] = Wire.read();
    }
  
  // Convert the data to 13-bits
    int temp = ((data[0] & 0x1F) * 256 + data[1]);
    if(temp > 4095)
    {
      temp -= 8192;
    }
    float cTemp = temp * 0.0625;
    float fTemp = cTemp * 1.8 + 32;
  
  // Print the values for the Arduino Serial Plotter
    Serial.print("DegC:");  Serial.print(cTemp);  Serial.print(",");
    Serial.print("DegF:");  Serial.print(fTemp);  Serial.println();

  delay(50);
}

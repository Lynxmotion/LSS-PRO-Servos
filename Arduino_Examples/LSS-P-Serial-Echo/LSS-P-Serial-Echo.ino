byte bytesIn;

// Setup, initialize 
void setup() 
{
  Serial.begin(115200);  
}

// Loop forever
void loop() 
{
  // Serial data is pending
  if (Serial.available()) 
  { 
    // Echo serial data on serial device
    bytesIn = Serial.read();
    Serial.write(bytesIn);
  }  
}

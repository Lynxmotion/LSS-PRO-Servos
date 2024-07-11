/**
 * Author Teemu Mäntykallio
 * Initializes the library and runs the stepper
 * motor in alternating directions.
 * https://www.arduino.cc/reference/en/libraries/tmcstepper/
 */

#include <TMCStepper.h>

#define EN_PIN    PC11  // Enable
#define DIR_PIN   PC8   // Direction
#define STEP_PIN  PC7   // Step
#define CS_PIN    PA4   // Chip select
#define SW_MOSI   PA7   // Software Master Out Slave In (MOSI)
#define SW_MISO   PA6   // Software Master In Slave Out (MISO)
#define SW_SCK    PA5   // Software Slave Clock (SCK)
#define SD_MODE   PB14  // SD Mode
#define SPI_MODE  PB15  // SPI Mode

#define R_SENSE 0.075f // Watterott TMC5160 uses 0.075

// Select your stepper driver type
  //TMC5160Stepper driver(CS_PIN, R_SENSE);
  TMC5160Stepper driver(CS_PIN, R_SENSE, SW_MOSI, SW_MISO, SW_SCK);

void setup() {

// Configure the pins
  pinMode(EN_PIN,       OUTPUT);
  pinMode(STEP_PIN,     OUTPUT);
  pinMode(DIR_PIN,      OUTPUT);
  digitalWrite(EN_PIN,  LOW);      // Enable driver in hardware

// Set the correct MODE 
  pinMode(SD_MODE,      OUTPUT);
  digitalWrite(SD_MODE, LOW);
  pinMode(SPI_MODE,     OUTPUT);
  digitalWrite(SD_MODE, HIGH);

  driver.begin();                 //  SPI: Init CS pins and possible SW SPI pins
  driver.toff(5);                 // Enables driver in software
  driver.rms_current(1000);       // Set motor RMS current
  driver.microsteps(16);          // Set microsteps to 1/16th

//driver.en_pwm_mode(true);       // Toggle stealthChop on TMC2130/2160/5130/5160
//driver.en_spreadCycle(false);   // Toggle spreadCycle on TMC2208/2209/2224
  driver.pwm_autoscale(true);     // Needed for stealthChop
}

bool direction = LOW;

void loop() {
  // Set direction
  digitalWrite(DIR_PIN, direction);

  // Run 50 steps
  for (uint16_t i = 15000; i > 0; i--) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(80);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(80);
  }

  // Change direction
  direction = (direction == LOW) ? HIGH : LOW;

  delay(1000);
}

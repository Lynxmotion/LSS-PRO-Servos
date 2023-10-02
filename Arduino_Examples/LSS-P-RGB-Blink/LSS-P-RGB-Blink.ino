// Variables declared for PIN assignment
#define LED_B  PD10
#define LED_R  PD12
#define LED_G  PD13

void setup()
{
  // Set the pins to Output mode
  pinMode(LED_B, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
}

void loop()
{
  // Set the RGB color to Red only
  digitalWrite(LED_B, HIGH);
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, HIGH);
  delay(500);
  // Set the RGB color to Green only
  digitalWrite(LED_B, HIGH);
  digitalWrite(LED_R, HIGH);
  digitalWrite(LED_G, LOW);
  delay(500);
  // Set the RGB color to Blue only
  digitalWrite(LED_B, LOW);
  digitalWrite(LED_R, HIGH);
  digitalWrite(LED_G, HIGH);
  delay(500);
  // Set the RGB color to White which is RGB at the same time
  digitalWrite(LED_B, LOW);
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, LOW);
  delay(500);
  // Shut all outputs, no colors
  digitalWrite(LED_B, HIGH);
  digitalWrite(LED_R, HIGH);
  digitalWrite(LED_G, HIGH);
  delay(500); 
}

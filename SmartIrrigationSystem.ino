// Smart Irrigation System

int sensor_pin = A0;
int output_value;

void setup() {
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  Serial.println("Reading from the Moisture sensor…");
  delay(2000);
}

void loop() {
  output_value = analogRead(sensor_pin); // Raw value between 0 and 1023

  Serial.print("Sensor Reading: ");
  Serial.println(output_value);

  // Adjust threshold as per your sensor (try printing values in dry and wet conditions)
  if (output_value < 500) { // Dry soil (low value) ➝ Turn ON pump
    digitalWrite(3, HIGH);
    Serial.println("Pump ON");
  } else { // Wet soil (high value) ➝ Turn OFF pump
    digitalWrite(3, LOW);
    Serial.println("Pump OFF");
  }

  delay(1000);
}

int Buzzer_Pin = 7;

void setup() {
  Serial.begin(9600);
  pinMode(Buzzer_Pin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  tone(Buzzer_Pin,523);
  delay(1000);
  tone(Buzzer_Pin,587);
  delay(1000);
  tone(Buzzer_Pin,659);
  delay(1000);
}
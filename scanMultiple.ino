void scanMultiple() {

  if (analogRead(SW1_ADC_pin) > 100) {
    strcpy(multiMessage, SW1_ID);
    Serial.println("SW1 Detected");
  }
  if (analogRead(SW2_ADC_pin) > 100) {
    strcpy(multiMessage, SW2_ID);
    Serial.println("SW2 Detected");
  }
  if (analogRead(SW3_ADC_pin) > 100) {
    strcpy(multiMessage, SW3_ID);
    Serial.println("SW3 Detected");
  }
  if (analogRead(SW4_ADC_pin) > 100) {
    strcpy(multiMessage, SW4_ID);
    Serial.println("SW4 Detected");
  }
}

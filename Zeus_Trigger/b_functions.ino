void drawLogo(void) {
 
  display.clearDisplay();

  display.drawBitmap(
    (display.width()  - LOGO_WIDTH ) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
}

void resetButton3(void){
  // Resets button 2 to off so that double selections don't happen
  button3State = 0;
  button3PrevState = 0;
  button3Debounce = currentMillis;
}

void resetButton2(void){
  // Resets button 2 to off so that double selections don't happen
  button2State = 0;
  button2PrevState = 0;
  button2Debounce = currentMillis;
}


void nikonShoot(void) {
  int i;
  for (i = 0; i < 76; i++) {
    digitalWrite(IR_LED, HIGH);
    delayMicroseconds(7);
    digitalWrite(IR_LED, LOW);
    delayMicroseconds(7);
  }
  delay(27);
  delayMicroseconds(810);
  for (i = 0; i < 16; i++) {
    digitalWrite(IR_LED, HIGH);
    delayMicroseconds(7);
    digitalWrite(IR_LED, LOW);
    delayMicroseconds(7);
  }
  delayMicroseconds(1540);
  for (i = 0; i < 16; i++) {
    digitalWrite(IR_LED, HIGH);
    delayMicroseconds(7);
    digitalWrite(IR_LED, LOW);
    delayMicroseconds(7);
  }
  delayMicroseconds(3545);
  for (i = 0; i < 16; i++) {
    digitalWrite(IR_LED, HIGH);
    delayMicroseconds(7);
    digitalWrite(IR_LED, LOW);
    delayMicroseconds(7);
  }
}

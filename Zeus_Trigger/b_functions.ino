void drawLogo(void) {
 
  display.clearDisplay();

  display.drawBitmap(
    (display.width()  - LOGO_WIDTH ) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
}

void resetButton2(void){
  // Resets button 2 to off so that double selections don't happen
  button2State = 0;
  button2PrevState = 0;
  button2Debounce = currentMillis;
}

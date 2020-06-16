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

void resetButton3(void){
  // Resets button 2 to off so that double selections don't happen
  button3State = 0;
  button3PrevState = 0;
  button3Debounce = currentMillis;
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

int getSeconds(unsigned long milliseconds){
  /*
   * Takes a time in miliseconds.
   * Returns the number of full seconds that don't make up a minute.
   */

   int seconds = milliseconds / 1000;
   seconds = seconds % 60;
   return seconds;
}

int getMinutes(unsigned long milliseconds){
  /*
   * Takes a time in miliseconds.
   * Returns the number of full minutes that don't make up a full hour.
   */
   int seconds = milliseconds / 1000;
   int minutes = seconds / 60;
   minutes = minutes % 60;
   return minutes;
}

int getHours(unsigned long milliseconds){
  /*
   * Takes a time in miliseconds.
   * Returns the number of full hours.
   */
   int seconds = milliseconds / 1000;
   int minutes = seconds / 60;
   int hours = minutes / 60;
   return hours;
}

void displayTime(int x, int y, int hours, int minutes, int seconds){
  /*
   * Takes an x coordinate and a y coordinate.
   * Displays hours minutes and seconds as provided on the x and y coordinates
   */
  display.setCursor(0,y);
  display.print("H:");
  display.setCursor(10,y);
  display.print(hours);
  display.setCursor(35,y);
  display.print("M:");
  display.setCursor(45,y);
  display.print(minutes);
  display.setCursor(70,y);
  display.print("S:");
  display.setCursor(80,y);
  display.print(seconds);
  display.display();
}
unsigned long setTime(const char optionName[20], unsigned long prevTime){
  /*
   * Used in a menu to obtain a period of time from the user.
   * Takes a menuName up to 10 characters long.
   * Takes a prevTime in milliseconds (the existing time before any changes are made).
   * Converts the prevTime to Hours, Minutes and Seconds.
   * Displays that converted prevTime.
   * Allows the user to edit the hours, minutes and seconds.
   * returns the new time in milliseconds
   */
   bool done = false;
   int seconds = getSeconds(prevTime);
   int minutes = getMinutes(prevTime);
   int hours = getHours(prevTime);

   while(!done){
    buttonDebounce();
    
    // Display prevTime in hours, minutes and seconds
    display.clearDisplay();
    display.setCursor(0,5);
    display.print(optionName);
    displayTime(0,20, hours, minutes, seconds);
    if(button2State){
      return 0;
    }
    if(button3State){
      done = true;
      resetButton3();
      //DO SAVE
    }
  }
  return 0;
}

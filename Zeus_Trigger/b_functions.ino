void drawLogo(void) {
 
  display.clearDisplay();

  display.drawBitmap(
    (display.width()  - LOGO_WIDTH ) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
}

void cameraCableShoot(void){
  // Placeholder for cable activated camera trigger method
  return;
}

void canonIRShoot(void){
  // Placeholder for Canon infrared trigger method
  return;
}

void flash1Trigger(void){
  // Placeholder for external first flash trigger
}

void flash2Trigger(void){
  // Placeholder for external first flash trigger
}

void nikonIRShoot(void) {
  // Nikon infrared camera trigger
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
   unsigned long seconds;
   seconds = milliseconds / 1000UL;
   seconds = seconds % 60UL;
   return seconds;
}

int getMinutes(unsigned long milliseconds){
  /*
   * Takes a time in miliseconds.
   * Returns the number of full minutes that don't make up a full hour.
   */
   unsigned long seconds, remSeconds, minutes;
   seconds = milliseconds / 1000UL;
   remSeconds = seconds % 60UL;
   seconds = seconds - remSeconds;
   if(seconds == 0){
    minutes = 0;
   }
   else{
    minutes = seconds / 60UL;
    minutes = minutes % 60UL;
   }
   return minutes;
}

int getHours(unsigned long milliseconds){
   /*
   * Takes a time in miliseconds.
   * Returns the number of full hours.
   */
   unsigned long seconds, remSeconds, minutes, remMinutes, hours;
   seconds = milliseconds / 1000UL;
   remSeconds = seconds % 60UL;
   seconds = seconds - remSeconds;
   if(seconds == 0){
    minutes = 0;
   }
   else{
    minutes = seconds / 60UL;
    remMinutes = minutes % 60UL;
    minutes = minutes - remMinutes;
   }

  if(minutes == 0){
    hours = 0;
  }
  else{
   hours = minutes / 60UL;
   hours = hours % 24;
  }
  return hours;
}

int getDays(unsigned long milliseconds){
   /*
   * Takes a time in miliseconds.
   * Returns the number of full days.
   */
   unsigned long seconds, remSeconds, minutes, remMinutes, hours, remHours, days;
   seconds = milliseconds / 1000UL;
   remSeconds = seconds % 60UL;
   seconds = seconds - remSeconds;
   if(seconds == 0){
    minutes = 0;
   }
   else{
    minutes = seconds / 60UL;
    remMinutes = minutes % 60UL;
    minutes = minutes - remMinutes;
   }

  if(minutes == 0){
    hours = 0;
  }
  else{
   hours = minutes / 60UL;
   remHours = hours % 24UL;
   hours = hours - remHours;
  }

  if(hours == 0){
    days = 0;
  }
  else{
    days = hours / 24UL;
  }
  return days;
}

unsigned long getMilliseconds(unsigned long days, unsigned long hours, unsigned long minutes, unsigned long seconds){
  /*
   * Takes 3 ints (hours, minutes and seconds) and returns an unsigned long.
   * The returned value is the number of milliseconds in the given time.
   */

  unsigned long milliseconds = 0;
  milliseconds += (days * 86400000);
  milliseconds += (hours * 3600000);
  milliseconds += (minutes * 60000);
  milliseconds += (seconds * 1000);
  return milliseconds;
}

void displayTime(int x, int y, int days, int hours, int minutes, int seconds, int invert, bool flash){
  /****TO DO: Only display larger units if above zero****/
  /*
   * Takes an x coordinate and a y coordinate, hours, minutes and seconds, an invert number and a flash boolean.
   * Displays hours minutes and seconds as provided on the x and y coordinates.
   * If the invert number is 0, nothing is inverted. 1 inverts hours, 2 minutes and 3 seconds.
   * If the flash boolean is true the inverted item will flash. Otherwise it won't.
   */
  
  if(flash){
    if(currentMillis > lastFlash + flashTime){
      lastFlash = currentMillis;
      flashState = !flashState;
    }
  }

  //Days
  display.setCursor(0,y);
  if(invert == 1 && (flashState == 1 || !flash)){
    // invert == 1 refers to the first item (hours) being selected.
    // flashState == 1 refers to the process of flasshing being in the "on phase".
    // !flash means it will light the selected item regardles of flashState if flash is false.
    display.setTextColor(BLACK, WHITE);
  }
  else{
    display.setTextColor(WHITE);
  }
  display.print("D:");
  display.setCursor(10,y);
  display.print(days);
  
  //Hours
  display.setCursor(35,y);
  if(invert == 2 && (flashState == 1 || !flash)){
    // invert == 1 refers to the first item (hours) being selected.
    // flashState == 1 refers to the process of flasshing being in the "on phase".
    // !flash means it will light the selected item regardles of flashState if flash is false.
    display.setTextColor(BLACK, WHITE);
  }
  else{
    display.setTextColor(WHITE);
  }
  display.print("H:");
  display.setCursor(45,y);
  display.print(hours);

  //Minutes
  display.setCursor(70,y);
  if(invert == 3 && (flashState == 1 || !flash)){
    display.setTextColor(BLACK, WHITE);
  }
  else{
    display.setTextColor(WHITE);
  }
  display.print("M:");
  display.setCursor(80,y);
  display.print(minutes);

  //Seconds
  display.setCursor(105,y);
  if(invert == 4 && (flashState == 1 || !flash)){
    display.setTextColor(BLACK, WHITE);
  }
  else{
    display.setTextColor(WHITE);
  }
  display.print("S:");
  display.setCursor(115,y);
  display.print(seconds);
  
  display.display();
  display.setTextColor(WHITE);
}

void setTime(const char optionName[20], unsigned long &prevTime){
  /*
   * Used in a menu to obtain a period of time from the user.
   * Takes a menuName up to 20 characters long.
   * Takes a prevTime in milliseconds (the existing time before any changes are made).
   * Converts the prevTime to Hours, Minutes and Seconds.
   * Displays that converted prevTime.
   * Allows the user to edit the hours, minutes and seconds.
   * changes the value of the passed variable referenced in prevTime.
   */
   bool done = false;
   int seconds = getSeconds(prevTime);
   int minutes = getMinutes(prevTime);
   int hours = getHours(prevTime);
   int days = getDays(prevTime);
   int selected = 1;
   bool editMode = false;

   while(!done){
    buttonDebounce();
    
    // Display prevTime in hours, minutes and seconds
    display.clearDisplay();
    display.setCursor(0,5);
    display.print(optionName);
    display.setCursor(50,50);
    if(selected==5){
    display.setTextColor(BLACK, WHITE);
    }
    else{
    display.setTextColor(WHITE);
    }
    display.print("Save");
    display.setTextColor(WHITE);
    displayTime(0,25, days, hours, minutes, seconds, selected, editMode);

    //Left and right buttons
    
    //Left if not in edit mode. Cycle back to last item if at first item.
    if(button1State && !editMode){
      if(selected == 1){
        selected = 5;
      }
      else{
        selected--;
      }
      resetButton1();
    }

    //Edit value - if in edit mode
    if(button1State && editMode){
      if(selected == 1)
        if(days > 0){
          days--;
        }
        else{
          days = 48;
        }
      
      else if(selected == 2){
        if(hours > 0){
            hours--;
          }
          else{
            hours = 23;
          }
      }
      
      else if(selected == 3){
        if(minutes > 0){
          minutes--;
        }
          else{
            minutes = 59;
          }
      }

      else if (selected == 4){
        if(seconds > 0){
          seconds--;
        }
        else{
          seconds = 59;
        }
      }
      resetButton1();
    }

    //Right if not in edit mode. Cycle back to first item if at last item.
    if(button4State && !editMode){
      if(selected == 5){
        selected = 1;
      }
      else{
        selected++;
      }
      resetButton4();
    }

    // Back
    // Exit edit mode
    if(button2State){
      if(editMode){
        editMode = !editMode;
        resetButton2();
      }
      else{
        // Exit function without saving changes 
        resetButton2();
        return;
      }
    }

    //Edit value + if in edit mode
    if(button4State && editMode){
      if(selected == 1){
        if(days < 48){
          days++;
        }
        else{
          days = 0;
        }
      }
      else if(selected == 2){
        if(hours < 23){
          hours++;
        }
        else{
          hours = 0;
        }
      } 
      else if(selected == 3){
        if(minutes < 59){
          minutes++;
        }
        else{
          minutes = 0;
        }
      }
      else if(selected = 4){
        if(seconds < 59){
          seconds++;
        }
        else{
          seconds = 0;
        }
      }
      resetButton4();
    }

    //Select
    if(button3State && !editMode && selected > 0 && selected < 5){
      editMode = true;
      resetButton3();
    }

    if(button3State && editMode && selected > 0 && selected < 5){
      editMode = false;
      resetButton3();
    }

    if(button3State && selected == 5){
      done = true;
      resetButton3();
      prevTime = getMilliseconds(days, hours, minutes, seconds);

    }
  }
  return;
}

int selectItem(const char optionName1[10], int noOfOptions, const char opt1[10], const char opt2[10], const char opt3[10], int currentValue){
  /*
   * Takes a menu name, option 1 name, option 2 name and the current value.
   * Allows the user to choose from the available options.
   * Returns the selected option.
   */

   int selected = currentValue;

   while(true){
    buttonDebounce();

    // Display the available options
    display.clearDisplay();
    display.setCursor(0,5);
    display.print(optionName1);
    
    display.setCursor(0,20);
    if(selected==1){
      // Highlight if selected
      display.setTextColor(BLACK, WHITE);
    }
    else{
      // Display with no highlight if not selected
      display.setTextColor(WHITE);
    }
    display.print(opt1);
    
    display.setCursor(0,35);
    if(selected==2){
      display.setTextColor(BLACK, WHITE);
    }
    else{
      display.setTextColor(WHITE);
    }
    display.print(opt2);
    display.setTextColor(WHITE);

    display.setCursor(0,50);
    if(selected==3){
      display.setTextColor(BLACK, WHITE);
    }
    else{
      display.setTextColor(WHITE);
    }
    display.print(opt3);
    display.setTextColor(WHITE);
    
    display.display();

    // Left button
    if (button1State){
      if (selected > 0){
        selected--;
      }
      else{
        selected = noOfOptions;
      }
      resetButton1();
    }

    // Right button
    if (button4State){
      if (selected < noOfOptions){
        selected++;
      }
      else{
        selected = 1;
      }
      resetButton4();
    }

    // Back button - return original value
    if (button2State){
      resetButton2();
      return currentValue;
    }

    // Enter button, return changes
    if (button3State){
      resetButton3();
      return selected;
    }
   }
}

void trigger(void){
  digitalWrite(RED_LED, 1);
  //Trigger1
  if (triggerDevice1 == 1){
    cameraCableShoot();
  }
  else if(triggerDevice1 == 2){
    nikonIRShoot();
  }
  else if(triggerDevice1 == 3){
    canonIRShoot();
  }
  else if(triggerDevice1 == 4){
    flash1Trigger();    
  }
  else if(triggerDevice1 == 5){
    flash2Trigger();
  }
  
  //Trigger2
  if (triggerDevice2 == 1){
    cameraCableShoot();
  }
  else if(triggerDevice2 == 2){
    nikonIRShoot();
  }
  else if(triggerDevice2 == 3){
    canonIRShoot();
  }
  else if(triggerDevice2 == 4){
    flash1Trigger();    
  }
  else if(triggerDevice2 == 5){
    flash2Trigger();
  }
  
  //Trigger3
  if (triggerDevice3 == 1){
    cameraCableShoot();
  }
  else if(triggerDevice3 == 2){
    nikonIRShoot();
  }
  else if(triggerDevice3 == 3){
    canonIRShoot();
  }
  else if(triggerDevice3 == 4){
    flash1Trigger();    
  }
  else if(triggerDevice3 == 5){
    flash2Trigger();
  }
  
  //Trigger4
  if (triggerDevice4 == 1){
    cameraCableShoot();
  }
  else if(triggerDevice4 == 2){
    nikonIRShoot();
  }
  else if(triggerDevice4 == 3){
    canonIRShoot();
  }
  else if(triggerDevice4 == 4){
    flash1Trigger();    
  }
  else if(triggerDevice4 == 5){
    flash2Trigger();
  }
  digitalWrite(RED_LED, 0);
}

void selectIntervalometerTargetType(void){
  return;
}

void setIntervalTargetTime(void){
  return;
}

void setIntervalTargetShots(void){
  return;
}

void startIntervalometer(void){
  currentMillis = millis();
  unsigned long lastShot = 0; // Time last photograph was taken
  unsigned long startTime;
  unsigned long endTime;
  int shotsTaken;
  unsigned long shotsRemaining;
  unsigned long nextShotTime;
  
  //unsigned long timeRemaining; // For possible furute display
  
  // Calculate the end time for the intervalometer
  if (intervalTargetTime == 1){ // There is no target.
    endTime = currentMillis + 9999UL;
  }
  else if (intervalTargetType == 2){ // Target is time
    endTime = currentMillis + intervalTargetTime;
  }
  else if (intervalTargetType == 3){ // Target type is no. of shots
    endTime = currentMillis + (intervalometerInterval * intervalTargetShots);
  }

  // Calculate the number of shots to be taken
  shotsRemaining = (endTime - currentMillis) / intervalometerInterval;
  
  while((currentMillis < endTime) && (shotsRemaining > 0)){
    buttonDebounce();
    currentMillis = millis();
    if (currentMillis >= lastShot + intervalometerInterval){
      trigger();
      lastShot = currentMillis;
      if (intervalTargetType != 1){ // If there's a target, countdown.
        shotsRemaining--;
      }
      else { // No target is selected so we will keep the endTime fixed to current time + 9999ms
        endTime = currentMillis + 9999;
      }
    }
    nextShotTime = intervalometerInterval - (currentMillis - lastShot);
    
    //timeRemaining = endTime - currentMillis; // For possible future display
    
    display.clearDisplay();
    display.setCursor(0,5);
    display.print("Intervalometer live");
    display.setCursor(0,20);
    if (intervalTargetType != 1){ // No target is selected so we won't show shots remaining
      display.print("Remaining: ");
      display.print(shotsRemaining);
      display.setCursor(0,35);    
    }
    display.print("Time until next shot: ");
    displayTime(0, 50,getDays(nextShotTime), getHours(nextShotTime), getMinutes(nextShotTime), getSeconds(nextShotTime), 0, false);
    display.display();

    if (button2State){
      resetButton2;
      return;
    }
  }  
}

void getLong(const char optionName[20], unsigned long &prevLong){
  /*
   * Used in a menu to obtain a number from a user.
   * Takes a menuName up to 10 characters long.
   * Takes an int.
   * Displays that int.
   * Allows the user to edit the int.
   * Saves the new value to the original variable.
   */
   int units = prevLong % 10;
   int tens = ((prevLong % 100) - units) / 10;
   int hundreds = ((prevLong % 1000) - (tens * 10)) / 100;
   int thousands = ((prevLong % 10000) - (hundreds * 100)) / 1000;
   int tthousands = ((prevLong % 100000) - (thousands * 1000)) / 10000;
   int selected = 1;
   bool editMode = false;

   while(true){
    buttonDebounce();
    if(currentMillis > lastFlash + flashTime){
      lastFlash = currentMillis;
      flashState = !flashState;
    }
    // Display menu name and save option
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setCursor(0,5);
    display.print(optionName);
    display.setCursor(50,50);
    if((selected==6) && (flashState || !editMode)){
      display.setTextColor(BLACK, WHITE);
    }
    else{
      display.setTextColor(WHITE);
    }
      display.print("Save");
    display.setTextColor(WHITE);

    // Display prevLong in ten thousands, thousands, hundreds, tens and units
    
    // Ten thousands
    display.setCursor(0,25);
    if ((selected == 1) && (flashState || !editMode)){
      display.setTextColor(BLACK, WHITE);
    }
    else{
      display.setTextColor(WHITE);
    }
    display.print(tthousands);
    
    // Thousands
    display.setCursor(10,25);
    if ((selected == 2) && (flashState || !editMode)){
      display.setTextColor(BLACK, WHITE);
    }
    else{
      display.setTextColor(WHITE);
    }
    display.print(thousands);
    
    // Hundreds
    display.setCursor(20,25);
    if ((selected == 3) && (flashState || !editMode)){
      display.setTextColor(BLACK, WHITE);
    }
    else{
      display.setTextColor(WHITE);
    }
    display.print(hundreds);
    
    // Tens
    display.setCursor(30,25);
    if ((selected == 4) && (flashState || !editMode)){
      display.setTextColor(BLACK, WHITE);
    }
    else{
      display.setTextColor(WHITE);
    }
    display.print(tens);
    
    // Units
    display.setCursor(40,25);
    if ((selected == 5) && (flashState || !editMode)){
      display.setTextColor(BLACK, WHITE);
    }
    else{
      display.setTextColor(WHITE);
    }
    display.print(units);
    
    display.display();


    //Left and right buttons
    
    //Left if not in edit mode. Cycle back to last item if at first item.
    if(button1State && !editMode){
      if(selected == 1){
        selected = 6;
      }
      else{
        selected--;
      }
      resetButton1();
    }

    //Edit value - if in edit mode
    if(button1State && editMode){
      
      if(selected == 1){
        if(tthousands > 0){
            tthousands--;
          }
          else{
            tthousands = 9;
          }
      }
      
      else if(selected == 2){
        if(thousands > 0){
          thousands--;
        }
          else{
            thousands = 9;
          }
      }

      else if (selected == 3){
        if(hundreds > 0){
          hundreds--;
        }
        else{
          hundreds = 9;
        }
      }
      else if (selected == 4){
        if(tens > 0){
          tens--;
        }
        else{
          tens = 9;
        }
      }
      else if (selected == 5){
        if(units > 0){
          units--;
        }
        else{
          units = 9;
        }
      }
      resetButton1();
    }

    //Right if not in edit mode. Cycle back to first item if at last item.
    if(button4State && !editMode){
      if(selected == 6){
        selected = 1;
      }
      else{
        selected++;
      }
      resetButton4();
    }

    // Back
    // Exit edit mode
    if(button2State){
      if(editMode){
        editMode = !editMode;
        resetButton2();
      }
      else{
        // Exit function without saving changes 
        resetButton2();
        return;
      }
    }

    //Edit value + if in edit mode
    if(button4State && editMode){
      if(selected == 1){
        if(tthousands < 9){
          tthousands++;
        }
        else{
          tthousands = 0;
        }
      } 
      else if(selected == 2){
        if(thousands < 9){
          thousands++;
        }
        else{
          thousands = 0;
        }
      }
      else if(selected == 3){
        if(hundreds < 9){
          hundreds++;
        }
        else{
          hundreds = 0;
        }
      }
      else if(selected == 4){
        if(tens < 9){
          tens++;
        }
        else{
          tens = 0;
        }
      }
      else if(selected == 5){
        if(units < 9){
          units++;
        }
        else{
          units = 0;
        }
      }
      resetButton4();
    }

    //Select
    if(button3State && selected > 0 && selected < 6){
      editMode = !editMode;
      resetButton3();
    }

    if(button3State && selected == 6){
      resetButton3();
      prevLong = units + (10UL*tens) + (100UL*hundreds) + (1000UL*thousands) + (10000UL*tthousands);
      return;
    }
  }
}

void drawLogo(void) {
 
  display.clearDisplay();

  display.drawBitmap(
    (display.width()  - LOGO_WIDTH ) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
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
   * Takes a menuName up to 10 characters long.
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
        Serial.println("Back");
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

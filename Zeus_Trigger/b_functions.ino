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
   int seconds;
   seconds = milliseconds / 1000;
   seconds = seconds % 60;
   return seconds;
}

int getMinutes(unsigned long milliseconds){
  /*
   * Takes a time in miliseconds.
   * Returns the number of full minutes that don't make up a full hour.
   */
   int seconds, remSeconds, minutes;
   seconds = milliseconds / 1000;
   remSeconds = seconds % 60;
   seconds = seconds - remSeconds;
   if(seconds == 0){
    minutes = 0;
   }
   else{
    minutes = seconds / 60;
    minutes = minutes % 60;
   }
   return minutes;
}

int getHours(unsigned long milliseconds){
   /*
   * Takes a time in miliseconds.
   * Returns the number of full hours.
   */
   int seconds, remSeconds, minutes, remMinutes, hours;
   seconds = milliseconds / 1000;
   remSeconds = seconds % 60;
   seconds = seconds - remSeconds;
   if(seconds == 0){
    minutes = 0;
   }
   else{
    minutes = seconds / 60;
    remMinutes = minutes % 60;
    minutes = minutes - remMinutes;
   }

  if(minutes == 0){
    hours = 0;
  }
  else{
   hours = minutes / 60;
  }
  return hours;
}

unsigned long getMilliseconds(int hours, int minutes, int seconds){
  /*
   * Takes 3 ints (hours, minutes and seconds) and returns an unsigned long.
   * The returned value is the number of milliseconds in the given time.
   */
  unsigned long milliseconds = 0;
  milliseconds += hours * 3600000;
  milliseconds += minutes * 60000;
  milliseconds += seconds * 1000;
  return milliseconds;
}

void displayTime(int x, int y, int hours, int minutes, int seconds, int invert, bool flash){
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
      Serial.println("Triggered!");
    }
  }
  
  //Hours
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
  display.print("H:");
  display.setCursor(10,y);
  display.print(hours);

  //Minutes
  display.setCursor(35,y);
  if(invert == 2 && (flashState == 1 || !flash)){
    display.setTextColor(BLACK, WHITE);
  }
  else{
    display.setTextColor(WHITE);
  }
  display.print("M:");
  display.setCursor(45,y);
  display.print(minutes);

  //Seconds
  display.setCursor(70,y);
  if(invert == 3 && (flashState == 1 || !flash)){
    display.setTextColor(BLACK, WHITE);
  }
  else{
    display.setTextColor(WHITE);
  }
  display.print("S:");
  display.setCursor(80,y);
  display.print(seconds);
  
  display.display();
  display.setTextColor(WHITE);
}

unsigned long setTime(const char optionName[20], unsigned long &prevTime){
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
   int selected = 1;
   bool editMode = false;

   while(!done){
    buttonDebounce();
    
    // Display prevTime in hours, minutes and seconds
    display.clearDisplay();
    display.setCursor(0,5);
    display.print(optionName);
    display.setCursor(35,35);
    if(selected==4){
    display.setTextColor(BLACK, WHITE);
    }
    else{
    display.setTextColor(WHITE);
    }
    display.print("Save");
    display.setTextColor(WHITE);
    displayTime(0,20, hours, minutes, seconds, selected, editMode);

    //Left and right buttons
    
    //Left if not in edit mode. Cycle back to last item if at first item.
    if(button1State && !editMode){
      if(selected == 1){
        selected = 4;
      }
      else{
        selected--;
      }
      resetButton1();
    }

    //Edit value - if in edit mode
    if(button1State && editMode){
      if(selected == 1 && hours > 0){
        hours--;
      }
      
      else if(selected == 2){
        if(minutes == 0 && hours > 0){
            minutes = 59;
            hours--;
          }
          else if(minutes > 0){
            minutes--;
          }
      }
      
      else if(selected == 3){
        if(seconds == 0 && (minutes > 0 || hours > 0)){
          seconds = 59;
          if(minutes == 0 && hours > 0){
            minutes = 59;
            hours--;
          }
          else{
            minutes--;
          }
        }
        else if(seconds > 0){
          seconds--;
        }
      }   
      resetButton1();
    }

    //Right if not in edit mode. Cycle back to first item if at last item.
    if(button4State && !editMode){
      if(selected == 4){
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
      }
      else{
        // Exit function without saving changes
        
        return 0;
      }
    }

    //Edit value + if in edit mode
    if(button4State && editMode){
      if(selected == 1 && hours < 99){
        hours++;
      }
      else if(selected == 2){
        if(minutes == 59 && hours < 99){
            minutes = 0;
            hours++;
          }
          else if(minutes < 59){
            minutes++;
          }
      } 
      else if(selected == 3){
        if(seconds == 59 && (minutes < 59 || hours < 99)){
          seconds = 0;
          if(minutes < 59){
            minutes++;
            minutes = 0;
            hours++;
          }
          else{
            minutes = 0;
            hours++;
          }
        }
        else if(seconds < 59){
          seconds++;
        }
      }
      resetButton4();
    }

    //Select
    if(button3State && !editMode && selected > 0 && selected < 4){
      editMode = true;
      resetButton3();
    }

    if(button3State && editMode && selected > 0 && selected < 4){
      editMode = false;
      resetButton3();
    }

    if(button3State && selected == 4){
      done = true;
      resetButton3();
      // Test that the enter key changes the passed variable.
      prevTime = getMilliseconds(hours, minutes, seconds);
    }
  }
  return 0;
}

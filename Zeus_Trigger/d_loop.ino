void loop() {

  currentMillis = millis();
    
  button1Read = !digitalRead(BUTTON_1);
  button2Read = !digitalRead(BUTTON_2);
  button3Read = !digitalRead(BUTTON_3);

  // Button 1 debounce code
  if (button1Read != button1PrevState){
    button1Debounce = currentMillis;
  }
  if ((currentMillis - button1Debounce) > debounceDelay){
    if (button1Read != button1State){
      button1State = button1Read;
    }
  }
  button1PrevState = button1Read;
  ////////////////////////////////////////

  // Button 2 debounce code
  if (button2Read != button2PrevState){
    button2Debounce = currentMillis;
  }
  if ((currentMillis - button2Debounce) > debounceDelay){
    if (button2Read != button2State){
      button2State = button2Read;
    }
  }
  button2PrevState = button2Read;
  ////////////////////////////////////////

  // Button 3 debounce code
  if (button3Read != button3PrevState){
    button3Debounce = currentMillis;
  }
  if ((currentMillis - button3Debounce) > debounceDelay){
    if (button3Read != button3State){
      button3State = button3Read;
    }
  }
  button3PrevState = button3Read;
  ////////////////////////////////////////

  // LED testing
  digitalWrite(GREEN_LED, button1State);
  digitalWrite(IR_LED, button2State);
  digitalWrite(RED_LED, button3State);
  ////////////////////////////////////////

  // Navigate the menu
  // Go down a level
  if (button1State && ((currentMillis - lastMenuChange) > menuChangeDelay)){
    lastMenuChange = currentMillis;
    // If already at lowest level of main menu cycle back to the top
    if (mainMenuItem == 1){
      mainMenuItem = highestMainMenuItem;
    }
    
    // If already at lowest level of menu 1 cycle back to the top
    else if (mainMenuItem == 101){
      mainMenuItem = highestMenu1Item;
    }
    // Otherwise go down 1
    else {
      mainMenuItem = mainMenuItem - 1;
    }
  }
  // Go up a level
  if (button3State && ((currentMillis - lastMenuChange) > menuChangeDelay)){
    lastMenuChange = currentMillis;
    // If already at the highest level cycle back to the bottom
    if (mainMenuItem == highestMainMenuItem){
      mainMenuItem = 1;
    }
    // If already at the highest level of 1 menu cycle back to the bottom
    else if (mainMenuItem == highestMenu1Item){
      mainMenuItem = 101;
    }
    // Otherwise go up 1
    else {
      mainMenuItem = mainMenuItem + 1;
    }
  }

  if (debug){
    //Display the current select menu item in the serial output every time it changes if debugging is enabled
    if (mainMenuItem != prevMainMenuItem){
      Serial.println();
      Serial.println("///////////");
      Serial.println("Debug - Current mainMenuItem:");
      Serial.println(mainMenuItem);
      Serial.println("///////////");
      Serial.println();
      prevMainMenuItem = mainMenuItem;
    }
  }
  switch (mainMenuItem) {
    ////////////////////////////////// 
    case 1:
      // Display menu item 1
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 1");
      display.setCursor(0,20);
      display.print("Test sub menu");
      display.display();
           
      if (button2State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        mainMenuItem = 101;
        resetButton2();
      }
      break;
    //////////////////////////////////   
    case 2:
      // Display menu item 2
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 2");
      display.setCursor(0,20);
      display.print("Trigger Nikon Camera");
      display.display();
      
      if (button2State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        if (debug){
          Serial.println("nikonShoot");
        }
        nikonShoot();
        resetButton2();
      }
      break;
    ////////////////////////////////// 
    case 3:
      // Display menu item 3
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 3");
      display.display();
      
      if (button2State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        resetButton2();
      }
      break;
    ////////////////////////////////// 
    case 4:
      // Display menu item 4
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 4");
      display.display();
      
      if (button2State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        resetButton2();
      }
      break;
    ////////////////////////////////// 
    case 5:
      // Display menu item 5
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 5");
      display.display();
      
      if (button2State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        resetButton2();
      }
      break;
    ////////////////////////////////// 
    case 6:
      // Display menu item 6
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 6");
      display.display();
      
      if (button2State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        resetButton2();
      }
      break;
    ////////////////////////////////// 
    //End of main menu////////////////
    ////////////////////////////////// 
    //Sub Menus///////////////////////
    //Sub Menu 1//////////////////////
      case 101:
      // Display menu item 101 - Sub menu for 1
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 101");
      display.display();

      if (button2State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        resetButton2();
      }
      break;
      //////////////////////////////////
      case 102:
      // Display menu item 102 - Sub menu for 1
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 102");
      display.display();

      if (button2State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        resetButton2();
      }
      break;
      //////////////////////////////////
      case 103:
      // Display menu item 103 - Sub menu for 1
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 103");
      display.display();

      if (button2State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        resetButton2();
      }
      break;
      //////////////////////////////////
      case 104:
      // Display menu item 104 - Sub menu for 1
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 104");
      display.display();

      if (button2State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        resetButton2();
      }
      break;
      //////////////////////////////////
      case 105:
      // Display menu item 105 - Sub menu for 1
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 105");
      display.display();

      if (button2State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        resetButton2();
      }
      break;
      //////////////////////////////////
      case 106:
      // Display menu item 106 - Sub menu for 1
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 106 - BACK");
      display.display();

      if (button2State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        mainMenuItem = 1;
        resetButton2();
      }
      break;
      //////////////////////////////////
     
  }

}

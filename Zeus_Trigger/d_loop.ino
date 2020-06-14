void loop() {

  currentMillis = millis();
    
  button1Read = !digitalRead(BUTTON_1);
  button2Read = !digitalRead(BUTTON_2);
  button3Read = !digitalRead(BUTTON_3);
  button4Read = !digitalRead(BUTTON_4);

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
  
  // Button 4 debounce code
  if (button4Read != button4PrevState){
    button4Debounce = currentMillis;
  }
  if ((currentMillis - button4Debounce) > debounceDelay){
    if (button4Read != button4State){
      button4State = button4Read;
    }
  }
  button4PrevState = button4Read;
  ////////////////////////////////////////

  // Navigate the menu
  // Navigate left
  if (button1State && ((currentMillis - lastMenuChange) > menuChangeDelay)){
    lastMenuChange = currentMillis;
    // If already at first item of main menu cycle back to the last
    if (menuItem == 1){
      menuItem = highestMenu0Item;
    }
    
    // If already at first item of menu 1 cycle back to the last
    else if (menuItem == 101){
      menuItem = highestMenu1Item;
    }
    // If already at first item of menu 11 cycle back to the last
    else if (menuItem == 111){
      menuItem = highestMenu11Item;
    }
    // Otherwise left 1
    else {
      menuItem--;
    }
  }
  // Navigate right
  if (button4State && ((currentMillis - lastMenuChange) > menuChangeDelay)){
    lastMenuChange = currentMillis;
    // If already at the last item of main menu cycle back to the first
    if (menuItem == highestMenu0Item){
      menuItem = 1;
    }
    // If already at the last item of menu 1 cycle back to the first
    else if (menuItem == highestMenu1Item){
      menuItem = 101;
    }
    // If already at the last item of menu 11 cycle back to the first
    else if (menuItem == highestMenu11Item){
      menuItem = 111;
    }
    // Otherwise go right 1
    else {
      menuItem++;
    }
  }

  // Back button
  if (button2State){
    menuItem = parentItem;
    resetButton2();
  }


  if (debug){
    //Display the current select menu item in the serial output every time it changes if debugging is enabled
    if (menuItem != prevMenuItemDebug){
      Serial.println();
      Serial.println("///////////");
      Serial.println("Debug - menuItem:");
      Serial.println(menuItem);
      Serial.println("///////////");
      Serial.println();
      prevMenuItemDebug = menuItem;
    }
    if (parentItem != prevParentItemDebug){
      Serial.println("///////////");
      Serial.println("Debug - parentItem:");
      Serial.println(parentItem);
      Serial.println("///////////");
      Serial.println();
      prevParentItemDebug = parentItem;
    }
    digitalWrite(RED_LED, button1State);
    digitalWrite(GREEN_LED, button4State);
  }
  switch (menuItem) {
    ////////////////////////////////// 
    case 1:
      // Display menu item 1
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 1");
      display.setCursor(0,20);
      display.print("Test sub menu");
      display.display();
           
      if (button3State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        menuItem = 101;
        resetButton3();
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
      
      if (button3State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        if (debug){
          Serial.println("nikonShoot");
        }
        nikonShoot();
        resetButton3();
      }
      break;
    ////////////////////////////////// 
    case 3:
      // Display menu item 3
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 3");
      display.display();
      
      if (button3State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        resetButton3();
      }
      break;
    ////////////////////////////////// 
    case 4:
      // Display menu item 4
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 4");
      display.display();
      
      if (button3State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        resetButton3();
      }
      break;
    ////////////////////////////////// 
    case 5:
      // Display menu item 5
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 5");
      display.display();
      
      if (button3State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        resetButton3();
      }
      break;
    ////////////////////////////////// 
    case 6:
      // Display menu item 6
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 6");
      display.display();
      
      if (button3State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        resetButton3();
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
      parentItem = 1;

      if (button3State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        resetButton3();
      }
      break;
      //////////////////////////////////
      case 102:
      // Display menu item 102 - Sub menu for 1
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 102");
      display.setCursor(0,20);
      display.print("Test sub sub menu");
      display.display();
      parentItem = 1;

      if (button3State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        menuItem = 111;
        resetButton3();
      }
      break;
      //////////////////////////////////
      case 103:
      // Display menu item 103 - Sub menu for 1
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 103");
      display.display();
      parentItem = 1;

      if (button3State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        resetButton3();
      }
      break;
      //////////////////////////////////
      case 104:
      // Display menu item 104 - Sub menu for 1
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 104");
      display.display();
      parentItem = 1;

      if (button3State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        resetButton3();
      }
      break;
      //////////////////////////////////
      case 105:
      // Display menu item 105 - Sub menu for 1
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 105");
      display.display();
      parentItem = 1;

      if (button3State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        resetButton3();
      }
      break;
      //////////////////////////////////
      case 106:
      // Display menu item 106 - Sub menu for 1
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 106");
      display.setCursor(0,20);
      display.print("BACK");
      display.display();
      parentItem = 1;

      if (button3State){
        display.invertDisplay(1);
        delay(100);
        //display.invertDisplay(0);
        menuItem = 1;
        resetButton3();
      }
      break;
      //////////////////////////////////
      case 111:
      // Display menu item 111 - Sub menu for 101
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 111");
      display.display();
      parentItem = 101;

      if (button3State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        resetButton3();
      }
      break;
      //////////////////////////////////
      case 112:
      // Display menu item 112 - Sub menu for 101
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 112");
      display.display();
      parentItem = 101;

      if (button3State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        resetButton3();
      }
      break;
      //////////////////////////////////
      case 113:
      // Display menu item 113 - Sub menu for 101
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 113");
      display.display();
      parentItem = 101;

      if (button3State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        resetButton3();
      }
      break;
      //////////////////////////////////
      case 114:
      // Display menu item 114 - Sub menu for 101
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Menu item 114");
      display.display();
      parentItem = 101;

      if (button3State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        resetButton3();
      }
      break;
     
  }

}

void loop() {    
  buttonDebounce();
  navigation();
  backCheck();

  if (debug){
    //Display the current select menu item in the serial output every time it changes if debugging is enabled
    if (menuItem != prevMenuItemDebug){
      Serial.println();
      Serial.println("///////////");
      Serial.println("menuItem:");
      Serial.println(menuItem);
      Serial.println("///////////");
      Serial.println();
      prevMenuItemDebug = menuItem;
    }
    if (parentItem != prevParentItemDebug){
      Serial.println("///////////");
      Serial.println("parentItem:");
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
      display.print("1) Intervalometer");
      display.setCursor(0,20);
      display.print("");
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
      display.print("2) Shoot!");
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
      display.print("3) Empty");
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
      display.print("4) Empty");
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
      display.print("5) Empty");
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
      display.print("6) Empty");
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
      // Display Intervalometer menu
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Intervalometer");
      display.setCursor(0,20);
      display.print("1) Set interval");
      display.setCursor(0,35);
      display.print("Current:");
      displayTime(0, 50, getHours(intervalometerInterval), getMinutes(intervalometerInterval), getSeconds(intervalometerInterval));
      parentItem = 1;

      if (button3State){
        parentItem = 101;
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        resetButton3();
        setTime("Set interval", intervalometerInterval);
        menuItem = 101;
      }
      break;
      //////////////////////////////////
      case 102:
      // Display menu item 102 - Sub menu for 1
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Intervalometer");
      display.setCursor(0,20);
      display.print("2) Test sub sub menu");
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
      display.print("Intervalometer");
      display.setCursor(0,20);
      display.print("3) Empty");
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
      display.print("Intervalometer");
      display.setCursor(0,20);
      display.print("4) Empty");
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
      display.print("Intervalometer");
      display.setCursor(0,20);
      display.print("5) Empty");
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
      display.print("Intervalometer");
      display.setCursor(0,20);
      display.print("6) Back");
      display.display();
      parentItem = 1;

      if (button3State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
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

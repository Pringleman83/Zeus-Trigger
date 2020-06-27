void loop() {    
  buttonDebounce();
  navigation();
  backCheck();
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
      display.print("Trigger");
      display.display();
      
      if (button3State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        trigger();
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
      displayTime(0, 50,getDays(intervalometerInterval), getHours(intervalometerInterval), getMinutes(intervalometerInterval), getSeconds(intervalometerInterval), 0, false);
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
      display.print("2) Set target type");
      //Time or number of shots
      display.setCursor(0,35);
      if (intervalTargetType == 1){ // Time
        display.print("<None>");
      }
      else if (intervalTargetType == 2){ // Time
        display.print("<Time>");
      }
      else if (intervalTargetType == 3){ // Number of shots
        display.print("<No. of Shots>");
      }
      display.display();
      parentItem = 1;

      if (button3State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        resetButton3();
        intervalTargetType = selectItem("Set target type", 3, "None", "Time", "No. of Shots", intervalTargetType);
      }
      break;
      //////////////////////////////////
      case 103:
      // Display menu item 103 - Sub menu for 1
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Intervalometer");
      display.setCursor(0,20);
      display.print("3) Set target ");
      display.setCursor(0,35);
      if (intervalTargetType == 1){ // None
        display.print("<No target>");
      }
      else if (intervalTargetType == 2){ // Time
        display.print("<Time>");
      }
      else if (intervalTargetType == 3){ // Number of shots
        display.print("<No. of shots>");
      }
      
      display.setCursor(0,50);
      if (intervalTargetType == 1){ // None
        display.print("Infinite loop");
      }
      else if (intervalTargetType == 2){ // Time
        displayTime(0, 50,getDays(intervalTargetTime), getHours(intervalTargetTime), getMinutes(intervalTargetTime), getSeconds(intervalTargetTime), 0, false);
      }
      else if (intervalTargetType == 3){ // Number of shots
        display.print(intervalTargetShots);
        display.print(" shots");
      }
      display.display();
      parentItem = 1;

      if (button3State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        resetButton3();
        if (intervalTargetType == 2){ // Time
          setTime("Set target time", intervalTargetTime);
        }
        if (intervalTargetType == 3){ // Number of shots
           getLong("Enter no. of shots:", intervalTargetShots);
        }
      }
      break;
      //////////////////////////////////
      case 104:
      // Display menu item 104 - Sub menu for 1
      display.clearDisplay();
      display.setCursor(0,5);
      display.print("Intervalometer");
      display.setCursor(0,20);
      display.print("4) Start");
      display.display();
      parentItem = 1;

      if (button3State){
        display.invertDisplay(1);
        delay(100);
        display.invertDisplay(0);
        resetButton3();
        startIntervalometer();
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

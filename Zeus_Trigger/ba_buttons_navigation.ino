void buttonDebounce(void){

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

}

void navigation(void){
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
}

void backCheck(void){
  // Back button
  if (button2State){
    menuItem = parentItem;
    resetButton2();
  }
}

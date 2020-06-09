void setup() {
  Serial.begin(115200); //For debugging purposes

  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(IR_LED, OUTPUT);

  bool on = true; // Used to animate logo during setup
  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Clear the buffer
  display.clearDisplay();

  // Intro display
  drawLogo();
  // Invert and restore display, pausing in-between
  for (int i=0; i<10; i++){
    display.invertDisplay(on);
    on = !on;
    delay(60);
  }  

  // Prepare display for main use
  display.setTextSize(1);
  display.setTextColor(WHITE);
  
}

void setup() {
  Serial.begin(9600); //For debugging purposes
  while(!Serial);

  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);
  pinMode(BUTTON_4, INPUT_PULLUP);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(IR_LED, OUTPUT);

  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  while(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    delay(1000);
  }

  // Clear the buffer
  display.clearDisplay();

  // Intro display
  drawLogo();
  delay(1000);
  // Invert and restore display, pausing in-between
  bool on = true; // Used to animate logo during setup
  for (int i=0; i<10; i++){
    display.invertDisplay(on);
    on = !on;
    delay(60);
  }
  delay(1000);

  // Prepare display for main use
  display.setTextSize(1);
  display.setTextColor(WHITE);
  
}

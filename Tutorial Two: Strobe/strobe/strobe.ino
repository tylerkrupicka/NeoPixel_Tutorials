//Tyler Krupicka
//7/5/15
//Strobe.ino
//This project modifies the last project to flash with a time variable

//Includes
#include <Adafruit_NeoPixel.h> //the neopixel library
#include <avr/power.h>

//Defines
#define PIN 6 //pin number of arduino data connection
#define WAIT 50 //delay amount in milliseconds

//create a Adafruit_NeoPixel named "strip". Our strip has 60 LEDs and is in pin 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

uint32_t magenta = strip.Color(255, 0, 255); // this creates a color with RGB values 255, 0 , 255
//in order for the strip to flash it needs to go to black
//setting the strip to black is the same as setting it to color except the RGB code is 0s
uint32_t black = strip.Color(0, 0, 0);

//setup will be run once at the start
void setup() {
  
  strip.begin(); //start the strip
  strip.setBrightness(100); //brightness goes from 0 to 255
  strip.show(); // Initialize all pixels to 'off'
}

//loop will be run repeatedly as long as the arduino is on
void loop() {
  //we need to loop through each pixel on the strip and set it to the color
  //for loops repeatedly do something until they reach a limit
  // this loop creates a counter "i" and sets it to zero, tells the loop to run only if i is 
  //less than the length of the strip, and tells i to increase by 1 each time the loop repeats
  for(int i = 0; i < strip.numPixels(); i++){
    //each time the loop runs i will be different (increasing)
    //we set the current pixel to magenta
    strip.setPixelColor(i, magenta);
  }
  //show the changes
  strip.show();
  
  //we need to hold the magenta color before flashing to black
  delay(WAIT);
  
  for(int i = 0; i < strip.numPixels(); i++){
    strip.setPixelColor(i, black);
  }
  strip.show();  
  //we need to hold black before going back
  delay(WAIT);
  
}

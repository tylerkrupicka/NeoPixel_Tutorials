//Tyler Krupicka
//7/5/15
//Color.ino
//This project sets the entire strip to a single color.

//Includes
#include <Adafruit_NeoPixel.h> //the neopixel library
#include <avr/power.h>

//Defines
#define PIN 6 //pin number of arduino data connection

//Colors
uint32_t magenta = strip.Color(255, 0, 255); // this creates a color with RGB values 255, 0 , 255

//create a Adafruit_NeoPixel named "strip". Our strip has 60 LEDs and is in pin 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

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
    //show the changes
    strip.show();
    
  }
  
}

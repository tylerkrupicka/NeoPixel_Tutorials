//Tyler Krupicka
//7/5/15
//ripple.ino
//This animation ripples outward from a random location with two colors. Print the random index.

//Includes
#include <Adafruit_NeoPixel.h> //the neopixel library
#include <avr/power.h>

//Defines
#define PIN 6 //pin number of arduino data connection
#define WAIT 100 //delay amount in milliseconds

//create a Adafruit_NeoPixel named "strip". Our strip has 60 LEDs and is in pin 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

//setup will be run once at the start
void setup() {
  
  Serial.begin(9600); //start the serial communication with 9600 baud (so we can print)
  
  strip.begin(); //start the strip
  strip.setBrightness(100); //brightness goes from 0 to 255
  strip.show(); // Initialize all pixels to 'off'
  
}

//loop
void loop() {
  
  int current_color = 1;
  
  //create colors
  uint32_t magenta = strip.Color(255, 0, 255); // this creates a color with RGB values 255, 0 , 255
  uint32_t blue = strip.Color(0, 0, 255); 
  uint32_t color; //we need a blank color that will alternate between the two
  
  //toggle between colors
  if( current_color = 1 ){
    current_color = 2;
  }
  else{
     current_color = 1; 
  }
  
  //generate random numbers
  //the function random returns a long integer, or "long", so our variable must be a long
  //random returns a number between 0 and the length of the strip
  long r = random(0,strip.numPixels());

  //print without new line
  Serial.print("The random number is: ");
  //print with new line
  Serial.println(r);
  
  long top = r; //the top part of the animation starts at the index
  long bottom = r; //the bottom starts at the index as well
  
  //For loop: Top = r , go as long as top is less than the max, increase each time
  for(int i = 0; i < strip.numPixels(); i++){
    
    //set colors
    strip.setPixelColor(top, color);
    strip.setPixelColor(bottom,color);
    
    //show changes
    strip.show();
    //wait
    delay(WAIT);
    
    //if statement: only run if condition is met
    if(top < strip.numPixels()){
      top = top + 1; 
    }
    if(bottom > 0){
      bottom = bottom - 1; 
    }
    
  }
  
  
}


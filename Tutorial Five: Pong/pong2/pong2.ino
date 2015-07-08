//Tyler Krupicka
//7/5/15
//pong.ino
//make pixel bounce back and forth with varying speed

//Includes
#include <Adafruit_NeoPixel.h> //the neopixel library
#include <avr/power.h>

//Defines
#define PIN 6 //pin number of arduino data connection
#define BRIGHT 100 //lets define the brightness here

//create a Adafruit_NeoPixel named "strip". Our strip has 60 LEDs and is in pin 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

//GLOBAL VARIABLES////////////////
//variables (number = 5) are only available in their most recent grouping {}
//defining them here outside of everything means that they are available everywhere
int bounceBack = false; //variables can also be true or false (called a boolean) this is useful for toggling (like boucing forward/back)

//This is the correct place to put colors, so they dont get made over and over in the loop
uint32_t magenta = strip.Color(255, 0, 255); // this creates a color with RGB values 255, 0 , 255
uint32_t black = strip.Color(0, 0, 0); // turns pixel off


//setup will be run once at the start
void setup() {
  
  strip.begin(); //start the strip
  strip.setBrightness(BRIGHT); //brightness goes from 0 to 255
  strip.show(); // Initialize all pixels to 'off'
  
}

//loop will be run repeatedly as long as the arduino is on
void loop() {
  
  //we want the pixel to go to the top if bounceback is false (index increasing)
  if(bounceBack == false){
    //count from 0 to 60, setting to the color
    //the difference from before is we need to set the one previous to black so only one is lit
    for(int i = 0; i < strip.numPixels(); i++){
      
      strip.setPixelColor(i, magenta);
      
      //we cant turn the one previous to black if were at 0
      //so we make a statement that we will only do it if i does not equal 0
      if(i != 0){
         strip.setPixelColor(i-1, black);
      }
      
      strip.show();    
      
      //now it will delay anywhere between 1 and 60 causing an odd speed change. cool
      delay(i);
      
    }
    //set bounceBack to true so it returns to the start
    bounceBack = true;
    
  } 
  //now we need to do the exact same thing but in reverse to bounce back to the start
  else{
    //start at the top and go down
    for(int i = strip.numPixels(); i > 0; i--){

      strip.setPixelColor(i, magenta);
      
      //we cant turn the one above to black at the top
      //so we make a statement that we will only do it if i does not equal the top
      //we use numpixels for everything because then the code will work with different strips
      if(i != strip.numPixels()){
         strip.setPixelColor(i+1, black);
      }
      
      strip.show();    
      delay(i);
      
    }
    //set bounceBack to false so it goes up again
    bounceBack = false;
      
  }


}

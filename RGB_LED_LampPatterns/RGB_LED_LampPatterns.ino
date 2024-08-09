
#include <Arduino.h>
#include <FastLED.h>  //library that will be used for RGB lighthing stips
#include <OneButton.h> //library used for push button

#define NUM_LEDS 60  //number of pixels on led strip
#define LED_PIN 2    //digital pin that led strip is connected to
#define BTN_PIN 5    //button pin connection


//variables required for potentiometer dimness
int pot = A0; 
int potVal = 0;
int outVal = 0;

//Defining all the patterns that the led strips will show
//Each row is a specific colour using the values of its RGB and the position of it
DEFINE_GRADIENT_PALETTE(rainbow_gp) {  ///pattern 1
   0, 126, 1, 142,
   25, 171, 1, 26,
   48, 224, 9, 1,
   71, 237, 138, 1,
   94, 52, 173, 1,
   117, 1, 201, 1,
   140, 1, 211, 54,
   163, 1, 124, 168,
   186, 1, 124, 168,
   209, 12, 1, 151,
   232, 12, 1, 151,
   255, 171, 1, 190,

};
//-----------------------------------------------------------//

  DEFINE_GRADIENT_PALETTE(sunset_gp) { ///pattern 2
  0, 120, 0, 0,
  22, 179, 22, 0,
  51, 255, 104, 0,
  85, 167, 22, 18,
  135, 100, 0, 103,
  198, 16, 0, 130,
  255, 0, 0, 160,
};

//-----------------------------------------------------------//

DEFINE_GRADIENT_PALETTE(coolHues_gp) { //pattern 3
  0, 0, 255, 255,
  255, 255, 0, 255
};
//-----------------------------------------------------------//

DEFINE_GRADIENT_PALETTE(yellowBlues_gp) { //pattern 4
  0, 249, 255, 2,
  97, 0, 241, 255,
  255, 249, 255, 2,
};
//-----------------------------------------------------------//

DEFINE_GRADIENT_PALETTE(Pastel_gp ){ //pattern 5
    0, 192, 50,207,
   51, 192, 50,207,
   51,  87, 50,207,
  102,  87, 50,207,
  102,  37, 73,207,
  153,  37, 73,207,
  153,  37,127,207,
  204,  37,127,207,
  204,  37,213,140,
  255,  37,213,140
 };

 //-----------------------------------------------------------//

DEFINE_GRADIENT_PALETTE(deepSea_gp) { //pattern 6
    0,   0,  1,  2,
  148,   1,  7, 24,
  194,   2, 31, 77,
  226,   1,108,144,
  255,   0,237,235
};
//-----------------------------------------------------------//

DEFINE_GRADIENT_PALETTE( blues_gp ) { // pattern 7
    0,   0,  0, 45,
   25,   0,  0,125,
   51,   0,  0,255,
   76,   7, 12,255,
  127,   7, 55,255,
  178,   0,138,255,
  242,   0,255,255,
  255, 255,255,255
 };
 //-----------------------------------------------------------//

DEFINE_GRADIENT_PALETTE(autumn_gp ) { //pattern 8
    0,  71,  3,  1,
   45, 128,  5,  2,
   84, 186, 11,  3,
  127, 215, 27,  8,
  153, 224, 69, 13,
  188, 229, 84,  6,
  226, 242,135, 17,
  255, 247,161, 79

};
//-----------------------------------------------------------//

DEFINE_GRADIENT_PALETTE(turq_gp) {//pattern 9
    0,   1, 33, 95,
   38,   1,107, 37,
   76,  42,255, 45,
  127, 255,255, 45,
  178,  42,255, 45,
  216,   1,107, 37,
  255,   1, 33, 95};
//-----------------------------------------------------------//

DEFINE_GRADIENT_PALETTE(caribbeanSea_gp ) {//pattern 10
    0,   0,  0,  0,
  137,  11,112,153,
  191,  40,219,105,
  255, 255,255,255
 };
//-----------------------------------------------------------//

DEFINE_GRADIENT_PALETTE(forestWild_gp ) {//pattern 11
    0,   0, 55, 25,
   17,   1, 62, 25,
   33,   1, 72, 25,
   51,   3, 82, 25,
   68,   8, 92, 25,
   84,  14,104, 25,
  102,  23,115, 25,
  119,  35,127, 25,
  135,  48,141, 25,
  153,  67,156, 25,
  170,  88,169, 25,
  186, 112,186, 25,
  204, 142,201, 25,
  221, 175,217, 25,
  237, 210,235, 25,
  255, 255,255, 25,
  };

//-----------------------------------------------------------//

DEFINE_GRADIENT_PALETTE(softTones_gp) {// 12
    0, 184, 15,155,
   35,  78, 46,168,
   84,  65,169,230,
  130,   9,127,186,
  163,  77,182,109,
  191, 242,246, 55,
  216, 142,128,103,
  255,  72, 50,168
};
//-----------------------------------------------------------//

DEFINE_GRADIENT_PALETTE(galaxy_gp ) {// 13
    0,   0,  0,  0,
   12,   1,  1,  3,
   53,   8,  1, 22,
   80,   4,  6, 89,
  119,   2, 25,216,
  145,   7, 10, 99,
  186,  15,  2, 31,
  233,   2,  1,  5,
  255,   0,  0,  0
};

//-----------------------------------------------------------//

DEFINE_GRADIENT_PALETTE(magentaTints_gp ) {//14
    0,  71, 27, 39,
   31, 130, 11, 51,
   63, 213,  2, 64,
   70, 232,  1, 66,
   76, 252,  1, 69,
  108, 123,  2, 51,
  255,  46,  9, 35
 };
//-----------------------------------------------------------//

DEFINE_GRADIENT_PALETTE( dawn_gp ) {//15
    0, 227,101,  3,
  117, 194, 18, 19,
  255,  92,  8,192
 
 };
//-----------------------------------------------------------//

//Activate the CRGB control from Led library and include the number of rgb led strips 
CRGB leds[NUM_LEDS];

///Activating all the gradients and assigning them to palette variables for usage
CRGBPalette16 rainbowPal = rainbow_gp;
CRGBPalette16 sunsetPal = sunset_gp;
CRGBPalette16 coolHuesPal = coolHues_gp;
CRGBPalette16 yellowBluesPal = yellowBlues_gp;
CRGBPalette16 PastelPal = Pastel_gp;
CRGBPalette16 deepSeaPal = deepSea_gp;
CRGBPalette16 bluesPal = blues_gp;
CRGBPalette16 caribbeanSeaPal = caribbeanSea_gp;
CRGBPalette16 autumnPal = autumn_gp;
CRGBPalette16 forestWildPal = forestWild_gp;
CRGBPalette16 softTonesPal = softTones_gp;
CRGBPalette16 galaxyPal = galaxy_gp;
CRGBPalette16 magentaTintsPal = magentaTints_gp;
CRGBPalette16 dawnPal = dawn_gp;
CRGBPalette16 turqPal = turq_gp;


uint8_t paletteIndex = 0; //the starting index, will take in 8 bits

uint8_t patternCounter = 0; //changing patterns, will take in 8 bits, keeps track of what pattern we are currently showing
uint8_t timerCounter = 0;


//activating button library by creating object called "btn"
OneButton btn = OneButton(BTN_PIN, true, true);  //labelling the pin, whether it is connected to ground(true), and if object will use input_pullout(true)

void setup() {
  //set up fastled library with the type of led strips being used, and the variables associated with
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds,NUM_LEDS);
  //next pattern is called when button is pressed down and released
  btn.attachClick(nextPattern);   
}

void loop() {
  //read value of potentiameter and map out the value with different ranges
  potVal = analogRead(pot);
  outVal = map(potVal, 0 , 1023, 0 , 255);


  analogWrite(LED_PIN, outVal); //write analog value to rbg led pin

  FastLED.setBrightness(outVal);//brightness controlled by the variable's value
  
//based on what pattern counter value is , it will switch to the according case.
//As default, it starts at 0 and runs through the cases
  switch (patternCounter) { 
    case 0:
      rainbow();//rainbow colours
      break;
    case 1:
      sunset();//purple, red, orange,yellow
      break;
    case 2:
      coolHues(); //purple and blue colours
      break;
    case 3:
      yellowBlues(); //yellow and blue
      break;
    case 4:
      Pastel(); //light colours
      break;
    case 5:
      deepSea(); //dark blue colours
      break;
    case 6:
      forestWild(); //variations of green
      break;
    case 7:
      autumn(); // red, orange, and yellow
      break;
    case 8:
      caribbeanSea();// light blue colors
      break;
    case 9:
      turq(); //light blue and green colors
      break;
    case 10:
      blues(); //blue colors
      break;
    case 11:
      softTones();//more lighter colors
      break;
    case 12:
      galaxy(); //dark blue and purple
      break;
    case 13:
      magentaTints(); //purple and pink
      break;
    case 14:
      dawn(); //yellow, orange, green, blue, purple
      break;
    case 15:
      timerPattern();
      break; 
  }
//each time case breaks, it goes to this line 
  FastLED.show();
  //checks button each time through the loop 
  //once button is pressed and goes back to the pattern cases
  btn.tick();   
}

void nextPattern() {//for the next pattern with push button
  //add one to pattern counter each time and mod it to the amount of patterns, which are 16
  patternCounter = (patternCounter + 1) % 16;
}

void nextTimerPattern(){ //for the next pattern with timer
  //add one to variable each time and mod it to the amount of patterns
  timerCounter = (timerCounter + 1) % 16; 
}


//------------------------------------PATTERN Functions --> Total: 16 -----------------------------------/////

void rainbow(){

   fill_palette(leds, NUM_LEDS, paletteIndex, 255/NUM_LEDS, rainbowPal, 255, LINEARBLEND); ///fill the led stip with linear blend gradient
   
  EVERY_N_MILLISECONDS(30){ //periodically, paletteIndex will increase in increments, results in a moving gradient
    paletteIndex++;
 }
}

void sunset() {
  fill_palette(leds, NUM_LEDS, paletteIndex, 255/NUM_LEDS, sunsetPal, 255, LINEARBLEND); ///gradient shows with linearblend
   
  EVERY_N_MILLISECONDS(30){ //periodically, paletteIndex will increase in increments, results in a moving gradient
    paletteIndex++;
  } 
}

void coolHues() {
  fill_palette(leds, NUM_LEDS, paletteIndex, 255/NUM_LEDS, coolHuesPal, 255, LINEARBLEND); 
}


void yellowBlues() {
    EVERY_N_MILLISECONDS(16){
    //Switch on an LED at random, choosing a random color from the palette
    leds[random8(0, NUM_LEDS)] = ColorFromPalette(yellowBluesPal, random8(), 255, LINEARBLEND);
  }
}

void Pastel() {
  fill_palette(leds, NUM_LEDS, paletteIndex, 255/NUM_LEDS, PastelPal, 255,LINEARBLEND); ///this code allows the gradient to show 
 }


void deepSea() {
  ///this code allows the gradient to show
  fill_palette(leds, NUM_LEDS, paletteIndex, 255/NUM_LEDS, deepSeaPal, 255, LINEARBLEND); 
 //periodically, paletteIndex will increase in increments, results in a moving gradient
  EVERY_N_MILLISECONDS(50){ 
    paletteIndex++;
  } 
   
}

void blues() {
 
  fill_palette(leds, NUM_LEDS, paletteIndex, 255/NUM_LEDS, bluesPal, 255, LINEARBLEND); ///this code allows the gradient to show
   
  EVERY_N_MILLISECONDS(50){//periodically, paletteIndex will increase in increments, results in a moving gradient 
    paletteIndex++;
  }
}

void autumn() {
  fill_palette(leds, NUM_LEDS, paletteIndex, 255/NUM_LEDS, autumnPal, 255, LINEARBLEND);///this code allows the gradient to show

  EVERY_N_MILLISECONDS(30){ //periodically, paletteIndex will increase in increments, results in a moving gradient
    paletteIndex++;
  }
}

void caribbeanSea() {
   EVERY_N_MILLISECONDS(20){//for every(how many increments it says)...
    //Switch on an LED at random, choosing a random color from the palette
    //take any random color from chosen palette, display it, then change after the number of milliseconds
    leds[random8(0, NUM_LEDS)] = ColorFromPalette(caribbeanSeaPal, random8(), 255, LINEARBLEND);
  }  
}

void turq() {
  fill_palette(leds, NUM_LEDS, paletteIndex, 255/NUM_LEDS, turqPal, 255, LINEARBLEND);///this code allows the gradient to show

  EVERY_N_MILLISECONDS(30){ //periodically, paletteIndex will increase in increments, results in a moving gradient
    paletteIndex++;
  }
  
 
}

void forestWild() {
  fill_palette(leds, NUM_LEDS, paletteIndex, 255/NUM_LEDS, forestWildPal, 255, LINEARBLEND);///this code allows the gradient to show
}

void softTones() {
  fill_palette(leds, NUM_LEDS, paletteIndex, 255/NUM_LEDS, softTonesPal, 255, LINEARBLEND);///this code allows the gradient to show
}

void galaxy() {
  fill_palette(leds, NUM_LEDS, paletteIndex, 255/NUM_LEDS, galaxyPal, 255, LINEARBLEND);///this code allows the gradient to show
  
  EVERY_N_MILLISECONDS(20){ //periodically, paletteIndex will increase in increments, results in a moving gradient
    paletteIndex++;
  }
}

void magentaTints() {
  EVERY_N_MILLISECONDS(16){ //for every(how many increments it says)...
    //Switch on an LED at random, choosing a random color from the palette

    //take any random color from chosen palette, display it, then change after the number of milliseconds
    leds[random8(0, NUM_LEDS)] = ColorFromPalette(magentaTintsPal, random8(), 255, LINEARBLEND);
  }
}

void dawn() {
  fill_palette(leds, NUM_LEDS, paletteIndex, 255/NUM_LEDS, dawnPal, 255, LINEARBLEND); ///this code allows the gradient to show

  EVERY_N_MILLISECONDS(20){//periodically, paletteIndex will increase in increments, results in a moving gradient 
    paletteIndex++;
  }  
}


void timerPattern(){

  switch (timerCounter) {
    case 0:
      rainbow();//rainbow colours
      break;
    case 1:
      sunset();//purple, red, orange,yellow
      break;
    case 2:
      coolHues(); //purple and blue colours
      break;
    case 3:
      yellowBlues(); //yellow and blue
      break;
    case 4:
      Pastel(); //light colours
      break;
    case 5:
      deepSea(); //dark blue colours
      break;
    case 6:
      forestWild(); //variations of green
      break;
    case 7:
      autumn(); // red, orange, and yellow
      break;
    case 8:
      caribbeanSea();// light blue colors
      break;
    case 9:
      turq(); //light blue and green colors
      break;
    case 10:
      blues(); //blue colors
      break;
    case 11:
      softTones();//more lighter colors
      break;
    case 12:
      galaxy(); //dark blue and purple
      break;
    case 13:
      magentaTints(); //purple and pink
      break;
    case 14:
      dawn(); //yellow, orange, green, blue, purple
      break; 
      
  }
  
  EVERY_N_SECONDS(8) {  ///every 8 seconds, the next pattern will display in the case after next timer pattern function is called
    nextTimerPattern();
  }

  FastLED.show(); // show led lights

}
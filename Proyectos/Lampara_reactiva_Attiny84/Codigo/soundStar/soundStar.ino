/*
  Author: Elena C. K.
  Description: Attiny84 to control DotStar LED strip from Adafruit. It only have enough byte to control approximately 32 LEDs.
  Use the FastLED library to program.
  IDE Attiny84 Physical Pin
  0      PA0           13 - TX
  1      PA1           12 - RX
  2      PA2           11 - OPAMP OUT
  3      PA3           10
  4      PA4            9
  5      PA5            8
  6      PA6            7
  7      PA7            6 - D1
  8      PB2            5 - C1
  9      PB1            3
  10     PB0           2
*/

#include <FastLED.h>
#define LED_DT 7                                             // Serial data pin
#define LED_CK 8                                             // Serial clock pin for APA102 or WS2801
#define COLOR_ORDER BGR                                       // It's GRB for WS2812B
#define LED_TYPE APA102                                       // What kind of strip are you using (APA102, WS2801 or WS@2812B
#define NUM_LEDS 72
#define MIC 2
#define DC_OFFSET 512

#include <SoftwareSerial.h>
#define RX 1
#define TX 0
CRGB leds[NUM_LEDS];
SoftwareSerial Serial(TX, RX);

uint8_t max_bright = 128;                                      // Overall brightness definition. It can be changed on the fly.

// Colours defined for below
long firstval = 0xff00ff;
CRGB rgbval(50,0,500);
CHSV hsvval(100,255,200);
uint8_t startpos = 0;
int endpos = NUM_LEDS-1;

uint8_t thishue = 0;
uint8_t deltahue = 15;

void setup() {
  Serial.begin(57600);
  FastLED.clear();
  //  LEDS.addLeds<LED_TYPE, LED_DT, COLOR_ORDER>(leds, NUM_LEDS);       // Use this for WS2812B
  LEDS.addLeds<LED_TYPE, LED_DT, LED_CK, COLOR_ORDER>(leds, NUM_LEDS); // Use this for APA102 or WS2801

  FastLED.setBrightness(max_bright);
  set_max_power_in_volts_and_milliamps(5, 500);

  pinMode(MIC, INPUT);
}

void loop() {
  int sample = 0;                                            // Current sample. Starts with negative values, which is why it's signed.
  sample = analogRead(MIC) - DC_OFFSET;
  sample = abs(sample);
//  Serial.println(sample);
//  delay(100);

//FORWARD_HUES, BACKWARD_HUES, SHORTEST_HUES, LONGEST_HUES
//  fill_gradient(leds, startpos, CHSV(50, 255,255) , endpos, CHSV(150,255,255), SHORTEST_HUES);
  if(sample >= 18){
    sample =18;
  }
  fill_gradient(leds, 4*sample , CHSV(50, 255,255), CHSV(100,255,255), LONGEST_HUES);    // up to 4 CHSV values

// fill_rainbow section
//  fill_rainbow(leds, 20+NUM_LEDS/(NUM_LEDS-10*sample), thishue, deltahue);            // Use FastLED's fill_rainbow routine.
//  fill_solid(leds,NUM_LEDS,0);                                // Clear the strip for. . . 
//  fill_rainbow(leds+1, NUM_LEDS-2, thishue, deltahue);        // One pixel border at each end.

  FastLED.show();                         // Power managed display
  delay(30);
}

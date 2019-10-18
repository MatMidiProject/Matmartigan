// Read analog potentiometer on Circuit Playground Express or other board with changes
// Mike Barela for Adafruit Industries 9/2018 based on
// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
#include <MIDI.h>  // INlcude MIDI library
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// Which pin on the microcontroller board is connected to the NeoPixels?
#define PIN8           8// 12 For Circuit Playground Express
#define PIN9           9 // 12
#define PIN10          10 //24
#define PIN11          11   // 16
#define PIN12          12 
#define PIN13          13
// How many NeoPixels are attached to the board?
#define NUMPIXELS      24
#define NUMPIXELS2     24
#define NUMPIXELS3     16
#define NUMPIXELS4     16
#define NUMPIXELS5     12
#define NUMPIXELS6     12
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN8, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS2, PIN9, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3 = Adafruit_NeoPixel(NUMPIXELS3, PIN10, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels4 = Adafruit_NeoPixel(NUMPIXELS4, PIN11, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels5 = Adafruit_NeoPixel(NUMPIXELS5, PIN12, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels6 = Adafruit_NeoPixel(NUMPIXELS6, PIN13, NEO_GRB + NEO_KHZ800);


int delayval = 10; // delay for half a second
int brightness = 10;
int delayval2= 10; // delay for half a second
int brightness2 = 10;
int delayval3 = 10; // delay for half a second
int brightness3 = 10;
int delayval4 = 10; // delay for half a second
int brightness4 = 10;
int delayval5 = 10; // delay for half a second
int brightness5 = 10;
int delayval6 = 10; // delay for half a second
int brightness6 = 10;

const int buttonPin = 42 ; 
const int buttonPin2 = 38 ; 
const int buttonPin3 = 44 ; 
const int buttonPin4 = 40 ;   

const int buttonPin5 = 43 ; 
const int buttonPin6 = 45 ; 
const int buttonPin7 = 41 ; 
const int buttonPin8 = 39 ;   

const int buttonPin9= 52  ; 
const int buttonPin10 = 46  ; 
const int buttonPin11 = 48  ; 
const int buttonPin12 = 50 ;   


int buttonState = 0;
int lastButtonState = 0;
int toggleState = 0;

int buttonState2 = 0;
int lastButtonState2 = 0;
int toggleState2 = 0;

int buttonState3= 0;
int lastButtonState3 = 0;
int toggleState3 = 0;

int buttonState4 = 0;
int lastButtonState4 = 0;
int toggleState4 = 0;

int buttonState5 = 0;
int lastButtonState5 = 0;
int toggleState5 = 0;

int buttonState6 = 0;
int lastButtonState6 = 0;
int toggleState6 = 0;

int buttonState7= 0;
int lastButtonState7 = 0;
int toggleState7 = 0;

int buttonState8 = 0;
int lastButtonState8 = 0;
int toggleState8 = 0;

int buttonState9 = 0;
int lastButtonState9 = 0;
int toggleState9 = 0;

int buttonState10 = 0;
int lastButtonState10 = 0;
int toggleState10 = 0;

int buttonState11= 0;
int lastButtonState11 = 0;
int toggleState11 = 0;

int buttonState12 = 0;
int lastButtonState12 = 0;
int toggleState12 = 0;

// the number of the pushbutton pin
const int ledPin =  24;      // the number of the LED pin
const int ledPin2 =  27;    
const int ledPin3 =  26;      // the number of the LED pin
const int ledPin4 =  25;    

const int ledPin5 =  28;      // the number of the LED pin
const int ledPin6 =  30;    
const int ledPin7 =  29;      // the number of the LED pin
const int ledPin8 =  31;  

const int ledPin9 =  33;      // the number of the LED pin
const int ledPin10 =  34;    
const int ledPin11 =  32;      // the number of the LED pin
const int ledPin12 =  35;  

static int iAn0Val;
static int iAn1Val;
static int iAn2Val;
static int iAn3Val; 
static int iAn4Val;
static int iAn5Val;

void setup() 
{
  
  Serial.begin(9600);
  pinMode(39, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT); 
  pinMode(41, INPUT_PULLUP);
  pinMode(ledPin2, OUTPUT); 
  pinMode(43, INPUT_PULLUP);
  pinMode(ledPin3, OUTPUT); 
  pinMode(45, INPUT_PULLUP);
  pinMode(ledPin4, OUTPUT); 
  pinMode(38, INPUT_PULLUP);
  pinMode(ledPin5, OUTPUT); 
  pinMode(40, INPUT_PULLUP);
  pinMode(ledPin6, OUTPUT); 
  pinMode(42, INPUT_PULLUP);
  pinMode(ledPin7, OUTPUT); 
  pinMode(44, INPUT_PULLUP);
  pinMode(ledPin8, OUTPUT); 
  pinMode(46, INPUT_PULLUP);
  pinMode(ledPin9, OUTPUT); 
  pinMode(48, INPUT_PULLUP);
  pinMode(ledPin10, OUTPUT); 
  pinMode(50, INPUT_PULLUP);
  pinMode(ledPin11, OUTPUT); 
  pinMode(52, INPUT_PULLUP);
  pinMode(ledPin12, OUTPUT); 
  pixels.begin(); // This initializes the NeoPixel library.
  pixels2.begin(); // This initializes the NeoPixel library.
  pixels.setBrightness(brightness);
  pixels2.setBrightness(brightness);
  pixels3.begin(); // This initializes the NeoPixel library.
  pixels4.begin(); // This initializes the NeoPixel library.
  pixels3.setBrightness(brightness);
  pixels4.setBrightness(brightness);
  pixels5.begin(); // This initializes the NeoPixel library.
  pixels5.setBrightness(brightness);
  pixels6.begin(); // This initializes the NeoPixel library.
  pixels6.setBrightness(brightness);
  MIDI.begin();
}

void loop()

{

  affiche () ;
  ring1();
  ring2();
  ring3();
  ring4();
  ring5();
  ring6();
  button();
   
 }

 void affiche ()
{
static int iAn0ValPrev;
iAn0ValPrev = 0 ;
iAn0ValPrev = iAn0Val ; // previous value
iAn0Val = analogRead(A0); // Divide by 8 to get range of 0-127 for midi
if (abs (iAn0Val - iAn0ValPrev)>3)
analogPinMidiTX(1,iAn0Val,iAn0ValPrev); //TX value 
pixels.show(); // This sends the updated pixel color to the hardware.
digitalWrite(8,HIGH);
delay(1); // petit délai pour l'oeil
pixels.show(); // This sends the updated pixel color to the hardware.
digitalWrite(8,LOW);
 
static int iAn1ValPrev;
iAn1ValPrev = 0 ;
iAn1ValPrev = iAn1Val; 
iAn1Val = analogRead(A1);
if (abs (iAn1Val - iAn1ValPrev)>3)
analogPinMidiTX(2,iAn1Val,iAn1ValPrev); 
pixels2.show(); // This sends the updated pixel color to the hardware.
digitalWrite(9,HIGH);
delay(1); // petit délai pour l'oeil
pixels2.show(); // This sends the updated pixel color to the hardware.
digitalWrite(9,LOW);
  
static int iAn2ValPrev;
iAn2ValPrev = 0 ;
iAn2ValPrev = iAn2Val; 
iAn2Val = analogRead(A2);
if (abs (iAn2Val - iAn2ValPrev)>3)
analogPinMidiTX(3,iAn2Val,iAn2ValPrev); 
//delay(5);
pixels3.show(); // This sends the updated pixel color to the hardware.
digitalWrite(10,LOW);
delay(1); // petit délai pour l'oeil
pixels3.show(); // This sends the updated pixel color to the hardware.
digitalWrite(10,HIGH);
  
static int iAn3ValPrev;
iAn3ValPrev = 0 ;
iAn3ValPrev = iAn3Val; 
iAn3Val = analogRead(A3);
if (abs (iAn3Val - iAn3ValPrev)>3)
analogPinMidiTX(4,iAn3Val,iAn3ValPrev); 
pixels4.show(); // This sends the updated pixel color to the hardware.
digitalWrite(11,LOW);
delay(1); // petit délai pour l'oeil
pixels4.show(); // This sends the updated pixel color to the hardware.
digitalWrite(11,HIGH);

  
static int iAn4ValPrev;
iAn4ValPrev = 0 ;
iAn4ValPrev = iAn4Val; 
iAn4Val = analogRead(A4);
if (abs (iAn4Val - iAn4ValPrev)>3)
analogPinMidiTX(5,iAn4Val,iAn4ValPrev); 
pixels5.show(); // This sends the updated pixel color to the hardware.
digitalWrite(12,HIGH);
delay(1); // petit délai pour l'oeil
pixels5.show(); // This sends the updated pixel color to the hardware.
digitalWrite(12,LOW);
        
static int iAn5ValPrev;
iAn5ValPrev = 0 ;
iAn5ValPrev = iAn5Val; 
iAn5Val = analogRead(A5);
if (abs (iAn5Val - iAn5ValPrev)>3)
analogPinMidiTX(6,iAn5Val,iAn5ValPrev); 
pixels6.show(); // This sends the updated pixel color to the hardware.
digitalWrite(13,HIGH);
delay(1); // petit délai pour l'oeil
pixels6.show(); // This sends the updated pixel color to the hardware.
digitalWrite(13,LOW);
}

 void button ()
 {
  // PAD 1
  {
  buttonState = digitalRead(buttonPin);
  if(buttonState != lastButtonState && buttonState == 1 && toggleState == 0) 
     {
     digitalWrite(ledPin,HIGH); 
     MIDI.sendControlChange(51, 127, 1);
     toggleState = 1;
     }
     else if(buttonState != lastButtonState && buttonState == 1 && toggleState == 1) 
     {
      digitalWrite(ledPin, LOW); 
      MIDI.sendControlChange(51,0, 1);
      toggleState = 0;
      }
      lastButtonState = buttonState;
      }
      
      {
  buttonState2 = digitalRead(buttonPin2);
  if(buttonState2 != lastButtonState2 && buttonState2 == 1 && toggleState2 == 0) 
     {
     digitalWrite(ledPin2,HIGH); 
     MIDI.sendControlChange(52, 127, 1);
     toggleState2 = 1;
     }
     else if(buttonState2 != lastButtonState2 && buttonState2 == 1 && toggleState2 == 1) 
     {
      digitalWrite(ledPin2, LOW); 
      MIDI.sendControlChange(52,0, 1);
      toggleState2 = 0;
      }
      lastButtonState2 = buttonState2;
      }
      
            {
  buttonState3 = digitalRead(buttonPin3);
  if(buttonState3 != lastButtonState3 && buttonState3 == 1 && toggleState3 == 0) 
     {
     digitalWrite(ledPin3,HIGH); 
     MIDI.sendControlChange(53, 127, 1);
     toggleState3 = 1;
     }
     else if(buttonState3 != lastButtonState3 && buttonState3 == 1 && toggleState3 == 1) 
     {
      digitalWrite(ledPin3, LOW); 
      MIDI.sendControlChange(53,0, 1);
      toggleState3 = 0;
      }
      lastButtonState3 = buttonState3;
      }
      
     {
  buttonState4 = digitalRead(buttonPin4);
  if(buttonState4 != lastButtonState4 && buttonState4 == 1 && toggleState4 == 0) 
     {
     digitalWrite(ledPin4,HIGH); 
     MIDI.sendControlChange(54, 127, 1);
     toggleState4 = 1;
     }
     else if(buttonState4 != lastButtonState4 && buttonState4 == 1 && toggleState4 == 1) 
     {
      digitalWrite(ledPin4, LOW); 
      MIDI.sendControlChange(54,0, 1);
      toggleState4 = 0;
      }
      lastButtonState4 = buttonState4 ;

      }
      //PAD 2

        {
  buttonState5 = digitalRead(buttonPin5);
  if(buttonState5 != lastButtonState5 && buttonState5 == 1 && toggleState5 == 0) 
     {
     digitalWrite(ledPin5,HIGH); 
     MIDI.sendControlChange(55, 127, 1);
     toggleState5 = 1;
     }
     else if(buttonState5 != lastButtonState5 && buttonState5 == 1 && toggleState5 == 1) 
     {
      digitalWrite(ledPin5, LOW); 
      MIDI.sendControlChange(55,0, 1);
      toggleState5 = 0;
      }
      lastButtonState5 = buttonState5;
      }
      
      {
  buttonState6 = digitalRead(buttonPin6);
  if(buttonState6 != lastButtonState6 && buttonState6 == 1 && toggleState6 == 0) 
     {
     digitalWrite(ledPin6,HIGH); 
     MIDI.sendControlChange(56, 127, 1);
     toggleState6 = 1;
     }
     else if(buttonState6 != lastButtonState6 && buttonState6 == 1 && toggleState6 == 1) 
     {
      digitalWrite(ledPin6, LOW); 
      MIDI.sendControlChange(56,0, 1);
      toggleState6 = 0;
      }
      lastButtonState6 = buttonState6;
      }
      
            {
  buttonState7 = digitalRead(buttonPin7);
  if(buttonState7 != lastButtonState7 && buttonState7 == 1 && toggleState7 == 0) 
     {
     digitalWrite(ledPin7,HIGH); 
     MIDI.sendControlChange(57, 127, 1);
     toggleState7 = 1;
     }
     else if(buttonState7 != lastButtonState7 && buttonState7 == 1 && toggleState7 == 1) 
     {
      digitalWrite(ledPin7, LOW); 
      MIDI.sendControlChange(57,0, 1);
      toggleState7 = 0;
      }
      lastButtonState7 = buttonState7;
      }
      
     {
  buttonState8 = digitalRead(buttonPin8);
  if(buttonState8 != lastButtonState8 && buttonState8 == 1 && toggleState8 == 0) 
     {
     digitalWrite(ledPin8,HIGH); 
     MIDI.sendControlChange(58, 127, 1);
     toggleState8 = 1;
     }
     else if(buttonState8 != lastButtonState8 && buttonState8 == 1 && toggleState8 == 1) 
     {
      digitalWrite(ledPin8, LOW); 
      MIDI.sendControlChange(58,0, 1);
      toggleState8 = 0;
      }
      lastButtonState8 = buttonState8 ;

      }

      //PAD 3
              {
  buttonState9 = digitalRead(buttonPin9);
  if(buttonState9 != lastButtonState9 && buttonState9 == 1 && toggleState9 == 0) 
     {
     digitalWrite(ledPin9,HIGH); 
     MIDI.sendControlChange(59, 127, 1);
     toggleState9 = 1;
     }
     else if(buttonState9 != lastButtonState9 && buttonState9 == 1 && toggleState9 == 1) 
     {
      digitalWrite(ledPin9, LOW); 
      MIDI.sendControlChange(59,0, 1);
      toggleState9 = 0;
      }
      lastButtonState9 = buttonState9;
      }
      
      {
  buttonState10 = digitalRead(buttonPin10);
  if(buttonState10 != lastButtonState10 && buttonState10 == 1 && toggleState10 == 0) 
     {
     digitalWrite(ledPin10,HIGH); 
     MIDI.sendControlChange(60, 127, 1);
     toggleState10 = 1;
     }
     else if(buttonState10 != lastButtonState10 && buttonState10 == 1 && toggleState10 == 1) 
     {
      digitalWrite(ledPin10, LOW); 
      MIDI.sendControlChange(60,0, 1);
      toggleState10 = 0;
      }
      lastButtonState10 = buttonState10;
      }
      
            {
  buttonState11 = digitalRead(buttonPin11);
  if(buttonState11 != lastButtonState11 && buttonState11 == 1 && toggleState11 == 0) 
     {
     digitalWrite(ledPin11,HIGH); 
     MIDI.sendControlChange(60, 127, 1);
     toggleState11 = 1;
     }
     else if(buttonState11 != lastButtonState11 && buttonState11 == 1 && toggleState11 == 1) 
     {
      digitalWrite(ledPin11, LOW); 
      MIDI.sendControlChange(60,0, 1);
      toggleState11 = 0;
      }
      lastButtonState11 = buttonState11;
      }
      
     {
  buttonState12 = digitalRead(buttonPin12);
  if(buttonState12 != lastButtonState12 && buttonState12 == 1 && toggleState12 == 0) 
     {
     digitalWrite(ledPin12,HIGH); 
     MIDI.sendControlChange(61, 127, 1);
     toggleState12 = 1;
     }
     else if(buttonState12 != lastButtonState12 && buttonState12 == 1 && toggleState12 == 1) 
     {
      digitalWrite(ledPin12, LOW); 
      MIDI.sendControlChange(61,0, 1);
      toggleState12 = 0;
      }
      lastButtonState12 = buttonState12 ;

      }
 }
void ring1 ()
   {
 int i;              // loop variable
static int value ; // analog read of potentiometer
int display_value;  // number of NeoPixels to display out of NUMPIXELS
value = analogRead(A0 ); 
display_value = int( value * NUMPIXELS / 1024);// Read PIN value and scale from 0 to NUMPIXELS -1
// number of NeoPixels to display out of NUMPIXELS
// For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one
            for(int i=0;i<NUMPIXELS;i++)
                  {
                  if(i<7 or i==NUMPIXELS-1)
                      {
                  pixels.setPixelColor(i, 050, 050, 050); //blanc
                      }
                   }
            for(int i=0;i<NUMPIXELS;i++)
                  {
                  if(i>=7 or i==NUMPIXELS-1)
                      {
                  pixels.setPixelColor(i, 255, 255, 000); // jaune
                      }
                  }
            for(int i=0;i<NUMPIXELS;i++)
                  {
                  if(i>=15 or i==NUMPIXELS-1)
                      {
                  pixels.setPixelColor(i, 255, 000, 000); //rouge
                      }
                  }
             for(i=display_value; i<NUMPIXELS; i++) 
             {
             pixels.setPixelColor(i, 0, 0, 0);   
             }

    value = map(value, 0, 1023, 15 , 50);   //sets brightRead to a value between 1 and 100
    if (brightness != value) 
    {                  // only update brightness if changed
    brightness = value ;
    pixels.setBrightness(brightness);
    }
    delay(delayval); // Delay for a period of time (in milliseconds).
    }
   
void ring2 () 
      {
   int i;          
   static int  value2;         
   int display_value2; 
   value2 = analogRead(A1);
   display_value2 = int(value2  * NUMPIXELS2 / 1023);
   
            for(int i=0;i<NUMPIXELS2;i++)
                  {
                  if(i<7 or i==NUMPIXELS2-1)
                      {
                  pixels2.setPixelColor(i, 050, 050, 050); //blanc
                      }
                   }
            for(int i=0;i<NUMPIXELS2;i++)
                  {
                  if(i>=7 or i==NUMPIXELS2-1)
                      {
                  pixels2.setPixelColor(i, 255, 255, 000); // jaune
                      }
                  }
            for(int i=0;i<NUMPIXELS2;i++)
                  {
                  if(i>=15 or i==NUMPIXELS2-1)
                      {
                  pixels2.setPixelColor(i, 255, 000, 000); //rouge
                      }
                  }
             for(i=display_value2; i<NUMPIXELS2; i++) 
             {
             pixels2.setPixelColor(i, 0, 0, 0);   
             }
          

    value2 = map(value2, 0, 1023, 1, 50);  
    if (brightness2 != value2) 
    {                
    brightness2 = value2;
    pixels2.setBrightness(brightness2);
    }
    delay(delayval2); 
    }
   void ring3 ()
   {
    int i;              // loop variable
    static int  value3;          // analog read of potentiometer
    int display_value3;  // number of NeoPixels to display out of NUMPIXELS
    value3 = analogRead(A2);
    display_value3 = int(value3  * NUMPIXELS3/ 1023);
    int MaxPixelID = NUMPIXELS3;
    int MinValue3 =min(abs(MaxPixelID-display_value3),MaxPixelID);
    for(int i=0;i<NUMPIXELS3;i++) 
     { //turn all off
       pixels3.setPixelColor(i,0,0,0); 

     }
    if(display_value3>=0) 
    { 
    for(int i=16; i>= MinValue3;i--) 
    {
    pixels3.setPixelColor(i, 050,050,050); 
     }
    }

    for(int i=10; i>= MinValue3;i--) 
    {
    pixels3.setPixelColor(i, 255,255,000); 
     }
    
    for(int i=5; i>= MinValue3;i--) 
    {
    pixels3.setPixelColor(i, 255,000,000); 
    }
     

    value3 = map(value3, 0, 1023, 1, 50);   
    if (brightness3 != value3) 
    {                  
      brightness3 = value3;
      pixels3.setBrightness(brightness3);
    }
  

     delay(delayval3); 
   }

void ring4 ()
      {
   int i;             
   static int value4;          
   int display_value4; 
   value4 = analogRead(A3);
   display_value4 = int(value4  * NUMPIXELS4 / 1023);
   int MaxPixelID1 = NUMPIXELS4;
   int MinValue4 =min(abs(MaxPixelID1-display_value4),MaxPixelID1);
   
     for(int i=0;i<NUMPIXELS4;i++) 
     { //turn all off
       pixels4.setPixelColor(i,0,0,0); 

     }
    if(display_value4>=0) 
    { 
    for(int i=16; i>= MinValue4;i--) 
    {
    pixels4.setPixelColor(i, 050,050,050); 
     }
    }

    for(int i=10; i>= MinValue4;i--) 
    {
    pixels4.setPixelColor(i, 255,255,000); 
     }
    
  for(int i=5; i>= MinValue4;i--) 
    {
    pixels4.setPixelColor(i, 255,000,000); 
    }
 
    value4 = map(value4, 0,1023, 1, 50);  
    if (brightness4 != value4) 
    {                
      brightness4 = value4;
      pixels4.setBrightness(brightness4);
    }
    delay(delayval4); 
    }


void ring5 ()
   {
   int i;              // loop variable
   static int value5;          // analog read of potentiometer
   int display_value5;  // number of NeoPixels to display out of NUMPIXELS
   value5 = analogRead(A4);
   display_value5 = int(value5  * NUMPIXELS5 / 1023);

 for(int i=0;i<NUMPIXELS5;i++)
                  {
                  if(i<4 or i==NUMPIXELS5-1)
                      {
                  pixels5.setPixelColor(i, 050, 050, 050); //blanc
                      }
                   }
            for(int i=0;i<NUMPIXELS5;i++)
                  {
                  if(i>=4 or i==NUMPIXELS5-1)
                      {
                  pixels5.setPixelColor(i, 255, 255, 000); // jaune
                      }
                  }
            for(int i=0;i<NUMPIXELS5;i++)
                  {
                  if(i>=7 or i==NUMPIXELS5-1)
                      {
                  pixels5.setPixelColor(i, 255, 000, 000); //rouge
                      }
                  }
             for(i=display_value5; i<NUMPIXELS5; i++) 
             {
             pixels5.setPixelColor(i, 0, 0, 0);   
             }

    value5 = map(value5, 0, 1023, 1, 50);  
    if (brightness5 != value5) 
    {                
      brightness5 = value5;
      pixels5.setBrightness(brightness5);
    }
    
delay(delayval5);
    }
void ring6 ()
 {
   int i;              // loop variable
   static int  value6;          // analog read of potentiometer
   int display_value6;  // number of NeoPixels to display out of NUMPIXELS
   value6 = analogRead(A5);
   display_value6 = int(value6  * NUMPIXELS6 / 1023);

   for(int i=0;i<NUMPIXELS6;i++)
                  {
                  if(i<4 or i==NUMPIXELS6-1)
                      {
                  pixels6.setPixelColor(i, 050, 050, 050); //blanc
                      }
                   }
            for(int i=0;i<NUMPIXELS6;i++)
                  {
                  if(i>=4 or i==NUMPIXELS6-1)
                      {
                  pixels6.setPixelColor(i, 255, 255, 000); // jaune
                      }
                  }
            for(int i=0;i<NUMPIXELS6;i++)
                  {
                  if(i>=7 or i==NUMPIXELS6-1)
                      {
                  pixels6.setPixelColor(i, 255, 000, 000); //rouge
                      }
                  }
             for(i=display_value6; i<NUMPIXELS6; i++) 
             {
             pixels6.setPixelColor(i, 0, 0, 0);   
             }


    value6 = map(value6, 0, 1023, 1, 50);  
    if (brightness6 != value6) 
    {                
      brightness6 = value6;
      pixels6.setBrightness(brightness6);
    }
    delay(delayval6); 
    }

void analogPinMidiTX(int iChan, int iVal, int iValPrev)
{  
  if(iValPrev != iVal)  // TX Value only if it has changed
    iValPrev != iVal ;
    iVal = iVal >> 3 ;
    MidiTX(176,iChan,iVal); // 176 = CC command, 1 = Which Control, val = value read from Potentionmeter
}

void MidiTX(unsigned char MESSAGE, unsigned char CONTROL, unsigned char VALUE) //Valeur en Midi Command
{
   Serial.write(MESSAGE);
   Serial.write(CONTROL);
   Serial.write(VALUE);
}  

   

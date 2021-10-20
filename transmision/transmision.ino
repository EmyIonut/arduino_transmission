/**
 * Simple demonstration of the Combined PPM (CPPM) receiver library using a multi-color LED.
 *
 * Moving the sticks on the RC transmitter will change the LED's color and brightness.
 */

#include <CPPM.h>

const uint8_t NUM_CHANNELS = 8;
int in1 = 12;
int in2 = 11;

// CPPM channel assignments
const uint8_t Y_CHAN = 2;       // throttle = luminance (brightness)
const uint8_t R_CHAN = 3;       // rudder   = red
const uint8_t G_CHAN = 0;       // aileron  = green
const uint8_t B_CHAN = 1;       // elevator = blue

// OUTPUT: Multi-color LED pins
const uint8_t R_LED_PIN = 5;    // uses timer0
const uint8_t G_LED_PIN = 6;    // uses timer0
const uint8_t B_LED_PIN = 11;   // uses timer2

void setup(void)
{
    CPPM.begin(NUM_CHANNELS);
    Serial.begin(9600);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
}

void loop(void)
{
    int16_t channels[NUM_CHANNELS];
    
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
    if (CPPM.ok())
    {
        CPPM.read(channels);
        
        double brightness1 = channels[Y_CHAN] / 255.0;
        double brightness2 = channels[R_CHAN] / 255.0;
        double brightness3 = channels[G_CHAN] / 255.0;
        double brightness4 = channels[B_CHAN] / 255.0;
        analogWrite(R_LED_PIN, constrain(280 * brightness1, 0, 255));
        //Serial.println(constrain(280 * brightness1, 0, 255));
        
        //Serial.print("r");
        analogWrite(G_LED_PIN, constrain(channels[G_CHAN] * brightness2, 0, 255));
        //Serial.println(constrain(280 * brightness2, 0, 255));
        //Serial.print("g");
        analogWrite(B_LED_PIN, constrain(265 * brightness3, 0, 255));
       double throttle3 = constrain(265 * brightness3, 0, 255);
        if(throttle3 >135){
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        Serial.println("Forward");
          }
          else if(throttle3 >126 && throttle3 <136){
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        Serial.println("Idle");
            }
          else{
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        Serial.println("Reverse");
              }
        Serial.println(constrain(265 * brightness3, 0, 255));
        Serial.print("b");
        Serial.println(constrain(265 * brightness3, 0, 255));
        Serial.print("b");
    }
    else
    {
        analogWrite(R_LED_PIN, 0);
        analogWrite(G_LED_PIN, 0);
        analogWrite(B_LED_PIN, 0);
    }
    delay(200);
    
}

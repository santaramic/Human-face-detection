#include <Adafruit_NeoPixel.h>
#include <avr/power.h>    

#define LED1 8
#define LED2 10
#define NUM_LED1 30 // Number of LED1
#define NUM_LED2 30 // Number of LED2
#define pressSensor1 A1 // connected to PressSeonsor1
#define pressSensor2 A3 // connected to PressSeonsor2

Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUM_LED1, LED1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUM_LED2, LED2, NEO_GRB + NEO_KHZ800);

int delay_value = 10; // 0.01 second
int continuous_delay = 4000; // 7 seconds

char Recog; // char형으로 visual studio에서 인식 값 '0' 또는 '1'을 받음

void setup() {

  pixels1.begin();
  pixels2.begin();
  Serial.begin(9600);

}

void loop() {
 
  int press_value1 = analogRead(pressSensor1);
  int press_value2 = analogRead(pressSensor2);
  delay(100);

  // face detection 값의 변화 감지 시 (값의 변동 감지, face or non-face 감지)
  if (Serial.available()){

    Recog = Serial.read();
    
    if((Recog == '1') && (press_value1 >= 50)){
      
      for(int i=0; i<NUM_LED1; i++){
        
        pixels1.setPixelColor(i, pixels1.Color(255, 0, 0));
        pixels1.show(); // update pixel1 corlor infomation to computer
        delay(delay_value);

        pixels2.setPixelColor(i, pixels2.Color(0, 0, 0));
        pixels2.show(); // update pixel2 corlor infomation to computer
        delay(delay_value); // 추후 interrupt 방식 고려
        
        }
        delay(continuous_delay); // 변동성을 줄이기 위해 7sec의 딜레이 삽입
      }

    else if((press_value1 >= 50) && (press_value2 >= 50)){

        for(int i=0; i<NUM_LED1; i++){
        
        pixels1.setPixelColor(i, pixels1.Color(255, 0, 0));
        pixels1.show(); // update pixel1 corlor infomation to computer
        delay(delay_value);
        
        pixels2.setPixelColor(i, pixels2.Color(255, 127, 0));
        pixels2.show(); // update pixel2 corlor infomation to computer
        delay(delay_value); // 추후 interrupt 방식 고려
        
        }
        delay(continuous_delay); // 변동성을 줄이기 위해 7sec의 딜레이 삽입
    }

    else if((press_value1 >= 50) && (press_value2 >= 50) && (Recog == '1')){

        for(int i=0; i<NUM_LED1; i++){
        
        pixels1.setPixelColor(i, pixels1.Color(255, 0, 0));
        pixels1.show(); // update pixel1 corlor infomation to computer
        delay(delay_value);
        
        pixels2.setPixelColor(i, pixels2.Color(255, 127, 0));
        pixels2.show(); // update pixel2 corlor infomation to computer
        delay(delay_value); // 추후 interrupt 방식 고려
        
        }
        delay(continuous_delay); // 변동성을 줄이기 위해 7sec의 딜레이 삽입
    }
    
    else{
      for(int i=0; i<NUM_LED1; i++){
        pixels1.setPixelColor(i, pixels1.Color(0, 0, 0));
        pixels1.show(); // update pixel1 corlor infomation to computer
        delay(delay_value);

        pixels2.setPixelColor(i, pixels2.Color(0, 0, 0));
        pixels2.show(); // update pixel2 corlor infomation to computer
        delay(delay_value); // 추후 interrupt 방식 고려
        
        }
      }
    }

    // face detection 값의 변화가 없을 시 (값의 변동이 없을 때)
    else{
      if((press_value1 < 50) || (press_value2 < 50)){
        for(int i=0; i<NUM_LED1; i++){
        pixels1.setPixelColor(i, pixels1.Color(0, 0, 0));
        pixels1.show(); // update pixel1 corlor infomation to computer
        delay(delay_value);

        pixels2.setPixelColor(i, pixels2.Color(0, 0, 0));
        pixels2.show(); // update pixel2 corlor infomation to computer
        delay(delay_value); // 추후 interrupt 방식 고려
        
        }
      }

      else if((press_value1 >= 50) && (press_value2 >= 50)){

        for(int i=0; i<NUM_LED1; i++){
        
        pixels1.setPixelColor(i, pixels1.Color(255, 0, 0));
        pixels1.show(); // update pixel1 corlor infomation to computer
        delay(delay_value);

        pixels2.setPixelColor(i, pixels2.Color(255, 127, 0));
        pixels2.show(); // update pixel2 corlor infomation to computer
        delay(delay_value); // 추후 interrupt 방식 고려
        
        }
        delay(continuous_delay); // 변동성을 줄이기 위해 7sec의 딜레이 삽입
    }
    
      else{
      }
    }
  }

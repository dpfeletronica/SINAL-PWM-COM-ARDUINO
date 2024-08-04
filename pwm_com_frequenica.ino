




#include "TimerOne.h"
#include <LiquidCrystal.h>
 const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int pinoSinal = 10;
const int pinoPotFreq = A0;
const int pinoPotDuty = A1;
int freq=950;
int bot=0;

int pushbutton = 9; // declara o push button na porta 9
int pushbutton1 = 8; // declara o push button na porta 8
 int dutyVal=0;
void setup (){
   pinMode(pushbutton, INPUT_PULLUP); // define o pino do botao como entrada
    pinMode(pushbutton1, INPUT_PULLUP); // define o pino do botao como entrada
  pinMode(pinoSinal, OUTPUT);

  Timer1.initialize(100000);
   lcd.begin(16, 2);
      lcd.setCursor(0, 0);
     lcd.print("///PWM TESTE///");
      lcd.setCursor(0, 1);
     lcd.print("   MECANICA");
     delay(2000);
     lcd.clear();
      lcd.setCursor(0, 0);
     lcd.print("///PWM TESTE///");
      lcd.setCursor(0, 1);
     lcd.print("   MAZUQUINI");
     delay(2000);
     lcd.clear();
}

void loop(){

  dutyVal = leituraPot(pinoPotDuty);
  int periodoval = freq;

  periodoval  = map(periodoval , 0, 1000, 1000, 10000);

  Timer1.pwm (pinoSinal, dutyVal, periodoval);
     
     
     lcd.setCursor(0, 0);
     lcd.print("Duty ");
     if((dutyVal-25)/10>=0){
     lcd.print((dutyVal-25)/10);
      lcd.print("% ");
      lcd.print(" ON ");
     }else{
      lcd.print("0");
       lcd.print("% ");
      lcd.print(" OFF ");
     }
    
     lcd.setCursor(0, 1);
     lcd.print("Freq ");
     
         if (digitalRead(pushbutton) == LOW) // Se o botão for pressionado
  {
   bot ++;
    delay(300);
  }
     
  if(bot==0){
     lcd.print(100);
     lcd.print("Hz ");
     freq=990;
  }
  if(bot==1){
     lcd.print(200);
     lcd.print("Hz ");
     freq=450;
  }
   if(bot==2){
     lcd.print(300);
     lcd.print("Hz ");
     freq=250;
  }
   if(bot==3){
     lcd.print(400);
     lcd.print("Hz ");
     freq=160;
  }
   if(bot==4){
     lcd.print(500);
     lcd.print("Hz ");
     freq=110;
  }
   if(bot==5){
     lcd.print(600);
     lcd.print("Hz ");
     freq=70;
  }
   if(bot==6){
     lcd.print(700);
     lcd.print("Hz ");
     freq=46;
  }
   if(bot==7){
     lcd.print(800);
     lcd.print("Hz ");
     freq=28;
  }
   if(bot==8){
     lcd.print(900);
     lcd.print("Hz ");
     freq=12;
  }
   if(bot==9){
     lcd.print(1000);
     lcd.print("Hz ");
     freq=0;
  }
   if(bot==10){
     bot=0;
  }
  
}
int leituraPot(int pinoPot){
  int leitura=0;
  int numLeituras=10;
  for(int i =0 ; i <numLeituras; i++){
    leitura = leitura + analogRead(pinoPot);
    delay(5);
  }
  leitura=leitura / numLeituras;
  return leitura;
  
}

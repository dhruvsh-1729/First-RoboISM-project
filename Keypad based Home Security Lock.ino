#include<Keypad.h>
int pinbuz=13;
int greenpin=11;
char key;
int curr=0;
char actual[4]="1234";
const byte ROWS = 4;
const byte COLS = 4;
char posKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
Keypad customKeypad = Keypad(makeKeymap(posKeys), rowPins, colPins, ROWS, COLS);
void setup() {
  // put your setup code here, to run once
  Serial.begin(9600);
  pinMode(pinbuz,OUTPUT);
  pinMode(greenpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
static int count=1;
key=customKeypad.getKey();
 if(key){
  if(key==actual[curr]){
    Serial.print(key);
    ++curr;
    if(curr==4){
      digitalWrite(greenpin,HIGH);
      digitalWrite(pinbuz,LOW);
      delay(10000);
      digitalWrite(greenpin,LOW);
      curr=0;
      exit(1);
      }  
      }
  else{
    if(count==1){
    alert1();count++;}
    else if(count==2){
    alert2();count++;}
    else if(count==3){
    alert3();count++;}
    else if(count>3){
      digitalWrite(pinbuz,HIGH);}
    }    
  }

}

void alert1(void){
  for(int i=0;i<5;i++){
    digitalWrite(pinbuz,HIGH);
    delay(100);
    digitalWrite(pinbuz,LOW);
    delay(1000);
      }
    }
void alert2(void){
  for(int i=0;i<10;i++){
    digitalWrite(pinbuz,HIGH);
    delay(100);
    digitalWrite(pinbuz,LOW);
    delay(700);
      }
    }
void alert3(void){
  for(int i=0;i<15;i++){
    digitalWrite(pinbuz,HIGH);
    delay(100);
    digitalWrite(pinbuz,LOW);
    delay(300);
      }
    }

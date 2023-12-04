/*
Kevin Lin
Temperature sensor 
DHT22 + Arduino nano
kevinlin04@vt.edu

      A
     ---
  F |   | B
     --- <-G
  E |   | C
     ---
      D
    
  Top Row:    1 A F 2 3 B
  Bottom Row: E D . C G 4
  . is the decimal point between the numbers

  Display: starts from left side
  1 2 3 4
  
 */
//temperature sensor setup
#include <dht.h>
#define dataPin 2
dht DHT;


//seven segment display set up
int pinA = A1, pinB = A5, pinC = 7, pinD = 9, pinE = 10, pinF = A2, pinG = 6, decimal = 8;//assigning the leds
int D1 = A0, D2 = A3, D3 = A4, D4 = 5;//assigning the digits(first number, second number, etc.)


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pins as outputs.
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);
  pinMode(decimal, OUTPUT);      
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);

}

void loop() {
  //for some reason digitalwrite for these is opposite what you expect
  //low is on and high is off
  //very strange
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);

  DHT.read22(dataPin);
  double temperature = ((double)DHT.temperature*9/5)+32;
  delay(100);
  
  for(int i=0;i<500;i++){
    tens(temperature);
    delay(5);
    digitalWrite(decimal, HIGH);
    ones(temperature);
    delay(5);
    digitalWrite(decimal, LOW);
    tenths(temperature);
    delay(5);
    f();
    delay(5);
  }
}
void f(){
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4,LOW);

  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);  
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);  
  digitalWrite(pinE, HIGH);  
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH); 
}
void tens(double temp){//first number 76.5 -> 7
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  
  int firstDigit = temp/10;
  numberDecider(firstDigit);
  
}
void ones(double temp){//second number 76.5 -> 6
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  digitalWrite(decimal, HIGH);

  int secondDigit = temp-(((int)(temp/10))*10);//76.5-(7*10) = 6.5
  numberDecider(secondDigit);
}
void tenths(double temp){//third number 76.5 -> 5
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D4, HIGH);

  int thirdDigit = (temp-(int)temp)*10;//76.5-(76[int numbers round down no matter what]) = .5*10 = 5
  numberDecider(thirdDigit);
}
void numberDecider(int num){
  switch(num){
    case 0:
      zero();
      break;
    case 1:
      one();
      break;
    case 2:
      two();
      break;
    case 3:
      three();
      break;
    case 4:
      four();
      break;
    case 5:
      five();
      break;
    case 6:
      six();
      break;
    case 7:
      seven();
      break;
    case 8:
      eight();
      break;
    case 9:
      nine();
      break;
  }
}
//numbers, call the function to display on seven segment display
void zero(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);   
}
void one(){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);   
}
void two(){
  digitalWrite(pinA, HIGH);  
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);  
  digitalWrite(pinD, HIGH);  
  digitalWrite(pinE, HIGH);  
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);   
}
void three(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);   
}
void four(){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);   
}
void five(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);  
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);  
  digitalWrite(pinE, LOW);  
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);   
}
void six(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);  
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);  
  digitalWrite(pinE, HIGH);  
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);   
}
void seven(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);   
}
void eight(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);  
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);  
  digitalWrite(pinE, HIGH);  
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);    
}
void nine(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);  
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);  
  digitalWrite(pinE, LOW);  
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);    
}
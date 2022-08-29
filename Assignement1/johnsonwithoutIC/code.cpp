#include <Arduino.h>
#include<stdio.h>
int Q1, Q2, Q3, Q4, Q44;
int D11,D12,D13,D14;
int D1,D2,D3,D4;
void disp_led(int Q1,int Q2,int Q3,int Q4)
{

  digitalWrite(2,Q1);
  digitalWrite(3,Q2);
  digitalWrite(4,Q3);
  digitalWrite(5,Q4);

}
void setup() 
{
  int D1=0, D2=0, D3=0, D4=0, Q1=0, Q2=0, Q3=0, Q4=0;
  Q44 = !D4;
  pinMode(2,OUTPUT); 
  pinMode(3,OUTPUT); 
  pinMode(4,OUTPUT); 
  pinMode(5,OUTPUT); 
  pinMode(6,OUTPUT);
  pinMode(13,OUTPUT);
}

void CLK()
{
 digitalWrite(13,HIGH);
 delay(1000);
 digitalWrite(13,LOW);
 delay(3000);
}

void loop()
{
while(1){
  disp_led(Q1,Q2,Q3,Q4);

D11=D1;
D12=D2;
D13=D3;
D14=D4;
  D1 = Q44;
  Q1 = D1;
 CLK;
 D2=D11;
 Q2 = D2;
 CLK;
D3=D12;
  Q3 = D3;
CLK;
D4=D13;
  Q4 = D4;
  Q44 = !Q4;
  
delay(3000);

}
}


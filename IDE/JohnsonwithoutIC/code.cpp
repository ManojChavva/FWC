#include<Arduino.h> 
#include<stdio.h> 
int Q1=0, Q2=0, Q3=0, Q4=0, Q44=1;
int D1,D2,D3,D4;
void disp (int Q4,int Q3,int Q2,int Q1)
{
  digitalWrite(2,Q1);
  digitalWrite(3,Q2);
  digitalWrite(4,Q3);
  digitalWrite(5,Q4);

}
void setup() 
{
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
  delay(1000);
}
void loop()
{
disp(Q4,Q3,Q2,Q1);
  D1 = Q44;
  Q1 = D1;
CLK();
disp(Q4,Q3,Q2,Q1);
D2 = Q1;
Q2=D2;
  CLK();
disp(Q4,Q3,Q2,Q1);
D3=Q2;
Q3 = D3;
CLK();
disp(Q4,Q3,Q2,Q1);
D4=Q3;
Q4 = D4;
Q44 = !Q4;
 CLK();
disp(Q4,Q3,Q2,Q1);
}


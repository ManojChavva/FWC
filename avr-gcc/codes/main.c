#include <avr/io.h>
#include <util/delay.h> 

int Q1=0,Q2=0,Q3=0,Q4=0,Q44=1;
int D1,D2,D3,D4;
 
void clk1(){
PORTB=((1<<PB5));
_delay_ms(1000);
PORTB=((0<<PB5));
_delay_ms(1000);
}

void disp(int Q4,int Q3,int Q2,int Q1){
int  out1;
out1=(Q4<<5) | (Q3<<4) | (Q2<<3) |(Q1<<2);
PORTD=out1;
}


int main (void)
{
 //set PD2-PD5 as output pins 0xFC=0b11111100 (binary)
  DDRD   |= 0x3C;
  //set PB0 as output pin
  DDRB    |= ((1 << DDB5));


  while (1) {
    disp(Q4,Q3,Q2,Q1);
    clk1();
     D1=Q44;
     Q1=D1;
    disp(Q4,Q3,Q2,Q1);
    clk1();
   D2=Q1;
   Q2=D2;
    disp(Q4,Q3,Q2,Q1);
    clk1();  
    D3=Q2;
    Q3=D3;
    disp(Q4,Q3,Q2,Q1);
   clk1();
   D4=Q3;
   Q4=D4;
   Q44=!Q4;  

   disp(Q4,Q3,Q2,Q1);
      clk1();
}
  return 0;

}

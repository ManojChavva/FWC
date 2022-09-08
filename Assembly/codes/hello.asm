.include "/home/anu/anusha1/m328Pdef.inc"

.def led1 = r20
.def mask=r21

ldi r17,0b00111100         ;2,3,4,5 pins outputs
out DDRD,r17

sbi DDRB, 5 ;set pin 13 as output pin (DDRB pin 5)
ldi r16, 0b00000101 ;the last 3 bits define the prescaler, 101 => division by 1024
out TCCR0B, r16 

ldi r26,0b00000000             ;Q1
ldi r27,0b00000000             ;Q2
ldi r28,0b00000000             ;Q3
ldi r29,0b00000000             ;Q4
ldi r30,0b00000001              ;Q44
clr led1
ldi mask,0b00100000

start:
     ;eor led1,mask
     ;out PORTB,led1
     call loop2
     rcall clk1
loop1:
     mov r19,r30           ;D1=r19,Q1=r26
     mov r26,r19
     call loop2
     rcall clk1
     mov  r25,r26                ;D2=r25,Q2=r27
     mov r27,r25
     call loop2
     rcall clk1
     mov r24,r27                  ;D3=r24,Q3=r28
     mov r28,r24
     call loop2
     rcall clk1
     mov r23,r28                 ;D4=r23,Q4=r29
     mov r29,r23
     ldi r30,0b00000001
     eor r30,r29
     call loop2
     rcall clk1
     cp mask,led1
     brne loop1
loop2:
;ldi r17,0b00000000
       mov r17,r29
       lsl r17
       or r17,r28
       lsl r17
       or r17,r27
       lsl r17
       or r17,r26
       lsl r17
       lsl r17
       out PORTD,r17
clk1:
w0:	sbi DDRB,5
     ldi r18,0b01000000	;this is delay (function)
         rcall PAUSE
         cbi DDRB,5
     ldi r18,0b01000000	;this is delay (function)
          rcall PAUSE
          ret

PAUSE:;this is delay (function)
lp2:	;loop runs 64 times
		IN r16, TIFR0 ;tifr is timer interupt flag (8 bit timer runs 256 times)
		ldi r17, 0b00000010
		AND r16, r17 ;need second bit
		BREQ PAUSE 
		OUT TIFR0, r17	;set tifr flag high
	dec r18
	brne lp2
	ret

rjmp start

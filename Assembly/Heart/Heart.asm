#include <p16f887.inc>

banksel TRISC
clrf	TRISC
banksel PORTC
clrf	PORTC

banksel	TRISD
clrf	TRISD
banksel	PORTD
clrf	PORTD

Main
	clrf	PORTD
	clrf	PORTC
	movlw 	B'01000010'
	movwf	PORTD
	movlw	B'11000111'
	movwf   PORTC
	; Next col
	call 	Delay
	clrf	PORTD
	clrf	PORTC
	movlw 	B'00100100'
	movwf	PORTD
	movlw	B'10111011'
	movwf   PORTC
	call 	Delay
	; Last col
	clrf	PORTD
	clrf	PORTC
	movlw 	B'00011000'
	movwf	PORTD
	movlw	B'11011101'
	movwf   PORTC
	call 	Delay
	
	goto 	Main

Delay
	decfsz	20h
	goto 	Delay
	return	

end
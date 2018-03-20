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
	bsf		PORTC, 0
	call 	Delay
	bcf 	PORTC, 0
	bsf 	PORTD, 0
	call 	Delay
	bcf 	PORTD, 0
	goto 	Main
Delay
	decfsz	20h
	goto 	Delay
	return
end
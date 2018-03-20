#include <p16f887.inc>
; Switch
banksel TRISC
clrf	TRISC
banksel	PORTC
; LED
banksel TRISD
clrf 	TRISD
banksel PORTD
clrf	PORTD

Main
	btfss 	PORTC, 0 ; If clicked
	goto 	TurnLight
	goto 	Main

TurnLight
	movf	PORTD, 0 ; W <- PORTD
	clrf	21h
	movwf	21h ; W -> temporary
	btfsc 	21h, 0 ; skip if off
	bcf	PORTD, 0
	btfss	21h, 0
	bsf	PORTD, 0
	call	Delay
	goto 	Main

Delay
	decfsz 	20h
	goto 	Delay
	return	

end

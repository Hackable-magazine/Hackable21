cpu z80

;.ORG 0000H
* = 0000H

code

; un commentaire

.INIT	JP .PLOP
	NOP
.PLOP	NOP
	NOP
	JP .INIT



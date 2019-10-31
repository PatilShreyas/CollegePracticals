PRINT MACRO M
 MOV AH,09H
 LEA DX,M
 INT 21H
 ENDM

DATA SEGMENT
MSGMENU DB 10,13,"** --- MENU --- **"
     DB 10,13,"1.HEX To BCD Conversion"
     DB 10,13,"2.BCD To HEX"
     DB 10,13,"3.EXIT"
     DB 10,13,"ENTER YOUR CHOICE : $"
	 
 MSGH DB 10,13,"ENTER HEX NO : $"
 MSGEQB DB 10,13,"BCD EQUIVALENT : $"
 
 MSGB DB 10,13,"Enter BCD Number : $"
 MSGEQH DB 10,13,"Hex Equivalent : $"
 MSGIV db 10,13,"!!! INVALID BCD !!!$"

 NUM DW ?
 TEMP DB ?
 
DATA ENDS

CODE SEGMENT
 ASSUME CS:CODE,DS:DATA
 MAIN: 
	MOV AX,DATA
    MOV DS,AX

    MOV AX,02H
	INT 10H

	; Display MENU
Menu:   
	PRINT MSGMENU
	
	MOV AH,01H
	INT 21H

	CMP AL,31H
	JE H2B
	
	CMP AL,32H
	JE B2H
	
	CMP AL,33H
	JE Exit

H2B:
	PRINT MSGH
	CALL INPUT
	
	MOV NUM,BX
	PRINT MSGEQB
	CALL Hex2Bcd

	JMP Menu
	
B2H:
	CALL Bcd2Hex
	JMP MENU
DN2:     
	PRINT MSGIV
	
Exit:
	MOV AH,4CH
	INT 21H
	
	
	INPUT PROC
		MOV CL,04H
		MOV SI,04H
		MOV BX,00H

	UP:     
		MOV AH,01H
		INT 21H

		CMP AL,39H
		JNG DN
		SUB AL,37H
		JMP DN1

	DN:     
		SUB AL,30H
		SHL BX,CL

		ADD BL,AL
		DEC SI
		JNZ UP

	DN1:    
	RET
	INPUT ENDP

Bcd2Hex PROC
	MOV SI,04H
	MOV CL,10H
	MOV BX,0000H

	Print MSGB

	UPN:                 ;Get Input
        MOV AH,01H
        INT 21H
        
        CMP AL,39H      ;ASCII to Hex
        JA DN2
        SUB AL,30H

        MOV AH,00H
        PUSH AX
        MOV AX,BX
        MUL CX
        MOV BX,AX

        POP AX
        ADD BX,AX

        DEC SI
        JNZ UPN

        Print MSGEQH
		
        MOV TEMP,BH
        CALL Display1
        MOV TEMP,BL
        CALL Display1
        JMP Menu
RET
Bcd2Hex ENDP


Hex2Bcd PROC
        MOV AX,NUM
        MOV CX,00H
        MOV BX,10

UP1:    MOV DX,0
        DIV BX
        PUSH DX
        INC CX
        OR AX,AX
        JNZ UP1

UP2:    POP DX
        ADD DL,30H
        MOV AH,02H
        INT 21H
        LOOP UP2
        RET
    Hex2Bcd ENDP
	
	Display1 PROC
        MOV DL,TEMP
        AND DL,0F0H
        MOV CL,04H

        SHR DL,CL
        CMP DL,09H
        JNG NEXT
        ADD DL,07H

	NEXT:  
		ADD DL,30H
        MOV AH,02H
        INT 21H
        
    RET
	Display1 ENDP

	
	CODE ENDS
	END MAIN

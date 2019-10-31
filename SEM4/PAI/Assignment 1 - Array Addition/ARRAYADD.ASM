DATA SEGMENT
ARRAY1 DW 1000H,2000H,3000H,5000H,4000H
MSG DB 10,13,"ARRAY ADDITION = $"
RESULT DW 0
TMP DB ?
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
MAIN:   MOV AX,DATA
        MOV DS,AX
        
        MOV AX,02H
        INT 10H

        LEA BX,ARRAY1
        XOR DI,DI
        MOV CL,05H
UP:     MOV AX,[BX+DI]
        ADD RESULT,AX
        INC DI
        INC DI
        DEC CL
        JNZ UP

        MOV BX,RESULT
        MOV TMP,BH

        LEA DX,MSG
        MOV AH,09H
        INT 21H

        CALL DISPLAY
        MOV TMP,BL
        CALL DISPLAY
        
        MOV AH,4CH
        INT 21H
        
        DISPLAY PROC
        MOV DL,TMP
        AND DL,0F0H 
        MOV CL,04H
        SHR DL,CL
        CMP DL,09H
        JNG NEXT
        ADD DL,07H

NEXT:   ADD DL,30H
        MOV AH,02H
        INT 21H
        
        MOV DL,TMP
        AND DL,0FH
        CMP DL,09H
        JNG NEXT1

NEXT1:  ADD DL,30H
        MOV AH,02H
        INT 21H
        RET
        DISPLAY ENDP
CODE ENDS
END MAIN

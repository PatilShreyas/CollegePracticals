;Program: LCD interface program
;Description: The program to display the string on LCD display.
;This program is developed for SBC_51 board and needs the stepper motor interface to be connected.

;Interface declaration
RS  EQU P3^2
EN  EQU P3^3

	org 0h
	ljmp start

DelaymS:
	mov r4,#04	;  (4*255) ~ 1000uS = 1mS
	mov r5,#0	
loop:
	djnz r5,loop
	djnz r4,loop
	ret

;Subroutine to write DATA to LCD : 
;Input Value: passed in A accumulator

write_lcd_data:
	mov P0,A		;Write the value on port P0
	mov r6,#05h		;Call delay for 5mS
continue1:
	lcall DelaymS
	djnz r6, continue1
	SETB RS
	SETB EN
	mov r6,#01h		;Call delay for 1mS
continue2:
	lcall DelaymS
	djnz r6, continue2
	MOV P3,#00		; clear the control signals
	ret

;Subroutine to send command to LCD

write_lcd_cmd:
	mov P0,A		;Write the value on port P0
	mov r6,#0ah		;Call delay for 5mS
continue3:
	lcall DelaymS
	djnz r6, continue3
	SETB EN
	mov r6,#01h		;Call delay for 1mS
continue4:
	lcall DelaymS
	djnz r6, continue4
	MOV P3,#00		; clear the control signals
	ret
	
	
;Subroutine to blink display
blink_display:
	mov a,#08
	lcall write_lcd_cmd
	mov a, #0fh
	lcall write_lcd_cmd
	ret

start:
	mov a,#0x38				; //function set
	lcall write_lcd_cmd
	mov a,#0x08				; //display off
	lcall write_lcd_cmd
	mov a,#0x01				; //display clear
	lcall write_lcd_cmd
	mov a,#0x06				; //entry mode set
	lcall write_lcd_cmd
	mov a,#0x0f				; //display on
	lcall write_lcd_cmd
	mov a,#0x80				; //set address counter value
	lcall write_lcd_cmd
	
	;Start displaying the string
	mov a,#'H'				 
	lcall write_lcd_data
	mov a,#'E'				 
	lcall write_lcd_data
	mov a,#'L'				 
	lcall write_lcd_data
	mov a,#'L'				 
	lcall write_lcd_data
	mov a,#'O'				 
	lcall write_lcd_data
	mov a,#' '				 
	lcall write_lcd_data
	mov a,#'W'				 
	lcall write_lcd_data
	mov a,#'O'				 
	lcall write_lcd_data
	mov a,#'R'				 
	lcall write_lcd_data
	mov a,#'L'				 
	lcall write_lcd_data
	mov a,#'D'				 
	lcall write_lcd_data

infinite_loop:
		lcall blink_display
		sjmp infinite_loop
END	





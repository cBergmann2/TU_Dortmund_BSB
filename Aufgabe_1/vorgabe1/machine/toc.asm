; $Id: toc.asm 956 2008-10-19 22:24:23Z hsc $

;******************************************************************************
;* Betriebssysteme                                                            *
;*----------------------------------------------------------------------------*
;*                                                                            *
;*                               T O C . A S M                                *
;*                                                                            *
;*----------------------------------------------------------------------------*
;*
;******************************************************************************

%include "machine/toc.inc"

; EXPORTIERTE FUNKTIONEN

[GLOBAL toc_switch]
[GLOBAL toc_go]

; IMPLEMENTIERUNG DER FUNKTIONEN


[SECTION .text]

; TOC_GO : Startet den ersten Prozess ueberhaupt.
;
; Diese Funktion lädt die Prozessorregister mit 
; den Inhalten der Struktur regs.
;
; C Prototyp: void toc_go (struct toc* regs);

toc_go:
	;Parameter regs wird benötigt
	mov eax, [4+esp] 	; &regs in eax speichern
	
	;Parameter in regs in die register laden
	mov ebx, [eax]
	add eax, 4
	mov esi, [eax]
	add eax, 4
	mov edi, [eax]
	add eax, 4
	mov ebp, [eax]
	add eax, 4
	mov esp, [eax]
	
	ret
  

; TOC_SWITCH : Prozessumschaltung. Der aktuelle Registersatz wird     
;              gesichert und der Registersatz des neuen "thread of control"
;              wird in den Prozessor eingelesen.  
;
; Diese Funktion führt einen Kontextwechsel durch. Dazu brauchen 
; nur die aktuellen Registerwerte in regs_now gesichert und durch 
; die Werte von regs_then ersetzt werden. 
;
; C Prototyp: void toc_switch (struct toc* regs_now,
;                              struct toc* reg_then);

toc_switch:
	;Parameter regs_now mit den aktuellen Registern füllen
	mov eax, [4+esp] 	; &regs in eax speichern
	
	;Parameter in regs in die register laden
	mov [eax], ebx
	add eax, 4
	mov [eax], esi
	add eax, 4
	mov [eax], edi 
	add eax, 4
	mov [eax], ebp
	add eax, 4
	mov [eax], esp


	;Parameter regs wird benötigt
	mov eax, [8+esp] 	; &regs in eax speichern
	
	;Parameter in regs in die register laden
	mov ebx, [eax]
	add eax, 4
	mov esi, [eax]
	add eax, 4
	mov edi, [eax]
	add eax, 4
	mov ebp, [eax]
	add eax, 4
	mov esp, [eax]
	
	ret

	


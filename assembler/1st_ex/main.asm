section .data
    S dd 6
		N dd 1
		M dd 1
		err db "-1", 0x0A
		len equ $ - err

section .bss
    result resb 16

section .text
    global _start

_start:
		; store S M
		mov eax, [S]
		mov ebx, [M]

		; store S * M in ebx
		imul eax, ebx
		mov ebx, eax

		; store S / 7 in ecx
		mov eax, [S]
		mov ecx, 7
		div ecx
		mov ecx, eax

		; store S - S / 7 in ecx
		mov eax, [S]
		sub eax, ecx
		mov ecx, eax

		; store (S - S / 7) in ecx
		mov eax, [N]
		imul eax, ecx
		mov ecx, eax

		; cmp ebx and ecx
		cmp ebx, ecx
		jg error 

		; store S * M / N in eax
		xor edx, edx
		mov eax, ebx
		mov ecx, [N]
		div ecx

		; increment eax, remainder <= 0
		cmp edx, 0
		jle convert
		inc eax

convert:
    lea edi, [result + 15] 
    mov byte [edi], 0x0A  
		
		; convert
    dec edi              
    xor edx, edx         
    mov ecx, 10          
    div ecx              
    add dl, '0'          
    mov [edi], dl        
    test eax, eax        
    jnz convert          

		; print
    mov eax, 4           
    mov ebx, 1           
    lea ecx, [edi]       
    lea edx, [result + 16] 
    sub edx, ecx         
    int 0x80             

		call done

error:
		mov eax, 4
		mov ebx, 1
		mov ecx, err
		mov edx, len
		int 0x80

done:
		mov eax, 1
		mov ebx, 0
		int 0x80

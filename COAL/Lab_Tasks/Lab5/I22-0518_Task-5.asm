.model small
.stack 100h
.data
    v1   db 5
    msg1 db 10,13,"Even number$"
    msg2 db 10,13,"Odd number$"
.code
main proc
         mov ax,@data
         mov ds,ax
         mov al,v1
         and al,1
         cmp al,0
         jne odd
         mov ah,09h
         lea dx,msg1
         int 21h
jmp endprogram
odd:
         mov ah,09h
         lea dx,msg2
         int 21h
endprogram:
            mov ah,4ch
            int 21h
main endp
    end main 
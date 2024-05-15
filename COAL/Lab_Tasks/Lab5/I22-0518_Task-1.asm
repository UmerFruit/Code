.model small
.stack 100h
.data
    v1   db 5
    v2   db 7
    msg1 db "equal$"
    msg2 db 10,13,"not equal$"
.code
main proc
               mov ax,@data
               mov ds,ax
               mov al,v1
               mov bl,v2
               cmp al,bl
               je  equal
               mov dx,offset msg2
               mov ah,09h
               int 21h
               jmp endprogram
    equal:     
               mov dx,offset msg1
               mov ah,09h
               int 21h
               jmp endprogram
    endprogram:
               mov ah,4ch
               int 21h
main endp
    end main 
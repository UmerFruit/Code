.model small
.stack 100h
.data
.code
main proc
    mov ax,5
    mov bx,10
    mov ax,bx
    mov bx,15
    mov ax,bx
    mov cx,300
    mov dx,200

    mov ax,4ch
    int 21h
    
    
main endp
    end main
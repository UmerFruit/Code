.model small
.stack 100h
.data
    v1 dw ?
    v2 db ?
.code
main proc

    mov ax,@data
    mov ds,ax
    mov v1,10
    mov bl,5
    mov ax,v1
    div bl

    mov cx,ax

    mov dl,ch
    add dl,'0'
    mov ah,2
    int 21h
    mov dl,cl
    add dl,'0'
    mov ah,2
    int 21h

    mov ah,4ch
    int 21h
main endp
    end main
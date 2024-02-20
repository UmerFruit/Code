.model small
.stack 100h
.data
    v1 db 2
    v2 db 5
.code
main proc

    mov ax,@data
    mov ds,ax

    mov al,v1
    mul v2

    aam
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
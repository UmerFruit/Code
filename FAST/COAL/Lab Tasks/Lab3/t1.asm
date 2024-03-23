.model small
.stack 100h
.data
    v1 db 15
    v2 db 25
.code
main proc

    mov ax,@data
    mov ds,ax

    mov al,v1
    add al,v2

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
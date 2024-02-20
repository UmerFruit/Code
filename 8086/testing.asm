.model small
.stack 100h
.data
    v1 db 15
    v2 db 25
.code
main proc

    mov ax,@data
    mov ds,ax

    mov ax,2
    add ax,97

    mov dx,ax

    mov ah,2
    int 21h

    mov ah,4ch
    int 21h
main endp
    end main
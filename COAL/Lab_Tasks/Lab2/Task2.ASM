.model small
.stack 100h
.data
.code
main proc
    mov ah,1; read char with echo (8 for without echo)
    int 21h
    mov ah,2
    mov ah,2
    mov dl,al; the entered character is stored in al
    int 21h
    mov ah,4ch
    int 21h
main endp
    end main
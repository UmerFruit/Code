.model small
.stack 100h
.data
.code
main proc
    mov ah,1
    int 21h ;   because it reads in ascii so 0 = 48
    sub al,'0'; from ascii to actual num (this process is called Stripping the ascii)
    mov dl,al

    mov ah,1
    int 21h

    sub al,'0'  ;strip the ascii
    add dl,al
    add dl,'0'  ;bring back to 48 - onward range

    mov ah,2
    int 21h
    mov ah,4ch
    int 21h
main endp
    end main
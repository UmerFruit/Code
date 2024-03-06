.model small
.stack 100h
.data
arr1 db 1,2,3,4,5
warr2 dw 5 dup(25)
arr3 dd 25 dup(2024h)
types db 3 dup(?)
lengths db 3 dup(?)
sizes db 3 dup(?)   

.code
main proc
    mov ax,@data
    mov ds,ax

    mov types[0],type arr1
    mov ah,4ch
    
    int 21h

main endp
    end main
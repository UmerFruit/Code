.model small
.stack 100h
.data
    arr1  db 1,2,3,4,5
    warr2 dw 5 dup(25)
    arr3  dd 2 dup(2024h)
    t     db ?
    l     db ?
    s     db ?
.code
main proc

         mov ax,@data
         mov ds,ax
         
         mov t, type arr1
         mov l,length warr2
         mov s, size arr3
         mov si,offset arr3

         mov ah,4ch
         int 21h

main endp
    end main
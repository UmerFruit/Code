.model small
.stack 100h
.data
    arr1    db 4h,35h,25h,6h,2h,25h,62h,3h,12h,68h,22h,44h,55h
    replace db 99h
.code
main proc

         mov ax,@data
         mov ds,ax
         
         mov si,offset arr1
         mov bl,replace
         mov [si+8],bl

         mov ah,4ch
         int 21h

main endp
    end main 
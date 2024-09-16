.model small
.stack 100h
.data
    var   dd 12345678h
    num   dw ?
    denom db ?
.code
main proc

         mov ax,@data
         mov ds,ax
         mov si,offset var
         mov ax,[si+2]
         mov bx,0
         mov bl,[si]
         div bx
         mov ah,4ch
         int 21h

main endp
    end main 
.model small
.stack 100h
.data
    var   dd 22345677h
    num   dw ?
    denom db ?
.code
main proc

         mov ax,@data
         mov ds,ax
         mov si,offset var
         mov ax,0
         mov al,[si+3]
         mov bx,0
         mov bl,[si]
         mul bx
         mov ah,4ch
         int 21h

main endp
    end main 
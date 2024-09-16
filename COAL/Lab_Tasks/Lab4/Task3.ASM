.model small
.stack 100h
.data
    var1 db 20h
.code
main proc
         mov ax,@data
         mov ds,ax

         mov si,offset var1
         mov bl,[si]
    
         mov ah,4ch
         int 21h

main endp
    end main
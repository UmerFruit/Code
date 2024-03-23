.model small
.stack 100h
.data
    var1 Db 3 dup('m'), 'Hello$'
    len  equ $ - var1
.code

main proc
         mov ax,@data
         mov ds,ax
         lea dx,var1
         mov ah,9
         int 21h

         mov dl,10
         mov ah,2
         int 21h

         mov dl,type var1
         add dl,48
         mov ah,2
         int 21h

         mov dl,10
         mov ah,2
         int 21h

         mov bl,len
         aam
         mov dl,bh
         add dl,'0'
         mov ah,2
         int 21h

         mov dl,bl
         add dl,'0'
         mov ah,2
         int 21h

         mov dl,10
         mov ah,2
         int 21h

         mov bl,size var1
         aam
         mov dl,bh
         add dl,48
         mov ah,2
         int 21h

         mov dl,bl
         add dl,48
         mov ah,2
         int 21h

         mov ah,4ch
         int 21h
main endp
end main
.model small
.stack 100h
.data

.code
main proc
         mov ax,@data
         mov ds,ax

         mov al,6
         mov bl,5
         cmp al,bl
         ja  l2
    l1:  
         inc bl
         ja  l3

    l2:  
         inc bl
         jz  l1
    l3:
        


         mov ah,4ch
         int 21h
main endp
end main
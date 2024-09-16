.model small
.stack 100h
.data
    arr  db 1,4,5,7,2
.code
main proc
         mov  ax,@data
         mov  ds,ax
         mov  cx,5
         mov  si,offset arr
         mov  ax,0
    l1:  
         add  al,[si]
         inc  si
         loop l1
         aam
         mov  bl,al
         mov  bh,ah
         mov  dl,bh
         add  dl,'0'
         mov  ah,2
         int  21h
         
         mov  dl,bl
         add  dl,'0'
         mov  ah,2
         int  21h

         mov  ah,4ch
         int  21h
main endp
    end main 
.model small
.stack 100h

.data
    msg1  db 10,13,'Enter Number: $'
    marks dw 5 dup(30)
    first db 0
    count dw 5

.code
main proc
               mov  ax, @data
               mov  ds, ax
               mov  cx, count
               mov  si, 0

               mov  dx, offset msg1
               mov  ah, 09h
               int  21h

               mov  ah, 01h
               int  21h

               sub  al, 30h
               mov  bh,10
               mul  bh
               mov  bh,al
                   
               mov  ah, 01h
               int  21h

               sub  al, 30h
                 
               mov  bl,al
               add  bl,bh
               mov  bh,0
                ;input num is now in bl
                mov cx,bx
                inc cx
                mov ax,bx
                mul cx
                mov cx,2
                div cx


               mov  bx,ax

               mov  ah, 09h
               int  21h
               
               mov  ax,bx
               aam
               mov  bl,al
               mov  al,AH
               mov  ah,0
               aam
               
               mov  cx,ax
               mov  ah, 02h
               mov  dl,ch
               add  dl,30h
               int  21h
               mov  dl,cl
               add  dl,30h
               int  21h
               mov  dl,bl
               add  dl,30h
               int  21h
               mov  dl,10
               int  21h
               mov  dl,13
               int  21h


               mov  ax, 4Ch
               int  21h
main endp
end main

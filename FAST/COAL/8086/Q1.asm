.model small
.stack 100h

.data
    msg1   db 10,13,'Enter price of item $'
    msg2   db 10,13,'Total bill: $'
    prices dw 5 dup(?)
    count  dw 5

.code
main proc
               mov  ax, @data
               mov  ds, ax

               mov  cx, count
               mov  si, 0
    input_loop:
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
               mov  prices[si], bx
               add  si,1
               loop input_loop

               mov  si, offset prices
               mov  ax, 0
               mov  cx,count
    calc_loop: 
               add  al,[si]
               inc  si
               loop calc_loop
               mov  dx, offset msg2
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

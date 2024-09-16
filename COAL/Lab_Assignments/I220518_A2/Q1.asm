.model small
.stack 100h
.data
    msg  db 10,13,"Enter 8 numbers : $"
    ad   db 10,13,"Sum = $"
    su   db 10,13,"Sub = $"
    mu   db 10,13,"Mul = $"
    divi db 10,13,"Div = $"
    nums db 8 dup(?)
      
.code
plus proc
             mov  bh,[si]
             inc  si
             mov  bl,[si]
             inc  si
             add  bl,bh
             mov  al,bl
             aam
             mov  bx,ax
             lea  dx,ad
             mov  ah,9
             int  21h
             mov  dl,bh
             add  dl,30h
             mov  ah,2
             int  21h
             mov  dl,bl
             add  dl,30h
             mov  ah,2
             int  21h
             ret
plus endp
min proc
             mov  bl,[si]
             inc  si
             mov  bh,[si]
             inc  si
             sub  bl,bh
             lea  dx,su
             mov  ah,9
             int  21h
              
             mov  dl,bl
             add  dl,30h
             mov  ah,2
             int  21h
             ret
min endp
prod proc
             mov  bh,[si]
             inc  si
             mov  bl,[si]
             inc  si
             mov  al,bl
             mul  bh
             aam
             mov  bx,ax
             lea  dx,mu
             mov  ah,9
             int  21h
             mov  dl,bh
             add  dl,30h
             mov  ah,2
             int  21h
             mov  dl,bl
             add  dl,30h
             mov  ah,2
             int  21h
             ret
prod endp
division proc
             mov  bh,[si]
             inc  si
             mov  bl,[si]
             inc  si
             mov  al,bh
             mov  ah,0

             div  bl
             aad
             mov  bx,ax
             lea  dx,divi
             mov  ah,9
             int  21h
             mov  dl,bl
             add  dl,30h
             mov  ah,2
             int  21h
             ret
division endp

main proc
             mov  ax,@data
             mov  ds,ax

             lea  dx,msg
             mov  ah,9
             int  21h

             lea  si,nums
             mov  cx,8
    input:   
             mov  ah,1
             int  21h
             sub  al,30h
             mov  [si],al
             inc  si
             loop input
             lea  si,nums
             call plus
             call min
             call prod
             call division
             mov  ah,4ch
             int  21h
main endp
end main

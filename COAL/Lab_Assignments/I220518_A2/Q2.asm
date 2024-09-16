.model small
.stack 100h
.data
      msg  db 10,13,"Enter number : $"
      i    dw 1
      n    dw 50
.code

main proc
                mov  ax,@data
                mov  ds,ax

                lea  dx,msg
                mov  ah,09h
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
                mov  n,bx
                mov  dl,10
                mov  ah,2
                int  21h

                mov  cl,0
                call Factors
      exi:      
                call printFacs

                mov  ah,4ch
                int  21h
    
main endp
Factors proc
      f:        
                mov  dx,0
                mov  ax,n
                div  i
                cmp  dx,0
                jz   print
                cmp  al,1
                jz   exi
                
      t:        
                inc  i
                mov  ax,i
                cmp  ax,n
                jnz  f
                jmp  exi
      
      print:    
                push i
                inc  cl
                jmp  t
     
Factors endp
printFacs proc
                pop  si
      printing: 
                pop  ax
                aam
                mov  dl,ah
                add  dl,30h
                mov  ah,2
                mov  bl,al
                int  21h
                mov  dl,bl
                add  dl,30h
                int  21h
                mov  dl,' '
                int  21h
                loop printing
                push si
                ret
printFacs endp
end main

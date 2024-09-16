.model small
.stack 100h
.data
      msg  db 10,13,"Enter numbers : $"
      a    db ?
      b    db ?
      c    db ?
      d    db ?
      e    db ?
      f    db ?
      g    db ?
.code

main proc
            mov  ax,@data
            mov  ds,ax
            call input
            mov  al,g
            cmp  al,f
            je   c2
      ;1st if
      c1:   
            mov  al,e
            cmp  al,d
            jne  c2
            jmp  exi
      c2:   
            mov  al,g
            cmp  al,d
            je   c4
      c3:   
      mov al,f
            cmp  al,e
            jle  c4
            jmp  exi
      c4:                      ; inside 2nd if
            mov al,a
            cmp  al,g
            ja   c5
            jmp  exi
      c5:   
            mov al,b
            cmp  al,e
            jbe  c6
            jmp  exi
      c6:                      ; inside 3rd if
            mov al,c
            cmp  al,a
            ja   c7
            jmp  exi
      c7:   
            mov al,e
            cmp  al,c
            jae  c8
            jmp  exi
      c8:   
            mov  dl,a
            add  dl,30h
            mov  ah,2
            int  21h
      exi:  
            mov  ah,4ch
            int  21h
    
main endp
input proc
            lea dx,msg
            mov ah,9
            int 21h

            mov  ah,1
            int  21h
            sub  al,30h
            mov  a,al
            
            mov  ah,1
            int  21h
            sub  al,30h
            mov  b,al

            mov  ah,1
            int  21h
            sub  al,30h
            mov  c,al

            mov  ah,1
            int  21h
            sub  al,30h
            mov  d,al

            mov  ah,1
            int  21h
            sub  al,30h
            mov  e,al

            mov  ah,1
            int  21h
            sub  al,30h
            mov  f,al

            mov  ah,1
            int  21h
            sub  al,30h
            mov  g,al

            mov dl,10
            mov ah,2
            int 21h
            ret
input endp
end main

.model small
.stack 100h
.data
    v1   db 6,2,5,8,2,1
    msg1 db 10,13,"E$"
    msg2 db 10,13,"O$"
    len  =  ($-v1+1)
.code
main proc
               mov  ax,@data
               mov  ds,ax
               mov cx,6
               mov  si,offset v1
    l1:        
               mov  al,[si]
               inc si
               and  al,1
               cmp  al,0
               jne  odd
               mov  ah,09h
               lea  dx,msg1
               int  21h
               jmp xd
    odd:       
               mov  ah,09h
               lea  dx,msg2
               int  21h
    xd:
            loop l1
    
    mov ah,4ch
    int 21h
               
main endp
    end main 
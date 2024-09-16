; print the grade according to the entered Number
; if marks>85 grade = A
; if marks>80 grade = A-
; if marks>75 grade = B+
; if marks>70 grade = B
; if marks>65 grade = B-
; if marks>60 grade = C+
; else fail
.model small
.stack 100h
.data
     msg1 db 10,13,"Enter marks: $"
     msg2 db 10,13,"Your Grade is: $"

.code
main proc
          mov ax,@data
          mov ds,ax
         
          lea dx,msg1
          mov ah,09h
          int 21h

          mov ah,01h
          int 21h
          sub al,30h
          mov bl,10
          mul bl
          mov bh,al

          mov ah,01h
          int 21h
          sub al,30h
          add bh,al

          mov ah,09h
          lea dx,msg2
          int 21h
          mov ah,02h
          cmp bh,85
          ja  f1
          cmp bh,80
          ja  f2
          cmp bh,75
          ja  f3
          cmp bh,70
          ja  f4
          cmp bh,65
          ja  f5
          cmp bh,60
          ja  f6

          jmp f7
         
     f1:  

          mov dl,'A'
          int 21h
          jmp f8
     f2:  
          mov dl,'A'
          int 21h
          mov dl,'-'
          int 21h
          jmp f8
     f3:  
          mov dl,'B'
          int 21h
          mov dl,'+'
          int 21h
          jmp f8
     f4:  
          mov dl,'B'
          int 21h
          jmp f8
     f5:  
          mov dl,'B'
          int 21h
          mov dl,'-'
          int 21h
          jmp f8
    
     f6:  
          mov dl,'C'
          int 21h
          mov dl,'+'
          int 21h
          jmp f8
     f7:                   ;else
          mov dl,'F'
          int 21h
          jmp f8
     f8:  
          mov ah,4ch
          int 21h
main endp
end main
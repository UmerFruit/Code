.model small
.stack 100h
.data
  n1        db ?
  n2        db ?
  n3        db ?
  sum       dw ?
  numberStr DB 8 DUP (0)
  msg       db 10,13,"Sum is $"
.code
num2str PROC
                mov  bx, 10
                mov  cx, 0
  countDigits:  
                mov  dx, 0
                div  bx
                push dx
                inc  cx
                cmp  ax,0
                jnz  countDigits
  stringConvert:
                pop  dx
                add  dl, '0'
                mov  [si], dl
                inc  si
                loop stringConvert
                               
                mov  [si],BYTE PTR '$'
                ret
num2str ENDP
square proc
                mov  bx,0

                mov  al,n1
                mul  al
                add  bx,ax

                mov  al,n2
                mul  al
                add  bx,ax

                mov  al,n3
                mul  al
                add  bx,ax

                mov  ax,bx
                lea  si,numberStr
                call num2str
                ret  2
square endp
main proc
                mov  ax, @data
                mov  ds, ax

                mov  ah,1
                int  21h
                sub  al,30h
                mov  n1,al

                mov  ah,1
                int  21h
                sub  al,30h

                mov  n2,al

                mov  ah,1
                int  21h
                sub  al,30h

                mov  n3,al

                call square
                               
                lea  dx,msg
                mov  ah,9
                int  21h

                lea  dx,numberStr
                mov  ah,9
                int  21h

                mov  ah,4ch
                int  21h
main endp
end main

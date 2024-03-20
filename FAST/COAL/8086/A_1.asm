.model small
.stack 100h
.data 
str1 db 10,13,"Enter the number : $"
.code
main proc
        mov ax,@data
        mov ds,ax
        mov ah,9
        lea dx,str1
        int 21h
        mov ah,1
        int 21h
        sub al,30h
        mov cx,0
        mov bx,0
        mov cl,al
        mov bl,al
        mov dl,10
        mov ah,2
        int 21h
        l1:

        l2:
        mov dl,"*"
        mov ah,2
        int 21h

        loop l2
        mov dl,10
        mov ah,2
        int 21h
        dec bx
        mov cx,bx

        loop l1
        

        mov ah,4ch
        int 21h
       

main endp
end main

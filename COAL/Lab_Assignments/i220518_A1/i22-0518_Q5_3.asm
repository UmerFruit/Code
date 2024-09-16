.model small
.stack 100h
.data 
msg db 10,13,"Enter the number : $"
var db ?
.code
main proc
        mov ax,@data
        mov ds,ax
        mov ah,9
        lea dx,msg
        int 21h
        mov ah,1
        int 21h
        sub al,30h
        mov var,al
        mov cx,0
        mov cl,al
        mov bl,1
        mov ah,2
        mov bh,al
        mov dl,10
        int 21h
        l1:        
        mov dl,' '
        space:
        int 21h
        loop space
        mov cl,bl
        
        l3:
        mov dl,'*'
        int 21h
        mov dl,' '
        int 21h
        loop l3
        
        mov dl,10
        int 21h
        mov dl,13
        int 21h
        add bl,1
        mov cl,bh
        dec bh
        loop l1

        mov cl,2
        mov bh,3
        mov bl,var
        dec bl
        inc var
        inc var

        p1:
        mov dl,' '
        space2:
        int 21h
        loop space2
        mov cl,bl

        p2:
        mov dl,'*'
        int 21h
        mov dl,' '
        int 21h
        loop p2

        mov dl,10
        int 21h
        mov dl,13
        int 21h
        dec bl
        inc bh
        mov cl,bh
        

        cmp bh,var
        je ex
        loop p1

        ex:
        mov ah,4ch
        int 21h
main endp
end main


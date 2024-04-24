; input 2 digit hexadecimal number and print it in decimal
.model small
.stack 100h
.data
    msg1 db 10,13,"Enter Number (hex lowercase only): $"
.code
main proc
         mov ax,@data
         mov ds,ax

         lea dx,msg1
         mov ah,09h
         int 21h
         
         mov ah,01h
         int 21h
 
         cmp al,'a'
         jae f1
         jmp f3
    f1:  
         cmp al,'f'
         jbe f2
         jmp f3
    f2:  
         sub al,'a'
         add al,10
         jmp f4
    f3:  
         sub al,30h
    f4:  
         mov bl,16
         mul bl
         mov bh,al

         mov ah,01h
         int 21h

         cmp al,'a'
         jae f5
         jmp f7
    f5:  
         cmp al,'f'
         jbe f6
         jmp f7
    f6:  
         sub al,'a'
         add al,10
         jmp f8
    f7:  
         sub al,30h
    f8:  
         add bh,al       ;BH has number
        mov ax,0
         mov al,bh
        aam
        mov bl,al
        mov al,ah
        mov ah,0
        aam

        mov ch,ah
        mov cl,al
        mov ah,02h
        mov dl,10
        int 21h
        mov dl,ch
        add dl,30h
        int 21h
        mov dl,cl
        add dl,30h
        int 21h
        mov dl,bl
        add dl,30h
        int 21h

        

         mov ah,4ch
         int 21h
main endp
end main
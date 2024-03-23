;Program in Assembly Language Read Three Numbers from User and Display Smallest Number
.model small
.stack 100h
.data
    msg3 db 10,13,'They are equal.$'
    msg4 db 10,13,'Largest Number is : $'
   
.code

main proc
            mov ax,@data
            mov ds,ax
               
            mov ah,01h
            int 21h

            sub al,'0'
            mov bl,al

            mov ah,01h
            int 21h
            mov bh,al
            sub bh,'0'

            cmp bh,bl

            jz  equal
            ja  greater
            jb  less

    equal:  
            mov dx,offset msg3
            mov ah,09h
            int 21h
            mov ah,4ch
            int 21h
    less:   
            mov dx,offset msg4
            mov ah,09h
            int 21h
            mov dl,bl
            add dl,'0'
            mov ah,02
            int 21h
            mov ah,4ch
            int 21h
    greater:
            mov dx,offset msg4
            mov ah,09h
            int 21h
            mov dl,bh
            add dl,'0'
            mov ah,02
            int 21h
            mov ah,4ch
            int 21h
       

main endp
end main

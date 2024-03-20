.model small
.stack 100h

.data
    msg1   db 10,13,'Enter price of item $'
    msg2   db 10,13,'Total bill: $'
    prices dw 5 dup(?)
    count  dw 5

.code
main proc
         mov ax, @data
         mov ds, ax
         mov ax,0
         mov ax,23fh
         mov bh,AH
         mov ah,0
         aam
         mov cx,ax
         mov al,bh
         mov si,16
         mul si
         aam
         
         add ch,al
         mov bl,ah
         ;testing posibility 1
         mov ah,0
         mul si
         aam
         
         mov bl,al
         mov al,AH
         mov ah,0
         aam

         mov ax, 4Ch
         int 21h
main endp
end main

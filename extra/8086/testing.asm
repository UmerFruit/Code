.model small
.stack 100h
.data
b1 db 5,4,3,2,1
b2 db 9,0ah,0bh,0ch
w1 dw 1,2,3
w2 dw 0aaaah,0bbbbh,0cccch
.code
main proc

    mov ax,@data
    mov ds,ax
    mov ax,0
    mov al,b1
    add al,b2
    mov ah,[b1+1]
    add ah,[b2+1]
    mov bh,[b1+2]
    add bh,[b2+2]
    mov bl,[b1+5]
    add bl,[b2+5]
    mov cx,w1
    mov dx,[w1+2]
    mov si,[w1+4]
    add cx,w2
    add dx,[w2+2]
    add si,[w2+4]
    
main endp
    end main
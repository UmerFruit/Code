;display a pixel

;for video mode
.model small
.stack 100h
.data
xcord dw 200
ycord dw 150
.code
main proc
;set graphic mode
mov ax,@DATA
mov ds,ax
mov ah, 0h ;set video mode
mov al,6h ; resolution 200*640 B\W graphics
int 10h
;accessing and displaying pixel
mov cx,200
l1:
push cx
mov ah, 0ch
mov al, 0fh ; white color
mov cx, xcord ; column 0 to 639
mov dx, ycord ; row 0 to 199
inc xcord
int 10h
pop cx
loop l1

mov cx,100
l2:
push cx
mov ah, 0ch
mov al, 0fh ; white color
mov cx, xcord ; column 0 to 639
mov dx, ycord ; row 0 to 199
sub xcord,1
dec ycord
int 10h
pop cx
loop l2

mov cx,100
l3:
push cx
mov ah, 0ch
mov al, 0fh ; white color
mov cx, xcord ; column 0 to 639
mov dx, ycord ; row 0 to 199
dec xcord
inc ycord
int 10h
pop cx
loop l3


mov ah, 4ch
int 21h
main endp
end main

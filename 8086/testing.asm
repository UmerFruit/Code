.model small
.stack 100h
.data
v1 db 01h,25h,85h,21h,90h,1Ah,0Dh,0ffh,0Eh,0CCh
.code
main proc

    mov ax,@data
    mov ds,ax
    mov ax,word ptr [v1+2]
    mov eax,dd ptr [v1+8]
    mov eax,dd ptr [v1+5]
    mov ax,word ptr [v1+9]
    mov ax,db ptr v1

    mov ah,4ch
    int 21h

main endp
    end main
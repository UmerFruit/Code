; a hardcoded array is given having alphanumeric characters
; seperate the alphabets from the numbers in 2 seperate array and display it
.model small
.stack 100h
.data
arr db "I am James Bond,007. I was born in 1920.$"
nums db 7 dup(0)
letters db 33 dup(0)
.code
main proc
    mov ax,@data
    mov ds,ax

    lea si,arr
    mov cx,40
    mov bx,0
    mov dx,0
    l1: 
        mov al,[si]
        cmp al,'0'
        jae f1
        jmp f3
        f1:
            cmp al,'9'
            jbe f2
            jmp f3
        f2:
            push si
            lea si,nums
            add si,bx
            mov [si],al
            inc bl
            pop si
            jmp f10
        f3:
            push si
            lea si,letters
            add si,dx
            mov [si],al
            inc dx
            pop si
            jmp f10
  
        f10:
        inc si
        loop l1
    
    mov cx,7
    lea si,nums
    l2:
        mov ah,02h
        mov dl,[si]
        int 21h
        inc si
        loop l2
    mov cx,33
    lea si,letters
    l3:
        mov ah,02h
        mov dl,[si]
        int 21h
        inc si
        loop l3



    mov ah,4ch
    int 21h
main endp
end main
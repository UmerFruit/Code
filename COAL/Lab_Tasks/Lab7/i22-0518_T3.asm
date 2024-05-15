.model small
.stack 100h
.data
    msg  db "umer farooq$"
.code
toupper proc
    l1:     
            sub  [si],BYTE PTR 32
            inc  si
            loop l1
            ret  2
toupper endp

main proc
            mov  ax, @data
            mov  ds, ax
            lea  si, msg
            mov  cx,11
           
            call toupper
            
            mov  ah,9
            lea  dx, msg
            int  21h
            
            mov  ah,4ch
            int  21h
main endp
end main

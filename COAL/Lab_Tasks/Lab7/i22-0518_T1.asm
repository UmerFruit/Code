.model small
.stack 100h
.data
     arr1 db 2, 5, 1, 6,4
     arr2 db 5 dup(?)
.code
rev proc
             pop  si
             lea  di,arr2
             mov  cx,5
     retrive:
             pop  [di]
             inc  di
             loop retrive
             
             push si
             ret
rev endp

main proc
             mov  ax, @data
             mov  ds, ax
             mov  cx,5
             lea  si,arr1
     storing:
             push [si]
             inc  si
             loop storing

             call rev

             lea  si,arr2
             mov  cx,5
     l2:     
             mov  dl,[si]
             add  dl,30h
             mov  ah,02h
             int  21h
             add  si,1
             loop l2
             mov  ah,4ch
             int  21h
main endp
end main

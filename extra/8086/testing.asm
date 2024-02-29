.model small
.stack 100h
.data

arr1 db 1,2,3,4,5
      6,4,3,2
    db 2,2,4
.code
main proc

    mov ax,@data
    mov ds,ax
    mov ah,lengthof arr1


    

    
main endp
    end main
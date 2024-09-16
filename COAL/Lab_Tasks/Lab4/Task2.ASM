.model small
.stack 100h
.data
    arr1 db 1,2,3,4,5
.code
main proc

         mov  ax,@data
         mov  ds,ax
         
         mov  cx,5
         mov  si,offset arr1
         mov  ax,0
    sum: 
         add  al,[si]
         add  si,2
         loop sum
    
         mov  ah,4ch
         int  21h

main endp
    end main 
;Create an Array of 10 elements. Then take a numbers and check if the numbers are in the array. If found display “FOUND” in a variable else store “NOT FOUND”
.model small
.stack 100h
.data
    array  db 1,2,3,4,5,6,7,8
    number db 9
    result db ?
    msg1   db 'FOUND$'
    msg2   db 'NOT FOUND$'
.code
main PROC
           mov  ax,@data
           mov  ds,ax
           mov  cx,8
           mov  si, offset array
    search:
           mov  al,[si]
           mov dl,al
        
           cmp  number,al
           je   found
           
           inc  si
           loop search
           lea  dx,msg2
           mov  ah,9
           int  21h
           jmp  next
    
    found: 
           lea  dx,msg1
           mov  ah,9
           int  21h
           jmp next
    next:  
           mov  ah,4ch
           int  21h
    
           
main endp
end main

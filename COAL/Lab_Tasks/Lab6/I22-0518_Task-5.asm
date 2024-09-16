.model small
.stack 100h
.data
  arr  db 2,1,3,6,8
.code
main proc
              mov  ax,@data
              mov  ds,ax
    
              mov  si,offset arr
              mov  cx,5
              mov  bl,[si]
  LoopA:      
              cmp  [si],bl
              jle  not_largest    ; If element is less than or equal to the current largest, skip
              mov  bl,[si]        ; Update the current largest if necessary
  not_largest:
              inc  si
              loop LoopA
    
              add  bl,48          ; Convert the largest element to ASCII for output
              mov  dl,bl
              mov  ah,2
              int  21h
    
              mov  si,offset arr
              mov  cx,4
              mov  bl,[si]
    
  LoopB:      
              cmp  [si],bl
              jge  not_smol       ; If element is greater than or equal to the current smallest, skip
              mov  bl,[si]        ; Update the current smallest if necessary
  not_smol:   
              inc  si
              loop LoopB
    
              add  bl,48          ; Convert the smallest element to ASCII for output
              mov  dl,bl
              mov  ah,2
              int  21h
              
              mov  ah, 4Ch
              int  21h
    
main endp
end main

.model small
.stack 100h
.data
    arr  db 0,1,2,3,4,5,6,7,8,9
.code
main proc
          mov  ax,@data
          mov  ds,ax
    
          mov  cx,10
          lea  si,arr
    print:
          mov  dl,[si]
          add  dl,30h
          mov  ah,2
          int  21h
          inc  si
          loop print
    
          mov  ah,4ch
          int  21h
main endp
    end main
end

.model small
.stack 100h
.data
arr db "abcdegfhijklmnopqrstuvwxyz"
   
.code
main proc
         
          mov  ax,@data
          mov  ds,ax

          mov  cx,26
          lea  si,arr
    print:
          mov  dl,[si]
          mov  ah,02h
          int  21h
          inc  si
          loop print

          mov  ah,4ch
          int  21h
main endp
    end main
end

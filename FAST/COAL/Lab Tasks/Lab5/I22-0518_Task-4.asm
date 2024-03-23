.model small
.stack 100h
.data
    arr  db 65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90
.code
main proc
         mov  ax,@data
         mov  ds,ax
         mov  cx,25
         mov  si,0
         mov  ah,2
         mov  dl,0ah
         int  21h
         mov  dl,0dh
         int  21h
    L1:  
         mov  dl,arr[si]
         int  21h
         inc  si
         loop L1
         mov  ah,4ch
         int  21h
main endp
    end main
end

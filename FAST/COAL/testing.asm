.MODEL SMALL 
.STACK 100H 
.DATA
     DIGIT1 DB 0AH, 0DH, "ENTER FIRST DIGIT: $"
     DIGIT2 DB 0AH, 0DH, "ENTER SECOND DIGIT: $"
     RESULT DB 0AH, 0DH, "RESULT IS $"
.CODE
     MAIN:
          MOV AX, @DATA
          MOV DS, AX
         
          LEA DX, DIGIT1
          MOV AH, 09H
          INT 21H
         
     ;    MOV AH, 01H
     ;    INT 21H
          mov al,'8'
          SUB AL, 30H
          MOV BH, AL
         
     ;    MOV AH, 01H
     ;    INT 21H
          mov al,'7'
         
          SUB AL, 30H
          MOV BL, AL                ; BH:BL FIRST NUMBER
         
          LEA DX, DIGIT2
          MOV AH, 09H
          INT 21H
         
     ;    MOV AH, 01H
     ;    INT 21H
          mov al,'8'
         
          SUB AL, 30H
          MOV CH, AL
         
     ;    MOV AH, 01H
     ;    INT 21H
          mov al,'7'
          SUB AL, 30H
          MOV CL, AL                ; CH:CL SECOND NUMBER
         
          ADD BL, CL
         
          MOV AL, BL
          MOV AH, 00H
          AAA
         
          MOV CL, AL                ; LAST DIGIT OF ANSWER
          MOV BL, AH
         
          ADD BL, BH
          ADD BL, CH
         
          MOV AL, BL
          MOV AH, 00H
          AAA
         
          MOV BX, AX
          mov al,'8'
          SUB AL, 30H
          mov dh,al
          mov al,'7'
          SUB AL, 30H
          mov ch,al
          
          add dh,cl
          mov al,dh
          mov ah,00h
          aaa
          mov cl,al
          mov dh,bl
          add dh,AH
          add dh,bh
          add dh,ch
          
          mov al,dh
          mov ah,00h
          aaa
          add bl,al
          add bl,ah
          add bl,bh
          mov al,bl
          mov ah,00h
          aaa
          mov bl,al
          add bh,ah

          MOV DX, OFFSET RESULT
          MOV AH, 09H
          INT 21H
         
          MOV DL, BH
          ADD DL, 30H
          MOV AH, 02H
          INT 21H
         
          MOV DL, BL
          ADD DL, 30H
          MOV AH, 02H
          INT 21H
         
          MOV DL, CL
          ADD DL, 30H
          MOV AH, 02H
          INT 21H
     EXIT:
          MOV AH, 04CH
          INT 21H
    END MAIN     

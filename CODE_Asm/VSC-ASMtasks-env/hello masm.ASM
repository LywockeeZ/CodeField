; .586
DATA SEGMENT; use16
        MESG DB 'hello masm','$'
DATA ENDS
CODE SEGMENT; USE16
    ASSUME CS:CODE,DS:DATA
BEG:    MOV AX,DATA
        MOV DS, AX
LAST:   MOV AH,9
        MOV DX, OFFSET MESG
        INT 21H
        MOV AH,4CH
        INT 21H;BACK TO DOS
        
CODE ENDS
END  BEG

INIT53:
        MOV DX, 0D0D3H          ;写控制字
        MOV AL, 00110110B       ;计数器0的方式字
        OUT DX, AL
        MOV AL, 200
        MOV DX, 0D0D0H          ;计数器0写计数值的地址
        OUT DX, AL              ;低8位
        MOV AL, 0
        OUT DX, AL              ;高8位
        MOV DX, 0D0D3H
        MOV AL, 01110100B       ;计数器1的方式字
        OUT DX, AL
        MOV DX, 0D0D1H          ;计数器1写计数值的地址
        MOV AX, 10000
        OUT DX, AL              ;低八位写入
        MOV AL, AH
        OUT DX, AL              ;高八位写入
        MOV DX, 0D0D3H
        MOV AL, 10110100B       ;计数器2的方式字
        OUT DX, AL
        MOV DX, 0D0D2H          ;计数器2写计数值的地址
        MOV AL, 10
        OUT DX, AL
        MOV AL, 0
        OUT DX, AL

;初始化程序
INIT55: MOV DX, 0FE06H          ;控制寄存器
        MOV AL, 10011010B       ;A口方式0，输入
        OUT DX, AL              ;C口高输入，低输出
        MOV AL, 0
        OUT DX, AL
;数据采集程序
ACQUQ:  MOV DX, SEG DATA
        MOV DS, DX
        LEA SI, DATA
        MOV DX, 0FE04H          ;C口
        MOV AL, 01H
        OUT DX, AL
        CALL Delay1us
        MOV AL, 00H
        OUT DX, AL
        NOP
WAIT:   IN  AL, DX
        TEST AL, 80H
        JZ  WAIT
        MOV DX, 0FE00H          ;A口
        IN  AL, DX
        MOV [SI], AL

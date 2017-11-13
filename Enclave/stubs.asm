.CODE

EXTERN ocall_generic : PROC


myprintf PROC EXPORT
mov rax, 0900000000h
mov [rax + 0f8h], rsp
mov rsp, [rax + 0e8h]
sub rsp, 28h
call ocall_generic
mov rcx, 0900000000h
mov rsp, [rcx + 0f8h]
ret
myprintf ENDP

END

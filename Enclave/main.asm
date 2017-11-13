.CODE

EXTERN main : PROC
EXTERN ocall_generic : PROC

ecall_main PROC EXPORT
;mov gs:[0e8h], rsp
;mov rsp, gs:[0f8h]
;mov	rax, gs:[0f0h]
mov rcx, 1
sub rsp, 28h
call main
add rsp, 28h
;mov rsp, gs:[0e8h]
ret
ecall_main ENDP

END

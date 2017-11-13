.CODE

EXTERN main : PROC
EXTERN main1 : PROC
EXTERN ocall_generic : PROC

main2 PROC
ret
main2 ENDP

ecall_main PROC EXPORT
mov rax, 0900000000h
mov [rax + 0e8h], rsp
mov rsp, [rax + 0f8h]
sub rsp, 28h
call main
add rsp, 28h
mov rcx, 0900000000h
mov rsp, [rcx + 0e8h]
ret
ecall_main ENDP

END

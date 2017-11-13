.CODE

EXTERN ocall_generic : PROC


printf PROC EXPORT
mov rax, 0900000000h
mov [rax], rcx
mov [rax + 8], rdx
mov [rax + 16], r8
mov [rax + 24], r9
mov qword ptr [rax + 32], 1
mov r10, [rsp]
mov [rax + 40], r10

mov [rax + 0f8h], rsp
mov rsp, [rax + 0e8h]
sub rsp, 28h

lea rcx, [rax + 64]
mov rdx, 1

call ocall_generic

mov rcx, 0900000000h
mov rsp, [rcx + 0f8h]
mov rdx, [rcx + 40]
mov rax, [rcx + 64]
mov [rsp], rdx

ret
printf ENDP

END

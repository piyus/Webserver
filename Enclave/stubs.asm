.CODE

EXTERN ocall_generic : PROC


myprintf PROC EXPORT
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

call ocall_generic

mov rcx, 0900000000h
mov rsp, [rcx + 0f8h]
mov rdx, [rcx + 40]
mov [rsp], rdx

ret
myprintf ENDP

END

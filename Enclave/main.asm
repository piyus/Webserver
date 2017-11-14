.CODE

EXTERN main : PROC
EXTERN ocall_generic : PROC
EXTERN copy_globals: PROC

EnableMpx PROC EXPORT
bndmk bnd1, qword ptr [rdx + r9]
bndmk bnd0, qword ptr [r8 + 0200000h]
;xor rax, rax
;bndcl bnd0, rax
ret
EnableMpx ENDP


ecall_main PROC EXPORT
mov rax, 0900000000h
mov [rax + 0e8h], rsp
mov rsp, [rax + 0f8h]
sub rsp, 28h
call copy_globals
mov rcx, 1
call main
add rsp, 28h
mov rcx, 0900000000h
mov rsp, [rcx + 0e8h]
ret
ecall_main ENDP

END

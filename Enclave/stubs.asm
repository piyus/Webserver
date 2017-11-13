.CODE

EXTERN ocall_generic : PROC


myprintf PROC EXPORT
;mov r10, gs:[0f0h]
;mov [r10], rcx
;mov [r10+8], rdx
;mov [r10+16], r8
;mov [r10+24], r9
;mov [r10+32], rsp
;mov rsp, gs:[0f8h]
mov rcx, 1
sub rsp, 28h
call ocall_generic
add rsp, 28h
;mov r10, gs:[0f0h]
;mov rsp, [r10+32]
ret
myprintf ENDP

END

.CODE

; LauncApp  func, stack

LaunchApp PROC EXPORT
mov rax, 0900000000h
mov [rax + 48], rsp
mov r11, rcx
mov rsp, [rax + 0f8h]
mov rcx, next
mov [rsp], rcx
mov rcx, [rax]
mov rdx, [rax+8]
mov r8, [rax+16]
mov r10, [rax+24]
jmp r11
next:
mov rcx, 0900000000h
mov rsp, [rcx + 48]
ret
LaunchApp ENDP



END

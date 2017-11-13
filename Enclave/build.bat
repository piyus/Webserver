%CCP%\clang -m64 -S -emit-llvm -fno-builtin -fno-jump-tables %1.c -o %1.ll
%CCP%\opt --instnamer --annotations-inference %1.ll -o %1_reg.ll
%CCP%\llc --generate-sgx-code --code-model=large %1_reg.ll -o %1_reg.s
%CCP%\clang -m64 -c %1_reg.s -o %1.o

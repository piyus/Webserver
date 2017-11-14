python gen_wrappers.py functions.txt functions.asm functions.h
move functions.h app\
move functions.asm enclave
cd enclave
set CCP=C:\Users\piyus\asplos\build\Release\bin
rem call build.bat main
call build.bat mongoose
call build.bat simplest_web_server
rem ar -ru main.a mongoose.o simplest_web_server.o
rem rem move main.a main.o
rem call build hello
rem ar -ru main.a hello.o
rem move main.a main.o
rem move hello.o main.o 

rem ar -ru main.a C:\Users\piyus\sgxc_support\sgx_start.o main.o C:\Users\piyus\sgxc_support\sgx_end.o 
rem 
rem move main.a main.o



ml64 -c main.asm
ml64 -c stubs.asm
cl -c library.c

cd ..
cd app
ml64 -c app_asm.asm
cd ..
msbuild SampleEnclave.sln


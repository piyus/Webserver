extern unsigned long long _sgx_public_globals_start;
extern unsigned long long _sgx_public_globals_end;
int printf (const char*, ...);
void copy_globals(void){
	char * start = (char*)&_sgx_public_globals_start;
	char * stop = (char*)&_sgx_public_globals_end;
	char *dest = (char*)0xa00000000;
	//char fmt[] = "%c\n";
	for (start; start<stop; start++, dest++){
		//printf(fmt, *start);
		*dest = *start;
	}
	return;
}

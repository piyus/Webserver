extern unsigned long long _sgx_public_globals_start;
extern unsigned long long _sgx_public_globals_end;
int printf (const char*, ...);


extern void* malloc(size_t);
extern void EnableMpx(unsigned char*, unsigned char*, unsigned char*, size_t);
#define MPX_ALIGNMENT 64
#define PAGE_SIZE 4096
#define ALIGN(x, y) (size_t)(((size_t)(x) + (size_t)(y) - 1) & ~((size_t)(y) - 1))
unsigned char g_MpxBuf[PAGE_SIZE + MPX_ALIGNMENT];
void* memset(void*,int,size_t);
#define NULL (void*)0
unsigned char* private_stack;

void copy_globals(void)
{
	unsigned char* ret = private_stack;
    EnableMpx(NULL, ret + (128<<20), ret, 0x1);
	char * start = (char*)&_sgx_public_globals_start;
	char * stop = (char*)&_sgx_public_globals_end;
	char *dest = (char*)0xA0000000000;
	//char fmt[] = "%c\n";
	for (start; start<stop; start++, dest++){
		//printf(fmt, *start);
		*dest = *start;
	}
	return;
}


unsigned long long ecall_big_malloc()
{
	unsigned char* ret = (unsigned char*)malloc(4096*32);
	private_stack = ret;
    //EnableMpx(NULL, ret + (128<<20), ret, 0xfffffffffff);
   // EnableMpx(NULL, ret + (128<<20), ret, 0x1);
	return (unsigned long long)ret;
}

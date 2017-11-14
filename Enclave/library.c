#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <io.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


#define PUBLIC_LOWER	(void*)0x0
#define PUBLIC_UPPER	(void*)0xffffffffffffffff
#define PRIVATE_LOWER	(void*)0x0
#define PRIVATE_UPPER	(void*)0xffffffffffffffff
/*
#define PUBLIC_LOWER	(void*)0x3000000000
#define PUBLIC_UPPER	(void*)0x3100000000
#define PRIVATE_LOWER	(void*)0x3A00000000
#define PRIVATE_UPPER	(void*)0x3B00000000
*/
#include <windows.h>


/*struct _iobuf_real {
        char *_ptr;
        int   _cnt;
        char *_base;
        int   _flag;
        int   _file;
        int   _charbuf;
        int   _bufsiz;
        char *_tmpfname;
}; 
*/
void assert_public(const void* s){
	if(s < PUBLIC_LOWER || s >= PUBLIC_UPPER){
		printf("Public out of bound access at %p\n", s);
		exit(-1);
	}
}

void assert_private(const void* s){
	if(s < PRIVATE_LOWER || s >= PRIVATE_UPPER){
		printf("Private out of bound access at %p\n", s);
		exit(-1);
	}
}

int get_encrypt_length(const char *t, size_t n){
	return n*2;
}

int is_private_file(const char* path){
	int length = strlen(path);
	if(strcmp(".ptxt" , &path[length-5])==0)
		return 1;
	return 0;
}

int encrypt(char * dest, const char *src, size_t n ) {
	int i;
	for(i=0;i<n; i++) {
		dest[i]='*';
	}
	return 0;
}

enum fd_type {
	UNDEFINED=0, PUBLIC, PRIVATE
};

static enum fd_type fds_type[2050] = {0};


FILE* fopen__wrapper(const char* filename, const char * mode) {
	FILE* ret = fopen(filename, mode);
	if(is_private_file(filename))
		fds_type[_fileno(ret)] = PRIVATE;
	else
		fds_type[_fileno(ret)] = PUBLIC;
	return ret;
}

int fclose__wrapper(FILE* stream) {
	int fd = _fileno(stream);
	int ret = fclose(stream);
	if (ret==0)
		fds_type[fd] = UNDEFINED;
	return ret;
}

size_t fread__wrapper( void * ptr, size_t size, size_t count, FILE * stream ) {
	assert_public(ptr);
	assert_public((char*)ptr + size*count);
	enum fd_type type = fds_type[_fileno(stream)];
	if(type == UNDEFINED){
		printf("Attempting read on unknown file\n");
		exit(-1);
	}else if(type == PRIVATE) {
		printf("Attempting to read private file with public_read\n");
		exit(-1);
	}
	return fread(ptr, size, count, stream);
}

void* mymalloc(size_t);
size_t fread_private__wrapper ( void * ptr, size_t size, size_t count, FILE * stream ) {

/*	
	assert_private(ptr);
	assert_private((char*)ptr + size*count);
	enum fd_type type = fds_type[_fileno(stream)];
	if(type == UNDEFINED){
		printf("Attempting read on unknown file\n");
		exit(-1);
	}else if(type == PUBLIC) {
		printf("Attempting to read public file with private_read\n");
		exit(-1);
	}
	*/
	char *public_ptr = mymalloc(size * count);
	int ret = fread(public_ptr, size, count, stream);
	myfree(public_ptr);
	return ret;
}



/*

#include <stdio.h>
#include <windows.h>

unsigned long long init_readrdtsc__wrapper__inner(void){
	LARGE_INTEGER sysFreq;
	unsigned long long microFreq;
	QueryPerformanceFrequency(&sysFreq);
	microFreq = sysFreq.QuadPart/1000;
	printf("microFreq initialized as = %llu\n", microFreq);
	return microFreq;
}



unsigned long long readrdtsc__wrapper__inner(void) {
	 unsigned long long lo, hi;
	 __asm__( "rdtsc" : "=a" (lo), "=d" (hi) ); 
	 return( lo | (hi << 32) );
}*/


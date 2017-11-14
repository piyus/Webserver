


#define _beginthread (void*)1
//#define _gmtime64 (void*)2
//#define _rmdir (void*)4

#include <time.h>
#include <direct.h>
#include <assert.h>


#pragma comment(lib, "Ws2_32.lib")
#pragma warning(disable:4996)


#define _wassert assert

extern "C" {
void* mymalloc(size_t);
void* mycalloc(size_t, size_t);
void* myrealloc(void*, size_t);
void myfree(void*);

}


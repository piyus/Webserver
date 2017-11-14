#include "includes.h"
void* function_pointers[] = {
	NULL,
	(void*)CloseHandle, // 1
	(void*)CreatePipe, // 2
	(void*)CreateProcessW, // 3
	(void*)DuplicateHandle, // 4
	(void*)FindClose, // 5
	(void*)FindFirstFileW, // 6
	(void*)FindNextFileW, // 7
	(void*)GetCurrentProcess, // 8
	(void*)GetFileAttributesW, // 9
	(void*)GetFullPathNameW, // 10
	(void*)GetLastError, // 11
	(void*)GetLocalTime, // 12
	(void*)GetStdHandle, // 13
	(void*)MultiByteToWideChar, // 14
	(void*)ReadFile, // 15
	(void*)RegCloseKey, // 16
	(void*)RegEnumKeyExW, // 17
	(void*)RegOpenKeyExW, // 18
	(void*)RegQueryValueExW, // 19
	(void*)SetHandleInformation, // 20
	(void*)SetLastError, // 21
	(void*)Sleep, // 22
	(void*)SystemTimeToFileTime, // 23
	(void*)WSAGetLastError, // 24
	(void*)WSAStartup, // 25
	(void*)WideCharToMultiByte, // 26
	(void*)WriteFile, // 27
	(void*)__WSAFDIsSet, // 28
	(void*)__acrt_iob_func , // 29
	(void*)__stdio_common_vfprintf , // 30
	(void*)__stdio_common_vsprintf, // 31
	(void*)__stdio_common_vsscanf, // 32
	(void*)_atoi64, // 33
	(void*)_beginthread, // 34
	(void*)_errno, // 35
	(void*)_fileno, // 36
	(void*)_gmtime64, // 37
	(void*)_localtime64, // 38
	(void*)_rmdir, // 39
	(void*)_strdup, // 40
	(void*)_wfopen, // 41
	(void*)_wopen, // 42
	(void*)_wstat64, // 43
	(void*)accept, // 44
	(void*)bind, // 45
	(void*)closesocket, // 46
	(void*)connect, // 47
	(void*)fclose, // 48
	(void*)fflush, // 49
	(void*)fgetc, // 50
	(void*)fgets, // 51
	(void*)fputc, // 52
	(void*)fputs, // 53
	(void*)fread, // 54
	(void*)fseek, // 55
	(void*)fwrite, // 56
	(void*)getenv, // 57
	(void*)getpeername, // 58
	(void*)getsockname, // 59
	(void*)getsockopt, // 60
	(void*)htonl, // 61
	(void*)htons, // 62
	(void*)inet_ntoa, // 63
	(void*)ioctlsocket, // 64
	(void*)listen, // 65
	(void*)ntohl, // 66
	(void*)ntohs, // 67
	(void*)rand, // 68
	(void*)recv, // 69
	(void*)recvfrom, // 70
	(void*)select, // 71
	(void*)send, // 72
	(void*)sendto, // 73
	(void*)setsockopt, // 74
	(void*)shutdown, // 75
	(void*)socket, // 76
	(void*)wcscat, // 77
	(void*)mymalloc, // 78
	(void*)myrealloc, // 79
	(void*)mycalloc, // 80
	(void*)myfree, // 81
	(void*)fopen, // 82
	(void*)exit, // 83
};

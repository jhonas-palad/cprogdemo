#ifndef __MYLIB__
#define __MYLIB__

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define MAX_UNICODE 0x10ffff

#define MY_PERROR(str) do { perror(str); exit(EXIT_FAILURE); } while(0);

/* Converts bytestring to a multibyte string */
wchar_t *MyMbstoWcs(char *, size_t *);

#include "my_random.h"



#endif /* __MYLIB__ */
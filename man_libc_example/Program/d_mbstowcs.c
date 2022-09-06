/*
$ ./t_mbstowcs de_DE.UTF-8 Grüße!
The behavior of mbstowcs() depends on the LC_CTYPE
category of the current locale.

The function mbsrtowcs(3) provides a better inter‐
face to the same functionality.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>


/* 
An invalid multibyte sequence has been  encountered.  
In this case, (size_t) -1 is returned.
*/
#define MBSERR (size_t) -1

/*
In order to avoid the case 2 above, the programmer
should make sure n is greater than or equal to mb‐
stowcs(NULL,src,0)+1.
*/
#define mbslen(mbcs) \
	({ \
		size_t res; \
		res = mbstowcs(NULL, mbcs, 0); \
		res; \
	})
#define EXIT_ERROR(msg) do{ perror(msg); exit(EXIT_FAILURE);}while(0);


int
main(int argc, char **argv){

	size_t _mbslen; /* Number of multibyte characters in source  */
	wchar_t *wcs; /* Pointer to converted wide character string */
	wchar_t *wptr; 

	if(argc < 3){
		fprintf(stderr, "Usage: %s <locale> <string>\n", *(argv));
		exit(EXIT_FAILURE);
	}

	if(setlocale(LC_ALL, *(argv + 1)) == NULL){
		EXIT_ERROR("setlocale")
	}
	/* 
	Calculate the length to hold argv[2] converted to a wide character string
	if first argument is NULL then last argument will not be evaluated.
	*/
	_mbslen = mbslen(*(argv + 2));
	if(_mbslen == MBSERR){
		EXIT_ERROR("mbslen")
	}


	/*Describe the source string to the user*/
	printf("Length of source string (excluding terminator):\n");
	printf("\t%zu bytes\n", strlen(argv[2]));
	printf("\t%zu multibyte characters\n\n", _mbslen);

	/*
	
	Allocate wide character string of the desired size.
	Add 1 to allow for terminating null wide character (L'\0').
	*/
	wcs = calloc(_mbslen + 1, sizeof(wchar_t));
	if(wcs == NULL){
		EXIT_ERROR("calloc");
	}

	/*
	Convert multibyte character string from argv[2] 
	to a wide character string (wchar_t)
	*/
	if(mbstowcs(wcs, argv[2], _mbslen + 1) == MBSERR){
		EXIT_ERROR("mbstowcs");
	}

	printf("Wide character string is %ls (%zu characters)\n", wcs, _mbslen);


	/*
		Inspect the classes of the characters in the wide character string.
	*/
	for(wptr = wcs; *wptr != 0 ; wptr++){
		printf("\t%lc ", (unsigned int) *wptr);

		if(iswalpha(*wptr)){
			printf("alpha ");
			printf("%s case", iswlower(*wptr) ? "lower" : "upper");
		}else{
			printf("any");
		}
		putchar('\n');
	}


	exit(EXIT_SUCCESS);

}

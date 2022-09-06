#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>


#define ERROR(func) do {perror(#func); exit(EXIT_FAILURE); } while(0);

int main(int argc, char **argv){
    int base;
    char *endptr, *str;
    long int val;

    if(argc < 2){
        fprintf(stderr, "Usage: %s <string> [base]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    str = argv[1]; // String to convert to long int
    base = (argc > 2) ? atoi(argv[2]) : 10; // Get the base if given. Use 10 by default.

    errno = 0; /* To distinguish succes/failure after call */
    val = strtol(str, &endptr, base);

    /* Check for various possible errors */
    if((errno == ERANGE  && (val == LONG_MAX || val == LONG_MIN))
        || (errno != 0 && val == 0)){
            ERROR(strtol);
        }

    if (endptr == str){
        fprintf(stderr, "str:%s, endptr:%s. No digits were found. Return %lu: %s\n",str, endptr, val, strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("strtol() returned %ld %lx\n", val, (unsigned long)val);

    if(*endptr != '\0'){
        printf("Further characters after number: %s\n", endptr);
    }

    exit(EXIT_SUCCESS);

}
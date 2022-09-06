#ifndef __DATA__
#define __DATA__

#include <string.h>

#define ERROR(msg, err_no) \
    do { \
        int err = !err_no ? errno: err_no;\
        fprintf(stderr, "%s: %s\n",msg, strerror(err)); exit(1); \
    }while(0);

typedef char *c_pointer;

typedef struct argv{
    int len_arg;
    c_pointer str_arg;
}Argv;

Argv *new_argv(int, c_pointer);

void show_bytes(Argv *);

int check_atoi(c_pointer);

#endif //__DATA__
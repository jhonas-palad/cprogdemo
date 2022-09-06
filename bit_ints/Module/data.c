#include "../Include/data.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MIN(v1, v2) \
    ({ \
        int max, _v1 = (int)(v1), _v2 = (int)(v2); \
        max = _v1 < _v2 ? _v1 : _v2; \
        max; \
    })

void show_bytes(Argv *argv){
    c_pointer start = argv->str_arg;
    int size_str_arg = (int)strlen(start);
    int i, len, arg_len = argv->len_arg;

    len = MIN(size_str_arg, arg_len);


    fprintf(stdout, "------------------------------------------------|\n");
    fprintf(stdout, "No.\t| char\t| Hex \t| Memory Address\t|\n");
    fprintf(stdout, "--------|-------|-------|-----------------------|\n");
    for(i = 0; i < len; i++){
        fprintf(stdout,"%d\t| %c\t| 0x%2x\t| %p\t|\n",i,start[i] ,*(start + i), start + i);
        fprintf(stdout, "--------|-------|-------|-----------------------|\n");
    }
        
}


Argv *new_argv(int len, c_pointer str){
    size_t str_len = strlen(str);
    size_t str_size = str_len * sizeof(char);
    Argv *n_argv = (Argv *) malloc (sizeof(Argv));

    if(!n_argv){
        ERROR("Memory allocation for n_argv failed", errno);
    }

    n_argv->len_arg = len;
    n_argv->str_arg = (c_pointer) malloc(str_size);
    memcpy(n_argv->str_arg, str, str_size);
    return n_argv;
}

#define ONE 49
#define NINE 57

#define chtoi(ch) \
    ({ \
        int res; \
        res = ch - '0'; \
        res; \
    })

int check_atoi(c_pointer str){
    char *ptr = str;
    int str_len = (int) strlen(str);
    int res = 0;
    int index = 0;
    do{
        char ch = *(ptr + index);

        if(ch < ONE || ch > NINE){
            return -1;
        }
        res = res * 10 + chtoi(ch);
        index++;

    }while(index < str_len);
    return res;
}
    
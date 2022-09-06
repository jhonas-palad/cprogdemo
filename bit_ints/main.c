#include "Include/data.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


int main(int argc, char **argv){
    
    if(argc < 2){
        ERROR("Please supply '-l' and '-s' arguments", EINVAL);
    }
    if(argc > 3){
        ERROR("Too many arguments", EINVAL);
    }
    // for(int i = 0; i < argc; i++){
    //     fprintf(stdout, "argv: %d. %s\n", i, *(argv + i));
    // }

    //the first arg is the name of the program
    int len = check_atoi(*(argv + 1));
    if(len < 0){
        ERROR("Cannot convert arg:len to int", EINVAL);
    }
    c_pointer str = *(argv + 2);
    

    Argv *n_argv = new_argv(len, str);

    show_bytes(n_argv);

    free(n_argv->str_arg);
    free(n_argv);
    return 0;
}
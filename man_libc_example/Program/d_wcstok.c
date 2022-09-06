/* Display all paths with ':' delimeter */

#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>


#define ARRAY_SIZE(arr) sizeof(arr) / sizeof(arr[0])

int main(int argc, char **argv){

    char buffer[1024];

    char *paths = getenv("PATH");

    if(paths == NULL){
        perror("getenv");
        exit(EXIT_FAILURE);
    }

    /* Convert byte to multibyte */
    wchar_t *w_paths;
    /* Calculate the len that is needed for w_path allocation. */
    size_t w_paths_len = mbstowcs(NULL, paths, 0); 

    if(w_paths_len == (size_t) - 1){
        perror("mbstowcs");
        exit(EXIT_FAILURE);
    }

    /* Allocate memory for w_path */
    w_paths = calloc(w_paths_len + 1, sizeof(wchar_t));

    if(mbstowcs(w_paths, paths, w_paths_len + 1) == (size_t) - 1){
        perror("mbstowcs");
        exit(EXIT_FAILURE);
    }
    
    wchar_t *path;
    wchar_t delim[] = L":";
    wchar_t *next_path;

    printf("PATH:\n");

    for(path = wcstok(w_paths, delim, &next_path); 
        path != NULL; 
        path = wcstok(NULL, delim, &next_path)
        ){
            printf("\t%ls\n", path);
        }



    exit(EXIT_SUCCESS);
}
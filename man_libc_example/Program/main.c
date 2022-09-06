#include <mylib.h>
#include <locale.h>
#include <langinfo.h>
#include <string.h>

int main(int argc, char **argv){
    if(argc < 2){
        fprintf(stderr, "Usage: %s <mbstring> [lang]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    // char *lang = (argc > 2) ? argv[2] : getenv("LANG");

    if(setlocale(LC_CTYPE, "") == NULL){
        MY_PERROR("setlocale");
    }
    char *encoding;
    if(strcmp((encoding = nl_langinfo(CODESET)), "UTF-8") == 0){
        printf("Decoding: %s\n", encoding);
    }
    
    size_t len;
    wchar_t *mbstr = MyMbstoWcs(argv[1], &len);

    for(size_t i = 0; i < len; i++){
        wchar_t wch = mbstr[i];
        printf("%ld. %lc 0x%X\n",i, wch, (unsigned int)wch);
    }
    exit(EXIT_SUCCESS);
}
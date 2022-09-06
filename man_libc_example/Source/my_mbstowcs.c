/* 
 * If  dest  is  not  NULL,  the mbstowcs() function converts the multibyte string src to a wide-character string
 * starting at dest.  At most n wide characters are written to dest.  The sequence of characters  in  the  string
 * src shall begin in the initial shift state.  The conversion can stop for three reasons:
 * 
 * 1. An invalid multibyte sequence has been encountered.  In this case, (size_t) -1 is returned.
 * 
 * 2. n  non-L'\0' wide characters have been stored at dest.  In this case, the number of wide characters written
 *     to dest is returned, but the shift state at this point is lost.
 * 
 * 3. The multibyte string has been completely converted, including the terminating null  character  ('\0').   In
 *     this case, the number of wide characters written to dest, excluding the terminating null wide character, is
 *     returned.
 * 
 * The programmer must ensure that there is room for at least n wide characters at dest.
 * 
 * If dest is NULL, n is ignored, and the conversion proceeds as above, except that the converted wide characters
 * are not written out to memory, and that no length limit exists.
 * 
 * In  order  to  avoid  the  case  2  above,  the  programmer should make sure n is greater than or equal to mb‐
 * stowcs(NULL,src,0)+1. 
 * 
 * RETURN VALUE
 * The mbstowcs() function returns the number of wide characters that make up the converted  part  of  the  wide-
 * character string, not including the terminating null wide character.  If an invalid multibyte sequence was en‐
 * countered, (size_t) -1 is returned.
 * 
 * The behavior of mbstowcs() depends on the LC_CTYPE category of the current locale.
 * The function mbsrtowcs(3) provides a better interface to the same functionality
 */

#include <mylib.h>



static const size_t MBSERR = (size_t) - 1;


static size_t is_valid_mbch(wchar_t ch){
    if(ch != L'\0'){
        if(ch > MAX_UNICODE) return 0;
        /* We can add some validation here */
    }
    return 1;
}


static size_t
_my_mbstowcs(wchar_t *ptr, char *str, size_t len){

    size_t count = mbstowcs(ptr, str, len);

    if(ptr != NULL && count != MBSERR){
        for(size_t i = 0; i < count; i++){
            wchar_t mbch = ptr[i];
            if(!is_valid_mbch(mbch)){
                return MBSERR;
            }
        }
    }

    return count;
}

/* Calculate the len of the string using mbstowcs. strlen suitable for ASCII*/
static size_t _my_mbslen(char *str){
    return _my_mbstowcs(NULL, str, 0);
}

wchar_t *MyMbstoWcs(char *str, size_t *len){
    wchar_t *buffer;
    size_t len_buffer;

    if((len_buffer = _my_mbslen(str)) == MBSERR){
        MY_PERROR("_my_mbslen");
    }

    if((buffer = calloc(len_buffer + 1, sizeof(wchar_t))) == NULL){
        MY_PERROR("calloc");
    }
    *len = len_buffer;
    len_buffer += 1; //Read the notes why we did this.
    if(_my_mbstowcs(buffer, str, len_buffer) == MBSERR){
        MY_PERROR("_my_mbstowcs");
    }

    return buffer;

}


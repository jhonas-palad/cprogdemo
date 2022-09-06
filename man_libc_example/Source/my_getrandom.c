#include <mylib.h>

#include <fcntl.h>
# ifdef HAVE_SYS_STAT_H
#   include <sys/stat.h>
# endif
# ifdef HAVE_LINUX_RANDOM_H
#   include <linux/random.h>
#  endif
# if defined(HAVE_SYS_RANDOM_H) && (defined(HAVE_GETRANDOM) || defined(HAVE_GETENTROPY))
#   include<sys/random.h>
# endif
# if !defined(HAVE_GETRANDOM) && defined(HAVE_GETRANDOM_SYSCALL)
#   include<sys/syscall.h>
# endif

#if defined(HAVE_GETRANDOM) || defined(HAVE_GETRANDOM_SYSCALL)
#define MY_GETRANDOM 1
/* Definition of getrandom wrapper */
#elif defined(HAVE_GETENTROPY)
#define MY_GETENTROPY 1
/* Definition of getentropy wrapper */
#endif /* elif defined(HAVE_GETENTROPY) */






static size_t myurandom(void *buffer, size_t bufflen, int blocking, int raise){
#if defined(MY_GETRANDOM) || defined(MY_GETENTROPY)
    int res;
#endif
    if(bufflen < 0){

    }
}

size_t MyGetRandomBlock(void *buff, size_t buff_len){
    return myurandom(buff, buff_len, 1, 1);
}

size_t MyGetRandomNonBlock(void *buff, size_t buff_len){
    return myurandom(buff, buff_len, 0, 1);
}
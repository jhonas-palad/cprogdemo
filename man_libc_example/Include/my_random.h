#ifndef __MY_RANDOM__
#define __MY_RANDOM__

typedef union{
    unsigned char uc[24];
}RandBuffer;


size_t MyGetRandomBlock(void *, size_t);
size_t MyGetRandomNonBlock(void *, size_t);



#endif /* __MY_RANDOM__ */
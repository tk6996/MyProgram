#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H
#define FOREACH(__declaration,__expression)                  \
    for(size_t __index=0,(__declaration)=(__expression)[0];  \
    __index<sizeof((__expression))/sizeof((__expression)[0]);\
    __index++,(__declaration)=(__expression)[__index])
#define EVAL(arg) #arg
void printbit(void* address,int bytes);
#endif
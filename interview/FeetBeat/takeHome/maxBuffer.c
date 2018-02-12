#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>
#include "main.h"
#include "maxBuffer.h"

#define TRUE    1
#define FALSE   0

#if 1
#define DBGM(...)     {printf("[MAX_BUF] ");printf(__VA_ARGS__);}
#else
#define DBGM(...)
#endif

static int currentBufferSize;
static unsigned int maxBuffer[BUFFER_SIZE];

void maxBuffer_push(unsigned int value){
    int idx = 0;

    if(currentBufferSize < BUFFER_SIZE){
        while(idx < currentBufferSize && value > maxBuffer[idx]){
            idx++;
        }
        DBGM("%d : insert idx = %d\n",value,idx);

        int i;
        for(i=currentBufferSize;i>idx;--i){
            maxBuffer[i] = maxBuffer[i-1];
        }
        maxBuffer[idx] = value;
        currentBufferSize++;
    }
    else{
        while(idx < BUFFER_SIZE && value > maxBuffer[idx]){
            idx++;
        }

        if(idx == 0){
            return;
        }
        idx--;
        DBGM("%d : insert idx = %d\n",value,idx);

        int i;
        for(i=0;i<idx;++i){
            maxBuffer[i] = maxBuffer[i+1];
        }
        maxBuffer[idx] = value;
    }
}

int maxBuffer_retrieveAllElements(unsigned int buffer[]){

    memcpy(buffer,maxBuffer,currentBufferSize*sizeof(unsigned int));
   
    return currentBufferSize;
}

void maxBuffer_printAllElements(void){

    int i;

    for(i=0;i<currentBufferSize;++i){
        printf("%d : %d\n",i+1,maxBuffer[i]);
    }
}

int maxBuffer_initialize(void){
    int i;
    for(i=0;i<BUFFER_SIZE;++i){
        maxBuffer[i] = 0;
    }
    currentBufferSize = 0;
    DBG("Max Buffer Initialized\n");

    return TRUE;
}

#if 0
int main(void){

    int i = 0;
    for(i=40;i>0;--i){
        int x = rand() % 300;
        maxBuffer_push(x);
    }

    maxBuffer_printAllElements();

    return 0;
}
#endif


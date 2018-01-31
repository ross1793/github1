#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>
#include "main.h"


#define TRUE    1
#define FALSE   0

static int currentBufferSize;
static unsigned int maxBuffer[BUFFER_SIZE];

void maxBuffer_push(unsigned int number){
    if(currentBufferSize == 0){
        maxBuffer[0] = number;
        currentBufferSize = 1;
        return;
    }

    if(number >= maxBuffer[0]){
        // perform binary search for insert index
        int left = 0;
        int right = currentBufferSize;
        int idx;
        while(left<=right){
            idx = (right+left)/2;
            if(number == maxBuffer[idx]){
                break;
            }
            else if(number > maxBuffer[idx]){
                left = idx+1;
            }
            else{
                right = idx-1;
            }
        }
        DBG("insert idx = %d\n",idx);

        if(currentBufferSize >= BUFFER_SIZE){
            int i;
            for(i=0;i<idx;++i){
                maxBuffer[i] = maxBuffer[i+1];
            }
            maxBuffer[idx] = number;
        }
        else{
            maxBuffer[idx] = number;
            currentBufferSize++;
        }
    }
    return;
}

int maxBuffer_retrieveAllElements(unsigned int buffer[]){

   
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

int main(void){

    int i = 0;
    for(i=1;i<=33;++i){
        maxBuffer_push(i);
    }
    maxBuffer_printAllElements();

    return 0;
}

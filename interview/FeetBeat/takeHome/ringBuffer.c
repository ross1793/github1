///////////////////////////////////////////////////////////////////////////////
// Author : Chi-chi Lo
//
// Utilize a ring buffer that stores the last data input.
// To use it, please call ringBuffer_initialize first.
//
///////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>
#include "main.h"
#include "ringBuffer.h"

#define TRUE    1
#define FALSE   0

#if 0
#define DBGR(...)   {printf("[RING_BUF] ");printf(__VA_ARGS__);}
#else
#define DBGR(...)
#endif

static int startIdx, endIdx;
static int currentBufferSize;
static unsigned int ringBuffer[BUFFER_SIZE];

/******************************************************************************
 * Push a new number into the buffer.
 * @number : the number to be pushed.
 *****************************************************************************/
void ringBuffer_push(unsigned int number){
   ringBuffer[endIdx] = number; 
   endIdx++;
   endIdx = endIdx % BUFFER_SIZE; 

   currentBufferSize++;
   if(currentBufferSize > BUFFER_SIZE)
   {
       currentBufferSize = BUFFER_SIZE;
       startIdx = endIdx;
   }

   DBGR("END = %d, START = %d, SIZE = %d\n",endIdx, startIdx, currentBufferSize);
}

/******************************************************************************
 * Retrieve all elements from the ring buffer. The first-in element will be
 * first-out in the output buffer.
 * buffer[] : Buffer allocated by the caller.
 *****************************************************************************/
int ringBuffer_retrieveAllElements(unsigned int buffer[]){

    if(currentBufferSize == 0 || buffer == NULL)
        return 0;

    if(endIdx > startIdx){
        memcpy(buffer, ringBuffer+startIdx, currentBufferSize*sizeof(unsigned int));
    }
    else{
        memcpy(buffer, ringBuffer+startIdx, (BUFFER_SIZE-startIdx)*sizeof(unsigned int));
        memcpy(buffer+BUFFER_SIZE-startIdx, ringBuffer, (endIdx+1)*sizeof(unsigned int));
    }
   
    return currentBufferSize;
}

/******************************************************************************
 * Print all elements in the buffer with FIFO order
 *****************************************************************************/
void ringBuffer_printAllElements(void){

    if(currentBufferSize == 0)
        return;

    int i;
    int count = 1;

    if(endIdx > startIdx){
        for(i=startIdx;i<endIdx;++i){
            printf("%d : %d\n",count++,ringBuffer[i]);
        }
    }
    else{
        for(i=startIdx;i<BUFFER_SIZE;++i){
            printf("%d : %d\n",count++,ringBuffer[i]);
        }
        for(i=0;i<endIdx;++i)
            printf("%d : %d\n",count++,ringBuffer[i]);
        }
    }

/******************************************************************************
 * Initialize the buffer
 *****************************************************************************/
int ringBuffer_initialize(void){
   
   int i;

   currentBufferSize = 0;
   startIdx = 0;
   endIdx = 0;
   
   for(i=0;i<BUFFER_SIZE;++i){
      ringBuffer[i] = 0;
   }

   DBGR("Ring Buffer Initialized\n");

   return TRUE;
}

/*
int main(void){

    int i = 0;
    for(i=0;i<38;++i){
        ringBuffer_push(i);
    }
    ringBuffer_printAllElements();

    unsigned int buf[32];
    ringBuffer_retrieveAllElements(buf);
    for(i=0;i<32;++i){
        printf("%d -- %d\n",i+1,buf[i]);
    }


    return 0;
}
*/

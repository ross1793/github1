///////////////////////////////////////////////////////////////////////////////
// Author : Chi-chi Lo
//
// The max number list utilizes a heap data structure.
// Checking if a number can be pushed into the list : O(1)
// Pushing a new element into the buffer : O(log(n))
// Retrieving the whole list : O(nlog(n))
//
///////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>
#include "main.h"
#include "maxBuffer.h"

#define TRUE    1
#define FALSE   0

#if 0
#define DBGM(...)     {printf("[MAX_BUF] ");printf(__VA_ARGS__);}
#else
#define DBGM(...)
#endif

static int currentBufferSize;
static unsigned int maxBuffer[BUFFER_SIZE];

static void printBuffer(int size, int buffer[]){
    printf("%d : ",currentBufferSize);
    int i=0;
    for(i=0;i<size;++i){
        printf("%d ",buffer[i]);
    }
    printf("\n");
}

static void swap(unsigned int *a, unsigned int *b){
    unsigned int temp = *a;
    *a = *b;
    *b = temp;
}
static int getParentIdx(int i){
    return (i-1)/2;
}
static int getLeftIdx(int i){
    return 2*i + 1;
}
static int getRightIdx(int i){
    return 2*i + 2;
}
static void minHeapify(int i, unsigned int buffer[], int size){
    int l = getLeftIdx(i);
    int r = getRightIdx(i);
    int small = i;
    if(l < size && buffer[l] < buffer[i])
        small = l;
    if(r < size && buffer[r] < buffer[small])
        small = r;
    if(small != i){
        DBGM("swapping %d %d\n",buffer[i],buffer[small]);
        swap(&buffer[i], &buffer[small]);
        minHeapify(small, buffer, size);
    }
}

/******************************************************************************
 * Push a new number into the buffer. The buffer is implemented by heap.
 * @number : the number to be pushed into the buffer
 *****************************************************************************/
void maxBuffer_push(unsigned int value){
    //printBuffer(currentBufferSize, maxBuffer);
    if(currentBufferSize < BUFFER_SIZE){
        int idx = currentBufferSize;
        maxBuffer[idx] = value;
        currentBufferSize++;
        
        int parent = getParentIdx(idx);
        while(idx > 0)
        {
            if(maxBuffer[parent] > maxBuffer[idx])
                swap(&maxBuffer[parent],&maxBuffer[idx]);
            idx = parent;
            parent = getParentIdx(idx);
        }
    }
    else{
        // compare the value with min element in min-heap
        if(value < maxBuffer[0]){
            return;
        }
        maxBuffer[0] = value;
        minHeapify(0, maxBuffer, currentBufferSize);
    }
}

/******************************************************************************
 * Print all elements in the buffer.
 *****************************************************************************/
void maxBuffer_printAllElements(){
    int size = currentBufferSize;
    int tempBuffer[BUFFER_SIZE] = {0};
    memcpy(tempBuffer, maxBuffer, currentBufferSize*sizeof(unsigned int));
  
    do{
        printf("%d : %d\n",size, tempBuffer[0]);
        tempBuffer[0] = tempBuffer[size-1]; 
        minHeapify(0, tempBuffer, size);
        size--;
    }while(size>0);
}

/******************************************************************************
 * Retrieve all elements from the max value buffer. The output is always sorted.
 * @buffer[] : Buffer allocated by the caller
 *****************************************************************************/
int maxBuffer_retrieveAllElements(unsigned int buffer[]){
    int size = currentBufferSize;
    int tempBuffer[BUFFER_SIZE] = {0};
    memcpy(tempBuffer, maxBuffer, currentBufferSize*sizeof(unsigned int));
    int i = 0;

    do{
        buffer[i++] = tempBuffer[0];
        tempBuffer[0] = tempBuffer[size-1]; 
        minHeapify(0, tempBuffer, size);
        size--;
    }while(size>0);

    return currentBufferSize;
}

# if 0 // implemented by linear buffer
/******************************************************************************
 * Push a new number into the buffer.
 * @number : the number to be pushed into the buffer
 *****************************************************************************/
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
        idx = 0;

        while(idx < BUFFER_SIZE && value > maxBuffer[idx]){
            idx++;
        }
        DBGM("idx =  %d\n",idx);

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

/******************************************************************************
 * Retrieve all elements from the max value buffer. The output is always sorted.
 * @buffer[] : Buffer allocated by the caller
 *****************************************************************************/
int maxBuffer_retrieveAllElements(unsigned int buffer[]){

    memcpy(buffer,maxBuffer,currentBufferSize*sizeof(unsigned int));
   
    return currentBufferSize;
}

/******************************************************************************
 * Print all elements in the buffer.
 *****************************************************************************/
void maxBuffer_printAllElements(void){

    int i;

    for(i=0;i<currentBufferSize;++i){
        printf("%d : %d\n",i+1,maxBuffer[i]);
    }
}
#endif

/******************************************************************************
 * Initialize the buffer
 *****************************************************************************/
int maxBuffer_initialize(void){
    int i;
    for(i=0;i<BUFFER_SIZE;++i){
        maxBuffer[i] = 0;
    }
    currentBufferSize = 0;
    DBGM("Max Buffer Initialized\n");

    return TRUE;
}

#if 0
int main(void){

    int i = 0;
     srand (time(NULL));
    for(i=40;i>0;--i){
        int x = rand() % 300;
        maxBuffer_push(x);
    }

    maxBuffer_printAllElements();

    return 0;
}
#endif


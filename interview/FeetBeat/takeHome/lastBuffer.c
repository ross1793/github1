#include<stdio.h>

#define BUFFER_SIZE      32
static int startIdx, endIdx;
static int currentBufferSize;
static unsigned int lastBuffer[BUFFER_SIZE];

void lastBuffer_insertElement(unsigned int number){
   lastBuffer[endIdx] = number; 
   if(endIdx >= BUFFER_SIZE-1){
      endIdx = 0;
      startIdx = 1;
   else
      endIdx++;
}

int lastBuffer_retrieveAllElements(unsigned int buffer[]){
   memcpy(buffer, lastBuffer, currentBufferSize*sizeof(unsigned int)); 
   
   return currentBufferSize;
}

bool lastBuffer_initialize(void){
   
   int i;

   currentBufferSize = 0;
   startIdx = 0;
   endIdx = 0;
   
   for(i=0;i<BUFFER_SIZE;++i){
      lastBuffer[i] = 0;
   }

   return true;
}

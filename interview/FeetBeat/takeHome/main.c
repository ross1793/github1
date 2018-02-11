#include<stdio.h>
#include "main.h"
#include "ringBuffer.h"
#include "maxValueBuffer.h"

#define filter12bit(x)    (x & 4095)
#define READ_BYTES        3

#define HEAD_12BITS(buf)  (((*buf << 4) & 0xff0) | (*(buf+1) >> 4 & 0xf))
#define TAIL_12BITS(buf)  (((*buf << 8) & 0xf00) | (*(buf+1)  & 0xff))

void dataConversion(char *buffer, int size, int *num1, int *num2){
   if(size != 3){
      *num1 = 0;
      *num2 = 0;
      return;
   }
   
   *num1  = HEAD_12BITS(buffer);

   buffer++;

   *num2 = TAIL_12BITS(buffer);
}

void writeOutput(unsigned int maxBuffer[], int maxBufferSize,
                 unsigned int lastBuffer[], int lastBufferSize)
{

    int i = 0;

    if(lastBuffer == NULL || maxBuffer == NULL)
        return;

    printf("--Sorted Max 32 Values--\n");
    for(i=0;i<maxBufferSize;++i){
        printf("%d\n",maxBuffer[i]);
    }


    printf("--Last 32 Values--\n");
    for(i=0;i<lastBufferSize;++i){
        printf("%d\n",lastBuffer[i]);
    }

}

int main(void){

   ringBuffer_initialize();
   unsigned char buffer[READ_BYTES] = {0};

   FILE *fp;

   fp = fopen("test1.bin","rb");  // r for read, b for binary

   int offset = 0;

   while(1){
      if(fseek(fp,offset,SEEK_SET) != 0)
         break;

      if(fread(buffer,READ_BYTES,1,fp) != 1)
         break;

      int i = 0;
      DBG("%.2X %.2X %.2X == ", buffer[0], buffer[1], buffer[2]);

      int num1, num2;
      dataConversion(buffer, 3, &num1, &num2);
      DBG("%u %u\n",num1, num2);
      offset += 3;

      ringBuffer_push(num1);
      ringBuffer_push(num2);
      maxBuffer_push(num1);
      maxBuffer_push(num2);
   }

   ringBuffer_printAllElements();

   unsigned int lastBuffer[32] = {0};
   int valuesCount = ringBuffer_retrieveAllElements(lastBuffer);

   unsigned int maxBuffer[32] = {0};
   int maxCount = maxBuffer_retrieveAllElements(maxBuffer);

   writeOutput(maxBuffer, maxCount, lastBuffer, valuesCount);

   fclose(fp);

   return 0;
}

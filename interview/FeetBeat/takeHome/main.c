#include<stdio.h>
#include<unistd.h>
#include "main.h"
#include "ringBuffer.h"
#include "maxBuffer.h"

#define filter12bit(x)    (x & 4095)
#define READ_BYTES        3

#define HEAD_12BITS(buf)  (((*(buf) << 4) & 0xff0) | (*(buf+1) >> 4 & 0xf))
#define TAIL_12BITS(buf)  (((*(buf) << 8) & 0xf00) | (*(buf+1)  & 0xff))

#if 1
#define DBG(...)    printf(__VA_ARGS__)
#else
#define DBG(...)
#endif

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

void writeOutput(const char *filename,
                 unsigned int maxBuffer[], int maxBufferSize,
                 unsigned int lastBuffer[], int lastBufferSize)
{
    DBG("Writing to file %s\n",filename);
    FILE *fp = fopen(filename,"w");  // r for read, b for binary

    int i = 0;

    if(lastBuffer == NULL || maxBuffer == NULL)
        return;

    printf("--Sorted Max 32 Values--\n");
    fprintf(fp,"--Sorted Max 32 Values--\n");
    DBG("max buffer size == %d\n",maxBufferSize);
    for(i=0;i<maxBufferSize;++i){
        printf("%d\n",maxBuffer[i]);
        fprintf(fp,"%d\n",maxBuffer[i]);
    }


    printf("--Last 32 Values--\n");
    fprintf(fp,"--Last 32 Values--\n");
    DBG("last buffer size == %d\n",lastBufferSize);
    for(i=0;i<lastBufferSize;++i){
        printf("%d\n",lastBuffer[i]);
        fprintf(fp,"%d\n",lastBuffer[i]);
    }

    fclose(fp);
}

void readInput(const char *filename){

   unsigned char buffer[READ_BYTES] = {0};
   FILE *fp;
   int offset = 0;
   int num1, num2;

   DBG("Read file %s\n",filename);
   fp = fopen(filename,"rb");

    while(1){
        if(fseek(fp,offset,SEEK_SET) != 0)
            break;

        // read 3 bytes (24bits) at a time, which is equal to two 12bits inputs
        int readBytes = fread(buffer,1,3,fp);

        if(readBytes == 3){
            DBG("%.2X %.2X %.2X : ", buffer[0], buffer[1], buffer[2]);

            num1 = HEAD_12BITS(buffer);
            num2 = TAIL_12BITS(buffer+1);

            DBG("%u %u\n",num1, num2);

            ringBuffer_push(num1);
            ringBuffer_push(num2);
            maxBuffer_push(num1);
            maxBuffer_push(num2);
            offset += 3;
        }
        else if(readBytes == 2){
            // Special case, when only two bytes can be read
            DBG("%.2X %.2X : ", buffer[0], buffer[1]);
            num1 = HEAD_12BITS(buffer);

            DBG("%u\n",num1);

            ringBuffer_push(num1);
            maxBuffer_push(num1);
            break;
        }
        else{
            break;
        }
   }
   fclose(fp);
}

int main(int argc, char* argv[])
{
    if(argc < 2){
        printf("Syntax: ./dataProcessor 'filename'\n");
        return 1;
    }

   ringBuffer_initialize();
   maxBuffer_initialize();

   if(access(argv[1], F_OK) < 0){
       printf("file not exist\n");
       return 0;
   }

   readInput(argv[1]);

   unsigned int lastBuffer[32] = {0};
   int valuesCount = ringBuffer_retrieveAllElements(lastBuffer);

   unsigned int maxBuffer[32] = {0};
   int maxCount = maxBuffer_retrieveAllElements(maxBuffer);

   writeOutput("result.out",maxBuffer, maxCount, lastBuffer, valuesCount);

   return 0;
}

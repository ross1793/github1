#include<stdio.h>

#define filter12bit(x)    (x & 4095)
#define READ_BYTES        3

void dataConversion(char *buffer, int size, int *num1, int *num2){
   if(size != 3){
      *num1 = 0;
      *num2 = 0;
      return;
   }
   
   *num1 = (*buffer << 4) | (*(buffer+1) >> 4);
   *num2 = (*(buffer+1)&0b1111 << 8) | (*(buffer+2));
}


int main(void){

   printf("hello world\n");

   unsigned char buffer[READ_BYTES] = {0};

   FILE *fp;

   fp = fopen("test3.bin","rb");  // r for read, b for binary

   int offset = 0;

   while(1){
      if(fseek(fp,offset,SEEK_SET) != 0)
         break;

      if(fread(buffer,READ_BYTES,1,fp) != 1)
         break;

      int i = 0;
      for(i=0;i<READ_BYTES;++i){
         printf("%.2u\n", buffer[i]);
      }

      int num1, num2;
      dataConversion(buffer, 3, &num1, &num2);
      printf("%d %d\n",num1, num2);
      offset += 3;
   }

   fclose(fp);

   return 0;
}

#ifndef _RING_BUFFER_H_
#define _RING_BUFFER_H_


void ringBuffer_push(unsigned int number);
int ringBuffer_retrieveAllElements(unsigned int buffer[]);
void ringBuffer_printAllElements(void);
int ringBuffer_initialize(void);


#endif

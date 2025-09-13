
#ifndef RINGBUFFER_H
#define RINGBUFFER_H


typedef struct ringBuffer ringBuffer;

ringBuffer* new_ringBuffer(int size);
void delete_Buffer(ringBuffer **rb);


int enqueue(ringBuffer *rb,int n);
int dequeue(ringBuffer *rb,int *result);


int front(ringBuffer *rb,int *result);
int rear(ringBuffer *rb,int *result);


int isEmpty(ringBuffer *rb);
int size(ringBuffer *rb);


void display(ringBuffer *rb);

#endif

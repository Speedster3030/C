/**
 * Speedster3030;   13 Sept,2025
 * Ring Buffer/Circular Queue structure implementation.
 */

#include <stdio.h>
#include <stdlib.h>
#include "ringbuffer.h"

#define RB_OK 0
#define RB_FULL -1
#define RB_EMPTY -2

//ring Buffer/Circular Queue struct
struct ringBuffer
{
        int* arr;
        int count;
        int head;
        int tail;
        int max;
};


//Initialize a new ring buffer
ringBuffer* new_ringBuffer(int size)
{
        ringBuffer* rb=malloc(sizeof(ringBuffer));

        rb->max=size;
        rb->arr=malloc(size*sizeof(int));
        rb->count=0;
        rb->head=0;
        rb->tail=-1;

        return rb;
}


//free the structure from memory
void delete_Buffer(ringBuffer **rb)
{
        free((*rb)->arr);
        free(*rb);
        *rb=NULL;
}


//Put a value in the buffer
int enqueue(ringBuffer *rb,int n)
{
        if(rb->count==rb->max)
        {
                return RB_FULL;
        }

        rb->tail=(rb->tail+1) % rb->max;
        rb->arr[rb->tail]=n;
        rb->count++;
        return RB_OK;
}


//remove a value from the buffer
int dequeue(ringBuffer *rb,int *result)
{
        if(rb->count==0)
        {
                return RB_EMPTY;
        }

        *result=rb->arr[rb->head];
        rb->arr[rb->head]=0;
        rb->head=(rb->head+1) % rb->max;
        rb->count--;

        return RB_OK;
}


//get the value in front of the queue
int front(ringBuffer *rb,int *result)
{
        if(rb->count==0)
        {
                return RB_EMPTY;
        }

        *result=rb->arr[rb->head];
        return RB_OK;
}


//get the rear value of the queue
int rear(ringBuffer *rb,int *result)
{
        if(rb->count==0)
        {
                return RB_EMPTY;
        }

        *result=rb->arr[rb->tail];
        return RB_OK;
}


int isEmpty(ringBuffer *rb)
{
        return rb->count==0?1:0;
}


int size(ringBuffer *rb)
{
        return rb->count;
}


//basic display for the queue
void display(ringBuffer *rb)
{
        if(rb->count==0)
        {
                printf("Empty Ring Buffer\n");
                return;
        }

        printf("\nQueue:  ");

        int c=rb->head;
        int count=rb->count;
        while(count>0)
        {
                printf("%d, ",rb->arr[c]);
                c=(c+1)%rb->max;
                count--;
        }

        printf("\n\n");
}

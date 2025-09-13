/**
 * Speedster3030, 2025
 * Ring Buffer/Circular Queue structure implementation.
 */

#include<stdio.h>
#include<stdlib.h>

//ring Buffer/Circular Queue struct
typedef struct
{
        int* arr;
        int count;
        int head;
        int tail;
        int max;
}ringBuffer;

//Initialize a new ring buffer
ringBuffer* new_ringBuffer(int size)
{
        ringBuffer* rb=malloc(sizeof(ringBuffer));

        rb->max=size;
        rb->arr=malloc(size*sizeof(int));
        rb->count=0;
        rb->head=size-1;
        rb->tail=size-1;

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
                return -1;
        }

        rb->arr[rb->tail]=n;
        rb->tail--;
        if(rb->tail==-1)
        {
                rb->tail=rb->max-1;
        }
        rb->count++;
        return 0;
}

//remove a value from the buffer
int dequeue(ringBuffer *rb,int *result)
{
        if(rb->count==0)
        {
                return -1;
        }

        int t=rb->arr[rb->head];
        rb->arr[rb->head]=0;
        rb->head--;
        rb->count--;
        if(rb->head==-1)
        {
                rb->head=rb->max-1;
        }

        *result=t;
        return 0;
}

//get the value in front of the queue
int front(ringBuffer *rb,int *result)
{
        if(rb->count==0)
        {
                return -1;
        }

        *result=rb->arr[rb->head];
        return 0;
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
                c--;
                if(c<0)
                {
                        c=rb->max-1;
                }
                count--;
        }

        printf("\n");
}



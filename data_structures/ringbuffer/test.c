
#include <stdio.h>
#include <stdlib.h>
#include "ringbuffer.h"

int main()
{
        ringBuffer* r=new_ringBuffer(4);
        int result;

        enqueue(r,1);
        enqueue(r,2);
        enqueue(r,3);
        enqueue(r,4);
        display(r);
        dequeue(r,&result);
        display(r);
        rear(r,&result);
        printf("%d\n",result);

        delete_Buffer(&r);

        return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"


typedef struct nodo
{
  void* data;
  int priority;
}heapElem;

typedef struct Heap
{
  heapElem* heapArray;
  int size;
  int capac;
  /*int *arr;
  int count;
  int capacity;
  int heap_type;*/
} Heap;


void* heap_top(Heap* pq)
{ 
  if(pq->size==0){return NULL;}
    else
    {
      return pq->heapArray[0].data;
    }
}
 

void heap_push(Heap* pq, void* data, int priority)
{
  if(pq->size+1 > pq->capac)
  {
    pq->capac= (pq->capac)*2+1;
    pq->heapArray=realloc(pq->heapArray,(pq->capac)*sizeof(heapElem));
  }

  int actual=pq->size;
  while(actual>0 && pq->heapArray[(actual-1)/2].priority<priority)
  {
    pq->heapArray[actual]=pq->heapArray[(actual-1)/2];
    actual=(actual-1)/2;
  }
  pq->heapArray[actual].priority=priority;
  pq->heapArray[actual].data=data;
  pq->size++;
}


void heap_pop(Heap* pq)
{
  /*
 int pop;
    
    pop = h->arr[0];
    h->arr[0] = h->arr[h->count-1];
    h->count--;
    heapify_top_bottom(h, 0);
    return pop;
*/

}

/*Heap* createHeap(int capacity,int heap_type)
{
   Heap *h = (Heap * ) malloc(sizeof(Heap)); 
    if(h == NULL)
    {
        printf("Memory Error!");
        return NULL;
    }
    h->heap_type = heap_type;
    h->count=0;
    h->capacity = capacity;
    h->arr = (int *) malloc(capacity*sizeof(int)); 

    if ( h->arr == NULL)
    {
      printf("Memory Error!");
      return NULL;
    }
    return h;
}*/
Heap* createHeap()
{
  /*if(h == NULL)
  {
    return 0;
  }*/
  Heap* h= (Heap*) malloc(sizeof(Heap));
  h->capac=3;
  h->size=0;
  h->heapArray=(heapElem*) calloc(3,sizeof(heapElem));

return h ;
}

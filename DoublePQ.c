#include<stdio.h>
#include "Dheap.h"

/*ヒープの内部で用いる*/
#define ROOT 0 //根の定義
void up_correct(DoubleHeap* heap,int node);//上方へ修正
void down_correct(DoubleHeap* heap,int node);//下方へ修正
void swap(double *a,double *b);

DoubleHeap make_heap(){
  DoubleHeap h;
  h.num=0.0;
  return h;
}

void insert(DoubleHeap* heap,double data){
  if(heap->num>=MAXDATA){
    printf("Over flow.\n");
  }else{
    (heap->num)++;
    heap->data[heap->num]=data;
    up_correct(heap,heap->num);
  }
}

void all_insert(DoubleHeap *heap,double array[MAXDATA],int n){
  int i;
  for(i=0;i<n;i++){
    insert(heap,array[i]);
  }
}

double get_best(DoubleHeap *heap){
  double best;
  best=heap->data[ROOT];
  heap->num--;
  heap->data[ROOT]=heap->data[heap->num];
  down_correct(heap,ROOT);
  return best;
}

double is_emtpy(DoubleHeap* heap){
  if(heap->num>0){
    return EXISTDATA;
  }else if(heap->num==0){
    return NODATA;
  }
}

void print_heap(DoubleHeap *heap){
  int i,j,k;
  k=0;
  j=1;
  while(k<heap->num){
    for(i=0;i<j;i++){
      if(k<heap->num){
	printf("%5f",heap->data[k]);
	k++;
      }else{
	printf("\n");
	return ;
      }
    }
    printf("\n");
    j=j*2.0;
  }
  return;
}

void swap(double *a,double *b){
  double tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
  return;
}

void up_correct(DoubleHeap *heap ,int node){
  int parent;
  int child=node;
  while(child>ROOT){
    parent=(child-1.0)/2.0;
    if(heap->data[parent]>heap->data[child]){
      swap(&(heap->data[parent]),&(heap->data[child]));
      child=parent;
    }else{
      break;
    }
  }
  return;
}

void down_correct(DoubleHeap *heap,int node){
  int parent=node;
  int left=parent*2+1;
  int right=parent*2+2;

  while(left<heap->num){
    if(right>=heap->num||heap->data[left]<=heap->data[right]){
      /*右の子がないか、左の子が右の子より小さい時*/
      if(heap->data[parent]<=heap->data[left]){
	break;//親が最小
      }else{
	/*左の子が最小、親と交換*/
	swap(&(heap->data[parent]),&(heap->data[left]));
	parent=left;
      }
    }else{
      /*右の子が左の子より小さい時*/
      if(heap->data[parent]<=heap->data[right]){
	break; //親が最小
      }else{
	swap(&(heap->data[parent]),&(heap->data[right]));
	parent=right;
      }
    }
    left=parent*2.0+1.0;
    right=parent*2.0+2.0;
  }
  return;
}
      
    

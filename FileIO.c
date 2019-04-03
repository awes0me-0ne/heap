#include<stdio.h>
#include<stdlib.h>//乱数関連
#include<time.h>
#include"heap.h"

/*関数定義*/
#define MAX 10000//四桁の整数の最大値
void make_data_file(FILE *fp,int n){
  int i=0;
  int idata;
  srand(time(NULL));//乱数の種
  for(i=0;i<n;i++){
    idata=(int)rand()%MAX;
    fprintf(fp,"%5d\n",idata);
  }
  return;
}

int fscan_to_array(FILE* fp,int array[MAXDATA]){
  int i=0;
  int idata;
  while(fscanf(fp,"%d",&idata)!=EOF){
    array[i]=idata;
    i++;
  }
  return i;
}

void sort_fprint(FILE *fp,IntHeap* heap){
  int data;
  while(heap->num>0){
    data=get_best(heap);
    fprintf(fp,"%d\n",data);
  }
  return;
}

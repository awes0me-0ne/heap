#include<stdio.h>
#include<stdlib.h>//乱数関連
#include<time.h>
#include"Dheap.h"

/*関数定義*/
#define MAX 10000//四桁の整数の最大値
void make_data_file(FILE *fp,int n){
  int i=0;
  double idata;
  srand(time(NULL));//乱数の種
  for(i=0;i<n;i++){
    idata=(int)rand()%MAX+rand()%MAX/1000000.0;
    fprintf(fp,"%5f\n",idata);
  }
  return;
}

double fscan_to_array(FILE* fp,double array[MAXDATA]){
  int i=0;
  double idata;
  while(fscanf(fp,"%lf",&idata)!=EOF){
    array[i]=idata;
    i++;
  }
  return i;
}

void sort_fprint(FILE *fp,DoubleHeap* heap){
  double data;
  while(heap->num>0){
    data=get_best(heap);
    fprintf(fp,"%f\n",data);
  }
  return;
}

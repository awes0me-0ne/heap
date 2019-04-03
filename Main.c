#include<stdio.h>
#include "heap.h"

int main(){
  int Data[MAXDATA];
  IntHeap heap;
  IntHeap *h_p;
  FILE *fp_data,*fp_sort;
  int num=30;

  /*データ用意*/
  fp_data=fopen("InputData","w");
  make_data_file(fp_data,num);
  fclose(fp_data);

  /*ヒープ用意*/
  heap=make_heap();
  h_p=&heap;
  printf("ヒープ用意\n");
  printf("ヒープを表示します\n");
  print_heap(h_p);

  /*データ読み込み*/
  fp_data=fopen("InputData","r");
  printf("配列にデータを入れます。\n");
  num=fscan_to_array(fp_data,Data);
  fclose(fp_data);

  /*ヒープへの入力*/
  all_insert(h_p,Data,num);
  printf("%d\n",h_p->num);;
  print_heap(h_p);

  /*ファイルへの出力*/
  fp_sort=fopen("SortedData","w");
  sort_fprint(fp_sort,h_p);
  fclose(fp_sort);
  return 0;
}

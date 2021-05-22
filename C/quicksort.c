#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int partition(int *numbers, int l, int r){
  int i = 0, j = 0, p = 0, temp = 0;
  i = l;
  j = r + 1;
  p = numbers[l];
  do {
    do {
      i+=1;
    } while(numbers[i] < p);
    do {  
      j-=1;
    } while(numbers[j] > p);
    temp = numbers[j];
    numbers[j] = numbers[i];
    numbers[i] = temp;
  } while(i < j);
    temp = numbers[j];
    numbers[j] = numbers[i];
    numbers[i] = temp;

    temp = numbers[j];
    numbers[j] = numbers[l];
    numbers[l] = temp;
    return j;
}

void quicksort(int *numbers, int l, int r){
  int s = 0;
  if (l < r){
    s = partition(numbers, l, r);
    quicksort(numbers, l, s - 1);
    quicksort(numbers, s + 1, r);
  }
}

int main(int argc, char *argv[]){
  int vector[] = {1, 5, 10, -10, 3, 0, 1, 2, -30, 30, 40};
  int *numbers = vector;
  quicksort(numbers, 0, (sizeof(vector) / sizeof(numbers[0])) - 1);
  for (int x = 0; x < sizeof(vector) / sizeof(numbers[0]); x++){
    printf("%d, ", numbers[x]);
  }
}
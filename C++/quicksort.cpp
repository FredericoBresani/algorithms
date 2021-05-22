#include <iostream>

using namespace std;

int partition(int numbers[], int l, int r){
  int i = 0, j = 0, p = 0;
  i = l;
  j = r + 1;
  p = numbers[l];
  do {
    do {
      i = i + 1;
    } while (numbers[i] < p);
    do {
      j = j - 1;
    } while (numbers[j] > p);
    swap(numbers[i], numbers[j]);
    
  } while (i < j);
  swap(numbers[i], numbers[j]);
  swap(numbers[l], numbers[j]);
  return j;
}

void quicksort(int numbers[], int l, int r){
  int s = 0;
  if (l < r){
    s = partition(numbers, l, r);
    quicksort(numbers, l, s - 1);
    quicksort(numbers, s + 1, r);
  }
}


int main() {
  int teste[] = {1, 50, 5, -10, 9, 8, 7, 3, 4, 2, 1, 1, 0, 10, 15};
  quicksort(teste, 0, sizeof teste/sizeof teste[0] - 1);
  return 0;
}
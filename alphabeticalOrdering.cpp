#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <queue>

using namespace std;
bool AmenorqueB(string A, string B){
  bool verifica = false;
  for (int x = 0; x < A.length() && x < B.length(); x++){
    if (tolower(A[x]) < tolower(B[x])){
      verifica = true;
      return true;
    }
    else if (tolower(A[x]) > tolower(B[x])){
      return false;
    }
  }
  if (verifica == false && A.length() < B.length()){
    return true;
  }
    return false;
}

int partition(string nomes[], int l, int r){
  int i = 0, j = 0;
  string p = "";
  i = l;
  j = r + 1;
  p = nomes[l];
  do {
    do {
      i = i + 1;
    } while (AmenorqueB(nomes[i], p));
    do {
      j = j - 1;
    } while (AmenorqueB(p, nomes[j]));
    swap(nomes[i], nomes[j]);
    
  } while (i < j);
  swap(nomes[i], nomes[j]);
  swap(nomes[l], nomes[j]);
  return j;
}

void quicksort(string nomes[], int l, int r){
  int s = 0;
  if (l < r){
    s = partition(nomes, l, r);
    quicksort(nomes, l, s - 1);
    quicksort(nomes, s + 1, r);
  }
}


int main() {
  string teste[] = {"Hello guys", "this", "is", "an", "example", "of", "an", "alphabetical ordering", "with", "quicksort"};
  quicksort(teste, 0, sizeof teste/sizeof teste[0] - 1);
  return 0;
}
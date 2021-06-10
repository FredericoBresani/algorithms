#include <iostream>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

char* count_sheep(int n) {
  int loop = 0, allocate = 0, number = n, contarPotencia = 0;
  while (number >= 10){
    number = number / 10;
    contarPotencia++;
  }
  number = n;
  while(contarPotencia > 0){

    allocate = allocate + (number - pow(10, contarPotencia) + 1) * (contarPotencia + 1);
    number = number - (number - pow(10, contarPotencia) + 1);
    contarPotencia--;
  }
  allocate = allocate + number + n*9;
  char *resposta = (char *) calloc (allocate, sizeof(char));
  while (loop < n){
    sprintf(resposta + strlen(resposta), "%d sheep...", loop + 1);
    loop++;
  }
  return resposta;
}

int main(int argc, char *argv[]){
  char *oioi = count_sheep(1233);
  return 0;
}
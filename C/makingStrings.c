#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

typedef struct{
  char *r;
  int iterate;
} aoba;

aoba integrate(int coefficient, int exponent) {
  char *resposta;
  int e = exponent + 1;
  int c = coefficient / e;
  int eTemp = e;
  int cTemp = c;
  int tam = 0;
  while (eTemp > 0){
    tam++;
    eTemp = eTemp / 10;
  }
  while (cTemp > 0){
    tam++;
    cTemp = cTemp / 10;
  }
  tam = tam + 2;
  resposta = (char *) malloc (sizeof(char) * tam);
  sprintf(resposta, "%ix^%i", c, e);
  aoba coisa;
  coisa.iterate = tam;
  coisa.r = (char *) malloc (sizeof(char) * tam);
  sprintf(coisa.r, "%ix^%i", c, e);
  return coisa;
}

int main(int argc, char *argv[]){
  aoba nada = integrate(28, 1);
  for (int x = 0; x < nada.iterate; x++){
    printf("%c", nada.r[x]);
  } 
  return 0;
}
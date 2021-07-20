#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <array>
#include <queue>
#include <algorithm>

using namespace std;

int hexToDec(string hexString){
  int tamanho = hexString.length();
  int potencia = 0;
  int resultado = 0;
  for (int x = tamanho - 1; x >= 0; x--, potencia++){
    if (toupper(hexString[x]) == 'A'){
      resultado = resultado + pow(16, potencia) * 10;
    }
    else if (hexString[x] == '-'){
      resultado = resultado * -1;
    }
    else if (toupper(hexString[x]) == 'B'){
      resultado = resultado + pow(16, potencia) * 11;
    }
    else if (toupper(hexString[x]) == 'C'){
      resultado = resultado + pow(16, potencia) * 12;
    }
    else if (toupper(hexString[x] == 'D')){
      resultado = resultado + pow(16, potencia) * 13;
    }
    else if (toupper(hexString[x] == 'E')){
      resultado = resultado + pow(16, potencia) * 14;
    }
    else if (toupper(hexString[x] == 'F')){
      resultado = resultado + pow(16, potencia) * 15;
    } else {
      resultado = resultado + pow(16, potencia) * (hexString.at(x) - '0');
    }
    

  }
  return resultado;
}

int main() {
  cout << hexToDec("1E19D87E");
 return 0;
}
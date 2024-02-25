//        ALUMNO: Marcos Belda Martínez
// PARA COMPILAR: g++ -o mergeSortTest mergeSortTest.cpp *.o

#include "mergeSort.h"

using namespace std;




//-----// MAIN //------------------------------------------------//

int main() {
  
  vector<int> v = {23,15,51,8,45,71,2,1};

  cout << "VECTOR SIN ORDENAR: "; imprimir(v); cout << endl;

  mergeSort(v, 0, TAMANYO-1);

  cout << "   VECTOR ORDENADO: "; imprimir(v); cout << endl;
  
  return 1;
}
//---------------------------------------------------------------//

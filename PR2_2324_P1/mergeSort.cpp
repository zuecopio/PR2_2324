//        ALUMNO: Marcos Belda Martínez
// PARA COMPILAR: g++ -c mergeSort.cpp

#include "mergeSort.h"

using namespace std;




//-----// MERGE //-----------------------------------------------//

void merge( vector<int> &v, int ini, int mid, int end ) {
  
  int tamanyoA = (mid - ini) + 1;
  int tamanyoB = (end - (mid + 1)) + 1;

  int a[tamanyoA];
  int b[tamanyoB];

  int i, j, k;

  /* rellenar a */
  for (i = 0; i < tamanyoA; i++) {
    a[i] = v[ini+i];
  }

  /* rellenar b */
  for (j = 0; j < tamanyoB; j++) {
    b[j] = v[(mid+1)+j];
  }

  /* merge */
  i = 0, j = 0, k = 0;
  
  while (i < tamanyoA && j < tamanyoB) {
    if (a[i] < b[j]) {
      v[ini+k] = a[i];
      i++;
    }
    else {
      v[ini+k] = b[j];
      j++;
    }
    k++;
  }
  while (i < tamanyoA) {
    v[ini+k] = a[i];
    i++;
    k++;
  }
  while (j < tamanyoB) {
    v[ini+k] = b[j];
    j++;
    k++;
  }
}
//---------------------------------------------------------------//




//-----// MERGE SORT //------------------------------------------//

void mergeSort( vector<int> &v, int ini, int end ) {

  if( ini < end ) {
    int mid = (ini + end) / 2;
    mergeSort( v, ini, mid );
    mergeSort( v, mid + 1, end );
    merge( v, ini, mid, end );
  }
}
//---------------------------------------------------------------//




//-----// IMPRIMIR VECTOR //-------------------------------------//

void imprimir( vector<int> &v ) {
  cout << "{";
  for( int i = 0; i < TAMANYO; i++ ) {
    if ( i < TAMANYO-1 ) { cout << v[i] << ", "; }
    else { cout << v[i] << "}"; }
  }
}
//---------------------------------------------------------------//

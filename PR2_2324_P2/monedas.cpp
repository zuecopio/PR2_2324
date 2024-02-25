//        ALUMNO: Marcos Belda Martínez
// PARA COMPILAR: g++ -o ./bin/monedas ./src/monedas.cpp

#include <iostream>
#include <vector>
#include <iomanip>

#define N 4
#define M 8
#define NONE 1000

using namespace std;




//-----// MÍNIMO //----------------------------------------------//

int min( int a, int b ) {
  int diff = a - b;
  int sign = (diff >> 31) & 1;
  return b + sign*diff;			  
}
//---------------------------------------------------------------//




//-----// DEVOLUCIÓN MONEDAS //----------------------------------//

vector<int> devolucion_monedas( vector<int> &v, vector<int> &num_monedas, int m ) {

  for( int i = 0; i < (M+1); i++ ) {
    i == 0 ? cout << "      0€" : cout << setw(4) << i << "€";
  }

  cout << endl;
  
  int mat[N][M+1];
  for( int i = 0; i < N; i++ ) {
    for( int j = 0; j < (M+1); j++ ) {
      mat[i][j] = NONE;
    }
  }

  mat[0][0] = 0;
  mat[1][0] = 0;
  mat[2][0] = 0;

  cout << "0{" << v[0] << "}";
  cout << setw(4) << mat[0][0];
  
  // PARA J EN RANGO (1, M+1)
  for( int j = 1; j < (M+1); j++ ) {
    if( ( j >= v[0] ) && ( mat[0][ (j-v[0]) ] != NONE ) ) {
      mat[0][j] = ( 1 + ( mat[0][ (j-v[0]) ] ) );
      cout << setw(5) << mat[0][j];
    }
  }
  
  cout << endl;
  cout << "1{" << v[1] << "}";
  cout << setw(4) << mat[1][0];


  // PARA I EN RANGO (1, N)
  for( int i = 1; i < N; i++ ) {
    
    mat[i][0] = 0;
  
       // PARA J EN RANGO (1, M+1)
       for( int j = 1; j < (M+1); j++ ) {
	 
         if( j < v[i] || mat[i][j-v[i]] == NONE )
	   mat[i][j] = mat[i-1][j];
	 
	 else if ( mat[i-1][j] != NONE )
	   mat[i][j] = min( mat[i-1][j], 1 + mat[i][j-v[i]] );

	 else
	   mat[i][j] = 1 + mat[i][j-v[i]];

	 cout << setw(5) << mat[i][j];
       }

       cout << endl;
       if(i < N-1) {
	 cout << i+1 << "{" << v[i+1] << "}";
	 cout << setw(4) << mat[2][0];
       }

  }




  
  int i = N-1;
  int j = M;

  while( i >= 0 && j != 0 ) {
    
    if( i == 0 || mat[i][j] != mat[i-1][j] ) {
      num_monedas[i] += 1;
      j -= v[i];
    }

    else
      i = i - 1;
    
  }




  
  
  return num_monedas;
}
//---------------------------------------------------------------//




//-----// MAIN //------------------------------------------------//

int main() {
  vector<int> v = {1, 3, 4, 6};
  vector<int> num_monedas = {0, 0, 0, 0};

  vector<int> monedas = devolucion_monedas(v, num_monedas, M);

  for( int i = 0; i < N; i++ ) {
    cout << endl << "CANTIDAD DE MONEDAS DE " << v[i] << ": " << monedas[i];
  }
  cout << endl;
  
  return 0;
}
//---------------------------------------------------------------//

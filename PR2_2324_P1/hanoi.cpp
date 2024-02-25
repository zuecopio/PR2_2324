//        ALUMNO: Marcos Belda Martínez
// PARA COMPILAR: g++ -o hanoi hanoi.cpp

#include <iostream>
#include <string>

using namespace std;

void mover ( string origen, string destino ) {
  cout << "Disco movido de  " << origen << " a " << destino << endl;
}

void hanoi ( int num_discos, string origen, string auxiliar, string destino ) {
  if ( num_discos == 1 ) {
    mover(origen, destino);
  }

  else {
    hanoi( (num_discos - 1), origen, destino, auxiliar );
    mover(origen, destino);
    hanoi( (num_discos - 1), auxiliar, origen, destino );
  }
}

int main ( int argc, char **argv ) 
{
  hanoi(3, "A", "B", "C");
  return 0;
}

//        ALUMNO: Marcos Belda Martínez
// PARA COMPILAR: g++ -o busqueda busqueda.cpp

#include <iostream>
#include <chrono>


using namespace std;

// Constantes que definen los parametros de medida
#define MAXTALLA 100000
#define INITALLA 10000
#define INCRTALLA 10000
#define REPETICIONES 100000
#define REP_CASOMEJOR 2000000


//--------------------------------------------------------------------------------
void createArray(int a[], int tamanyo) {
    for (int i = 0; i < tamanyo; i++) { 
        a[i] = i; 
    }
}


//--------------------------------------------------------------------------------

int busqueda_iterativa( int x, int tamanyo, int a[] ) {
  int i = 0;

  while ( (i < tamanyo) && (a[i] != x) )
    { i++; }

  if (i < tamanyo)
    { return i; }

  else
    { return -1; }
}

void measuring_busqueda_iterativa() {
    
  long long tt = 0; // Tiempo total

  // Imprimir cabecera de resultados
  cout << "# Busqueda lineal. Tiempos en microsegundos\n";
  cout << "# Talla       Mejor       Peor     Promedio\n";
  cout << "#------------------------------------------\n";
    
  // Este bucle repite el proceso para varias tallas
  for (int t = INITALLA; t <= MAXTALLA; t += INCRTALLA) {
    // Crear el array una vez para cada talla
    int a[t];
    createArray(a, t);

    /***** Estudio del Caso mejor: buscar a[0] *****/

    // OJO: Como es muy rapido,
    // el numero de repeticiones es mayor
    tt = 0; // Tiempo acumulado inicial a 0
    for (int r = 0; r < REP_CASOMEJOR; r++) {
      auto ti = chrono::high_resolution_clock::now();

      busqueda_iterativa(a[0], t, a);

      auto tf = chrono::high_resolution_clock::now();
      tt += chrono::duration_cast<chrono::microseconds>(tf - ti).count();
    }
        
    // Tiempo medio del caso mejor
    double tMejor = (double) tt / REP_CASOMEJOR;         

    /***** Estudio del Caso peor: buscar uno que no esta, por ejemplo -1 *****/

    tt = 0; // Tiempo acumulado inicial a 0
    for (int r = 0; r < REPETICIONES; r++) {
      auto ti = chrono::high_resolution_clock::now();

      busqueda_iterativa(-1, t, a);

      auto tf = chrono::high_resolution_clock::now();
      tt += chrono::duration_cast<chrono::microseconds>(tf - ti).count();
    }
  
    // Tiempo medio del caso peor
    double tPeor = (double) tt / REPETICIONES; 
        
    /***** Estudio del Caso promedio: buscar un numero aleatorio entre 0 y t-1 *****/

    tt = 0; // Tiempo acumulado inicial a 0
    srand(time(0)); // definimos semilla del módulo rand
    for (int r = 0; r < REPETICIONES; r++) {
      int aux = (int) (1+ (rand() % t)); // Número a buscar
      //cout << "numero a buscar "<< aux << endl;

      auto ti = chrono::high_resolution_clock::now();

      busqueda_iterativa(aux, t, a);

      auto tf = chrono::high_resolution_clock::now();
      tt += chrono::duration_cast<chrono::microseconds>(tf - ti).count();
    }

    // Tiempo medio del caso promedio
    double tPromed = (double) tt / REPETICIONES; 
        
    // Imprimir resultados, por columnas
    printf("%8d %10.5f %10.5f %10.5f\n",
	   t, tMejor, tPeor, tPromed);
  }
}


//------------------------------------------------------------------------------




int busqueda_binaria( int x, int ini, int fin, int a[] ) {
  
  if( ini > fin ) {
    return -1;
  }

  int medio = ( ini + fin ) / 2;
  
  if( a[medio] == x ) {
    return medio;
  }
  
  else if( a[medio] > x ) {
    busqueda_binaria( x, ini, medio-1, a );
  }
  
  else {
    busqueda_binaria( x, medio+1, fin, a );
  }
}


void measuring_busqueda_binaria() {
    
  long long tt = 0; // Tiempo total

  // Imprimir cabecera de resultados
  cout << "# Busqueda binaria. Tiempos en microsegundos\n";
  cout << "# Talla       Mejor       Peor     Promedio\n";
  cout << "#------------------------------------------\n";
    
  // Este bucle repite el proceso para varias tallas
  for (int t = INITALLA; t <= MAXTALLA; t += INCRTALLA) {
    // Crear el array una vez para cada talla
    int a[t];
    createArray(a, t);

    /***** Estudio del Caso mejor: buscar a[0] *****/

    // OJO: Como es muy rapido,
    // el numero de repeticiones es mayor
    tt = 0; // Tiempo acumulado inicial a 0
    for (int r = 0; r < REP_CASOMEJOR; r++) {
      auto ti = chrono::high_resolution_clock::now();

      busqueda_binaria(a[0], 0, t, a);

      auto tf = chrono::high_resolution_clock::now();
      tt += chrono::duration_cast<chrono::microseconds>(tf - ti).count();
    }
        
    // Tiempo medio del caso mejor
    double tMejor = (double) tt / REP_CASOMEJOR;         

    /***** Estudio del Caso peor: buscar uno que no esta, por ejemplo -1 *****/

    tt = 0; // Tiempo acumulado inicial a 0
    for (int r = 0; r < REPETICIONES; r++) {
      auto ti = chrono::high_resolution_clock::now();

      busqueda_binaria(-1, 0, t, a);

      auto tf = chrono::high_resolution_clock::now();
      tt += chrono::duration_cast<chrono::microseconds>(tf - ti).count();
    }
  
    // Tiempo medio del caso peor
    double tPeor = (double) tt / REPETICIONES; 
        
    /***** Estudio del Caso promedio: buscar un numero aleatorio entre 0 y t-1 *****/

    tt = 0; // Tiempo acumulado inicial a 0
    srand(time(0)); // definimos semilla del módulo rand
    for (int r = 0; r < REPETICIONES; r++) {
      int aux = (int) (1+ (rand() % t)); // Número a buscar
      //cout << "numero a buscar "<< aux << endl;

      auto ti = chrono::high_resolution_clock::now();

      busqueda_binaria(aux, 0, t, a);

      auto tf = chrono::high_resolution_clock::now();
      tt += chrono::duration_cast<chrono::microseconds>(tf - ti).count();
    }

    // Tiempo medio del caso promedio
    double tPromed = (double) tt / REPETICIONES; 
        
    // Imprimir resultados, por columnas
    printf("%8d %10.5f %10.5f %10.5f\n",
	   t, tMejor, tPeor, tPromed);
  }
}



//---------------------------------------------------------------------------------

int main() {

  measuring_busqueda_iterativa();
  
  measuring_busqueda_binaria();

  return 1;
}

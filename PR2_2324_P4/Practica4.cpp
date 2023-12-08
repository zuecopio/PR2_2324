/*-----------------------------------------------------+
 |     P R A C T I C A 4 . C P P                       |
 +-----------------------------------------------------+
 |     Versión     : Practica4                         | 
 |     Autor       : Marcos Belda Martínez             |
 |     Asignatura  : PR2-GIIROB                        |     
 |     Descripción : Práctica 4: Grafos. Matriz de     |
 |                   adyacencias                       |
 +-----------------------------------------------------*/



#include <iostream>
using namespace std;

	/*-----------------------------------------------------+
	 |     ACTIVIDAD 1                                     |
	 +-----------------------------------------------------*/
	
	//-----[ CREACIÓN DE LA CLASE ]------------------(+)
	
	class AdjacencyMatrix {

		public:
			
			AdjacencyMatrix (int nvertex)
			{
				this->nvertex = nvertex;
				this->matrix = new int*[nvertex];
				
				for (int m = 0; m < nvertex; m++)
				{
					this->matrix[m] = new int[nvertex];
				}
				
				for (int i = 0; i < nvertex; i++)
				{
					for (int j = 0; j < nvertex; j++)
					{
						matrix[i][j] = 0;
						matrix[j][i] = 0;
					}
				}
			}
			
			~AdjacencyMatrix ()
			{
				delete[] matrix;
			}
			
			int num_vertex ()
			{
				return nvertex;
			}
			
			void create_arist ( int i, int j )
			{
				matrix[i][j] = 1;
				matrix[j][i] = 1;
			}
			
			void remove_arist ( int i, int j )
			{
				matrix[i][j] = 0;
				matrix[j][i] = 0;
			}
			
			void print_matrix ()
			{
				cout << endl << "     ";
				for (int m = 0; m < nvertex; m++)
				{
					cout << m << "   ";
				}
				cout << endl;
				for (int i = 0; i < nvertex; i++)
				{
					cout << " " << i << "   ";
					for (int j = 0; j < nvertex; j++)
					{
						cout << matrix[i][j] << "   ";
					}
					cout << endl;
				}
				cout << endl;
			}
			
			/*-----------------------------------------------------+
			 |     ACTIVIDAD 2                                     |
 			 +-----------------------------------------------------*/
			
			int leftPos ( bool* arr )
			{
				int pos = -1;
				for (int i = 0; i < nvertex; i++)
				{
					if (arr[i] == 1) { pos = i; }
				}
				return pos;
			}

			void wide_path (int v = 0)
			{
				bool visited[nvertex];
				bool left[nvertex];

				for (int m = 0; m < nvertex; m++)
				{
					visited[m] = 0;
					left[m] = 0;
				}
				visited[v] = 1;
				left[v] = 1;
				
				cout << " * Wide path: " << v;
				
				while (leftPos(left) != -1)
				{
					left[v] = 0;
					for (int i = 0; i < nvertex; i++)
					{
						if ((visited[i] == 0) && (matrix[v][i] == 1))
						{
							visited[i] = 1;
							left[i] = 1;
							cout << " - " << i;
						}
					}
					v = leftPos(left);
				}
				cout << endl << endl;
			}

			/*-----------------------------------------------------+
			 |     ACTIVIDAD 3                                     |
 			 +-----------------------------------------------------*/

			void deep_path (int v = 0)
			{
				bool visited[nvertex];
				for (int m = 0; m < nvertex; m++)
				{
					visited[m] = 0;
				}
				visited[v] = 1;

				cout << " * Deep path: " << v;
				deep_path_(visited, v);
				cout << endl << endl;
			}

		private:
			
			int nvertex;
			int** matrix;

			/*-----------------------------------------------------+
			 |     ACTIVIDAD 3                                     |
 			 +-----------------------------------------------------*/

			void deep_path_ (bool *visited, int v = 0)
			{
				bool left[nvertex];
				for (int m = 0; m < nvertex; m++)
				{
					left[m] = 0;
				}
				left[v] = 1;

				while (leftPos(left) != -1)
				{
					left[v] = 0;
					for (int i = 0; i < nvertex; i++)
					{
						if ((visited[i] == 0) && (matrix[v][i] == 1))
						{
							visited[i] = 1;
							left[i] = 1;
							cout << " - " << i;
							deep_path_(visited, i);
						}
					}
					v = leftPos(left);
				}
			}
	};
	
	//-----------------------------------------------(-)


int main () {
	
	//-----[ ACTIVIDAD 1: MOSTRAR MATRIZ ]-----------(+)

	AdjacencyMatrix AM = AdjacencyMatrix(5);
	
	AM.create_arist(0, 1);
	AM.create_arist(0, 2);
	AM.create_arist(1, 2);
	AM.create_arist(1, 3);
	AM.create_arist(2, 4);
	
	AM.print_matrix();

	//-----------------------------------------------(-)
	
	cout << endl;

	//-----[ ACTIVIDAD 2: WIDE PATH ]----------------(+)
	
	AM.wide_path();
	AM.wide_path(1);
	AM.wide_path(2);
	AM.wide_path(3);
	AM.wide_path(4);

	//-----------------------------------------------(-)
	
	cout << endl;

	//-----[ ACTIVIDAD 3: DEEP PATH ]----------------(+)
	
	AM.deep_path();
	AM.deep_path(1);
	AM.deep_path(2);
	AM.deep_path(3);
	AM.deep_path(4);

	//-----------------------------------------------(-)
	
	return 0;	
}

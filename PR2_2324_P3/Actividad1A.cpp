/*-----------------------------------------------------+
 |     A C T I V I D A D 1 A . C P P                   |
 +-----------------------------------------------------+
 |     Versión     : Actividad1A                       | 
 |     Autor       : Marcos Belda Martínez             |
 |     Asignatura  : PR2-GIIROB                        |     
 |     Descripción : Actividad 1A de la práctica 3 de  |
 |                   PR2, Tabla Hash                   |
 +-----------------------------------------------------*/



#include <iostream>
using namespace std;

	//-----[ TAMAÑO DE LAS TABLAS HASH ]-------------(+)
	
	#define SIZE 100
		
	//-----------------------------------------------(-)


int main() {
	
	//-----[ CREACIÓN DE LAS TABLAS HASH ]-----------(+)
	
	hash<int> int_hash;
	hash<char> char_hash;
	hash<float> float_hash;
	hash<double> double_hash;
	hash<string> string_hash;
	
	//-----------------------------------------------(-)
	
	//-----[ CREACIÓN DE LAS VARIABLES ]-------------(+)
	
	int tipo_int = 7;
	char tipo_char = 'L';
	float tipo_float = 3.5;
	double tipo_double = 13.3145;
	string tipo_string = "patata";
	
	//-----------------------------------------------(-)
	
	//-----[ CÁLCULO ÍNDICE HASH ]-------------------(+)
	
	size_t hash_val_int = int_hash(tipo_int);
	size_t hash_val_char = char_hash(tipo_char);
	size_t hash_val_float = float_hash(tipo_float);
	size_t hash_val_double = double_hash(tipo_double);
	size_t hash_val_string = string_hash(tipo_string);
	
	//-----------------------------------------------(-)
	
	//-----[ IMPRIMIR POSICIÓN EN LA TABLA ]---------(+)
	
	cout << endl;
	cout << "Hash value for " << tipo_int << ": " << hash_val_int << "[Hash index: " << (hash_val_int % SIZE) << "]";
	cout << endl << endl << endl;
	cout << "Hash value for " << tipo_char << ": " << hash_val_char << "[Hash index: " << (hash_val_char % SIZE) << "]";
	cout << endl << endl << endl;
	cout << "Hash value for " << tipo_float << ": " << hash_val_float << "[Hash index: " << (hash_val_float % SIZE) << "]";
	cout << endl << endl << endl;
	cout << "Hash value for " << tipo_double << ": " << hash_val_double << "[Hash index: " << (hash_val_double % SIZE) << "]";
	cout << endl << endl << endl;
	cout << "Hash value for " << tipo_string << ": " << hash_val_string << "[Hash index: " << (hash_val_string % SIZE) << "]";
	cout << endl << endl;
	
	//-----------------------------------------------(-)
	
	return 0;	
}


/*-----------------------------------------------------+
 |     A C T I V I D A D 2 . C P P                     |
 +-----------------------------------------------------+
 |     Versión     : Actividad2                        | 
 |     Autor       : Marcos Belda Martínez             |
 |     Asignatura  : PR2-GIIROB                        |     
 |     Descripción : Actividad 2 de la práctica 3 de   |
 |                   PR2, Tabla Hash                   |
 +-----------------------------------------------------*/

/*-----------------------------------------------------+
 |     PASO 1                                          |
 +-----------------------------------------------------*/


#include <iostream>
#include <unordered_map>

using namespace std;

	//-----[ PASO 1 ]--------------------------------(+)
	
	void print_ht( unordered_map<string, int> &ht )
	{
		cout << endl << "====== HASH TABLE ======" << endl;
		cout << " Num. buckets: " << ht.bucket_count() << endl;
		cout << " Num. elements: " << ht.size() << endl;
		cout << " Max. load factor: " << ht.max_load_factor() << endl;
		cout << " Current load factor: " << ht.load_factor() << endl;
		
		for( int i = 0; i < ht.bucket_count() ; i++ )
		{
			cout << " BUCKET " << i << ": ";
			for( unordered_map<string, int>::local_iterator itr = ht.begin(i) ; itr != ht.end(i) ; itr++ )
			{
				cout << "[" << itr->first << " : " << itr->second << "]";
			}
			cout << endl;
		}
	}

	//-----------------------------------------------(-)
	
	//-----[ PASO 2 ]--------------------------------(+)
	
	bool insert_in_ht( unordered_map<string, int>& ht , string key , int val )
	{
		bool inserted = ht.insert({key, val}).second;
		
		cout << "  -> (" << key << ":" << val << ")";
		if (inserted) { cout << " inserted in bucket " << ht.bucket(key) << "!" << endl; }
		else { cout << " NOT INSERTED! KEY " << key << " already in hash table..." << endl;	}

		return inserted;
	}
			
	//-----------------------------------------------(-)
	
	//-----[ PASO 3 ]--------------------------------(+)
	
	unordered_map<string, int>::iterator search_in_ht( unordered_map<string, int> &ht , string key )
	{
		unordered_map<string, int>::iterator searched = ht.find(key);
		
		if (searched != ht.end())
		{
			cout << "  -> Key " << key << " FOUND in hash: ";
			cout << "[" << searched->first << ":" << searched->second << "]";
			cout << ", bucket " << ht.bucket(key) << endl;
		}
		else
		{
			cout << "  -> Key " << key << " NOT FOUND in hash..." << endl;
		}	
		
		return searched;
	}
			
	//-----------------------------------------------(-)
	
	//-----[ PASO 4 ]--------------------------------(+)
	
	 bool delete_in_ht( unordered_map<string, int> &ht , string key )
	{
		int removed = ht.erase(key);
		
		cout << "  -> Key " << key;
		if (removed != 0) { cout << " FOUND in hash and REMOVED" << endl; }
		else { cout << " NOT FOUND in hash and CAN'T be removed" << endl; }	
		
		return removed;
	}
			
	//-----------------------------------------------(-)
	
	//-----[ PASO 5 ]--------------------------------(+)
	
	#define SIZE 50
		
	//-----------------------------------------------(-)

int main() {
	
	//-----[ CREACIÓN DE LAS TABLA HASH ]------------(+)
	
	unordered_map<string, int> ht;
	//unordered_map<string, int> ht(SIZE); // PASO 5
		
	//-----------------------------------------------(-)
	
	//-----[ INSERT ]--------------------------------(+)
	
	print_ht(ht);
	insert_in_ht(ht, "One", 1);
	insert_in_ht(ht, "Two", 2);
	insert_in_ht(ht, "Three", 3);
	insert_in_ht(ht, "Four", 4);
	insert_in_ht(ht, "One", 56);
	print_ht(ht);
	cout << endl;
	
		
	//-----------------------------------------------(-)
	
	//-----[ SEARCH ]--------------------------------(+)
	
	search_in_ht(ht, "One");
	search_in_ht(ht, "Two");
	search_in_ht(ht, "Three");
	search_in_ht(ht, "Four");
	search_in_ht(ht, "Five");
	cout << endl;
		
	//-----------------------------------------------(-)
	
	//-----[ DELETE ]--------------------------------(+)
	
	delete_in_ht(ht, "One");
	delete_in_ht(ht, "Two");
	delete_in_ht(ht, "Three");
	delete_in_ht(ht, "Four");
	delete_in_ht(ht, "Five");
	print_ht(ht);
	cout << endl;
		
	//-----------------------------------------------(-)
	
	//-----[ REHASH ]--------------------------------(+)
	
	ht.rehash(SIZE);
	print_ht(ht);
	cout << endl;
		
	//-----------------------------------------------(-)
	
	return 0;	
}

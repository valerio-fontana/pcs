#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, const char *argv[]){	
	if (argc < 2){
		cout << "Errore: nome del file non specificato.\n";	
	}
	else {
		string filename = argv[1];
		ifstream ifs(filename);
		if (!ifs.is_open()) {
			cout << "Errore: file non aperto correttamente.\n";
		}
		else {
			string citta;
			double t1, t2, t3, t4;
			while (ifs >> citta >> t1 >> t2 >> t3 >> t4) {
				double media = (t1 + t2 + t3 + t4)/4.0;
				cout << citta;
				for (int i = 0; i < 12 - citta.length(); i++) {
					cout << " ";
				}
				cout << media << "\n";
			}
		}	
	}
	return 0;
}
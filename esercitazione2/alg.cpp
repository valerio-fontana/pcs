#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	static const int N = 10;
	double arr[N] = {1.2, 2.5, 3.4, 4.7, 5.3, 3.2, 6.9, 7.1, 4.3, 2.1};
	
	double minimo_loc = arr[0];
	
	for (int i = 0; i < N; i++) {
		if (arr[i] < minimo_loc) {
			minimo_loc = arr[i];
		}
	}
	cout << "Minimo = " << minimo_loc << "\n";
		
	double massimo_loc = arr[0];
	
	for (int i = 0; i < N; i++) {
		if (arr[i] > massimo_loc) {
			massimo_loc = arr[i];
		}
	}
	cout << "Massimo = " << massimo_loc << "\n";
	
	double somma = 0;
	
	for (int i = 0; i < N; i++) {
		somma += arr[i];
	}
	double media = somma/N;
	cout << "Media = " << media << "\n";
	
	double s = 0;
	
	for (int i = 0; i < N; i++) {
		s += pow(arr[i] - media, 2);
	}
	double dev = sqrt(s/N);
	cout << "Deviazione standard = " << dev << "\n";
	
	return 0;
}
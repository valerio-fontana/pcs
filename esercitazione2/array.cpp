#include <iostream>

int main()
{
	double ad[4] = {0.0, 1.1, 2.2, 3.3};
	float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
	int ai[3] = {0, 1, 2};
	
	for (int i = 0; i < 3; i++) {
		std::cout << &ad[i] << ", ";
	}
	std::cout << &ad[3] << "\n";
	
	for (int i = 0; i < 7; i++) {
		std::cout << &af[i] << ", ";
	}
	std::cout << &af[7] << "\n";
	
	for (int i = 0; i < 2; i++) {
		std::cout << &ai[i] << ", ";
	}
	std::cout << &ai[2] << "\n";
	
	int x = 1;
	float y = 1.1;
	
	std::cout << &x << "\n";
	std::cout << &y << "\n";
	
	(&y)[1] = 0;
	
	std::cout << x << "\n";
	
	return 0;
}
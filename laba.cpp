#include <iostream>

int main()
{
	int R = 10;
	const int len = 10;
	int numberArray[len];
	std::cout << "enter 10 numbers: ";
	for (int i = 0; i < len; i++) std::cin >> numberArray[i];
	
	for (int i = 0; i < len; i++)
	{
		std::cout << numberArray[i] << ' ';
		for (int j = 0; j < len; j++) std::cout << numberArray[i] - numberArray[j] << ' ' << '\t';

		std::cout << '\n';
	}
	return 0;
}
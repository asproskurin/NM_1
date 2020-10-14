#include "Matrix.h"

const int SIZE = 10;

int main()
{
	Matrix a(SIZE, -100, 100, 0, 0, false, true);
	a.print();

	a.multiply(SIZE - 1, 1 / a.get(SIZE - 1, 0));
	for (int i = SIZE - 2; i >= 0; i--)
	{
		a.multiply(i, 1 / a.get(i, 0));
		a.minus(i, SIZE - 1);
	}
	std::cout << std::endl;
	a.print();

	system("pause");
	return 0;
}
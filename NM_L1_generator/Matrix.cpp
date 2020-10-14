#include "Matrix.h"

Matrix::Matrix(size_t N) : N_(N), M_(N + 1)
{
	srand((unsigned)time(NULL));
	arr_ = new double*[N_];
	arr_[0] = new double[N_ * M_];
	for (size_t i = 1; i != N_; i++)
	{
		arr_[i] = arr_[i - 1] + M_;
	}
	for (size_t i = 0; i < N_; i++)
	{
		for (size_t j = 0; j < M_; j++)
		{
			arr_[i][j] = (float)rand();
		}
	}
}

Matrix::Matrix(size_t N, double left, double right) : N_(N), M_(N + 1)
{
	srand((unsigned)time(NULL));
	arr_ = new double*[N_];
	arr_[0] = new double[N_ * M_];
	for (size_t i = 1; i != N_; i++)
	{
		arr_[i] = arr_[i - 1] + M_;
	}
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	for (size_t i = 0; i < N_; i++)
	{
		for (size_t j = 0; j < M_; j++)
		{
			arr_[i][j] = rand() * fraction * (right - left) + left;
		}
	}
}

bool main_diagonal(size_t i, size_t j, size_t N_)
{
	return i + j == N_ || i + j + 1 == N_ || i + j + 2 == N_;
}

bool side_diagonal(size_t i, size_t j, size_t N_)
{
	return i == j || i == j - 1 || i == j + 1;
}

Matrix::Matrix(size_t N, double left, double right, bool diagonal) : N_(N), M_(N + 1)
{
	srand((unsigned)time(NULL));
	arr_ = new double*[N_];
	arr_[0] = new double[N_ * M_];
	for (size_t i = 1; i != N_; i++)
	{
		arr_[i] = arr_[i - 1] + M_;
	}
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	//Диагональ
	bool (*option1)(size_t, size_t, size_t);
	if (diagonal)
	{
		option1 = main_diagonal;
	}
	else
	{
		option1 = side_diagonal;
	}
	for (size_t i = 0; i < N_; i++)
	{
		for (size_t j = 0; j < N_; j++)
		{
			//Вот в этот иф всякие горизонтальные и вертикальные лепить
			if (j == 0 || j == N_ - 1 || option1(i, j, N))
			{
				arr_[i][j] = rand() * fraction * (right - left) + left;
			}
			else
			{
				arr_[i][j] = 0;
			}
		}
	}
	for (size_t i = 0; i < N_; i++)
	{
		arr_[i][M_ - 1] = rand() * fraction * (right - left) + left;
	}
}

Matrix::~Matrix()
{
	delete[] arr_[0];
	delete[] arr_;
}

void Matrix::print()
{
	std::cout.setf(std::ios::fixed);
	for (size_t i = 0; i < N_; i++)
	{
		for (size_t j = 0; j < M_; j++)
		{
			std::cout << std::setw(10) << std::setprecision(2) << std::left << arr_[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

void Matrix::multiply(size_t a, double p)
{
	for (size_t i = 0; i < M_; i++)
	{
		arr_[a][i] *= p;
	}
}

void Matrix::plus(size_t a, size_t b)
{
	for (size_t i = 0; i < M_; i++)
	{
		arr_[a][i] += arr_[b][i];
	}
}

void Matrix::minus(size_t a, size_t b)
{
	for (size_t i = 0; i < M_; i++)
	{
		arr_[a][i] -= arr_[b][i];
	}
}

double Matrix::get(size_t i, size_t j)
{
	return arr_[i][j];
}

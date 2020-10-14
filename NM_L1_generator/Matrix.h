#pragma once

#include <cstddef>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>

class Matrix
{
public:
	//Создание случайной матрицы размера NxM 
	Matrix(size_t N);
	//Создание матрицы размера NxM со значениями в диапапзоне
	Matrix(size_t N, double left, double right);
	//Создание матрицы размера NxM со значениями в диапапзоне и условиями из лабы (хз как надо - корни тоже рандомные)
	//Там вроде что-то про единичную матрицу ещё есть - как дойду до этого момента - допилю
	//diagonal == true -- главная тройная диагональ, false -- побочная
	Matrix(size_t N, double left, double right, bool diagonal);
	~Matrix();
	//Форматированный вывод матрицы
	void print();
	//Значение элемента по индексу
	double get(size_t i, size_t j);
	//Умножение строки на число
	void multiply(size_t a, double p);
	//Сложение строк
	void plus(size_t a, size_t b);
	//Вычитание строк
	void minus(size_t a, size_t b);
private:
	size_t N_, M_;
	double **arr_;
};
#pragma once

#include <cstddef>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>

class Matrix
{
public:
	//�������� ��������� ������� ������� NxM 
	Matrix(size_t N);
	//�������� ������� ������� NxM �� ���������� � ����������
	Matrix(size_t N, double left, double right);
	//�������� ������� ������� NxM �� ���������� � ���������� � ��������� �� ���� (�� ��� ���� - ����� ���� ���������)
	//��� ����� ���-�� ��� ��������� ������� ��� ���� - ��� ����� �� ����� ������� - ������
	//diagonal == true -- ������� ������� ���������, false -- ��������
	Matrix(size_t N, double left, double right, bool diagonal);
	~Matrix();
	//��������������� ����� �������
	void print();
	//�������� �������� �� �������
	double get(size_t i, size_t j);
	//��������� ������ �� �����
	void multiply(size_t a, double p);
	//�������� �����
	void plus(size_t a, size_t b);
	//��������� �����
	void minus(size_t a, size_t b);
private:
	size_t N_, M_;
	double **arr_;
};
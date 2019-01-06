#ifndef CHECK_H
#define CHECK_H

#include <iostream>
using namespace std;

class Check
{
protected:
	const int size = 10;		//������ ����
public:
//�������� �� ����������� �������� ������ �� �������
	bool check_remotenessCell(char **&, int&, int&, int&, int&);
//�������� �� ������������ ������ �� �� ���������, ������������ ��. ������ �������
	bool check_diagonalCell(char **&, int&, int&, int&, int&);
	bool check_ofFirstCell (char **&, int&, int&);		//�������� ���������� ������ ������
	bool check_234Cells	   (char **&, int&, int&);		//�������� 2 � 3 ������ ������������� �������
	bool result			   (char **&);					//���� �� ��� ������� �� ����
	bool check_size		   (int&, int&);				//�������� ��������� �� ������� ����
};

bool Check::check_remotenessCell(char **&array, int &x, int &y, int &x2, int &y2)
{//�������� ����������� ���������� ������ �� ������ �������
	for (int i = x - 1; i < x + 2; ++i)
	{
		if (i < 1 || i > 10) continue;
		for (int j = y - 1; j < y + 2; ++j)
		{
			if (j < 1 || j > 10) continue;
			if (x2 == i && y2 == j) {
				return true;
			}
		}
	}

	cout << "\nThe entered cell must be near of the ship!";
	return false;
}

bool Check::check_diagonalCell(char **&array, int &x, int &y, int &x2, int &y2)
{//�������� �� �������������� ���������� ������ ������ ������� �� ���������
	for (int i = x - 1; i < x + 2; ++i)
	{
		if (i < 1 || i > 10) continue;
		for (int j = y - 1; j < y + 2; ++j)
		{
			if (j < 1 || j > 10) continue;
			if (i == x - 1 && j == y - 1 && i == x2 && j == y2)
			{
				cout << "\nThe entered cell cannot be place diagonally!";
				return false;
			}
			else if (i == x + 1 && j == y + 1 && i == x2 && j == y2)
			{
				cout << "\nThe entered cell cannot be place diagonally!";
				return false;
			}
			else if (i == x - 1 && j == y + 1 && i == x2 && j == y2)
			{
				cout << "\nThe entered cell cannot be place diagonally!";
				return false;
			}
			else if (i == x + 1 && j == y - 1 && i == x2 && j == y2)
			{
				cout << "\nThe entered cell cannot be place diagonally!";
				return false;
			}
		}
	}
	return true;
}

bool Check::check_ofFirstCell(char **&array, int &x, int &y)
{//�������� ���������� ������ ������ ������������� ������� �� ������� ����� ������ �������
	if (!check_size(x, y)) {
		return false;
	}

	for (int i = x - 1; i < x + 2; ++i)
	{
		if (i < 1 || i > 10) continue;
		for (int j = y - 1; j < y + 2; ++j)
		{
			if (j < 1 || j > 10) continue;

			if (array[i][j] == '4' || array[i][j] == '3' || array[i][j] == '2' || array[i][j] == '1')
			{
				cout << "\nWrong location!";
				return false;
			}
		}
	}

	return true;
}

bool Check::check_234Cells(char **&array, int &x, int &y)
{//�������� ���������� ��������� ������ �������� ����� ������
	if (!check_size(x, y)) {
		return false;
	}

	int count = 0;
	for (int i = x - 1; i < x + 2; ++i)
	{
		if (i < 1 || i > 10) continue;
		for (int j = y - 1; j < y + 2; ++j)
		{
			if (j < 1 || j > 10) continue;

			if (array[x][y] != '-')
			{
				cout << "\nThis point occupied!";
				return false;
			}

			else if (array[i][j] == '3' || array[i][j] == '4' || array[i][j] == '2' || array[i][j] == '1')
			{
				count++;
				if (count > 1)
				{
					cout << "\nWrong location!";
					return false;
				}
			}
		}
	}

	return true;
}

bool Check::result(char **&array)
{//�������� ���������� �������� � ����
	for (int i = size; i > 0; --i)
	{
		for (int j = 1; j <= size; ++j)
		{
			if (array[i][j] == '4' || array[i][j] == '3' || array[i][j] == '2' || array[i][j] == '1')
			{
				return false;
			}
		}
	}

	return true;
}

bool Check::check_size(int &x, int &y)
{
	if (y < 1 || y > 10 || x < 1 || x > 10)
	{
		cout << "\nObserve the boundaries of the field!";
		return false;
	}

	return true;
}

#endif //CHECK_H

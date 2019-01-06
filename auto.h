//������� ��������������� ��������. ������ ������� ��������� ������ 1 �������.
#ifndef AUTO_H
#define AUTO_H

#include "check.h"
#include <ctime>

class Auto : public Check		//��������������� ��������
{
public:
	void autoFilling_fourDeck	(char **&);	//4� ���������
	void autoFilling_threeDeck	(char **&);	//3�
	void autoFilling_twoDeck	(char **&);	//2�
	void autoFilling_singleDeck	(char **&);	//1
};

void Auto::autoFilling_fourDeck(char **&array)
{//��������������� ���������������� �������
	srand(time(NULL));
	int fail, rotation, randNum, x, y, x2 = 0, y2 = 0, x3 = 0, y3 = 0, x4 = 0, y4 = 0;

	do
	{
		fail = 0;	//���� ����������� ������� � ��������� ��������, �� fail=1
		//������� ��������� ����������
		x = 1 + rand() % size;
		y = 1 + rand() % size;

		array[x][y] = '4';	//����� ���������� �

		rotation = rand() % 2;	//������������ ������� �� �, ���� �� Y
		randNum = rand() % 2;	//������������ ������� � +, ���� � - �� �����-�� ���

		if (rotation == 0)
		{
			if (randNum == 0)
			{
				x2 = x - 1; x3 = x - 2; x4 = x - 3;	//������������ ������� �� ��� � � �����
				y4 = y3 = y2 = y;

				if (!check_size(x2, y2) || !check_size(x3, y3) || !check_size(x4, y4)) 
				{//�������� ����� ���� ���� ��������� ������ �� ������� ����
					array[x][y] = '-';	//�������� ������ ����������.
					fail = 1;
				}				
				else
				{	//���� �������� ������, �� ��������� �������.
					array[x2][y2] = '4';
					array[x3][y3] = '4';
					array[x4][y4] = '4';
				}
			}
			else if (randNum == 1)
			{
				x2 = x + 1; x3 = x + 2; x4 = x + 3;	//������������ ������� �� ��� � � ����
				y4 = y3 = y2 = y;

				if (!check_size(x2, y2) || !check_size(x3, y3) || !check_size(x4, y4)) 
				{
					array[x][y] = '-';
					fail = 1;
				}
				else
				{
					array[x2][y2] = '4';
					array[x3][y3] = '4';
					array[x4][y4] = '4';
				}
			}
		}
		if (rotation == 1)
		{
			if (randNum == 0)
			{
				y2 = y - 1; y3 = y - 2; y4 = y - 3;	//������������ ������� �� ��� Y � �����
				x4 = x3 = x2 = x;

				if (!check_size(x2, y2) || !check_size(x3, y3) || !check_size(x4, y4)) 
				{
					array[x][y] = '-';
					fail = 1;
				}
				else
				{
					array[x2][y2] = '4';
					array[x3][y3] = '4';
					array[x4][y4] = '4';
				}
			}
			else if (randNum == 1)
			{
				y2 = y + 1; y3 = y + 2; y4 = y + 3;	//������������ ������� �� ��� Y � ����
				x4 = x3 = x2 = x;

				if (!check_size(x2, y2) || !check_size(x3, y3) || !check_size(x4, y4)) 
				{
					array[x][y] = '-';
					fail = 1;
				}
				else
				{
					array[x2][y2] = '4';
					array[x3][y3] = '4';
					array[x4][y4] = '4';
				}
			}
		}
	} while (fail == 1);	//fail == 1 ��� ������ ��������� ��������
}

void Auto::autoFilling_threeDeck(char **&array)
{//��������������� ������������� �������
	srand(time(NULL));
	int fail, rotation, randNum, x, y, x2 = 0, y2 = 0, x3 = 0, y3 = 0;

	do
	{
		fail = 0;	//���� ����������� ������� � ��������� ��������, �� fail=1

		do
		{//������� ��������� ����������
			x = 1 + rand() % size;
			y = 1 + rand() % size;

		} while (!check_ofFirstCell(array, x, y));

		array[x][y] = '3';	//����� ���������� ��

		rotation = rand() % 2;	//������������ ������� �� �, ���� �� Y
		randNum = rand() % 2;	//������������ ������� � +, ���� � - �� �����-�� ���

		if (rotation == 0)	//������ �� �
		{
			if (randNum == 0) //���� � �����
			{
				x2 = x - 1; x3 = x - 2;
				y3 = y2 = y;

				if (!check_234Cells(array, x2, y2))
				{
					array[x][y] = '-';
					fail = 1;
				}
				else if (check_234Cells(array, x2, y2))
				{
					array[x2][y2] = '3';

					if (!check_234Cells(array, x3, y3))
					{
						array[x][y] = '-';
						array[x2][y2] = '-';
						fail = 1;
					}
					else if (check_234Cells(array, x3, y3)) {
						array[x3][y3] = '3';
					}
				}
			}

			else if (randNum == 1)	//���� � ����
			{
				x2 = x + 1; x3 = x + 2;
				y3 = y2 = y;

				if (!check_234Cells(array, x2, y2))
				{
					array[x][y] = '-';
					fail = 1;
				}
				else if (check_234Cells(array, x2, y2))
				{
					array[x2][y2] = '3';

					if (!check_234Cells(array, x3, y3))
					{
						array[x][y] = '-';
						array[x2][y2] = '-';
						fail = 1;
					}
					else if (check_234Cells(array, x3, y3)) {
						array[x3][y3] = '3';
					}
				}
			}
		}

		else if (rotation == 1)	//������ �� Y
		{
			if (randNum == 0) //���� � �����
			{
				y2 = y - 1; y3 = y - 2;
				x3 = x2 = x;

				if (!check_234Cells(array, x2, y2))
				{
					array[x][y] = '-';
					fail = 1;
				}
				else if (check_234Cells(array, x2, y2))
				{
					array[x2][y2] = '3';

					if (!check_234Cells(array, x3, y3))
					{
						array[x][y] = '-';
						array[x2][y2] = '-';
						fail = 1;
					}
					else if (check_234Cells(array, x3, y3)) {
						array[x3][y3] = '3';
					}
				}
			}

			else if (randNum == 1)	//���� � ����
			{
				y2 = y + 1; y3 = y + 2;
				x3 = x2 = x;

				if (!check_234Cells(array, x2, y2))
				{
					array[x][y] = '-';
					fail = 1;
				}
				else if (check_234Cells(array, x2, y2))
				{
					array[x2][y2] = '3';

					if (!check_234Cells(array, x3, y3))
					{
						array[x][y] = '-';
						array[x2][y2] = '-';
						fail = 1;
					}
					else if (check_234Cells(array, x3, y3)) {
						array[x3][y3] = '3';
					}
				}
			}
		}
	} while (fail == 1);	//fail == 1 ��� ������ ��������� ��������
}

void Auto::autoFilling_twoDeck(char **&array)
{//��������������� ������������� �������
	srand(time(NULL));
	int fail, rotation, randNum, x, y, x2 = 0, y2 = 0;

	do
	{
		fail = 0;	//���� ����������� ������� � ��������� ��������, �� fail=1

		do
		{//������� ��������� ����������
			x = 1 + rand() % size;
			y = 1 + rand() % size;

		} while (!check_ofFirstCell(array, x, y));

		array[x][y] = '2';	//���������� ��

		rotation = rand() % 2;	//������������ ������� �� �, ���� �� Y
		randNum = rand() % 2;	//������������ ������� � +, ���� � - �� �����-�� ���

		if (rotation == 0)	//�� �
		{
			if (randNum == 0)	//� �����
			{
				x2 = x - 1;
				y2 = y;

				if (!check_234Cells(array, x2, y2))
				{
					array[x][y] = '-';
					fail = 1;
				}
				else if (check_234Cells(array, x2, y2)) {
					array[x2][y2] = '2';
				}
			}

			else if (randNum == 1)	//� ����
			{
				x2 = x + 1;
				y2 = y;

				if (!check_234Cells(array, x2, y2))
				{
					array[x][y] = '-';
					fail = 1;
				}
				else if (check_234Cells(array, x2, y2)) {
					array[x2][y2] = '2';
				}
			}
		}

		else if (rotation == 1)	//�� Y
		{
			if (randNum == 0)	//� �����
			{
				y2 = y - 1;
				x2 = x;

				if (!check_234Cells(array, x2, y2))
				{
					array[x][y] = '-';
					fail = 1;
				}
				else if (check_234Cells(array, x2, y2)) {
					array[x2][y2] = '2';
				}
			}

			else if (randNum == 1)	//� ����
			{
				y2 = y + 1;
				x2 = x;

				if (!check_234Cells(array, x2, y2))
				{
					array[x][y] = '-';
					fail = 1;
				}
				else if (check_234Cells(array, x2, y2)) {
					array[x2][y2] = '2';
				}
			}
		}
	} while (fail == 1);	//fail == 1 ��� ������ ��������� ��������
}

void Auto::autoFilling_singleDeck(char **&array)
{//��������������� ������������� �������
	srand(time(NULL));
	int x, y;

	do
	{//������� ��������� ����������
		x = 1 + rand() % size;
		y = 1 + rand() % size;

	} while (!check_ofFirstCell(array, x, y));

	array[x][y] = '1';	//���������� �
}

#endif //AUTO_H

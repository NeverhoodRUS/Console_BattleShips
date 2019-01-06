//функции авторасстановки кораблей. Каждая функция размещает только 1 корабль.
#ifndef AUTO_H
#define AUTO_H

#include "check.h"
#include <ctime>

class Auto : public Check		//авторасстановка кораблей
{
public:
	void autoFilling_fourDeck	(char **&);	//4х палубного
	void autoFilling_threeDeck	(char **&);	//3х
	void autoFilling_twoDeck	(char **&);	//2х
	void autoFilling_singleDeck	(char **&);	//1
};

void Auto::autoFilling_fourDeck(char **&array)
{//авторасстановка четырехпалубного корабля
	srand(time(NULL));
	int fail, rotation, randNum, x, y, x2 = 0, y2 = 0, x3 = 0, y3 = 0, x4 = 0, y4 = 0;

	do
	{
		fail = 0;	//если расстановка корабля в тупиковом раскладе, то fail=1
		//находим случайную координату
		x = 1 + rand() % size;
		y = 1 + rand() % size;

		array[x][y] = '4';	//сразу обозначаем её

		rotation = rand() % 2;	//расположение корабля по Х, либо по Y
		randNum = rand() % 2;	//расположение корябля в +, либо в - по соотв-ей оси

		if (rotation == 0)
		{
			if (randNum == 0)
			{
				x2 = x - 1; x3 = x - 2; x4 = x - 3;	//расположение корабля по оси Х в минус
				y4 = y3 = y2 = y;

				if (!check_size(x2, y2) || !check_size(x3, y3) || !check_size(x4, y4)) 
				{//проверка сразу всех трех координат только на границы поля
					array[x][y] = '-';	//затираем первую координату.
					fail = 1;
				}				
				else
				{	//если проверка прошла, то размещаем корабль.
					array[x2][y2] = '4';
					array[x3][y3] = '4';
					array[x4][y4] = '4';
				}
			}
			else if (randNum == 1)
			{
				x2 = x + 1; x3 = x + 2; x4 = x + 3;	//расположение корабля по оси Х в плюс
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
				y2 = y - 1; y3 = y - 2; y4 = y - 3;	//расположение корабля по оси Y в минус
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
				y2 = y + 1; y3 = y + 2; y4 = y + 3;	//расположение корабля по оси Y в плюс
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
	} while (fail == 1);	//fail == 1 при каждом неудачном раскладе
}

void Auto::autoFilling_threeDeck(char **&array)
{//авторасстановка трехпалубного корабля
	srand(time(NULL));
	int fail, rotation, randNum, x, y, x2 = 0, y2 = 0, x3 = 0, y3 = 0;

	do
	{
		fail = 0;	//если расстановка корабля в тупиковом раскладе, то fail=1

		do
		{//находим случайную координату
			x = 1 + rand() % size;
			y = 1 + rand() % size;

		} while (!check_ofFirstCell(array, x, y));

		array[x][y] = '3';	//сразу обозначаем ее

		rotation = rand() % 2;	//расположение корабля по Х, либо по Y
		randNum = rand() % 2;	//расположение корябля в +, либо в - по соотв-ей оси

		if (rotation == 0)	//строим по Х
		{
			if (randNum == 0) //идем в минус
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

			else if (randNum == 1)	//идем в плюс
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

		else if (rotation == 1)	//строим по Y
		{
			if (randNum == 0) //идем в минус
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

			else if (randNum == 1)	//идем в плюс
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
	} while (fail == 1);	//fail == 1 при каждом неудачном раскладе
}

void Auto::autoFilling_twoDeck(char **&array)
{//авторасстаровка двухпалубного корабля
	srand(time(NULL));
	int fail, rotation, randNum, x, y, x2 = 0, y2 = 0;

	do
	{
		fail = 0;	//если расстановка корабля в тупиковом раскладе, то fail=1

		do
		{//находим случайную координату
			x = 1 + rand() % size;
			y = 1 + rand() % size;

		} while (!check_ofFirstCell(array, x, y));

		array[x][y] = '2';	//обозначаем ее

		rotation = rand() % 2;	//расположение корабля по Х, либо по Y
		randNum = rand() % 2;	//расположение корябля в +, либо в - по соотв-ей оси

		if (rotation == 0)	//по Х
		{
			if (randNum == 0)	//в минус
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

			else if (randNum == 1)	//в плюс
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

		else if (rotation == 1)	//по Y
		{
			if (randNum == 0)	//в минус
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

			else if (randNum == 1)	//в плюс
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
	} while (fail == 1);	//fail == 1 при каждом неудачном раскладе
}

void Auto::autoFilling_singleDeck(char **&array)
{//авторасстановка однопалубного корабля
	srand(time(NULL));
	int x, y;

	do
	{//находим случайную координату
		x = 1 + rand() % size;
		y = 1 + rand() % size;

	} while (!check_ofFirstCell(array, x, y));

	array[x][y] = '1';	//обозначаем её
}

#endif //AUTO_H

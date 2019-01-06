//функции работы с полем и ручной расстановки кораблей
#ifndef BATTLESHIPS_H
#define BATTLESHIPS_H

#include "check.h"
#include <iomanip>
#include <cstdlib>

class BattleShips : public Check
{
private:
	int x, y, x2, y2, x3, y3, x4, y4;	//координаты (1я, 2я, 3я, 4я клетки кораблей)
public:
	BattleShips() { x = 0; y = 0; x2 = 0; y2 = 0; x3 = 0; y3 = 0; x4 = 0; y4 = 0; }	//конструктор
	void create_array    (char **&);	//создание поля
	void show_array      (char **&);	//показать поле
	void show_rivalfield (char **&);	//обозначение выстрелов на поле соперника
	void build_Fourdeck  (char **&);	//создание четырехпалубного корабля
	void build_Threedeck (char **&);	//создание трехпалубного корабля
	void build_Twodeck   (char **&);	//создание двухпалубного корабля
	void build_Singledeck(char **&);	//создание однопалубного корабля
	bool fight			 (char **&);	//проверка попал-непопал
};

void BattleShips::create_array(char **&array)
{//создание поля
	array = new char*[size];
	for (int i = size; i > 0; --i) {
		array[i] = new char[size];
	}

	for (int i = size; i > 0; --i)
	{
		for (int j = 1; j <= size; ++j) {
			array[i][j] = '-';
		}
	}
}

void BattleShips::show_array(char **&array)
{//показать поле
	for (int i = size; i > 0; --i)
	{
		for (int j = 1; j <= size; ++j) {
			cout << setw(3) << array[i][j];
		}
		cout << endl;
	}
}

void BattleShips::show_rivalfield(char **&array)
{//обозначение выстрелов на поле соперника
	char **temp = new char*[size];	//выделение памяти под новый массив, в который передадим
									//только обозначение выстрелов
	for (int i = size; i > 0; --i)
	{
		temp[i] = new char[size];
		for (int j = 1; j <= size; ++j) {
			temp[i][j] = array[i][j];	//копируем в темп наш массив поэлементно
		}
	}

	for (int i = size; i > 0; --i)
	{
		for (int j = 1; j <= size; ++j)
		{
			if (temp[i][j] == '4' || temp[i][j] == '3' || temp[i][j] == '2' || temp[i][j] == '1') {
				temp[i][j] = '-';	//находим не подбитые клетки кораблей и затираем их
			}
		}
	}

	show_array(temp);	//выводим наш массив в консоль
}

void BattleShips::build_Fourdeck(char **&array)
{//размещение четырехпалубного корабля
	do {
		cout << "\n#### 1:\n"; cin >> y; cin >> x;

	} while (!check_ofFirstCell(array, x, y));

	array[x][y] = '4';							//обозначить клетку в поле
	system("cls");
	show_array(array);							//вывод поля в консоль												
//вторая клетка********************************************************************************
	do {
		cout << "\n#### 2:\n"; cin >> y2; cin >> x2;

	} while (!check_234Cells(array, x2, y2) || !check_diagonalCell(array, x, y, x2, y2)
		|| !check_remotenessCell(array, x, y, x2, y2));

	array[x2][y2] = '4';
	system("cls");
	show_array(array);
//третья клетка********************************************************************************
	do {
		cout << "\n#### 3:\n"; cin >> y3; cin >> x3;

	} while (!check_234Cells(array, x3, y3) || !check_diagonalCell(array, x, y, x3, y3)
		|| !check_diagonalCell(array, x2, y2, x3, y3) || (!check_remotenessCell(array, x, y, x3, y3)
		&& !check_remotenessCell(array, x2, y2, x3, y3)));

	array[x3][y3] = '4';
	system("cls");
	show_array(array);
//четвертая клетка*****************************************************************************
	do {
		cout << "\n#### 4:\n"; cin >> y4; cin >> x4;

	} while (!check_234Cells(array, x4, y4) || !check_diagonalCell(array, x, y, x4, y4)
		|| !check_diagonalCell(array, x2, y2, x4, y4) || !check_diagonalCell(array, x3, y3, x4, y4)
		|| (!check_remotenessCell(array, x, y, x4, y4) && !check_remotenessCell(array, x2, y2, x4, y4)
		&& !check_remotenessCell(array, x3, y3, x4, y4)));

	array[x4][y4] = '4';
	system("cls");
	show_array(array);
}

void BattleShips::build_Threedeck(char **&array)
{//размещение трехпалубных кораблей
	for (short i = 0; i < 2; ++i)
	{
		do {
			cout << "\n### 1|1:\n"; cin >> y; cin >> x;

		} while (!check_ofFirstCell(array, x, y));

		array[x][y] = '3';
		system("cls");
		show_array(array);
//вторая клетка
		do {
			cout << "\n### 1|2:\n"; cin >> y2; cin >> x2;

		} while (!check_234Cells(array, x2, y2) || !check_remotenessCell(array, x, y, x2, y2)
			|| !check_diagonalCell(array, x, y, x2, y2));

		array[x2][y2] = '3';
		system("cls");
		show_array(array);
//третья клетка
		do {
			cout << "\n### 1|3:\n"; cin >> y3; cin >> x3;

		} while (!check_234Cells(array, x3, y3) || (!check_remotenessCell(array, x, y, x3, y3)
			&& !check_remotenessCell(array, x2, y2, x3, y3)) || (!check_diagonalCell(array, x, y, x3, y3)
				|| !check_diagonalCell(array, x2, y2, x3, y3)));

		array[x3][y3] = '3';
		system("cls");
		show_array(array);
	}
}

void BattleShips::build_Twodeck(char **&array)
{//размещение двухпалубных кораблей
//первая клетка
	for (short i = 0; i < 3; ++i)
	{
		do {
			cout << "\n## 1|1:\n"; cin >> y; cin >> x;

		} while (!check_ofFirstCell(array, x, y));

		array[x][y] = '2';
		system("cls");
		show_array(array);
//вторая клетка		
		do {
			cout << "\n## 1|2:\n"; cin >> y2; cin >> x2;

		} while (!check_234Cells(array, x2, y2) || !check_remotenessCell(array, x, y, x2, y2)
			|| !check_diagonalCell(array, x, y, x2, y2));

		array[x2][y2] = '2';
		system("cls");
		show_array(array);
	}
}

void BattleShips::build_Singledeck(char **&array)
{//размещение однопалубных кораблей
	for (short i = 0; i < 4; ++i)
	{
		do {
			cout << "\n# 1:\n"; cin >> y; cin >> x;

		} while (!check_ofFirstCell(array, x, y));

		array[x][y] = '1';
		system("cls");
		show_array(array);
	}
}

bool BattleShips::fight(char **&array)
{//выстрел. если попал, то клетка окрашивается в Х, иначе 0.
	int fail;
	do
	{
		fail = 0;
		cout << "Your choose:\n"; cin >> y; cin >> x;

		if (y < 1 || y > size || x < 1 || x > size) {
			cout << "\nObserve the boundaries of the field! Return please.";
			fail = 1;
		}
	} while (fail != 0);

	if (array[x][y] == '4' || array[x][y] == '3' || array[x][y] == '2' || array[x][y] == '1')
	{
		cout << "\a*hit!\n";
		array[x][y] = 'X';
		return true;
	}
	else
	{
		array[x][y] = '0';
		return false;
	}
}

#endif //BATTLESHIPS_H



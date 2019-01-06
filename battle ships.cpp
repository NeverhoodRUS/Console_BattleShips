#include "check.h"
#include "auto.h"
#include "battleships.h"

#include <windows.h>
#include <string>

int main()
{
	string namePl1;		//им€ первого игрока
	string namePl2;		//второго
	char **array1;		//оба массива объ€влены в теле main(), тк их необходимо поочередно передавать
	char **array2;		//в функции.
	int    choose;		//выбор игрока (авторасстановка, либо в ручную)

	BattleShips bs;
	Check 		ch;
	Auto 		aut;

	cout << "Name of Player1: ";
	getline(cin, namePl1);
	cout << "Name of Player2: ";
	getline(cin, namePl2);
//заполнение пол€ первым игроком
//*********************************************************************************************
	system("cls");
	cout << "\t\t" << namePl1 << " make a choose:\n" << "1 - auto fill the field; 2 - indepentent:\n";
	cin >> choose;
	if (choose != 2)	//кажда€ функци€ авторасстановки расстанавливает только 1 корбль,
	{					//поэтому вызываем каждую нужное кол-во раз
		bs.create_array			  (array1);
		aut.autoFilling_fourDeck  (array1);
		aut.autoFilling_threeDeck (array1);
		aut.autoFilling_threeDeck (array1);
		aut.autoFilling_twoDeck   (array1);
		aut.autoFilling_twoDeck	  (array1);
		aut.autoFilling_twoDeck   (array1);
		aut.autoFilling_singleDeck(array1);
		aut.autoFilling_singleDeck(array1);
		aut.autoFilling_singleDeck(array1);
		aut.autoFilling_singleDeck(array1);
		system("cls");
		bs.show_array(array1);
		Sleep(2000);
		system("cls");
	}
	else if (choose != 1)
	{
		bs.create_array	   (array1);			//создание пол€
		bs.build_Fourdeck  (array1);			//размещение четырехпалубных
		bs.build_Threedeck (array1);			//...трехпалубных
		bs.build_Twodeck   (array1);			//...двухпалубных
		bs.build_Singledeck(array1);		//...однопалубных
	}
//заполнение пол€ вторым игроком
//********************************************************************************************	
	cout << "\t\t" << namePl2 << " make a choose:\n" << "1 - auto fill the field; 2 - indepentent:\n";
	cin >> choose;
	if (choose != 2)
	{
		bs.create_array		      (array2);
		aut.autoFilling_fourDeck  (array2);
		aut.autoFilling_threeDeck (array2);
		aut.autoFilling_threeDeck (array2);
		aut.autoFilling_twoDeck   (array2);
		aut.autoFilling_twoDeck   (array2);
		aut.autoFilling_twoDeck   (array2);
		aut.autoFilling_singleDeck(array2);
		aut.autoFilling_singleDeck(array2);
		aut.autoFilling_singleDeck(array2);
		aut.autoFilling_singleDeck(array2);
		system("cls");
		bs.show_array(array2);
		Sleep(2000);
	}
	else if (choose != 1)
	{
		bs.create_array	   (array2);
		bs.build_Fourdeck  (array2);
		bs.build_Threedeck (array2);
		bs.build_Twodeck   (array2);
		bs.build_Singledeck(array2);
	}

	cout << endl;
	
//игра продолжаетс€ до тех пор, пока на одном из полей есть корабли
	do
	{
		system("cls");
		do
		{
			cout << "\n* * *The move of " << namePl1 << "* * *\n";
			bs.show_rivalfield(array2);

		} while (bs.fight(array2));			//выстрел первым игроком по полю второго игрока

		bs.show_rivalfield(array2);
		Sleep(1300);

		if (ch.result(array2))
		{
			cout << endl << namePl1 << " winner!\n\n";
			break;
		}

		system("cls");
		do
		{
			cout << "\n* * *The move of " << namePl2 << "* * *\n";
			bs.show_rivalfield(array1);

		} while (bs.fight(array1));			//выстрел вторым игроком по полю первого игрока

		bs.show_rivalfield(array1);
		Sleep(1300);

		if (ch.result(array1))
		{
			cout << endl << namePl2 << " winner\n\n!";
			break;
		}

	} while (!ch.result(array1) || !ch.result(array2));
	
	system("pause");
	return 0;
}

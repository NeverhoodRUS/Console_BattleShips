#include "check.h"
#include "auto.h"
#include "battleships.h"

#include <windows.h>
#include <string>

int main()
{
	string namePl1;		//��� ������� ������
	string namePl2;		//�������
	char **array1;		//��� ������� ��������� � ���� main(), �� �� ���������� ���������� ����������
	char **array2;		//� �������.
	int    choose;		//����� ������ (���������������, ���� � ������)

	BattleShips bs;
	Check 		ch;
	Auto 		aut;

	cout << "Name of Player1: ";
	getline(cin, namePl1);
	cout << "Name of Player2: ";
	getline(cin, namePl2);
//���������� ���� ������ �������
//*********************************************************************************************
	system("cls");
	cout << "\t\t" << namePl1 << " make a choose:\n" << "1 - auto fill the field; 2 - indepentent:\n";
	cin >> choose;
	if (choose != 2)	//������ ������� ��������������� ��������������� ������ 1 ������,
	{					//������� �������� ������ ������ ���-�� ���
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
		bs.create_array	   (array1);			//�������� ����
		bs.build_Fourdeck  (array1);			//���������� ���������������
		bs.build_Threedeck (array1);			//...������������
		bs.build_Twodeck   (array1);			//...������������
		bs.build_Singledeck(array1);		//...������������
	}
//���������� ���� ������ �������
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
	
//���� ������������ �� ��� ���, ���� �� ����� �� ����� ���� �������
	do
	{
		system("cls");
		do
		{
			cout << "\n* * *The move of " << namePl1 << "* * *\n";
			bs.show_rivalfield(array2);

		} while (bs.fight(array2));			//������� ������ ������� �� ���� ������� ������

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

		} while (bs.fight(array1));			//������� ������ ������� �� ���� ������� ������

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

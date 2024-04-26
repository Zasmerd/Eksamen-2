// Eksamen 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// https://github.com/rashev2021/MemoryGamesCards/blob/master/MemoryGames/Default.h
//

#include "TXlib.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <Windows.h>
#include "Default.h"
#include <rpcasync.h>
#include <wtypes.h>
#pragma comment(lib, "winmm.lib")
using namespace std;
void Menu()
{
	PlaySound(TEXT("menu.wav"), NULL, SND_FILENAME | SND_ASYNC);

	cout << endl << endl;
	cout << "\t\t\t\t\t\t #########################################################" << endl;
	cout << "\t\t\t\t\t\t ###############                       ###################" << endl;
	cout << "\t\t\t\t\t\t ###############    IGRA ""MEMORY""    ###################" << endl;
	cout << "\t\t\t\t\t\t ###############                       ###################" << endl;
	cout << "\t\t\t\t\t\t ###############                       ###################" << endl;
	cout << "\t\t\t\t\t\t Vnimanie! V igre net nadpisey igrayte na swoy strah i risk. Udachi!" << endl;
	cout << "\t\t\t\t\t\t #########################################################" << endl << endl;

	cout << "\t\t\t\t\t\t #########################################################" << endl;
	cout << "\t\t\t\t\t\t ###############       MENU IGRI       ###################" << endl << endl;
	cout << "\t\t\t\t\t\t #### POLE 4x2 (8 cart)                   - najmite [1]###" << endl;
	cout << "\t\t\t\t\t\t #### POLE 4x3 (12 cart)                  - najmite [2]###" << endl;
	cout << "\t\t\t\t\t\t #### VIYTI IZ IGRI                      - najmite [0] ###" << endl;
	cout << "\t\t\t\t\t\t #########################################################" << endl;
	cout << "\t\t\t\t\t\t #### SDELAYTE SWOI VIBOR I NAJMITE ENTER:  ";

	char i;
	County doc;
	doc.count = 0;
	doc.concidences = 0;
	doc.timer = 0;

	do
	{
		cin >> i;

		PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

		switch (i)
		{
		case '1':

			cout << endl << endl << "\t\t\t\t\t\t POLE 4x2 (8 cart)." << endl;
			cout << "\t\t\t\t\t\t IDET ZAGRUZKA ";
			PlaySound(TEXT("start.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Sleep(1000);
			cout << " .";
			Sleep(1000);
			cout << " .";
			Sleep(1000);
			cout << " .";
			Sleep(1000);
			cout << " .";
			Sleep(1000);
			cout << " .";
			Sleep(1000);
			cout << " .";
			Sleep(1000);
			cout << " .";
			Sleep(1000);
			cout << " .";
			Sleep(1000);
			cout << endl << endl << endl << endl << "\t\t\t\t\t\t ##################### IGRA MEMORY #####################" << endl;
			Sleep(1500);
			system("cls");
			StartGame_4x2(doc);
			break;

		case '2':
			cout << endl << endl << "\t\t\t\t\t\t POLE 4x3 (12 cart)." << endl;
			cout << "\t\t\t\t\t\t IDET ZAGRUZKA ";
			PlaySound(TEXT("start.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Sleep(1000);
			cout << " .";
			Sleep(1000);
			cout << " .";
			Sleep(1000);
			cout << " .";
			Sleep(1000);
			cout << " .";
			Sleep(1000);
			cout << " .";
			Sleep(1000);
			cout << " .";
			Sleep(1000);
			cout << " .";
			Sleep(1000);
			cout << " .";
			Sleep(1000);
			cout << endl << endl << endl << endl << "\t\t\t\t\t\t ##################### IGRA MEMORY #####################" << endl;
			Sleep(1500);
			system("cls");
			StartGame_4x3(doc);
			break;

		case '0':
			cout << endl << "\t\t\t\t\t\t VIHOD IZ IGRI." << endl;
			break;

		default:
			PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
			cout << endl << "\t\t\t\t\t\t NET. VIBERI SHTO-TO DRUGOE..." << endl;
			cout << "\t\t\t\t\t\t #### SDELAITE SWOI VIBOR I NAJMITE ENTER:  ";
			break;
		}

	} while (i == '0');
}
void Examination_4x2(char a, char a1, char b, char b1, char c, char c1, char d, char d1, char f, char f1, char f2, char f3, char f4, char f5, char f6, char f7, County doc)
{

	char o;

	if (a == '!' && c == '!' || b == '@' && c1 == '@' || d == '*' && a1 == '*' || b1 == '$' && d1 == '$')
	{
		doc.concidences++;
		PlaySound(TEXT("win2.wav"), NULL, SND_FILENAME | SND_ASYNC);
		cout << endl << "\t\t\t\t\t\t\t Íàéäåíî ñîâïàäåíèå." << endl;
		cout << endl << "\t\t\t\t\t\t\t Êîëè÷åñòâî ñîâïàäåíèé: " << doc.concidences << endl << endl;
		Sleep(1500);
		cout << "\t\t\t\t\t\t\t VIBERITE CARTU    - najmite [1]" << endl;
		cout << "\t\t\t\t\t\t\t Viyty       - najmite [2]" << endl;
		cout << "\t\t\t\t\t\t\t VIBERITE I NAJMITE Enter: ";

		if (a == '!' && c == '!')
		{
			a = c = f = f2 = ' ';
		}
		if (b == '@' && c1 == '@')
		{
			b = c1 = f1 = f6 = ' ';
		}
		if (d == '*' && a1 == '*')
		{
			d = a1 = f3 = f4 = ' ';
		}
		if (b1 == '$' && d1 == '$')
		{
			b1 = d1 = f5 = f7 = ' ';
		}

		do
		{
			cin >> o;
			PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			switch (o)
			{
			case '1':
				system("cls");
				StartGameNext_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				break;

			case '2':
				system("cls");
				Menu();
				break;

			default:
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Íå ïðàâèëüíî ñäåëàí âûáîð. Ïîâòîðèòå ïîïûòêó..." << endl;
				cout << "\t\t\t\t\t\t\t Ñäåëàéòå ñâîé âûáîð è íàæìèòå Enter: ";
				break;
			}
		} while (true);

	}
	else
	{
		system("cls");
		doc.count++;
		PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
		Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
		cout << endl << "\t\t\t\t\t\t\t Ñîâïàäåíèé íå íàéäåíî" << endl << endl;
		cout << endl << "\t\t\t\t\t\t\t Êîëè÷åñòâî ïåðåâîðîòîâ êàðò: " << doc.count << endl << endl;
		Sleep(1500);

		cout << "\t\t\t\t\t\t\t Íà÷àòü èãðó çàíîâî    - íàæìèòå [1]" << endl;
		cout << "\t\t\t\t\t\t\t Âûéòè â ìåíþ          - íàæìèòå [2]" << endl;
		cout << "\t\t\t\t\t\t\t Ñäåëàéòå ñâîé âûáîð è íàæìèòå Enter: ";

		do
		{
			cin >> o;
			PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			switch (o)
			{
			case '1':
				system("cls");
				StartGame_4x2(doc);
				break;

			case '2':
				system("cls");
				Menu();
				break;

			default:
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << endl << "\t\t\t\t\t\t\t Íå ïðàâèëüíî ñäåëàí âûáîð. Ïîâòîðèòå ïîïûòêó..." << endl;
				cout << "\t\t\t\t\t\t\t Ñäåëàéòå ñâîé âûáîð è íàæìèòå Enter: ";
				break;
			}
		} while (true);
	}
}
void Examination_4x3(char a, char a1, char b, char b1, char c, char c1, char d, char d1, char e1, char g1, char h1, char k1, char f, char f1, char f2, char f3, char f4, char f5, char f6, char f7, char f8, char f9, char f10, char f11, County doc)
{

	char o;

	if (a == '5' && c == '5' || b == '8' && d == '8' || c1 == '6' && a1 == '6' || b1 == '3' && d1 == '3' || e1 == '4' && h1 == '4' || g1 == '2' && k1 == '2')
	{
		doc.concidences++;
		PlaySound(TEXT("win2.wav"), NULL, SND_FILENAME | SND_ASYNC);
		cout << endl << "\t\t\t\t\t\t\t Íàéäåíî ñîâïàäåíèå." << endl;
		cout << endl << "\t\t\t\t\t\t\t Âðåìÿ èãðû: " << doc.timer << endl;
		cout << endl << "\t\t\t\t\t\t\t Êîëè÷åñòâî ñîâïàäåíèé: " << doc.concidences << endl << endl;
		Sleep(1500);
		cout << "\t\t\t\t\t\t\t Ïðîäîëæèòü èãðó    - najmite [1]" << endl;
		cout << "\t\t\t\t\t\t\t Âûéòè â ìåíþ       - najmite [2]" << endl;
		cout << "\t\t\t\t\t\t\t Vash vibor Enter: ";

		if (a == '5' && c == '5')
		{
			a = c = f = f2 = ' ';
		}
		if (b == '8' && d == '8')
		{
			b = d = f1 = f3 = ' ';
		}
		if (c1 == '6' && a1 == '6')
		{
			c1 = a1 = f3 = f6 = ' ';
		}
		if (b1 == '3' && d1 == '3')
		{
			b1 = d1 = f5 = f7 = ' ';
		}
		if (e1 == '4' && h1 == '4')
		{
			e1 = h1 = f8 = f10 = ' ';
		}
		if (g1 == '2' && k1 == '2')
		{
			g1 = k1 = f9 = f11 = ' ';
		}

		do
		{
			cin >> o;
			PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			switch (o)
			{
			case '1':
				system("cls");
				StartGameNext_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				break;

			case '2':
				system("cls");
				Menu();
				break;

			default:
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Íå ïðàâèëüíî ñäåëàí âûáîð. Ïîâòîðèòå ïîïûòêó..." << endl;
				cout << "\t\t\t\t\t\t\t Ñäåëàéòå ñâîé âûáîð è íàæìèòå Enter: ";
				break;
			}
		} while (true);

	}
	else
	{
		system("cls");
		doc.count++;
		PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
		Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
		cout << endl << "\t\t\t\t\t\t\t Ñîâïàäåíèé íå íàéäåíî" << endl << endl;
		cout << endl << "\t\t\t\t\t\t\t Êîëè÷åñòâî ïåðåâîðîòîâ êàðò: " << doc.count << endl << endl;
		Sleep(1500);

		cout << "\t\t\t\t\t\t\t Íà÷àòü èãðó çàíîâî    - íàæìèòå [1]" << endl;
		cout << "\t\t\t\t\t\t\t Âûéòè â ìåíþ          - íàæìèòå [2]" << endl;
		cout << "\t\t\t\t\t\t\t Ñäåëàéòå ñâîé âûáîð è íàæìèòå Enter: ";

		do
		{
			cin >> o;
			PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			switch (o)
			{
			case '1':
				system("cls");
				StartGame_4x3(doc);
				break;

			case '2':
				system("cls");
				Menu();
				break;

			default:
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << endl << "\t\t\t\t\t\t\t Íå ïðàâèëüíî ñäåëàí âûáîð. Ïîâòîðèòå ïîïûòêó..." << endl;
				cout << "\t\t\t\t\t\t\t Ñäåëàéòå ñâîé âûáîð è íàæìèòå Enter: ";
				break;
			}
		} while (true);
	}
}

void Card_4x3(char a, char a1, char b, char b1, char c, char c1, char d, char d1, char e1, char g1, char h1, char k1, char f, char f1, char f2, char f3, char f4, char f5, char f6, char f7, char f8, char f9, char f10, char f11)
{
	//ïåðâûé ðÿä
	cout << endl << "\t\t\t\t\t\t\t  -" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  " << endl;

	cout << "\t\t\t\t\t\t\t | " << a << " " << f << " " << f << " " << a << " |" <<
		"| " << b << " " << f1 << " " << f1 << " " << b << " |" <<
		"| " << c << " " << f2 << " " << f2 << " " << c << " |" <<
		"| " << d << " " << f3 << " " << f3 << " " << d << " |" << endl;

	cout << "\t\t\t\t\t\t\t | " << f << " " << f << " " << f << " " << f << " |" <<
		"| " << f1 << " " << f1 << " " << f1 << " " << f1 << " |" <<
		"| " << f2 << " " << f2 << " " << f2 << " " << f2 << " |" <<
		"| " << f3 << " " << f3 << " " << f3 << " " << f3 << " |" << endl;

	cout << "\t\t\t\t\t\t\t | " << f << " " << a << " " << a << " " << f << " |" <<
		"| " << f1 << " " << b << " " << b << " " << f1 << " |" <<
		"| " << f2 << " " << c << " " << c << " " << f2 << " |" <<
		"| " << f3 << " " << d << " " << d << " " << f3 << " |" << endl;

	cout << "\t\t\t\t\t\t\t | " << f << " " << a << " " << a << " " << f << " |" <<
		"| " << f1 << " " << b << " " << b << " " << f1 << " |" <<
		"| " << f2 << " " << c << " " << c << " " << f2 << " |" <<
		"| " << f3 << " " << d << " " << d << " " << f3 << " |" << endl;

	cout << "\t\t\t\t\t\t\t | " << f << " " << f << " " << f << " " << f << " |" <<
		"| " << f1 << " " << f1 << " " << f1 << " " << f1 << " |" <<
		"| " << f2 << " " << f2 << " " << f2 << " " << f2 << " |" <<
		"| " << f3 << " " << f3 << " " << f3 << " " << f3 << " |" << endl;

	cout << "\t\t\t\t\t\t\t | " << a << " " << f << " " << f << " " << a << " |" <<
		"| " << b << " " << f1 << " " << f1 << " " << b << " |" <<
		"| " << c << " " << f2 << " " << f2 << " " << c << " |" <<
		"| " << d << " " << f3 << " " << f3 << " " << d << " |" << endl;

	cout << "\t\t\t\t\t\t\t  -" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  " << endl;

	//âòîðîé ðÿä
	cout << "\t\t\t\t\t\t\t  -" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  " << endl;

	cout << "\t\t\t\t\t\t\t | " << a1 << " " << f4 << " " << f4 << " " << a1 << " |" <<
		"| " << b1 << " " << f5 << " " << f5 << " " << b1 << " |" <<
		"| " << c1 << " " << f6 << " " << f6 << " " << c1 << " |" <<
		"| " << d1 << " " << f7 << " " << f7 << " " << d1 << " |" << endl;

	cout << "\t\t\t\t\t\t\t | " << f4 << " " << f4 << " " << f4 << " " << f4 << " |" <<
		"| " << f5 << " " << f5 << " " << f5 << " " << f5 << " |" <<
		"| " << f6 << " " << f6 << " " << f6 << " " << f6 << " |" <<
		"| " << f7 << " " << f7 << " " << f7 << " " << f7 << " |" << endl;

	cout << "\t\t\t\t\t\t\t | " << f4 << " " << a1 << " " << a1 << " " << f4 << " |" <<
		"| " << f5 << " " << b1 << " " << b1 << " " << f5 << " |" <<
		"| " << f6 << " " << c1 << " " << c1 << " " << f6 << " |" <<
		"| " << f7 << " " << d1 << " " << d1 << " " << f7 << " |" << endl;

	cout << "\t\t\t\t\t\t\t | " << f4 << " " << a1 << " " << a1 << " " << f4 << " |" <<
		"| " << f5 << " " << b1 << " " << b1 << " " << f5 << " |" <<
		"| " << f6 << " " << c1 << " " << c1 << " " << f6 << " |" <<
		"| " << f7 << " " << d1 << " " << d1 << " " << f7 << " |" << endl;

	cout << "\t\t\t\t\t\t\t | " << f4 << " " << f4 << " " << f4 << " " << f4 << " |" <<
		"| " << f5 << " " << f5 << " " << f5 << " " << f5 << " |" <<
		"| " << f6 << " " << f6 << " " << f6 << " " << f6 << " |" <<
		"| " << f7 << " " << f7 << " " << f7 << " " << f7 << " |" << endl;

	cout << "\t\t\t\t\t\t\t | " << a1 << " " << f4 << " " << f4 << " " << a1 << " |" <<
		"| " << b1 << " " << f5 << " " << f5 << " " << b1 << " |" <<
		"| " << c1 << " " << f6 << " " << f6 << " " << c1 << " |" <<
		"| " << d1 << " " << f7 << " " << f7 << " " << d1 << " |" << endl;

	cout << "\t\t\t\t\t\t\t  -" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  " << endl;

	//òðåòèé ðÿä
	cout << "\t\t\t\t\t\t\t  -" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  " << endl;

	cout << "\t\t\t\t\t\t\t | " << e1 << " " << f8 << " " << f8 << " " << e1 << " |" <<
		"| " << g1 << " " << f9 << " " << f9 << " " << g1 << " |" <<
		"| " << h1 << " " << f10 << " " << f10 << " " << h1 << " |" <<
		"| " << k1 << " " << f11 << " " << f11 << " " << k1 << " |" << endl;

	cout << "\t\t\t\t\t\t\t | " << f8 << " " << f8 << " " << f8 << " " << f8 << " |" <<
		"| " << f9 << " " << f9 << " " << f9 << " " << f9 << " |" <<
		"| " << f10 << " " << f10 << " " << f10 << " " << f10 << " |" <<
		"| " << f11 << " " << f11 << " " << f11 << " " << f11 << " |" << endl;

	cout << "\t\t\t\t\t\t\t | " << f8 << " " << e1 << " " << e1 << " " << f8 << " |" <<
		"| " << f9 << " " << g1 << " " << g1 << " " << f9 << " |" <<
		"| " << f10 << " " << h1 << " " << h1 << " " << f10 << " |" <<
		"| " << f11 << " " << k1 << " " << k1 << " " << f11 << " |" << endl;

	cout << "\t\t\t\t\t\t\t | " << f8 << " " << e1 << " " << e1 << " " << f8 << " |" <<
		"| " << f9 << " " << g1 << " " << g1 << " " << f9 << " |" <<
		"| " << f10 << " " << h1 << " " << h1 << " " << f10 << " |" <<
		"| " << f11 << " " << k1 << " " << k1 << " " << f11 << " |" << endl;

	cout << "\t\t\t\t\t\t\t | " << f8 << " " << f8 << " " << f8 << " " << f8 << " |" <<
		"| " << f9 << " " << f9 << " " << f9 << " " << f9 << " |" <<
		"| " << f10 << " " << f10 << " " << f10 << " " << f10 << " |" <<
		"| " << f11 << " " << f11 << " " << f11 << " " << f11 << " |" << endl;

	cout << "\t\t\t\t\t\t\t | " << e1 << " " << f8 << " " << f8 << " " << e1 << " |" <<
		"| " << g1 << " " << f9 << " " << f9 << " " << g1 << " |" <<
		"| " << h1 << " " << f10 << " " << f10 << " " << h1 << " |" <<
		"| " << k1 << " " << f11 << " " << f11 << " " << k1 << " |" << endl;

	cout << "\t\t\t\t\t\t\t  -" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  " << endl;

}
void Card_4x2(char a, char a1, char b, char b1, char c, char c1, char d, char d1, char f, char f1, char f2, char f3, char f4, char f5, char f6, char f7)
{

	//ïåðâûé ðÿä
	cout << endl << "\t\t\t\t\t\t\t  -" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  " << endl;

	cout << "\t\t\t\t\t\t\t | " << a << " " << f << " " << f << " " << a << " |" <<
		"| " << b << " " << f1 << " " << f1 << " " << b << " |" <<
		"| " << c << " " << f2 << " " << f2 << " " << c << " |" <<
		"| " << d << " " << f3 << " " << f3 << " " << d << " |" << endl;

	cout << "\t\t\t\t\t\t\t | " << f << " " << f << " " << f << " " << f << " |" <<
		"| " << f1 << " " << f1 << " " << f1 << " " << f1 << " |" <<
		"| " << f2 << " " << f2 << " " << f2 << " " << f2 << " |" <<
		"| " << f3 << " " << f3 << " " << f3 << " " << f3 << " |" << endl;

	cout << "\t\t\t\t\t\t\t | " << f << " " << a << " " << a << " " << f << " |" <<
		"| " << f1 << " " << b << " " << b << " " << f1 << " |" <<
		"| " << f2 << " " << c << " " << c << " " << f2 << " |" <<
		"| " << f3 << " " << d << " " << d << " " << f3 << " |" << endl;

	cout << "\t\t\t\t\t\t\t | " << f << " " << a << " " << a << " " << f << " |" <<
		"| " << f1 << " " << b << " " << b << " " << f1 << " |" <<
		"| " << f2 << " " << c << " " << c << " " << f2 << " |" <<
		"| " << f3 << " " << d << " " << d << " " << f3 << " |" << endl;

	cout << "\t\t\t\t\t\t\t | " << f << " " << f << " " << f << " " << f << " |" <<
		"| " << f1 << " " << f1 << " " << f1 << " " << f1 << " |" <<
		"| " << f2 << " " << f2 << " " << f2 << " " << f2 << " |" <<
		"| " << f3 << " " << f3 << " " << f3 << " " << f3 << " |" << endl;

	cout << "\t\t\t\t\t\t\t | " << a << " " << f << " " << f << " " << a << " |" <<
		"| " << b << " " << f1 << " " << f1 << " " << b << " |" <<
		"| " << c << " " << f2 << " " << f2 << " " << c << " |" <<
		"| " << d << " " << f3 << " " << f3 << " " << d << " |" << endl;

	cout << "\t\t\t\t\t\t\t  -" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  " << endl;

	//âòîðîé ðÿä
	cout << "\t\t\t\t\t\t\t  -" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  " << endl;

	cout << "\t\t\t\t\t\t\t | " << a1 << " " << f4 << " " << f4 << " " << a1 << " |" <<
		"| " << b1 << " " << f5 << " " << f5 << " " << b1 << " |" <<
		"| " << c1 << " " << f6 << " " << f6 << " " << c1 << " |" <<
		"| " << d1 << " " << f7 << " " << f7 << " " << d1 << " |" << endl;

	cout << "\t\t\t\t\t\t\t | " << f4 << " " << f4 << " " << f4 << " " << f4 << " |" <<
		"| " << f5 << " " << f5 << " " << f5 << " " << f5 << " |" <<
		"| " << f6 << " " << f6 << " " << f6 << " " << f6 << " |" <<
		"| " << f7 << " " << f7 << " " << f7 << " " << f7 << " |" << endl;

	cout << "\t\t\t\t\t\t\t | " << f4 << " " << a1 << " " << a1 << " " << f4 << " |" <<
		"| " << f5 << " " << b1 << " " << b1 << " " << f5 << " |" <<
		"| " << f6 << " " << c1 << " " << c1 << " " << f6 << " |" <<
		"| " << f7 << " " << d1 << " " << d1 << " " << f7 << " |" << endl;

	cout << "\t\t\t\t\t\t\t | " << f4 << " " << a1 << " " << a1 << " " << f4 << " |" <<
		"| " << f5 << " " << b1 << " " << b1 << " " << f5 << " |" <<
		"| " << f6 << " " << c1 << " " << c1 << " " << f6 << " |" <<
		"| " << f7 << " " << d1 << " " << d1 << " " << f7 << " |" << endl;

	cout << "\t\t\t\t\t\t\t | " << f4 << " " << f4 << " " << f4 << " " << f4 << " |" <<
		"| " << f5 << " " << f5 << " " << f5 << " " << f5 << " |" <<
		"| " << f6 << " " << f6 << " " << f6 << " " << f6 << " |" <<
		"| " << f7 << " " << f7 << " " << f7 << " " << f7 << " |" << endl;

	cout << "\t\t\t\t\t\t\t | " << a1 << " " << f4 << " " << f4 << " " << a1 << " |" <<
		"| " << b1 << " " << f5 << " " << f5 << " " << b1 << " |" <<
		"| " << c1 << " " << f6 << " " << f6 << " " << c1 << " |" <<
		"| " << d1 << " " << f7 << " " << f7 << " " << d1 << " |" << endl;

	cout << "\t\t\t\t\t\t\t  -" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  "
		<< "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "-" << "  " << endl;
}

void StartGameNext_4x2(char a, char a1, char b, char b1, char c, char c1, char d, char d1, char f, char f1, char f2, char f3, char f4, char f5, char f6, char f7, County doc)
{

	char p;
	char p1 = '0';

	if (a != ' ' || c != ' ' || b != ' ' || c1 != ' ' || d != ' ' || a1 != ' ' || b1 != ' ' || d1 != ' ')
	{
		Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
	}

	if (a == ' ' && c == ' ' && b == ' ' && c1 == ' ' && d == ' ' && a1 == ' ' && b1 == ' ' && d1 == ' ')
	{
		PlaySound(TEXT("winner.wav"), NULL, SND_FILENAME | SND_ASYNC);
		doc.end = clock();
		doc.timer = (doc.end - doc.start) / CLOCKS_PER_SEC;
		cout << endl << "\t\t\t\t\t\t\t  URAAA!!! TI PROSHOL!!!" << endl;
		cout << endl << "\t\t\t\t\t\t\t  Vremya: " << doc.timer << " sec." << endl;
		cout << endl << "\t\t\t\t\t\t\t  Colichestwo perevarotov: " << doc.concidences << endl;
		cout << endl << "\t\t\t\t\t\t\t  Ne pravel'nih hodov: " << doc.count << endl << endl;
		cout << endl << "\t\t\t\t\t\t\t  Vse vashi carty. " << endl << endl;

		Card_4x2(a = '!', a1 = '*', b = '@', b1 = '$', c = '!', c1 = '@', d = '*', d1 = '$', f, f1, f2, f3, f4, f5, f6, f7);

		Sleep(5100);
		system("cls");
		Menu();
	}

	cout << endl << "\t\t\t\t\t\t\t Îòêðîéòå äâå ëþáûå êàðòû." << endl;
	cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå îäíó èç êàðò è íàæìèòå Enter: ";

	do
	{
		cin >> p;
		PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

		if (p > '8' || p == '0')
		{
			PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
			cout << endl << "\t\t\t\t\t\t\t Òàêîé êàðòû íåò. Ïîâòîðèòå ïîïûòêó..." << endl << endl;
			cout << "\t\t\t\t\t\t\t Îòêðîéòå äâå ëþáûå êàðòû." << endl;
			cout << "\t\t\t\t\t\t\t Âûáåðèòå îäíó èç êàðò è íàæìèòå Enter: ";
		}
		if (p == '1')
		{
			if (a == ' ')
			{

				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
				cin >> p;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			}
			else
			{
				a = '!';
				f = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðàþ êàðòó è íàæìèòå Enter: ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				if (p1 == '1' || p1 == '0' || p1 > '8')
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Ïåðâàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}

			if (p1 == '2')
			{
				if (b == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				}
				else
				{
					b = '@';
					f1 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '3')
			{
				if (c == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				}
				else
				{
					c = '!';
					f2 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '4')
			{
				if (d == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				}
				else
				{
					d = '*';
					f3 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}
			if (p1 == '5')
			{
				if (a1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a1 = '*';
					f4 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '6')
			{
				if (b1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b1 = '$';
					f5 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '7')
			{
				if (c1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c1 = '@';
					f6 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '8')
			{
				if (d1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				}
				else
				{
					d1 = '$';
					f7 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}
		}

		if (p == '2')
		{
			if (b == ' ')
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
				cin >> p;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else
			{
				b = '@';
				f1 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðàþ êàðòó è íàæìèòå Enter: ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				if (p1 == '2' || p1 == '0' || p1 > '8')
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Ïåðâàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}

			if (p1 == '1')
			{
				if (a == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a = '!';
					f = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '3')
			{
				if (c == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c = '!';
					f2 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '4')
			{
				if (d == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d = '*';
					f3 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '5')
			{

				if (a1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a1 = '*';
					f4 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '6')
			{
				if (b1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b1 = '$';
					f5 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '7')
			{
				if (c1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c1 = '@';
					f6 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '8')
			{
				if (d1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d1 = '$';
					f7 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}
		}

		if (p == '3')
		{
			if (c == ' ')
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
				cin >> p;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else
			{
				c = '!';
				f2 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðàþ êàðòó è íàæìèòå Enter: ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				if (p1 == '3' || p1 == '0' || p1 > '8')
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Ïåðâàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}

			if (p1 == '1')
			{

				if (a == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a = '!';
					f = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}

			}
			if (p1 == '2')
			{
				if (b == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b = '@';
					f1 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '4')
			{
				if (d == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d = '*';
					f3 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '5')
			{
				if (a1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a1 = '*';
					f4 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '6')
			{
				if (b1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b1 = '$';
					f5 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '7')
			{
				if (c1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c1 = '@';
					f6 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '8')
			{
				if (d1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d1 = '$';
					f7 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}
		}

		if (p == '4')
		{
			if (d == ' ')
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
				cin >> p;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else
			{
				d = '*';
				f3 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðàþ êàðòó è íàæìèòå Enter: ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				if (p1 == '4' || p1 == '0' || p1 > '8')
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Ïåðâàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}

			if (p1 == '1')
			{
				if (a == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a = '!';
					f = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '2')
			{
				if (b == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b = '@';
					f1 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '3')
			{
				if (c == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c = '!';
					f2 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '5')
			{
				if (a1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a1 = '*';
					f4 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '6')
			{
				if (b1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b1 = '$';
					f5 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '7')
			{
				if (c1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c1 = '@';
					f6 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '8')
			{
				if (d1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d1 = '$';
					f7 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}
		}

		if (p == '5')
		{
			if (a1 == ' ')
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
				cin >> p;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else
			{
				a1 = '*';
				f4 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðàþ êàðòó è íàæìèòå Enter: ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				if (p1 == '5' || p1 == '0' || p1 > '8')
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Ïåðâàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}

			if (p1 == '1')
			{
				if (a == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a = '!';
					f = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '2')
			{
				if (b == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b = '@';
					f1 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '3')
			{
				if (c == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c = '!';
					f2 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '4')
			{
				if (d == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d = '*';
					f3 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '6')
			{
				if (b1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b1 = '$';
					f5 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '7')
			{
				if (c1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c1 = '@';
					f6 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '8')
			{
				if (d1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d1 = '$';
					f7 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}
		}

		if (p == '6')
		{
			if (b1 == ' ')
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
				cin >> p;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else
			{
				b1 = '$';
				f5 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðàþ êàðòó è íàæìèòå Enter: ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				if (p1 == '6' || p1 == '0' || p1 > '8')
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Ïåðâàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}

			if (p1 == '1')
			{
				if (a == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a = '!';
					f = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '2')
			{
				if (b == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b = '@';
					f1 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '3')
			{
				if (c == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c = '!';
					f2 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '4')
			{
				if (d == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d = '*';
					f3 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '5')
			{
				if (a1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a1 = '*';
					f4 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '7')
			{
				if (c1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c1 = '@';
					f6 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '8')
			{
				if (d1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d1 = '$';
					f7 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}
		}

		if (p == '7')
		{
			if (c1 == ' ')
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
				cin >> p;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else
			{
				c1 = '@';
				f6 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðàþ êàðòó è íàæìèòå Enter: ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				if (p1 == '7' || p1 == '0' || p1 > '8')
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Ïåðâàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}

			if (p1 == '1')
			{
				if (a == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a = '!';
					f = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '2')
			{
				if (b == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b = '@';
					f1 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '3')
			{
				if (c == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c = '!';
					f2 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '4')
			{
				if (d == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d = '*';
					f3 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '5')
			{
				if (a1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a1 = '*';
					f4 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '6')
			{
				if (b1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b1 = '$';
					f5 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '8')
			{
				if (d1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d1 = '$';
					f7 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}
		}

		if (p == '8')
		{
			if (d1 == ' ')
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
				cin >> p;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else
			{
				d1 = '$';
				f7 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðàþ êàðòó è íàæìèòå Enter: ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				if (p1 >= '8' || p1 == '0')
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Ïåðâàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}

			if (p1 == '1')
			{
				if (a == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a = '!';
					f = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '2')
			{
				if (b == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b = '@';
					f1 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '3')
			{
				if (c == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c = '!';
					f2 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '4')
			{
				if (d == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d = '*';
					f3 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '5')
			{
				if (a1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a1 = '*';
					f4 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '6')
			{
				if (b1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b1 = '$';
					f5 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}

			if (p1 == '7')
			{
				if (c1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c1 = '@';
					f6 = ' ';
					system("cls");
					Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
					Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
				}
			}
		}

	} while (true);
}
void StartGameNext_4x3(char a, char a1, char b, char b1, char c, char c1, char d, char d1, char e1, char g1, char h1, char k1, char f, char f1, char f2, char f3, char f4, char f5, char f6, char f7, char f8, char f9, char f10, char f11, County doc)
{

	int p;
	int p1 = 0;

	if (a != ' ' || c != ' ' || b != ' ' || d != ' ' || c1 != ' ' || a1 != ' ' || b1 != ' ' || d1 != ' ' || e1 != ' ' || h1 != ' ' || g1 != ' ' || k1 != ' ')
	{
		Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
	}

	if (a == ' ' && c == ' ' && b == ' ' && d == ' ' && c1 == ' ' && a1 == ' ' && b1 == ' ' && d1 == ' ' && e1 == ' ' && h1 == ' ' && g1 == ' ' && k1 == ' ')
	{
		PlaySound(TEXT("winner.wav"), NULL, SND_FILENAME | SND_ASYNC);
		doc.end = clock();
		doc.timer = (doc.end - doc.start) / CLOCKS_PER_SEC;
		cout << endl << "\t\t\t\t\t\t\t  Uraa!!! Ti proshol!!!" << endl;
		cout << endl << "\t\t\t\t\t\t\t  Vremya: " << doc.timer << " sec." << endl;;
		cout << endl << "\t\t\t\t\t\t\t  Colichestvo perevarotov: " << doc.concidences << endl;
		cout << endl << "\t\t\t\t\t\t\t  Colichesrvo raundov: " << doc.count << endl << endl;
		cout << endl << "\t\t\t\t\t\t\t  Vot tvoi carti. " << endl << endl;

		Card_4x3(a = '5', a1 = '6', b = '8', b1 = '3', c = '5', c1 = '6', d = '8', d1 = '3', e1 = '4', g1 = '2', h1 = '4', k1 = '2', f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);

		Sleep(5100);
		system("cls");
		Menu();
	}

	cout << endl << "\t\t\t\t\t\t\t Îòêðîéòå äâå ëþáûå êàðòû." << endl;
	cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå îäíó èç êàðò è íàæìèòå Enter: ";

	do
	{
		cin >> p;
		PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

		if (p > 12 || p == 0)
		{
			PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
			cout << endl << "\t\t\t\t\t\t\t Òàêîé êàðòû íåò. Ïîâòîðèòå ïîïûòêó..." << endl << endl;
			cout << "\t\t\t\t\t\t\t Îòêðîéòå äâå ëþáûå êàðòû." << endl;
			cout << "\t\t\t\t\t\t\t Âûáåðèòå îäíó èç êàðò è íàæìèòå Enter: ";
		}
		if (p == 1)
		{
			if (a == ' ')
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
				cin >> p;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else
			{
				a = '5';
				f = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðóþ êàðòó è íàæìèòå Enter: ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				if (p1 == 1 || p1 == 0 || p1 > 12)
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Ïåðâàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}

			if (p1 == 2)
			{
				if (b == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b = '8';
					f1 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 3)
			{
				if (c == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c = '5';
					f2 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 4)
			{
				if (d == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d = '3';
					f3 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}
			if (p1 == 5)
			{
				if (a1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a1 = '6';
					f4 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 6)
			{
				if (b1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b1 = '3';
					f5 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 7)
			{
				if (c1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c1 = '6';
					f6 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 8)
			{
				if (d1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d1 = '3';
					f7 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 9)
			{
				if (e1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					e1 = '4';
					f8 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 10)
			{
				if (g1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					g1 = '2';
					f9 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 11)
			{
				if (h1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					h1 = '4';
					f10 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 12)
			{
				if (k1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					k1 = '2';
					f11 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}
		}

		if (p == 2)
		{
			if (b == ' ')
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
				cin >> p;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else
			{
				b = '8';
				f1 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðàþ êàðòó è íàæìèòå Enter: ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				if (p1 == 2 || p1 == 0 || p1 > 12)
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Ïåðâàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}

			if (p1 == 1)
			{
				if (a == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a = '5';
					f = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 3)
			{
				if (c == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c = '5';
					f2 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 4)
			{
				if (d == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d = '8';
					f3 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 5)
			{
				if (a1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a1 = '6';
					f4 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 6)
			{
				if (b1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b1 = '3';
					f5 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 7)
			{
				if (c1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c1 = '6';
					f6 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 8)
			{
				if (d1 == ' ')
				{
					do
					{
						cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
						cin >> p1;
						PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

					} while (p1 == '8' || p1 == '0');
				}
				else
				{
					d1 = '3';
					f7 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 9)
			{
				if (e1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					e1 = '4';
					f8 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 10)
			{
				if (g1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					g1 = '2';
					f9 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 11)
			{
				if (h1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					h1 = '4';
					f10 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 12)
			{
				if (k1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					k1 = '2';
					f11 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}
		}

		if (p == 3)
		{
			if (c == ' ')
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
				cin >> p;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else
			{
				c = '5';
				f2 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðàþ êàðòó è íàæìèòå Enter: ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				if (p1 == 3 || p1 == 0 || p1 > 12)
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Ïåðâàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}

			if (p1 == 1)
			{
				if (a == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a = '5';
					f = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}

			}
			if (p1 == 2)
			{
				if (b == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b = '8';
					f1 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 4)
			{
				if (d == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d = '8';
					f3 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 5)
			{
				if (a1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a1 = '6';
					f4 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 6)
			{
				if (b1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b1 = '3';
					f5 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 7)
			{
				if (c1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c1 = '6';
					f6 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 8)
			{
				if (d1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d1 = '3';
					f7 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 9)
			{
				if (e1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					e1 = '4';
					f8 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 10)
			{
				if (g1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					g1 = '2';
					f9 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 11)
			{
				if (h1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					h1 = '4';
					f10 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 12)
			{
				if (k1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					k1 = '2';
					f11 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}
		}

		if (p == 4)
		{
			if (d == ' ')
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
				cin >> p;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else
			{
				d = '8';
				f3 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðàþ êàðòó è íàæìèòå Enter: ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				if (p1 == 4 || p1 == 0 || p1 > 12)
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Ïåðâàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}

			if (p1 == 1)
			{
				if (a == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a = '5';
					f = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 2)
			{
				if (b == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b = '8';
					f1 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 3)
			{
				if (c == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c = '5';
					f2 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 4)
			{
				if (a1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a1 = '6';
					f4 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 6)
			{
				if (b1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b1 = '3';
					f5 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 7)
			{
				if (c1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c1 = '6';
					f6 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 8)
			{
				if (d1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d1 = '3';
					f7 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 9)
			{
				if (e1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					e1 = '4';
					f8 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 10)
			{
				if (g1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					g1 = '2';
					f9 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 11)
			{
				if (h1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					h1 = '4';
					f10 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 12)
			{
				if (k1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					k1 = '2';
					f11 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}
		}

		if (p == 5)
		{
			if (a1 == ' ')
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
				cin >> p;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else
			{
				a1 = '6';
				f4 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðàþ êàðòó è íàæìèòå Enter: ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				if (p1 == 5 || p1 == 0 || p1 > 12)
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Ïåðâàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}

			if (p1 == 1)
			{
				if (a == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a = '5';
					f = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 2)
			{
				if (b == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b = '8';
					f1 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 3)
			{
				if (c == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c = '5';
					f2 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 4)
			{
				if (d == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d = '8';
					f3 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 6)
			{
				if (b1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b1 = '3';
					f5 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 7)
			{
				if (c1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c1 = '6';
					f6 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 8)
			{
				if (d1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d1 = '3';
					f7 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 9)
			{
				if (e1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					e1 = '4';
					f8 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 10)
			{
				if (g1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					g1 = '2';
					f9 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 11)
			{
				if (h1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					h1 = '4';
					f10 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 12)
			{
				if (k1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					k1 = '2';
					f11 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}
		}

		if (p == 6)
		{
			if (b1 == ' ')
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
				cin >> p;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else
			{
				b1 = '3';
				f5 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðàþ êàðòó è íàæìèòå Enter: ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				if (p1 == 6 || p1 == 0 || p1 > 12)
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Ïåðâàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}

			if (p1 == 1)
			{
				if (a == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a = '5';
					f = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 2)
			{
				if (b == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b = '8';
					f1 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 3)
			{
				if (c == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c = '5';
					f2 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 4)
			{
				if (d == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d = '8';
					f3 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 5)
			{
				if (a1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a1 = '6';
					f4 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 7)
			{
				if (c1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c1 = '6';
					f6 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 8)
			{
				if (d1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d1 = '3';
					f7 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 9)
			{
				if (e1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					e1 = '4';
					f8 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 10)
			{
				if (g1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					g1 = '2';
					f9 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 11)
			{
				if (h1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					h1 = '4';
					f10 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 12)
			{
				if (k1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					k1 = '2';
					f11 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}
		}

		if (p == 7)
		{
			if (c1 == ' ')
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
				cin >> p;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else
			{
				c1 = '6';
				f6 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðàþ êàðòó è íàæìèòå Enter: ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				if (p1 == 7 || p1 == 0 || p1 > 12)
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Ïåðâàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}

			if (p1 == 1)
			{
				if (a == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a = '5';
					f = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 2)
			{
				if (b == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b = '8';
					f1 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 3)
			{
				if (c == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c = '5';
					f2 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 4)
			{
				if (d == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d = '8';
					f3 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 5)
			{
				if (a1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a1 = '6';
					f4 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 6)
			{
				if (b1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b1 = '3';
					f5 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 8)
			{
				if (d1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d1 = '3';
					f7 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 9)
			{
				if (e1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					e1 = '4';
					f8 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 10)
			{
				if (g1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					g1 = '2';
					f9 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 11)
			{
				if (h1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					h1 = '4';
					f10 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 12)
			{
				if (k1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					k1 = '2';
					f11 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}
		}

		if (p == 8)
		{
			if (d1 == ' ')
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
				cin >> p;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else
			{
				d1 = '$';
				f7 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðàþ êàðòó è íàæìèòå Enter: ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				if (p1 == 8 || p1 == 0 || p1 > 12)
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Ïåðâàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}

			if (p1 == 1)
			{
				if (a == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a = '5';
					f = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 2)
			{
				if (b == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b = '8';
					f1 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 3)
			{
				if (c == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c = '5';
					f2 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 4)
			{
				if (d == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d = '8';
					f3 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 5)
			{
				if (a1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a1 = '6';
					f4 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 6)
			{
				if (b1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b1 = '3';
					f5 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 7)
			{
				if (c1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c1 = '6';
					f6 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}

			}

			if (p1 == 9)
			{
				if (e1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					e1 = '4';
					f8 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 10)
			{
				if (g1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					g1 = '2';
					f9 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 11)
			{
				if (h1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					h1 = '4';
					f10 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 12)
			{
				if (k1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					k1 = '2';
					f11 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}
		}

		if (p == 9)
		{
			if (e1 == ' ')
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
				cin >> p;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else
			{
				e1 = '4';
				f8 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðàþ êàðòó è íàæìèòå Enter: ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				if (p1 == 9 || p1 == 0 || p1 > 12)
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Ïåðâàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}

			if (p1 == 1)
			{
				if (a == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a = '5';
					f = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 2)
			{
				if (b == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b = '8';
					f1 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 3)
			{
				if (c == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c = '5';
					f2 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 4)
			{
				if (d == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d = '8';
					f3 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 5)
			{
				if (a1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a1 = '6';
					f4 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 6)
			{
				if (b1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b1 = '3';
					f5 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 7)
			{
				if (c1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c1 = '6';
					f6 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}

			}

			if (p1 == 10)
			{
				if (g1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					g1 = '2';
					f9 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 11)
			{
				if (h1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					h1 = '4';
					f10 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 12)
			{
				if (k1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					k1 = '2';
					f11 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}
		}

		if (p == 10)
		{
			if (g1 == ' ')
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
				cin >> p;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else
			{
				g1 = '2';
				f9 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðàþ êàðòó è íàæìèòå Enter: ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				if (p1 == 10 || p1 == 0 || p1 > 12)
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Ïåðâàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}

			if (p1 == 1)
			{
				if (a == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a = '5';
					f = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 2)
			{
				if (b == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b = '8';
					f1 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 3)
			{
				if (c == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c = '5';
					f2 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 4)
			{
				if (d == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d = '8';
					f3 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 5)
			{
				if (a1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a1 = '6';
					f4 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 6)
			{
				if (b1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b1 = '3';
					f5 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 7)
			{
				if (c1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c1 = '6';
					f6 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}

			}

			if (p1 == 9)
			{
				if (e1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					e1 = '4';
					f8 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 11)
			{
				if (h1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					h1 = '4';
					f10 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 12)
			{
				if (k1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					k1 = '2';
					f11 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}
		}

		if (p == 11)
		{
			if (h1 == ' ')
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
				cin >> p;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else
			{
				h1 = '4';
				f10 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðàþ êàðòó è íàæìèòå Enter: ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				if (p1 == 11 || p1 == 0 || p1 > 12)
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Ïåðâàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}

			if (p1 == 1)
			{
				if (a == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a = '5';
					f = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 2)
			{
				if (b == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b = '8';
					f1 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 3)
			{
				if (c == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c = '5';
					f2 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 4)
			{
				if (d == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d = '8';
					f3 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 5)
			{
				if (a1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a1 = '6';
					f4 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 6)
			{
				if (b1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b1 = '3';
					f5 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 7)
			{
				if (c1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c1 = '6';
					f6 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}

			}

			if (p1 == 9)
			{
				if (e1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					e1 = '4';
					f8 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 10)
			{
				if (g1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					g1 = '2';
					f9 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 12)
			{
				if (k1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					k1 = '2';
					f11 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}
		}

		if (p == 12)
		{
			if (k1 == ' ')
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
				cin >> p;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else
			{
				k1 = '2';
				f11 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðàþ êàðòó è íàæìèòå Enter: ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				if (p1 >= 12 || p1 == 0)
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Ïåðâàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}

			if (p1 == 1)
			{
				if (a == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a = '5';
					f = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 2)
			{
				if (b == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b = '8';
					f1 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 3)
			{
				if (c == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c = '5';
					f2 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 4)
			{
				if (d == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					d = '8';
					f3 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 5)
			{
				if (a1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					a1 = '6';
					f4 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 6)
			{
				if (b1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					b1 = '3';
					f5 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 7)
			{
				if (c1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					c1 = '6';
					f6 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}

			}

			if (p1 == 9)
			{
				if (e1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					e1 = '4';
					f8 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 10)
			{
				if (g1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					g1 = '2';
					f9 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}

			if (p1 == 11)
			{
				if (h1 == ' ')
				{
					cout << "\t\t\t\t\t\t\t Ýòà êàðòà óæå âûèãðàëà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				else
				{
					h1 = '4';
					f10 = ' ';
					system("cls");
					Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
					Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
				}
			}
		}

	} while (true);

}

void StartGame_4x2(County doc)
{

	char a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7;
	a = a1 = b = b1 = c = b = c1 = d = d1 = f = f1 = f2 = f3 = f4 = f5 = f6 = f7 = '#';

	doc.start = clock();

	char p;
	char p1;

	Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);

	cout << endl << "\t\t\t\t\t\t\t Îòêðîéòå äâå ëþáûå êàðòû." << endl;
	cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå îäíó èç êàðò è íàæìèòå Enter: ";

	do
	{
		cin >> p;
		PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

		if (p > '8' || p == '0')
		{
			PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
			cout << endl << "\t\t\t\t\t\t\t Òàêîé êàðòû íåò. Ïîâòîðèòå ïîïûòêó..." << endl << endl;
			cout << "\t\t\t\t\t\t\t Îòêðîéòå äâå ëþáûå êàðòû." << endl;
			cout << "\t\t\t\t\t\t\t Âûáåðèòå îäíó èç êàðò è íàæìèòå Enter: ";
		}

		if (p == '1')
		{
			a = '!';
			f = ' ';
			system("cls");
			Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
			cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðóþ êàðòó è íàæìèòå Enter: ";
			cin >> p1;

			PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (p1 == '1' || p1 == '0' || p1 > '8')
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Ïåðâàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
				cin >> p1;

				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}

			if (p1 == '2')
			{
				b = '@';
				f1 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '3')
			{
				c = '!';
				f2 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '4')
			{
				d = '*';
				f3 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '5')
			{
				a1 = '*';
				f4 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '6')
			{
				b1 = '$';
				f5 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '7')
			{
				c1 = '@';
				f6 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '8')
			{
				d1 = '$';
				f7 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}

		}

		if (p == '2')
		{
			b = '@';
			f1 = ' ';
			system("cls");
			Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
			cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðóþ êàðòó è íàæìèòå Enter: ";

			cin >> p1;
			PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (p1 == '2' || p1 == '0' || p1 > '8')
			{
				do
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Âòîðàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				} while (p1 == '2' || p1 == '0');
			}
			if (p1 == '1')
			{
				a = '!';
				f = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '3')
			{
				c = '!';
				f2 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '4')
			{
				d = '*';
				f3 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '5')
			{
				a1 = '*';
				f4 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '6')
			{
				b1 = '$';
				f5 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '7')
			{
				c1 = '@';
				f6 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '8')
			{
				d1 = '$';
				f7 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
		}

		if (p == '3')
		{
			c = '!';
			f2 = ' ';
			system("cls");
			Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
			cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðóþ êàðòó è íàæìèòå Enter: ";
			cin >> p1;
			PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (p1 == '3' || p1 == '0' || p1 > '8')
			{
				do
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Òðåòüÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				} while (p1 == '3' || p1 == '0');
			}
			if (p1 == '1')
			{
				a = '!';
				f = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '2')
			{
				b = '@';
				f1 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '4')
			{
				d = '*';
				f3 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '5')
			{
				a1 = '*';
				f4 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '6')
			{
				b1 = '$';
				f5 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '7')
			{
				c1 = '@';
				f6 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '8')
			{
				d1 = '$';
				f7 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
		}

		if (p == '4')
		{
			d = '*';
			f3 = ' ';
			system("cls");
			Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
			cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðóþ êàðòó è íàæìèòå Enter: ";
			cin >> p1;
			PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (p1 == '4' || p1 == '0' || p1 > '8')
			{
				do
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t ×åòâåðòàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				} while (p1 == '4' || p1 == '0');
			}
			if (p1 == '1')
			{
				a = '!';
				f = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '2')
			{
				b = '@';
				f1 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '3')
			{
				c = '!';
				f2 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '5')
			{
				a1 = '*';
				f4 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '6')
			{
				b1 = '$';
				f5 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '7')
			{
				c1 = '@';
				f6 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '8')
			{
				d1 = '$';
				f7 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
		}

		if (p == '5')
		{
			a1 = '*';
			f4 = ' ';
			system("cls");
			Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
			cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðóþ êàðòó è íàæìèòå Enter: ";
			cin >> p1;
			PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (p1 == '5' || p1 == '0' || p1 > '8')
			{
				do
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Ïÿòàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				} while (p1 == '5' || p1 == '0');
			}
			if (p1 == '1')
			{
				a = '!';
				f = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '2')
			{
				b = '@';
				f1 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '3')
			{
				c = '!';
				f2 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '4')
			{
				d = '*';
				f3 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '6')
			{
				b1 = '$';
				f5 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '7')
			{
				c1 = '@';
				f6 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '8')
			{
				d1 = '$';
				f7 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
		}

		if (p == '6')
		{
			b1 = '$';
			f5 = ' ';
			system("cls");
			Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
			cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðóþ êàðòó è íàæìèòå Enter: ";
			cin >> p1;
			PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (p1 == '6' || p1 == '0' || p1 > '8')
			{
				do
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Øåñòàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				} while (p1 == '6' || p1 == '0');
			}
			if (p1 == '1')
			{
				a = '!';
				f = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '2')
			{
				b = '@';
				f1 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '3')
			{
				c = '!';
				f2 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '4')
			{
				d = '*';
				f3 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '5')
			{
				a1 = '*';
				f4 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '7')
			{
				c1 = '@';
				f6 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '8')
			{
				d1 = '$';
				f7 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
		}

		if (p == '7')
		{
			c1 = '@';
			f6 = ' ';
			system("cls");
			Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
			cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðóþ êàðòó è íàæìèòå Enter: ";
			cin >> p1;
			PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (p1 == '7' || p1 == '0' || p1 > '8')
			{
				do
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Ñåäüìàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				} while (p1 == '7' || p1 == '0');
			}
			if (p1 == '1')
			{
				a = '!';
				f = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '2')
			{
				b = '@';
				f1 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '3')
			{
				c = '!';
				f2 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '4')
			{
				d = '*';
				f3 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '5')
			{
				a1 = '*';
				f4 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '6')
			{
				b1 = '$';
				f5 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '8')
			{
				d1 = '$';
				f7 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
		}

		if (p == '8')
		{
			d1 = '$';
			f7 = ' ';
			system("cls");
			Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
			cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðóþ êàðòó è íàæìèòå Enter: ";
			cin >> p1;
			PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (p1 >= '8' || p1 == '0')
			{
				do
				{
					PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\t\t\t\t\t\t\t Âîñüìàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
					cin >> p1;
					PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

				} while (p1 == '8' || p1 == '0');
			}
			if (p1 == '1')
			{
				a = '!';
				f = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '2')
			{
				b = '@';
				f1 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '3')
			{
				c = '!';
				f2 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '4')
			{
				d = '*';
				f3 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '5')
			{
				a1 = '*';
				f4 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '6')
			{
				b1 = '$';
				f5 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
			if (p1 == '7')
			{
				c1 = '@';
				f6 = ' ';
				system("cls");
				Card_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7);
				Examination_4x2(a, a1, b, b1, c, c1, d, d1, f, f1, f2, f3, f4, f5, f6, f7, doc);
			}
		}

	} while (true);
}	  
void StartGame_4x3(County doc)
{

	char a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11;
	a = a1 = b = b1 = c = b = c1 = d = d1 = e1 = g1 = h1 = k1 = f = f1 = f2 = f3 = f4 = f5 = f6 = f7 = f8 = f9 = f10 = f11 = '#';

	doc.start = clock();

	int p;
	int p1;

	Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);

	cout << endl << "\t\t\t\t\t\t\t Îòêðîéòå äâå ëþáûå êàðòû." << endl;
	cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå îäíó èç êàðò è íàæìèòå Enter: ";

	do
	{
		cin >> p;
		PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

		if (p > 12 || p == 0)
		{
			PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
			cout << endl << "\t\t\t\t\t\t\t Òàêîé êàðòû íåò. Ïîâòîðèòå ïîïûòêó..." << endl << endl;
			cout << "\t\t\t\t\t\t\t Îòêðîéòå äâå ëþáûå êàðòû." << endl;
			cout << "\t\t\t\t\t\t\t Âûáåðèòå îäíó èç êàðò è íàæìèòå Enter: ";
		}

		if (p == 1)
		{
			a = '5';
			f = ' ';
			system("cls");
			Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
			cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðóþ êàðòó è íàæìèòå Enter: ";
			cin >> p1;

			PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (p1 == 1 || p1 == 0 || p1 > 12)
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Ïåðâàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
				cin >> p1;

				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}

			if (p1 == 2)
			{
				b = '8';
				f1 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 3)
			{
				c = '5';
				f2 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 4)
			{
				d = '8';
				f3 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 5)
			{
				a1 = '6';
				f4 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 6)
			{
				b1 = '3';
				f5 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 7)
			{
				c1 = '6';
				f6 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 8)
			{
				d1 = '3';
				f7 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 9)
			{
				e1 = '4';
				f8 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 10)
			{
				g1 = '2';
				f9 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 11)
			{
				h1 = '4';
				f10 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 12)
			{
				k1 = '2';
				f11 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
		}

		if (p == 2)
		{
			b = '8';
			f1 = ' ';
			system("cls");
			Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
			cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðóþ êàðòó è íàæìèòå Enter: ";

			cin >> p1;
			PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (p1 == 2 || p1 == 0 || p1 > 12)
			{

				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Âòîðàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			}
			if (p1 == 1)
			{
				a = '5';
				f = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 3)
			{
				c = '5';
				f2 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 4)
			{
				d = '8';
				f3 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 5)
			{
				a1 = '6';
				f4 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 6)
			{
				b1 = '3';
				f5 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 7)
			{
				c1 = '6';
				f6 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 8)
			{
				d1 = '3';
				f7 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 9)
			{
				e1 = '4';
				f8 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 10)
			{
				g1 = '2';
				f9 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 11)
			{
				h1 = '4';
				f10 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 12)
			{
				k1 = '2';
				f11 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
		}

		if (p == 3)
		{
			c = '5';
			f2 = ' ';
			system("cls");
			Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
			cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðóþ êàðòó è íàæìèòå Enter: ";
			cin >> p1;
			PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (p1 == 3 || p1 == 0 || p1 > 12)
			{

				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Òðåòüÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			}
			if (p1 == 1)
			{
				a = '5';
				f = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 2)
			{
				b = '8';
				f1 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 4)
			{
				d = '8';
				f3 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 5)
			{
				a1 = '6';
				f4 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 6)
			{
				b1 = '3';
				f5 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 7)
			{
				c1 = '6';
				f6 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 8)
			{
				d1 = '3';
				f7 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 9)
			{
				e1 = '4';
				f8 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 10)
			{
				g1 = '2';
				f9 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 11)
			{
				h1 = '4';
				f10 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 12)
			{
				k1 = '2';
				f11 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
		}

		if (p == 4)
		{
			d = '8';
			f3 = ' ';
			system("cls");
			Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
			cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðóþ êàðòó è íàæìèòå Enter: ";
			cin >> p1;
			PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (p1 == 4 || p1 == 0 || p1 > 12)
			{

				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t ×åòâåðòàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			}
			if (p1 == 1)
			{
				a = '5';
				f = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 2)
			{
				b = '8';
				f1 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 3)
			{
				c = '5';
				f2 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 5)
			{
				a1 = '6';
				f4 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 6)
			{
				b1 = '3';
				f5 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 7)
			{
				c1 = '6';
				f6 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 8)
			{
				d1 = '3';
				f7 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 9)
			{
				e1 = '4';
				f8 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 10)
			{
				g1 = '2';
				f9 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 11)
			{
				h1 = '4';
				f10 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 12)
			{
				k1 = '2';
				f11 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
		}

		if (p == 5)
		{
			a1 = '6';
			f4 = ' ';
			system("cls");
			Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
			cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðóþ êàðòó è íàæìèòå Enter: ";
			cin >> p1;
			PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (p1 == 5 || p1 == 0 || p1 > 12)
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Ïÿòàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			}
			if (p1 == 1)
			{
				a = '5';
				f = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 2)
			{
				b = '8';
				f1 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 3)
			{
				c = '5';
				f2 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 4)
			{
				d = '8';
				f3 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 6)
			{
				b1 = '3';
				f5 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 7)
			{
				c1 = '6';
				f6 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 8)
			{
				d1 = '3';
				f7 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 9)
			{
				e1 = '4';
				f8 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 10)
			{
				g1 = '2';
				f9 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 11)
			{
				h1 = '4';
				f10 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 12)
			{
				k1 = '2';
				f11 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
		}

		if (p == 6)
		{
			b1 = '3';
			f5 = ' ';
			system("cls");
			Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
			cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðóþ êàðòó è íàæìèòå Enter: ";
			cin >> p1;
			PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (p1 == 6 || p1 == 0 || p1 > 12)
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Øåñòàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			if (p1 == 1)
			{
				a = '5';
				f = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 2)
			{
				b = '8';
				f1 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 3)
			{
				c = '5';
				f2 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 4)
			{
				d = '8';
				f3 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 5)
			{
				a1 = '6';
				f4 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 7)
			{
				c1 = '6';
				f6 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 8)
			{
				d1 = '3';
				f7 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 9)
			{
				e1 = '4';
				f8 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 10)
			{
				g1 = '2';
				f9 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 11)
			{
				h1 = '4';
				f10 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 12)
			{
				k1 = '2';
				f11 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
		}

		if (p == 7)
		{
			c1 = '6';
			f6 = ' ';
			system("cls");
			Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
			cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðóþ êàðòó è íàæìèòå Enter: ";
			cin >> p1;
			PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (p1 == 7 || p1 == 0 || p1 > 12)
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Ñåäüìàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}

			if (p1 == 1)
			{
				a = '5';
				f = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 2)
			{
				b = '8';
				f1 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 3)
			{
				c = '5';
				f2 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 4)
			{
				d = '8';
				f3 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 5)
			{
				a1 = '6';
				f4 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 6)
			{
				b1 = '3';
				f5 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 8)
			{
				d1 = '3';
				f7 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 9)
			{
				e1 = '4';
				f8 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 10)
			{
				g1 = '2';
				f9 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 11)
			{
				h1 = '4';
				f10 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 12)
			{
				k1 = '2';
				f11 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
		}

		if (p == 8)
		{
			d1 = '3';
			f7 = ' ';
			system("cls");
			Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
			cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðóþ êàðòó è íàæìèòå Enter: ";
			cin >> p1;
			PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (p1 == 8 || p1 == 0 || p1 > 12)
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Âîñüìàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			if (p1 == 1)
			{
				a = '5';
				f = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 2)
			{
				b = '8';
				f1 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 3)
			{
				c = '5';
				f2 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 4)
			{
				d = '8';
				f3 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 5)
			{
				a1 = '6';
				f4 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 6)
			{
				b1 = '3';
				f5 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 7)
			{
				c1 = '6';
				f6 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 9)
			{
				e1 = '4';
				f8 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 10)
			{
				g1 = '2';
				f9 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 11)
			{
				h1 = '4';
				f10 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 12)
			{
				k1 = '2';
				f11 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
		}

		if (p == 9)
		{
			e1 = '4';
			f8 = ' ';
			system("cls");
			Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
			cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðóþ êàðòó è íàæìèòå Enter: ";
			cin >> p1;
			PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (p1 == 9 || p1 == 0 || p1 > 12)
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Âîñüìàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			if (p1 == 1)
			{
				a = '5';
				f = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 2)
			{
				b = '8';
				f1 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 3)
			{
				c = '5';
				f2 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 4)
			{
				d = '8';
				f3 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 5)
			{
				a1 = '6';
				f4 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 6)
			{
				b1 = '3';
				f5 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 7)
			{
				c1 = '6';
				f6 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 8)
			{
				d1 = '3';
				f7 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 10)
			{
				g1 = '2';
				f9 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 11)
			{
				h1 = '4';
				f10 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 12)
			{
				k1 = '2';
				f11 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
		}

		if (p == 10)
		{
			g1 = '2';
			f9 = ' ';
			system("cls");
			Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
			cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðóþ êàðòó è íàæìèòå Enter: ";
			cin >> p1;
			PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (p1 == 10 || p1 == 0 || p1 > 12)
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Âîñüìàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			if (p1 == 1)
			{
				a = '5';
				f = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 2)
			{
				b = '8';
				f1 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 3)
			{
				c = '5';
				f2 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 4)
			{
				d = '8';
				f3 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 5)
			{
				a1 = '6';
				f4 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 6)
			{
				b1 = '3';
				f5 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 7)
			{
				c1 = '6';
				f6 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 8)
			{
				d1 = '3';
				f7 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 9)
			{
				e1 = '4';
				f8 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 11)
			{
				h1 = '4';
				f10 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 12)
			{
				k1 = '2';
				f11 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
		}

		if (p == 11)
		{
			h1 = '4';
			f10 = ' ';
			system("cls");
			Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
			cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðóþ êàðòó è íàæìèòå Enter: ";
			cin >> p1;
			PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (p1 == 11 || p1 == 0 || p1 > 12)
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Âîñüìàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			if (p1 == 1)
			{
				a = '5';
				f = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 2)
			{
				b = '8';
				f1 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 3)
			{
				c = '5';
				f2 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 4)
			{
				d = '8';
				f3 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 5)
			{
				a1 = '6';
				f4 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 6)
			{
				b1 = '3';
				f5 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 7)
			{
				c1 = '6';
				f6 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 8)
			{
				d1 = '3';
				f7 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 9)
			{
				e1 = '4';
				f8 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 10)
			{
				g1 = '4';
				f9 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 12)
			{
				k1 = '2';
				f11 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
		}

		if (p == 12)
		{
			k1 = '2';
			f11 = ' ';
			system("cls");
			Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
			cout << endl << "\t\t\t\t\t\t\t Âûáåðèòå âòîðóþ êàðòó è íàæìèòå Enter: ";
			cin >> p1;
			PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);

			if (p1 == 12 || p1 == 0 || p1 > 12)
			{
				PlaySound(TEXT("fail.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "\t\t\t\t\t\t\t Âîñüìàÿ êàðòà óæå îòêðûòà. Âûáåðèòå äðóãóþ. ";
				cin >> p1;
				PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			if (p1 == 1)
			{
				a = '5';
				f = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 2)
			{
				b = '8';
				f1 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 3)
			{
				c = '5';
				f2 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 4)
			{
				d = '8';
				f3 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 5)
			{
				a1 = '6';
				f4 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 6)
			{
				b1 = '3';
				f5 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 7)
			{
				c1 = '6';
				f6 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 8)
			{
				d1 = '3';
				f7 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 9)
			{
				e1 = '4';
				f8 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 10)
			{
				g1 = '4';
				f9 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
			if (p1 == 11)
			{
				h1 = '4';
				f10 = ' ';
				system("cls");
				Card_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11);
				Examination_4x3(a, a1, b, b1, c, c1, d, d1, e1, g1, h1, k1, f, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, doc);
			}
		}

	} while (true);
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	HWND hwnd = GetForegroundWindow();
	ShowWindow(hwnd, SW_MAXIMIZE);

	Menu();
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

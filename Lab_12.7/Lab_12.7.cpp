#include<iostream>
#include<time.h>
#include<fstream>
#include<string>
#include<windows.h>
using namespace std;

struct Elem {
	Elem* link;
	int info;
};



void enqueue(Elem*& first, Elem*& last, int value)
{
	Elem* tmp = new Elem; // 1
	tmp->info = value;
	tmp->link = NULL; // 3
	if (last != NULL)
		last->link = tmp; // 4
	last = tmp; // 5
	if (first == NULL)
		first = tmp; // 6
}

void ReadFromFile(Elem*& top,Elem*&last, char* fname)
{
	ifstream f(fname);
	int start = 0, end, value;
	string data;
	getline(f, data);
	while (data.find_first_of("0123456789", start) != -1)
	{
		start = data.find_first_of("0123456789", start);
		end = data.find_first_of(" ,.", start);
		value = stoi(data.substr(start, end - start));
		enqueue(top,last, value);
		start = end + 1;
	}

}


bool RemoveValue(Elem*& first,int value)
{
	bool result = false;
	while (first != NULL)
	{
		if (first->info == value)
		{
			Elem* tmp = first->link; // 1
			delete first; // 2
			first = tmp;
			result = true;
		}
		else
		{
			break;
		}
	}
	Elem* L = first;
	while (L !=NULL&& L->link!=NULL)
	{
		if (L->link->info == value)
		{
			Elem* tmp = L->link->link; // 1
			delete L->link; // 2
			L->link = tmp;
			result = true;
		}
		else
		{
			L = L->link;
		}
	}
	return result;

}
bool RemoveNo(Elem*& first, int value)
{
	int n = 1;
	if (first!=NULL&&value==n)
	{
		Elem* tmp = first->link; // 1
		delete first; // 2
		first = tmp;
		return true;
	}
	Elem* L = first;

	while (L != NULL && L->link != NULL)
	{
		n++;
		if (value==n)
		{
			Elem* tmp = L->link->link; // 1
			delete L->link; // 2
			L->link = tmp;
			return true;
		}
		else
		{
			L = L->link;
		}
	}
	return false;

}


void Print(Elem* first)
{
	while (first != NULL)
	{
		cout << first->info << "\t";
		first = first->link;
	}
	cout << endl;

}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(NULL));
	int N,value,menu,n1,n2;
	char fname[] = "data.txt";
	Elem* first = NULL,
		* last = NULL;
	cout << "Зчитати з клавіатури - 1 " << endl;
	cout << "Зчитати з файлу - 2 " << endl;
	cin >> menu;
	switch (menu)
	{
	case 1:
		cout << "Введіть кількість елементиі : "; cin >> N;
		for (int i = 0; i < N; i++)
		{
			cout << "Введіть значення: "; cin >> value;
			enqueue(first, last, value);
		}
		break;
	case 2:
		ReadFromFile(first, last, fname);
		break;
	default:
		cout << "Ви ввели помелкове значення, тому дані запишуться з файлу" << endl;
	}
	cout << endl;
	Print(first);
	cout << endl;
	do
	{
		cout << "Вилучення за значенням - 1 " << endl;
		cout << "Вилучення за порядковим номeром - 2 " << endl;
		cout << "Вивести на екран - 3 " << endl;
		cout << "Вийти - 0 " << endl;
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "Введіть значення: "; cin >> n1;
			if (!RemoveValue(first,n1))
			{
				cout << "Такого елемента немає" << endl;
			}
			cout << endl;
			break;
		case 2:
			cout << "Введіть значення: "; cin >> n2;
			if (!RemoveNo(first, n2))
			{
				cout << "Такого елемента немає" << endl;
			}
			cout << endl;
			break;
		case 3:
			cout << endl;
			Print(first);
			cout << endl;
			break;
		default:
			break;
		}
	} while (menu!=0);

	


	return 0;
}


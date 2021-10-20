#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Stack//структура каждого элемента списка
{
	string data = "\0";//значение элемента
	Stack* next = NULL;//ссылка на следующий элемент 
};

int Count = 0;//кол элем в списке

string Pop(Stack*& next);
void DelAll(Stack*& next);
void Push(string n, Stack*& next);
void Print(Stack* next);


int main()
{

	setlocale(LC_ALL, "russian");
	Stack* Head = new Stack;
	int n = -1;
	string c;
	while (n != 0) {
		cout << "1: Создать стек;" << endl
			<< "2: Вывести стек;" << endl
			<< "3: Выборка;" << endl
			<< "4: Положить в стек;" << endl
			<< "5: Очистка стека;" << endl
			<< "0: Выход;" << endl
			<< "Введите номер операции: ";
		cin >> n;
		switch (n)
		{
		case 1:
			for (int i = 0; i < 18; i++)
			{
				cin >> c;
				Push(c, Head);
			}
			Print(Head);
			break;
		case 2:
			Print(Head);
			break;
		case 3:
			cout << endl << Pop(Head) << endl;
			Print(Head);
			break;
		case 4:
			cout << "Введите символ, которое нужно добавить в стек: ";
			cin >> c;
			Push(c, Head);
			Print(Head);
			break;
		case 5:
			DelAll(Head);
			Print(Head);
			break;
		case 0: break;
		default:
			cout << endl << "Вы ввели неверное значение" << endl << endl; break;
		}
	}
	system("pause");
	return 0;
}

void Push(string n, Stack*& Head)
{
	// создаём новый элемент
	Stack* temp = new Stack;//место под temp типа Stack в памяти 
	temp->data = n; // заполняем данные
	temp->next = Head;//предыдущая голова сдвигается вниз (в сылку на текущий элемент мы записываем голову)
	Count++;
	Head = temp;// текущий элемент становится головой
}
void DelAll(Stack*& Head)
{
	while (Head->next != NULL)
		Pop(Head);
}
string Pop(Stack*& Head)// вытаскивает верхний элемент с последующим элементом
{
	if (Head != NULL)
	{
		string k;
		k = Head->data;//во временную переменную записываем из головы данные
		Stack* temp = Head;// копируем голову в стек
		Head = Head->next;//головой становится второй элемент
		delete temp;
		Count--;
		return k;
	}
}

void Print(Stack* Head)
{
	ofstream f("output.txt");
	int i = Count - 1;
	if (Head != NULL)
	{
		cout << "\nСтек:\n";
		Stack* temp = Head;
		while (temp->next)
		{
			cout << i << ": " << temp->data << endl;;
			f << i << ": " << temp->data << endl;;
			temp = temp->next;
			i--;// s 18 k 0
		}
		//cout << i << ": " << temp->data << endl << endl;

	}
	else cout << "\nСтек пустой!!\n\n";
}

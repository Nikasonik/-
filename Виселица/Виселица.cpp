// Классическая виселица

#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <ctime>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int MAX_WRONG = 8; // макс кол-во ошибок
	vector<string>words = {
	"яблоко", "машина", "кот", "дерево", "книга", "телефон", "собака", "дом", "река", "город",
	"страна", "цветок", "песок", "гора", "друзья", "солнце", "лунка", "учитель", "школа", "поезд",
	"солнце", "птица", "капля", "космос", "песня", "снег", "цвет", "шум", "река", "стол"
	}; // массив слов
	srand(static_cast<unsigned int>(time(0))); // задаю генератор рандомизации
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0]; // слово для отгадывания
	int wrong = 0;
	string soFar(THE_WORD.size(), '-'); // часть слова, открытая на данный момент
	string used = ""; // уже отгаданные буквы
	cout << "\t\tДобро пожаловать в игру Виселица!!\n\n";

	// основной цикл
	while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
	{
		cout << "\nУ вас осталось " << " " << (MAX_WRONG - wrong) << " ошибок\n";
		cout << "\nВы использовали следующие буквы \n" << used << endl;
		cout << "\nОтгаданное слово - \n" << " " << soFar << endl;

		// получение вариантов пользователя
		char guess;
		cout << "\nВведите букву: \n";
		cin >> guess;
		//guess = toupper(guess); // перевод на верхний регистр

		while (used.find(guess) != string::npos)
		{
			cout << "\nВы угадали букву \n" << guess << endl;
			cout << "Введите букву: \n";
			cin >> guess;
			//guess = toupper(guess)
		}
		used += guess;
		if (THE_WORD.find(guess) != string::npos)
		{
			cout << "Верно!!! " << guess << " есть в этом слове\n";
			// обновить soFar включив туда угаданную букву
			for (int i = 0; i < THE_WORD.length(); ++i)
			{
				if (THE_WORD[i] == guess)
				{
					soFar[i] = guess;
				}
			}
		}
		else
		{
			cout << "Извините, " << guess << " нет в этом слове\n";
			++wrong;
		}
		// конец игры

	}
	if (wrong == MAX_WRONG)
	{
		
		cout << "\n Вас повесили\n";
	}
	else
	{
		cout << "\nВы победили!!!\n";
	}
	cout << "\nЗагадываемое слово было - \n" << THE_WORD << endl;
	return 0;
}
#include <iostream>
using namespace std;
const int N = 3;
class Harbinger {
private:
	string h_name, catchPhrase;
	int h_age;

public:
	Harbinger(string h_name = "Предвестник", int h_age = 3000, string catchPhrase = "\"Пойманная фраза\"");
	string GethName() { return h_name; }//геттер для имени;
	void SethName(string hNameValue) { h_name = hNameValue; }//сеттер для имени;
	int GethAge() { return h_age; }//геттер для возраста;
	void SethAge(int hAgeValue) { h_age = hAgeValue; }//сеттер для возраста;
	string GetCatchPhrase() { return catchPhrase; }//геттер для новой переменной;
	void SetCatchPhrase(string cPhraseValue) { catchPhrase = cPhraseValue; }//сеттер для новой переменной; 
};

Harbinger::Harbinger(string hh_name, int hh_age, string ccatchPhrase) { //конструктор по умолчанию;
	h_name = hh_name;
	h_age = hh_age;
	catchPhrase = ccatchPhrase;
}

class Prophet : public Harbinger //первое наслоедование  (модификатор наследования public, т.к необходимо, чтобы все члены родительского класса наследовались со своими спецификаторами доступа);
{
private:
	string ph_name, ph_call, magnumOpus[N];
	int ph_age;

public:
	Prophet(string h_name = "Пророк", int h_age = 50, string catchPhrase = "\"Пойманная фраза\"", string ph_name = "Пророк", string ph_call = "default ph_call", string defaltMagnumOpusElementValue = "default", int ph_age = 30);//создание объекта родительского класса;
	string GetphName() { return ph_name; }//геттер для имени;
	void SetphName(string pNameValue) { ph_name = pNameValue; }//сеттер для имени;
	string GetphCall() { return ph_call; }//геттер для самой длинной строки из массива;
	void SetphCall() { // сеттер для самой длинной строки из массива;
		string longestString = magnumOpus[0];
		for (int i = 1; i < N; i++)
		{
			if (magnumOpus[i].length() > longestString.length())
			{
				longestString = magnumOpus[i];
			}
		}
		ph_call = longestString;
	}
	string* GetMagnumOpus() { return magnumOpus; } //геттер для массива; 

	void SetMagnumOpus() { //сеттер для массива;
		cout << "Ввод массива с пророчествами\n";
		for (int i = 0; i < N; i++)
		{
			cout << "Введите " << i << "-й эл-т: ";
			do {
				cin >> magnumOpus[i];
				if (magnumOpus[i].length() > 25) //проверка условия о слишком длинной строке; 
				{
					cout << "Строка слишком длинная! Повторите попытку: ";
				}
			} while (magnumOpus[i].length() > 25);
		}
		SetphCall();
	}
	int GetphAge() { return ph_age; }//геттер для возраста;
	void SetphAge(int pAgeValue) { ph_age = pAgeValue; }//сеттер для возраста; 
};
Prophet::Prophet(string hh_name, int hh_age, string ccatchPhrase, string pph_name, string pph_call, string ddefaltMagnumOpusElementValue, int pph_age)
	: Harbinger(hh_name, hh_age, ccatchPhrase) { //конструктор по умолчанию;
	pph_name = ph_name;
	pph_call = ph_call;
	pph_age = ph_age;
	for (int i = 0; i < N; i++)
	{
		magnumOpus[i] = ddefaltMagnumOpusElementValue;
	}
}

class DeusEx : public Prophet //второе наследование;
{
private:
	string gd_name;
	int gd_year;
public:
	DeusEx(string h_name = "default h_name", int h_age = 50, string cPhrase = "default catchPhrase", string ph_name = "default ph_name", string ph_call = "default ph_call", string defaltMagnumOpusElementValue = "default", int ph_age = 30, string ggd_name = "Нух")
		: Prophet(h_name, h_age, cPhrase, ph_name, ph_call, defaltMagnumOpusElementValue, ph_age) {
		gd_name = ggd_name;
		srand(time(0));
		gd_year = rand() % 10000;
	}
	string GetGdName() { return gd_name; }
	int GetGdYear() { return gd_year; }
	void ShowInfo() { //метод, выводящий последовательно строки из задания; 
		SethName("Аллах");
		SethAge(10000);
		SetCatchPhrase("придет Моисей");
		SetphName("Моисей");
		SetMagnumOpus();
		cout << GethName() << " в возрасте " << GethAge() << " говорил, что " << GetCatchPhrase() << ".\n";
		int count = 0;
		for (int i = 0; i < N; i++)
		{
			if (GetMagnumOpus()[i] == GetphCall())
			{
				continue;
			}
			else
			{
				count++;
				if (count == 1)
				{
					cout << "Первое ";
				}
				else if (count == 2)
				{
					cout << "Второе ";
				}
				cout << "пророчество: " << GetMagnumOpus()[i] << "\n";
			}
		}
		cout << "Главное пророчество: " << GetphCall() << ".\n";
		cout << "Так говорил " << GetphName() << " " << "в возрасте" << GetphAge() << ".\n\n";
		cout << "В год " << gd_year << " пришел " << gd_name << ", которого предрекали " << GethName() << " и " << GetphName() << ".\n\n";
	}
};

class Believer : private DeusEx //третье наследование;
{
private:
	string bv_name;
	int bv_age;
public:
	Believer(string, int);
	string GetBelieverName() { return bv_name; }
	void SetBelieverName(string bv_name) { this->bv_name = bv_name; }
	int GetBelieverAge() { return bv_age; }
	void SetBelieverAge(int bv_age) { this->bv_age = bv_age; }
	void ShowMessage() {
		cout << "Верующий " << bv_name << " молится " << GetGdName() << " именем Моисей с " << GetGdYear() << " и по сей день" << "\n\n";
	}
};

Believer::Believer(string bbv_name, int bbv_age)
{
	bv_name = bbv_name;
	bv_age = bbv_age;
}
int main()
{
	setlocale(LC_ALL, "ru");
	DeusEx god;
	god.ShowInfo();

	Believer believer("человек", 50);
	believer.ShowMessage();

	system("pause");
	return 0;
}

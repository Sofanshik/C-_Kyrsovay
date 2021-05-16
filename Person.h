#pragma once
#include "General_functions.h"

class Person : virtual protected General_functions
{
protected:
	string name;
	string surname;
	int age;
public:
	string Get_self_name() override;
	string Get_self_surname();
	int Get_self_age();

	Person();
	Person(const Person& other);
	Person(string, string, int);

	void Print_info() override;
	void Set_all_info() override;

	void Set_self_name(string);
	void Set_self_surname(string);
	void Set_self_age(int);

	void Set_self_name() override;
	void Set_self_surname();
	void Set_self_age();

	void operator = (const Person& other);
	
	friend ostream& operator <<(ostream& os, Person& other); //Перегрузка оператора вывода
	friend istream& operator >>(istream& is, Person& other); //Перегрузка оператора ввода

	friend ostream& operator <<=(ostream& os, Person& other); //Перегрузка опретора ввода в файл
	friend istream& operator >>=(istream& is, Person& other); //Перегружка оператора вывода из файла

	~Person();
};

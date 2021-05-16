#pragma once
#include "My_Vector.h"
#include "Person.h"
#include "General_functions.h"

static int count_staff;

class Organisation : virtual protected General_functions
{
protected:
	string name;
	string phone;
	string adress;
	Vector<Person> list_of_persons;

	
	void Set_self_name() override;
	void Set_self_phone();
	void Set_self_adress();
	void Set_list_of_persons();

	void Set_self_name(string);
	void Set_self_phone(string);
	void Set_self_adress(string);

	string Get_self_name() override;
	string Get_self_phone();
	string Get_self_adress();

public:
	void Set_all_info() override;
	void Add_staff();
	void Dismiss_an_employee();
	void Dismiss_all_employees();
	void Print_info() override;

	Organisation();
	Organisation(const Organisation& other);

	void operator = (const Organisation& other);

	~Organisation();

	friend ostream& operator <<(ostream& os, Organisation& other); //Перегрузка оператора вывода
	friend istream& operator >>(istream& is, Organisation& other); //Перегрузка оператора ввода

	friend ostream& operator <<=(ostream& os, Organisation& other); //Перегрузка опретора ввода в файл
	friend istream& operator >>=(istream& is, Organisation& other);
	//Перегружка оператора вывода из файла
};


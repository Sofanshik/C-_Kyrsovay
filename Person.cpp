#include "Person.h"

string Person::Get_self_name()
{
	return this->name;
}

string Person::Get_self_surname()
{
	return this->surname;
}

int Person::Get_self_age()
{
	return this->age;
}

Person::Person()
{
	this->name = "";
	this->surname = "";
	this->age = 0;
	cout << "Конструктор за замовчуванням!(класа людина)" << endl;
}

Person::Person(const Person& other)
{
	this->name = other.name;
	this->surname = other.surname;
	this->age = other.age;
	cout << "Конструктор копіювання!(класа людина)" << endl;
}

Person::Person(string name, string surname, int age)
{
	this->name = name;
	this->surname = surname;
	this->age = age;
	cout << "Конструктор з параметрами!(класа людина)" << endl;
}

void Person::Print_info()
{
	cout << "Ім'я людини: \t" << this->name << endl;
	cout << "Прізвище людини: \t" << this->surname << endl;
	cout << "Вік людини: \t" << this->age << endl;
}

void Person::Set_all_info()
{
	this->Set_self_name();
	this->Set_self_surname();
	this->Set_self_age();
}

void Person::Set_self_name(string name)
{
	this->name = name;
	cout << "Сетер им'я (класу людина з параметром)!" << endl;
}

void Person::Set_self_surname(string surname)
{
	this->surname = surname;
	cout << "Сетер прізвища (класу людина з параметром)!" << endl;
}

void Person::Set_self_age(int age)
{
	this->age = age;
	cout << "Сетер віку (класу людина з параметром)!" << endl;
}

//======================================================================

void Person::Set_self_name()
{
	cout << "Введіть ім'я людини та натисніть 'Enter': " << endl;
	cin >> this->name;
	cin.get();
	cout << "Сетер им'я (класу людина)!" << endl;
}

void Person::Set_self_surname()
{
	cout << "Введіть прізвище людини та натисніть 'Enter': " << endl;
	cin >> this->surname;
	cin.get();
	cout << "Сетер прізвища (класу людина)!" << endl;
}

void Person::Set_self_age()
{

	cout << "Введить вік людини та натисніть 'Enter': " << endl;
	cin >> this->age;
	cin.get();
	cout << "Сетер віку (класу людина)!" << endl;
}

void Person::operator=(const Person& other)
{
	this->name = other.name;
	this->surname = other.surname;
	this->age = other.age;
	cout << "Оператор присвоювання!(класа людина)" << endl;
}

Person::~Person()
{
	cout << "Деструктор (класа людина)!" << endl;
}

ostream& operator<<(ostream& os, Person& other)
{
	os << "Ім'я людини: \t" << other.Get_self_name() << "\n" << "Прізвище людини: \t" << other.Get_self_surname() << "\n" << "Вік людини: \t" << other.Get_self_age() << "\n";
	return os;
}

istream& operator>>(istream& is, Person& other)
{
	cout << "Введіть ім'я людини та натисніть 'Enter': " << endl;
	is >> other.name;
	is.get();
	cout << "Введіть прізвище людини та натисніть 'Enter': " << endl;
	is >> other.surname;
	is.get();
	cout << "Введить вік людини та натисніть 'Enter': " << endl;
	is >> other.age;
	is.get();
	
	return is;
}

ostream& operator<<=(ostream& os, Person& other)
{
	
	os << other.Get_self_name() << "\n" << other.Get_self_surname() << "\n" << other.Get_self_age() << "\n";
	return os;
}

istream& operator>>=(istream& is, Person& other)
{
	getline(is, other.name);
	getline(is, other.surname);
	is >> other.age;
	is.get();
	return is;
}

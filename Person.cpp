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
	cout << "����������� �� �������������!(����� ������)" << endl;
}

Person::Person(const Person& other)
{
	this->name = other.name;
	this->surname = other.surname;
	this->age = other.age;
	cout << "����������� ���������!(����� ������)" << endl;
}

Person::Person(string name, string surname, int age)
{
	this->name = name;
	this->surname = surname;
	this->age = age;
	cout << "����������� � �����������!(����� ������)" << endl;
}

void Person::Print_info()
{
	cout << "��'� ������: \t" << this->name << endl;
	cout << "������� ������: \t" << this->surname << endl;
	cout << "³� ������: \t" << this->age << endl;
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
	cout << "����� ��'� (����� ������ � ����������)!" << endl;
}

void Person::Set_self_surname(string surname)
{
	this->surname = surname;
	cout << "����� ������� (����� ������ � ����������)!" << endl;
}

void Person::Set_self_age(int age)
{
	this->age = age;
	cout << "����� ��� (����� ������ � ����������)!" << endl;
}

//======================================================================

void Person::Set_self_name()
{
	cout << "������ ��'� ������ �� �������� 'Enter': " << endl;
	cin >> this->name;
	cin.get();
	cout << "����� ��'� (����� ������)!" << endl;
}

void Person::Set_self_surname()
{
	cout << "������ ������� ������ �� �������� 'Enter': " << endl;
	cin >> this->surname;
	cin.get();
	cout << "����� ������� (����� ������)!" << endl;
}

void Person::Set_self_age()
{

	cout << "������� �� ������ �� �������� 'Enter': " << endl;
	cin >> this->age;
	cin.get();
	cout << "����� ��� (����� ������)!" << endl;
}

void Person::operator=(const Person& other)
{
	this->name = other.name;
	this->surname = other.surname;
	this->age = other.age;
	cout << "�������� ������������!(����� ������)" << endl;
}

Person::~Person()
{
	cout << "���������� (����� ������)!" << endl;
}

ostream& operator<<(ostream& os, Person& other)
{
	os << "��'� ������: \t" << other.Get_self_name() << "\n" << "������� ������: \t" << other.Get_self_surname() << "\n" << "³� ������: \t" << other.Get_self_age() << "\n";
	return os;
}

istream& operator>>(istream& is, Person& other)
{
	cout << "������ ��'� ������ �� �������� 'Enter': " << endl;
	is >> other.name;
	is.get();
	cout << "������ ������� ������ �� �������� 'Enter': " << endl;
	is >> other.surname;
	is.get();
	cout << "������� �� ������ �� �������� 'Enter': " << endl;
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

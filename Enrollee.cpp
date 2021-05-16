#include "Enrollee.h"

Enrollee::Enrollee():Person()
{
	this->average_mark_of_the_certificate = 0;
	this->specialty = "";
	cout << "Конструктор за замовчуванням!(класа вступник)" << endl;
}

Enrollee::Enrollee(const Enrollee& other):Person(other)
{
	this->average_mark_of_the_certificate = other.average_mark_of_the_certificate;
	this->specialty = other.specialty;
	cout << "Конструктор копіювання!(класа вступник)" << endl;
}

void Enrollee::Print_info()
{
	cout << "Ім'я вступника: \t" << this->Get_self_name() << "\n" << "Прізвище вступника: \t" << this->Get_self_surname() << "\n" << "Вік вступника: \t" << this->Get_self_age() << "\n" <<
		"Середній бал вступника: \t" << this->Get_self_average_mark() << "\nСпеціальність за якою хоче навчатися вступник: \t" << this->Get_self_specialty() <<
		"\nЯкі пільги є у вступника: \t" << this->Get_self_privilages() << "\n";
}

void Enrollee::Set_all_info()
{
	this->Set_self_name();
	this->Set_self_surname();
	this->Set_self_age();
	this->Set_self_average_mark();
	this->Set_self_privilages();
	this->Set_self_specialty();
}

void Enrollee::Set_self_average_mark()
{
	cout << "Введіть середній бал атестату вступника та натисніть 'Enter': " << endl;
	cin >> this->average_mark_of_the_certificate;
	cout << "Сетер середнього балу (класу вступник)!" << endl;
}

void Enrollee::Set_self_privilages()
{
	cout << "Якщо в вас є пільга то впишить її в це поле та натисніть 'Enter', якщо в вас немає пільг просто напишіть - 'Ні' та натисніть 'Enter': " << endl;
	cin >> this->privileges;
	cin.get();
	cout << "Сетер пільг (класу вступник)!" << endl;
}

void Enrollee::Set_self_specialty()
{
	cout << "Оберіть спеціальність до якої хочете вступати та натисніть 'Enter': " << endl;
	cin >> this->specialty;
	cin.get();
	cout << "Сетер спеціальності (класу вступник)!" << endl;
	//Допилить с использованием массива класса кафедра
}

void Enrollee::Set_self_average_mark(double average_mark)
{
	this->average_mark_of_the_certificate = average_mark;
}

void Enrollee::Set_self_privilages(string privilage)
{
	this->privileges = privilage;
}

void Enrollee::Set_self_specialty(string specialty)
{
	this->specialty = specialty;
}

double Enrollee::Get_self_average_mark()
{
	return this->average_mark_of_the_certificate;
}

string Enrollee::Get_self_privilages()
{
	return this->privileges;
}

string Enrollee::Get_self_specialty()
{
	return this->specialty;
}

void Enrollee::Opportunity_enter_specialty()
{

}

void Enrollee::operator=(const Enrollee& other)
{
	this->name = other.name;
	this->surname = other.surname;
	this->age = other.age;
	this->average_mark_of_the_certificate = other.average_mark_of_the_certificate;
	this->specialty = other.specialty;
	cout << "Оператор присвоювання!(класа вступник)" << endl;
}

Enrollee::~Enrollee()
{
	cout << "Деструктор (класа вступник)!" << endl;
}

ostream& operator<<(ostream& os, Enrollee& other)
{
	os << "Ім'я вступника: \t" << other.Get_self_name() << "\n" << "Прізвище вступника: \t" << other.Get_self_surname() << "\n" << "Вік вступника: \t" << other.Get_self_age() << "\n" <<
		"Середній бал вступника: \t" << other.Get_self_average_mark() << "\nСпеціальність за якою хоче навчатися вступник: \t" << other.Get_self_specialty() << 
		"\nЯкі пільги є у вступника: \t" << other.Get_self_privilages() << "\n";
	return os;
}

istream& operator>>(istream& is, Enrollee& other)
{
	cout << "Введіть ім'я вступника та натисніть 'Enter': " << endl;
	is >> other.name;
	is.get();
	cout << "Введіть прізвище вступника та натисніть 'Enter': " << endl;
	is >> other.surname;
	is.get();
	cout << "Введить вік вступника та натисніть 'Enter': " << endl;
	is >> other.age;
	is.get();
	cout << "Введіть середній бал атестату вступника та натисніть 'Enter': " << endl;
	is >> other.average_mark_of_the_certificate;
	cout << "Якщо в вас є пільга то впишить її в це поле та натисніть 'Enter', якщо в вас немає пільг просто напишіть - 'Ні' та натисніть 'Enter': " << endl;
	is >> other.privileges;
	is.get();
	cout << "Оберіть спеціальність до якої хочете вступати та натисніть 'Enter': " << endl;
	is >> other.specialty;
	is.get();
	return is;
}

ostream& operator<<=(ostream& os, Enrollee& other)
{
	os << other.Get_self_name() << "\n" << other.Get_self_surname() << "\n" << other.Get_self_age() << "\n" << other.Get_self_average_mark() << "\n" << other.Get_self_specialty() <<
		"\n" << other.Get_self_privilages() << "\n";
	return os;
}

istream& operator>>=(istream& is, Enrollee& other)
{
	getline(is, other.name, '\n');
	getline(is, other.surname, '\n');
	is >> other.age;
	is.get();
	is >> other.average_mark_of_the_certificate;
	is.get();
	getline(is, other.specialty, '\n');
	getline(is, other.privileges, '\n');
	return is;
}

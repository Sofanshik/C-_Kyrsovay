#include "Teacher.h"

Teacher::Teacher():Person()
{
	this->subject_taught = "";
	this->position = "";
	cout << "Конструктор за замоченням(класу вчитель)!" << endl;
}

Teacher::Teacher(const Teacher& other):Person(other)
{
	this->subject_taught = other.subject_taught;
	this->position = other.position;
	cout << "Конструктор копіювання(класу вчитель)!" << endl;
}

void Teacher::Print_info()
{
	cout << "Ім'я викладача: \t" << this->Get_self_name() << "\n" << "Прізвище викладача: \t" << this->Get_self_surname() << 
		"\n" << "Вік викладача: \t" << this->Get_self_age() << "\n" << "Предмет,який викладається викладачем: \t" << this->Get_self_subject_taught() << 
		"\n" << "Посада, яку займає викладач: \t" << this->Get_self_position() << "\n";
}

void Teacher::Set_all_info()
{
	this->Set_self_name();
	this->Set_self_surname();
	this->Set_self_age();
	this->Set_self_subject_taught();
	this->Set_self_position();
}

void Teacher::Set_self_subject_taught()
{
	cout << "Введіть предмет який викладає цей викладач та натисніть 'Enter': \t";
	getline(cin, this->subject_taught);
	cout << "Сеттер предмета(класу вчитель)!" << endl;
}

void Teacher::Set_self_position()
{
	cout << "Введіть яку посаду займає викладач та натисніть 'Enter': \t";
	getline(cin, this->position);
	cout << "Сеттер посади(класу вчитель)!" << endl;
}

void Teacher::Set_self_subject_taught(string subject_taught)
{
	this->subject_taught = subject_taught;
	cout << "Сеттер предмета(класу вчитель)!" << endl;
}

void Teacher::Set_self_position(string position)
{
	this->position = position;
	cout << "Сеттер посади(класу вчитель)!" << endl;
}

string Teacher::Get_self_subject_taught()
{
	return this->subject_taught;
}

string Teacher::Get_self_position()
{
	return this->position;
}

void Teacher::operator=(const Teacher& other)
{
	this->name = other.name;
	this->surname = other.surname;
	this->age = other.age;
	this->subject_taught = other.subject_taught;
	this->position = other.position;
	cout << "Оператор присвоювання!(класа вчитель)" << endl;
}

Teacher::~Teacher()
{
	cout << "Деструктор (класу вчитель)!" << endl;
}

ostream& operator<<(ostream& os, Teacher& other)
{
	os << "Ім'я викладача: \t" << other.Get_self_name() << "\n" << "Прізвище викладача: \t" << other.Get_self_surname() << "\n" << "Вік викладача: \t" << other.Get_self_age() << "\n" <<"Предмет,який викладається викладачем: \t" << other.Get_self_subject_taught() << "\n" << "Посада, яку займає викладач: \t" << other.Get_self_position() << "\n";
	return os;
}

istream& operator>>(istream& is, Teacher& other)
{
	cout << "Введіть ім'я викладача та натисніть 'Enter': " << endl;
	is >> other.name;
	is.get();
	cout << "Введіть прізвище викладача та натисніть 'Enter': " << endl;
	is >> other.surname;
	is.get();
	cout << "Введить вік викладача та натисніть 'Enter': " << endl;
	is >> other.age;
	is.get();
	cout << "Введіть предмет який викладає цей викладач: \t";
	getline(is, other.subject_taught);
	cout << "Введіть яку посаду займає викладач: \t";
	getline(is, other.position);
	return is;
}

ostream& operator<<=(ostream& os, Teacher& other)
{
	os << other.Get_self_name() << "\n" << other.Get_self_surname() << "\n" << other.Get_self_age() << "\n" << other.Get_self_subject_taught() << "\n" << other.Get_self_position() << "\n";
	return os;
}

istream& operator>>=(istream& is, Teacher& other)
{
	//is >> other.name >> other.surname >> other.age;
	getline(is, other.name, '\n');
	getline(is, other.surname, '\n');
	is >> other.age;
	is.get();
	getline(is, other.subject_taught, '\n');
	getline(is, other.position, '\n');
	return is;
}

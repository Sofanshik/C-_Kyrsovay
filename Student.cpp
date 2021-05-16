#include "Student.h"

Student::Student() :Enrollee(){
	this->budget = 0;
	this->participation_in_life_university = "";
	this->year_of_entry = 0;
	cout << "Конструктор за замовчуванням!(класа студент)" << endl;
}

Student::Student(const Student& other):Enrollee(){
	this->budget = other.budget;
	this->participation_in_life_university = other.participation_in_life_university;
	this->year_of_entry = other.year_of_entry;
	cout << "Конструктор копіювання!(класа студент)" << endl;
}

Student::~Student(){ cout << "Деструктор!(класа студент)" << endl; }

void Student::Set_all_info(){
	this->Set_self_name();
	this->Set_self_surname();
	this->Set_self_age();
	this->Set_self_average_mark();
	this->Set_self_privilages();
	this->Set_self_specialty();
	this->Set_self_budget();
	this->Set_self_participation_in_l_u();
	this->Set_self_year_of_entry();}

void Student::Set_self_budget(){
	int count;
	cout << "Введіть 1 або 0, де 1 - студент на бюджеті, 0 - ні, та натисніть 'Enter': " << endl;
	cin >> count;
	switch (count)
	{
	case(1): 
		this->budget = true;
	case(0):
		this->budget = false;
	default:
		break;
	}
}

void Student::Set_self_average_mark()
{
	cout << "Введіть середній бал студента та натисніть 'Enter': " << endl;
	cin >> this->average_mark_of_the_certificate;
	cout << "Сетер середнього балу (класу вступник)!" << endl;
}

void Student::Set_self_specialty()
{
	cout << "Оберіть спеціальність за якою навчається студент та натисніть 'Enter': " << endl;
	cin >> this->specialty;
	cin.get();
	cout << "Сетер спеціальності (класу вступник)!" << endl;
	//Допилить с использованием массива класса кафедра
}

void Student::Set_self_participation_in_l_u(){
	int count;
	cout << "Введіть, 1 чи 0, де 1 - студент приймає участь у житті університета, 0 - якщо ні, та натисніть 'Enter': \n";
	cin >> count; // try for entrence count, if is not number
	switch (count)
	{
	case(1):
		cout << "Введіть, якою діяльністю займається студент для допомоги університету: \n";
		cin >> this->participation_in_life_university;
		getline(cin, this->participation_in_life_university);
	case(0):
		this->participation_in_life_university = "Ні.";
	default:
		break;
	}}

void Student::Set_self_year_of_entry(){
	cout << "Введіть рік, коли студент вступив до універа та натисніть 'Enter': \n";
	cin >> this->year_of_entry;
	cin.get();}

bool Student::Get_self_budget(){
	return this->budget;}

string Student::Get_self_participation_in_l_u(){
	return this->participation_in_life_university;}

int Student::Get_year_of_entry(){
	return this->year_of_entry;}

void Student::Print_info(){
	cout << "Ім'я студента: \t" << this->Get_self_name() << "\n" << "Прізвище студента: \t" << this->Get_self_surname() << "\n" << "Вік студента: \t" << this->Get_self_age() << "\n" <<
		"Середній бал студента: \t" << this->Get_self_average_mark() << "\nСпеціальність за якою навчаєтся студент: \t" << this->Get_self_specialty() <<
		"\nПільги студента: \t" << this->Get_self_privilages() << "\nЧи студент на бюджеті? \t" << this->Get_self_budget() <<
		"\nЧи робіть щось студент для університету: \t" << this->Get_self_participation_in_l_u() << 
		"\nРік в якому студент вступив у ВНЗ: \t" << this->Get_year_of_entry() << "\n"; }

void Student::operator=(const Student& other){
	this->name = other.name;
	this->surname = other.surname;
	this->age = other.age;
	this->average_mark_of_the_certificate = other.average_mark_of_the_certificate;
	this->specialty = other.specialty;
	this->budget = other.budget;
	this->participation_in_life_university = other.participation_in_life_university;
	this->year_of_entry = other.year_of_entry;
}

ostream& operator<<(ostream& os, Student& other)
{
	os << "Ім'я студента: \t" << other.Get_self_name() << "\n" << "Прізвище студента: \t" << other.Get_self_surname() << "\n" << "Вік студента: \t" << other.Get_self_age() << "\n" <<
		"Середній бал студента: \t" << other.Get_self_average_mark() << "\nСпеціальність за якою навчаєтся студент: \t" << other.Get_self_specialty() <<
		"\nПільги студента: \t" << other.Get_self_privilages() << "\nЧи студент на бюджеті? \t" << other.Get_self_budget() <<
		"\nЧи робіть щось студент для університету: \t" << other.Get_self_participation_in_l_u() <<
		"\nРік в якому студент вступив у ВНЗ: \t" << other.Get_year_of_entry() << "\n";
	return os;
}

istream& operator>>(istream& is, Student& other)
{
	other.Set_all_info();
	return is;
}

ostream& operator<<=(ostream& os, Student& other)
{
	os << other.Get_self_name() << "\n" << other.Get_self_surname() << "\n" << other.Get_self_age() << "\n" << other.Get_self_average_mark() << "\n" << other.Get_self_specialty() <<
		"\n" << other.Get_self_privilages() << "\n" << other.Get_self_budget() << "\n" << other.Get_self_participation_in_l_u() << "\n" <<
		other.Get_year_of_entry() << "\n";
	return os;
}

istream& operator>>=(istream& is, Student& other)
{
	getline(is, other.name, '\n');
	getline(is, other.surname, '\n');
	is >> other.age;
	is.get();
	is >> other.average_mark_of_the_certificate;
	is.get();
	getline(is, other.specialty, '\n');
	getline(is, other.privileges, '\n');
	is >> other.budget;
	is.get();
	getline(is, other.participation_in_life_university, '\n');
	is >> other.year_of_entry;
	return is;
}

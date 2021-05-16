#include "Enrollee.h"

Enrollee::Enrollee():Person()
{
	this->average_mark_of_the_certificate = 0;
	this->specialty = "";
	cout << "����������� �� �������������!(����� ��������)" << endl;
}

Enrollee::Enrollee(const Enrollee& other):Person(other)
{
	this->average_mark_of_the_certificate = other.average_mark_of_the_certificate;
	this->specialty = other.specialty;
	cout << "����������� ���������!(����� ��������)" << endl;
}

void Enrollee::Print_info()
{
	cout << "��'� ���������: \t" << this->Get_self_name() << "\n" << "������� ���������: \t" << this->Get_self_surname() << "\n" << "³� ���������: \t" << this->Get_self_age() << "\n" <<
		"������� ��� ���������: \t" << this->Get_self_average_mark() << "\n������������ �� ���� ���� ��������� ��������: \t" << this->Get_self_specialty() <<
		"\n�� ����� � � ���������: \t" << this->Get_self_privilages() << "\n";
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
	cout << "������ ������� ��� �������� ��������� �� �������� 'Enter': " << endl;
	cin >> this->average_mark_of_the_certificate;
	cout << "����� ���������� ���� (����� ��������)!" << endl;
}

void Enrollee::Set_self_privilages()
{
	cout << "���� � ��� � ����� �� ������� �� � �� ���� �� �������� 'Enter', ���� � ��� ���� ���� ������ �������� - 'ͳ' �� �������� 'Enter': " << endl;
	cin >> this->privileges;
	cin.get();
	cout << "����� ���� (����� ��������)!" << endl;
}

void Enrollee::Set_self_specialty()
{
	cout << "������ ������������ �� ��� ������ �������� �� �������� 'Enter': " << endl;
	cin >> this->specialty;
	cin.get();
	cout << "����� ������������ (����� ��������)!" << endl;
	//�������� � �������������� ������� ������ �������
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
	cout << "�������� ������������!(����� ��������)" << endl;
}

Enrollee::~Enrollee()
{
	cout << "���������� (����� ��������)!" << endl;
}

ostream& operator<<(ostream& os, Enrollee& other)
{
	os << "��'� ���������: \t" << other.Get_self_name() << "\n" << "������� ���������: \t" << other.Get_self_surname() << "\n" << "³� ���������: \t" << other.Get_self_age() << "\n" <<
		"������� ��� ���������: \t" << other.Get_self_average_mark() << "\n������������ �� ���� ���� ��������� ��������: \t" << other.Get_self_specialty() << 
		"\n�� ����� � � ���������: \t" << other.Get_self_privilages() << "\n";
	return os;
}

istream& operator>>(istream& is, Enrollee& other)
{
	cout << "������ ��'� ��������� �� �������� 'Enter': " << endl;
	is >> other.name;
	is.get();
	cout << "������ ������� ��������� �� �������� 'Enter': " << endl;
	is >> other.surname;
	is.get();
	cout << "������� �� ��������� �� �������� 'Enter': " << endl;
	is >> other.age;
	is.get();
	cout << "������ ������� ��� �������� ��������� �� �������� 'Enter': " << endl;
	is >> other.average_mark_of_the_certificate;
	cout << "���� � ��� � ����� �� ������� �� � �� ���� �� �������� 'Enter', ���� � ��� ���� ���� ������ �������� - 'ͳ' �� �������� 'Enter': " << endl;
	is >> other.privileges;
	is.get();
	cout << "������ ������������ �� ��� ������ �������� �� �������� 'Enter': " << endl;
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

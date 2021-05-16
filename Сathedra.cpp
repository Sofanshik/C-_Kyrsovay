#include "�athedra.h"


void �athedra::Set_all_info()
{
	int count_people;
	this->Set_self_name();
	cout << "������ ������� ��������, �� ���������� �� ������ �� �������� 'Enter': " << endl;
	cin >> count_people;
	this->Set_self_count_people_on_cath(count_people);
	this->Set_self_list_of_student();
	this->Set_self_min_mark_for_enter();
}

void �athedra::Print_info(){
	cout << "����� �������: \t" << this->Get_self_name();
	cout << "\nʳ������ ��������, �� ���������� �� ��� ������: \t" << this->Get_self_count_people_on_cath(); 
	cout << "\n�� �������� �� ���������� �� ��� ������: \n";
	this->list_students_in_cath.show();
	cout << "\n̳������� ��������� ���: \t" << this->Get_self_min_mark_for_enter() << "\n";
}

�athedra::�athedra()
{
	this->name = "";
	this->count_people_on_cathedra = 0;
	this->min_mark_for_enter = 0;
	cout << "����������� �� �����������(����� �������)!" << endl;
}

�athedra::�athedra(const �athedra& other)
{
	this->name = other.name;
	this->count_people_on_cathedra = other.count_people_on_cathedra;
	this->min_mark_for_enter = other.min_mark_for_enter;
	this->list_students_in_cath = other.list_students_in_cath;
	cout << "����������� ���������(����� �������!)" << endl;
}

�athedra::~�athedra(){
	this->list_students_in_cath.clear();
	cout << "���������� (����� �������)!" << endl;}

void �athedra::Set_self_name()
{
	cout << "������ ����� ������� �� �������� 'Enter': " << endl;
	getline(cin, this->name);
	cout << "����� ����� (����� �������)!" << endl;
}

void �athedra::Set_self_count_people_on_cath(int count_people)
{
	this->count_people_on_cathedra += count_people;
}

void �athedra::Set_self_list_of_student() {
	Student student;
	for (int i = 0; i < this->count_people_on_cathedra; i++) {
		student.Set_all_info();
		this->list_students_in_cath.push_back(student);}}

void �athedra::Set_self_list_of_student(const Student& student){
	for (int i = 0; i < this->count_people_on_cathedra; i++) {
		this->list_students_in_cath.push_back(student);}}

void �athedra::Set_self_min_mark_for_enter()
{
	cout << "������ ��������� ��� ��� ������ �� �� ������� �� �������� 'Enter': " << endl;
	cin >> this->min_mark_for_enter;
	cout << "����� ���������� ����(����� �������)!" << endl;
}

string �athedra::Get_self_name()
{
	return this->name;
}

int �athedra::Get_self_count_people_on_cath()
{
	return this->count_people_on_cathedra;
}

double �athedra::Get_self_min_mark_for_enter()
{
	return this->min_mark_for_enter;
}

void �athedra::operator=(const �athedra& other)
{
	this->name = other.name;
	this->count_people_on_cathedra = other.count_people_on_cathedra;
	this->min_mark_for_enter = other.min_mark_for_enter;
}

ostream& operator<<(ostream& os, �athedra& other)
{
	other.Print_info();
	return os;
}

istream& operator>>(istream& is, �athedra& other)
{
	other.Set_all_info();
	return is;
}

ostream& operator<<=(ostream& os, �athedra& other)
{
	//��������
	return os;
}

istream& operator>>=(istream& is, �athedra& other)
{
	//��������
	return is;
}

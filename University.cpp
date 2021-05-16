#include "University.h"

University::University():Organisation()
{
	this->place_in_international_ranking = 0;
	this->military_department = 0;
	this->size_cathedrals = 0;
	�athedra* cathedrals = new �athedra[size_cathedrals];
	cout << "����������� �� �������������!(����� ����������)" << endl;
}

University::University(const University& other):Organisation(other)
{
	this->place_in_international_ranking = other.place_in_international_ranking;
	this->military_department = other.military_department;
	if (this->cathedrals != nullptr) {
		this->size_cathedrals = other.size_cathedrals;
		delete[] cathedrals;
		this->cathedrals = new �athedra[other.size_cathedrals];
		for (int i = 0; i < other.size_cathedrals; i++) {
			this->cathedrals[i] = other.cathedrals[i];}}
	this->list_of_persons = other.list_of_persons;
	cout << "����������� ���������!(����� ����������)" << endl;
}

University::~University(){
	cout << "����������!(����� ����������)" << endl;}

void University::Set_all_info()
{
	this->Set_self_place_in_ranking();
	this->Set_self_military_department();
	this->Set_list_of_students();
	this->Set_self_cathidrals();
}

void University::Set_self_place_in_ranking()
{
	cout << "������ ���� �� ����� ����������� ���������� � �������� ����������� �� �������� 'Enter': " << endl;
	cin >> this->place_in_international_ranking;
	cin.get();
	cout << "����� ���� � �������� �����������(����� ����������)!" << endl;
}

void University::Set_self_military_department()
{
	cout << "����� �������� ������� �������(����� ����������)!" << endl;
}

void University::Set_self_cathidrals()
{
	cout << "������ ������� ������ ����������� �� �������� 'Enter': " << endl;
	cin >> this->size_cathedrals;
	cin.get();
	�athedra* cathedrals = new �athedra[size_cathedrals];
	for (int i = 0; i < size_cathedrals; i++) {
		cathedrals[i].Set_all_info();
	}
}

void University::Set_list_of_students()
{
	int i{};
	int count{};
	cout << "������ ������� ���������(����� �����), ���� ������ ���������: \t";
	cin >> count;
	count_staff += count;
	cout << endl;
	Student student;
	while (i != count) {
		student.Set_all_info();
		this->list_of_persons.push_back(student);
		i++;
	}
}

int University::Get_self_place_in_ranking()
{
	return this->place_in_international_ranking;
}

bool University::Get_self_military_department()
{

	return this->military_department;
}

void University::Add_student()
{
	Student student;
	student.Set_all_info();
	this->list_of_persons.push_back(student);
}

void University::Deduct_student()
{
	int index{};
	for (int i = 0; i < this->list_of_persons.size(); i++) {
		Student student = this->list_of_persons[i];
		cout << student << endl;
	}

	cout << "������ ����� ��������, ������� ������ ����������: \t";
	cin >> index;
	cout << endl;

	this->list_of_persons.pop_of_index(index - 1);
}

void University::Deduct_all_students()
{
	this->list_of_persons.clear();
}

void University::operator=(const University& other)
{
	this->name = other.name;
	this->phone = other.phone;
	this->adress = other.adress;
	this->place_in_international_ranking = other.place_in_international_ranking;
	this->military_department = other.military_department;
	this->list_of_persons = other.list_of_persons;
	this->size_cathedrals = other.size_cathedrals;
	delete[] cathedrals;
	this->cathedrals = new �athedra[other.size_cathedrals];
	for (int i = 0; i < other.size_cathedrals; i++) {
		this->cathedrals[i] = other.cathedrals[i];
	}
}

ostream& operator<<(ostream& os, University& other)
{
	os << "����� �����������: \t" << other.Get_self_name() << "\n" << "����� �������� �����������: \t" << other.Get_self_phone() << "\n"
		<< "������� �� ���� ����������� �����������: \t" << other.Get_self_adress() << "\n̳��� �� ����� ����������� ���������� � �������� �����������: \t" << other.Get_self_place_in_ranking() <<
		"\n�������� ������� �������: \t" << other.Get_self_military_department();
	//������� ����� ��������� �� ��������.
	os << "������ ��� �������� � ����� ����������: " << endl;
	for (int i = 0; i < other.list_of_persons.size(); i++) {
		os << (i + 1) << ") \t" << other.list_of_persons[i] << endl;
	}
	return os;
}

istream& operator>>(istream& is, University& other)
{
	other.Set_all_info();
	return is;
}

ostream& operator<<=(ostream& os, University& other)
{
	os << other.Get_self_name() << "\n" << other.Get_self_phone() << "\n" << other.Get_self_adress() << "\n" << other.Get_self_place_in_ranking() 
		<< "\n" << other.Get_self_military_department() << "\n";
	//os << "������ ��� �������� � ����� ����������: " << endl;
	for (int i = 0; i < other.list_of_persons.size(); i++) {
		os << (i + 1) << ") \t" << other.list_of_persons[i] << endl;
	}
	return os;
}

istream& operator>>=(istream& is, University& other)
{
	getline(is, other.name);
	getline(is, other.phone);
	getline(is, other.adress);
	is >> other.place_in_international_ranking;
	is.get();
	is >> other.military_department;
	is.get();
	for (int i = 0; i < count_staff; i++) {
		is >>= other.list_of_persons[i];
	}
	return is;
}

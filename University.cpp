#include "University.h"

University::University():Organisation()
{
	this->place_in_international_ranking = 0;
	this->military_department = 0;
	this->size_cathedrals = 0;
	Сathedra* cathedrals = new Сathedra[size_cathedrals];
	cout << "Конструктор за замовчуванням!(класа університет)" << endl;
}

University::University(const University& other):Organisation(other)
{
	this->place_in_international_ranking = other.place_in_international_ranking;
	this->military_department = other.military_department;
	if (this->cathedrals != nullptr) {
		this->size_cathedrals = other.size_cathedrals;
		delete[] cathedrals;
		this->cathedrals = new Сathedra[other.size_cathedrals];
		for (int i = 0; i < other.size_cathedrals; i++) {
			this->cathedrals[i] = other.cathedrals[i];}}
	this->list_of_persons = other.list_of_persons;
	cout << "Конструктор копіювання!(класа університет)" << endl;
}

University::~University(){
	cout << "Деструктор!(класа університет)" << endl;}

void University::Set_all_info()
{
	this->Set_self_place_in_ranking();
	this->Set_self_military_department();
	this->Set_list_of_students();
	this->Set_self_cathidrals();
}

void University::Set_self_place_in_ranking()
{
	cout << "Введіть місце на якому знаходиться університет у рейтингу університетів та натисніть 'Enter': " << endl;
	cin >> this->place_in_international_ranking;
	cin.get();
	cout << "Сетер місця в рейтингу університетів(класу університет)!" << endl;
}

void University::Set_self_military_department()
{
	cout << "Сетер наявності війскової кафедри(класу університет)!" << endl;
}

void University::Set_self_cathidrals()
{
	cout << "Введіть кількість кафедр університету та натисніть 'Enter': " << endl;
	cin >> this->size_cathedrals;
	cin.get();
	Сathedra* cathedrals = new Сathedra[size_cathedrals];
	for (int i = 0; i < size_cathedrals; i++) {
		cathedrals[i].Set_all_info();
	}
}

void University::Set_list_of_students()
{
	int i{};
	int count{};
	cout << "Введіть кількість персоналу(цифра людин), який хочете заповнити: \t";
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

	cout << "Введіть номер студенту, котрого хочете відрахувати: \t";
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
	this->cathedrals = new Сathedra[other.size_cathedrals];
	for (int i = 0; i < other.size_cathedrals; i++) {
		this->cathedrals[i] = other.cathedrals[i];
	}
}

ostream& operator<<(ostream& os, University& other)
{
	os << "Назва університету: \t" << other.Get_self_name() << "\n" << "Номер телефону університету: \t" << other.Get_self_phone() << "\n"
		<< "Адресса за якою знаходиться університету: \t" << other.Get_self_adress() << "\nМісце на якому знаходиться університет у рейтингу університетів: \t" << other.Get_self_place_in_ranking() <<
		"\nНаявності війскової кафедри: \t" << other.Get_self_military_department();
	//сделать вывод студентов по кафедрам.
	os << "Список усіх студентів у цьому університеті: " << endl;
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
	//os << "Список усіх студентів у цьому університеті: " << endl;
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

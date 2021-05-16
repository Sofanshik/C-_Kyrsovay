#include "Organisation.h"

Organisation::Organisation()
{
	this->name = "";
	this->adress = "";
	this->phone = "";
	cout << "Конструктор за замовчуванням!(класа організація)" << endl;
}

Organisation::Organisation(const Organisation& other)
{
	this->name = other.name;
	this->phone = other.phone;
	this->adress = other.adress;
	this->list_of_persons = other.list_of_persons;
	cout << "Конструктор копіювання!(класа організація)" << endl;
}

Organisation::~Organisation()
{
	this->list_of_persons.clear();
	cout << "Деструктор!(класа організація)" << endl;
}

void Organisation::Set_all_info()
{
	this->Set_self_name();
	this->Set_self_adress();
	this->Set_self_phone();
	this->Set_list_of_persons();
}

void Organisation::Set_self_name()
{
	cout << "Введіть назву організації та натисніть 'Enter': " << endl;
	getline(cin, this->name);
	cout << "Сетер назви (класу організацїя)!" << endl;
}

void Organisation::Set_self_phone()
{
	//можео добавить что можно выбрать сколько номеров хочешь чтоб было у организации
	cout << "Введіть номер телефону організації та натисніть 'Enter': " << endl;
	getline(cin, this->phone);
	cout << "Сетер номеру телефона (класу організацїя)!" << endl;
}

void Organisation::Set_self_adress()
{
	cout << "Введіть адресу організації та натисніть 'Enter': " << endl;
	getline(cin, this->adress);
	cout << "Сетер адреси (класу організацїя)!" << endl;
}

void Organisation::Set_list_of_persons()
{
	int i{};
	int count{};
	cout << "Введіть кількість персоналу(цифра людин), який хочете заповнити: \t";
	cin >> count;
	count_staff += count;
	cout << endl;
	Person person;
	while ( i != count) {
		person.Set_all_info();
		this->list_of_persons.push_back(person);
		i++;
	}
}

void Organisation::Set_self_name(string name)
{
	this->name = name;
	cout << "Сетер назви (класу організацїя з параметром)!" << endl;
}

void Organisation::Set_self_phone(string phone)
{
	this->phone = phone;
	cout << "Сетер номеру телефона (класу організацїя з параметром)!" << endl;
}

void Organisation::Set_self_adress(string adress)
{
	this->adress = adress;
	cout << "Сетер адреси (класу організацїя з параметром)!" << endl;
}

void Organisation::Add_staff()
{
	Person person;
	person.Set_all_info();
	this->list_of_persons.push_back(person);
	count_staff += 1;
}

void Organisation::Dismiss_an_employee()
{
	//сделать блок трай катч где будем ловаить исключения выходы за границу массива
	int index{};
	for (int i = 0; i < this->list_of_persons.size(); i++) {
		Person person = this->list_of_persons[i];
		cout << person << endl;
		count_staff -= 1;
	}

	//Сделать проверку если ввели число или не число
	//try
	//{
	//	cin >> index;
	//}
	//catch (const std::exception&)
	//{
	//}

	cout << "Введіть номер людини, котру хочете звільнити: \t";
	cin >> index;
	cout << endl;

	this->list_of_persons.pop_of_index(index - 1);
}

void Organisation::Dismiss_all_employees()
{
	this->list_of_persons.clear();
}

void Organisation::Print_info()
{
	cout << "Назва організації: \t" << this->name << endl;
	cout << "Номер телефону організації: \t" << this->phone << endl;
	cout << "Адресса за якою знаходиться організція: \t" << this->adress << endl;
	cout << "Список усіх працюючих людей у цій компанії: " << endl;
	for (int i = 0; i < this->list_of_persons.size(); i++) {
		cout << (i + 1) << ") \t" << this->list_of_persons[i] << endl;
	}
}

string Organisation::Get_self_name()
{
	return this->name;
}

string Organisation::Get_self_phone()
{
	return this->phone;
}

string Organisation::Get_self_adress()
{
	return this->adress;
}


void Organisation::operator=(const Organisation& other)
{
	this->name = other.name;
	this->phone = other.phone;
	this->adress = other.adress;
	this->list_of_persons = other.list_of_persons;
}

ostream& operator<<(ostream& os, Organisation& other)
{
	os << "Назва організації: \t" << other.Get_self_name() << "\n" << "Номер телефону організації: \t" << other.Get_self_phone() << "\n" 
		<< "Адресса за якою знаходиться організція: \t" << other.Get_self_adress() << "\n";
	os << "Список усіх працюючих людей у цій компанії: " << endl;
	for (int i = 0; i < other.list_of_persons.size(); i++) {
		os << (i + 1) << ") \t" << other.list_of_persons[i] << endl;
	}
	return os;
}

istream& operator>>(istream& is, Organisation& other)
{
	other.Set_all_info();
	return is;
}

ostream& operator<<=(ostream& os, Organisation& other)
{
	
	os << other.Get_self_name() << "\n" << other.Get_self_phone() << "\n" << other.Get_self_adress() << "\n";
	//os << "Список усіх працюючих людей у цій компанії: " << endl;
	for (int i = 0; i < other.list_of_persons.size(); i++) {
		os << (i + 1) << ") \t" << other.list_of_persons[i] << endl;
	}
	return os;
}

istream& operator>>=(istream& is, Organisation& other)
{
	getline(is, other.name);
	getline(is, other.phone);
	getline(is, other.adress);
	
	for (int i = 0; i < count_staff; i++) {
		
		is >>= other.list_of_persons[i];
	}
	return is;
}

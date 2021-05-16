#include "Ñathedra.h"


void Ñathedra::Set_all_info()
{
	int count_people;
	this->Set_self_name();
	cout << "Ââåä³òü ê³ëüê³ñòü ñòóäåíò³â, ÿê³ íàâ÷àşòüñÿ íà êàôåäğ³ òà íàòèñí³òü 'Enter': " << endl;
	cin >> count_people;
	this->Set_self_count_people_on_cath(count_people);
	this->Set_self_list_of_student();
	this->Set_self_min_mark_for_enter();
}

void Ñathedra::Print_info(){
	cout << "Íàçâà êàôåäğè: \t" << this->Get_self_name();
	cout << "\nÊ³ëüê³ñòü ñòóäåíò³â, ÿê³ íàâ÷àşòüñÿ íà ö³é êàôåäğ³: \t" << this->Get_self_count_people_on_cath(); 
	cout << "\nÓñ³ ñòóäåíòè ùî íàâ÷àşòüñÿ íà ö³é êàôåäğ³: \n";
	this->list_students_in_cath.show();
	cout << "\nÌ³í³ìàëüí³é ïğîõ³äíèé áàë: \t" << this->Get_self_min_mark_for_enter() << "\n";
}

Ñathedra::Ñathedra()
{
	this->name = "";
	this->count_people_on_cathedra = 0;
	this->min_mark_for_enter = 0;
	cout << "Êîíñòğóêòîğ çà çàìîâ÷åííÿì(êëàñó êàôåäğà)!" << endl;
}

Ñathedra::Ñathedra(const Ñathedra& other)
{
	this->name = other.name;
	this->count_people_on_cathedra = other.count_people_on_cathedra;
	this->min_mark_for_enter = other.min_mark_for_enter;
	this->list_students_in_cath = other.list_students_in_cath;
	cout << "Êîíñòğóêòîğ êîï³şâàííÿ(êëàñó êàôåäğà!)" << endl;
}

Ñathedra::~Ñathedra(){
	this->list_students_in_cath.clear();
	cout << "Äåñòğóêòîğ (êëàñó êàôåäğà)!" << endl;}

void Ñathedra::Set_self_name()
{
	cout << "Ââåä³òü íàçâó êàôåäğè òà íàòèñí³òü 'Enter': " << endl;
	getline(cin, this->name);
	cout << "Ñåòåğ íàçâè (êëàñó êàôåäğà)!" << endl;
}

void Ñathedra::Set_self_count_people_on_cath(int count_people)
{
	this->count_people_on_cathedra += count_people;
}

void Ñathedra::Set_self_list_of_student() {
	Student student;
	for (int i = 0; i < this->count_people_on_cathedra; i++) {
		student.Set_all_info();
		this->list_students_in_cath.push_back(student);}}

void Ñathedra::Set_self_list_of_student(const Student& student){
	for (int i = 0; i < this->count_people_on_cathedra; i++) {
		this->list_students_in_cath.push_back(student);}}

void Ñathedra::Set_self_min_mark_for_enter()
{
	cout << "Ââåä³òü ì³í³ìàëüíèé áàë äëÿ âñòóïó íà öş êàôåäğó òà íàòèñí³òü 'Enter': " << endl;
	cin >> this->min_mark_for_enter;
	cout << "Ñåòåğ ì³í³ìàëüíîãî áàëó(êëàñó êàôåäğà)!" << endl;
}

string Ñathedra::Get_self_name()
{
	return this->name;
}

int Ñathedra::Get_self_count_people_on_cath()
{
	return this->count_people_on_cathedra;
}

double Ñathedra::Get_self_min_mark_for_enter()
{
	return this->min_mark_for_enter;
}

void Ñathedra::operator=(const Ñathedra& other)
{
	this->name = other.name;
	this->count_people_on_cathedra = other.count_people_on_cathedra;
	this->min_mark_for_enter = other.min_mark_for_enter;
}

ostream& operator<<(ostream& os, Ñathedra& other)
{
	other.Print_info();
	return os;
}

istream& operator>>(istream& is, Ñathedra& other)
{
	other.Set_all_info();
	return is;
}

ostream& operator<<=(ostream& os, Ñathedra& other)
{
	//Äîïèëèòü
	return os;
}

istream& operator>>=(istream& is, Ñathedra& other)
{
	//Äîïèëèòü
	return is;
}

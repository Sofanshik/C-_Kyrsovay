#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include "Student.h"
#include "My_Vector.h"

using namespace std;

class Сathedra
{
protected:
	string name;
	int count_people_on_cathedra;
	double min_mark_for_enter;
	Vector<Student> list_students_in_cath;

	void Set_self_name();
	void Set_self_count_people_on_cath(int);
	void Set_self_list_of_student();
	void Set_self_list_of_student(const Student &student);
	void Set_self_min_mark_for_enter();

	string Get_self_name();
	int Get_self_count_people_on_cath();
	double Get_self_min_mark_for_enter();

public:
	void Set_all_info();
	void Print_info();

	Сathedra();
	Сathedra(const Сathedra& other);

	~Сathedra();

	void operator = (const Сathedra& other);

	friend ostream& operator <<(ostream& os, Сathedra& other); //Перегрузка оператора вывода
	friend istream& operator >>(istream& is, Сathedra& other); //Перегрузка оператора ввода

	friend ostream& operator <<=(ostream& os, Сathedra& other); //Перегрузка опретора ввода в файл
	friend istream& operator >>=(istream& is, Сathedra& other); //Перегружка оператора вывода из файла
};


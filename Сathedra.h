#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include "Student.h"
#include "My_Vector.h"

using namespace std;

class �athedra
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

	�athedra();
	�athedra(const �athedra& other);

	~�athedra();

	void operator = (const �athedra& other);

	friend ostream& operator <<(ostream& os, �athedra& other); //���������� ��������� ������
	friend istream& operator >>(istream& is, �athedra& other); //���������� ��������� �����

	friend ostream& operator <<=(ostream& os, �athedra& other); //���������� �������� ����� � ����
	friend istream& operator >>=(istream& is, �athedra& other); //���������� ��������� ������ �� �����
};


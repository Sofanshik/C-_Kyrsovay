#pragma once
#include "Enrollee.h"
class Student :
    public Enrollee
{
protected:
    bool budget;
    string participation_in_life_university;
    int year_of_entry;

public:
    Student();
    Student(const Student& other);
    ~Student();

    void Set_all_info() override;

    void Set_self_average_mark();
    void Set_self_specialty();
    void Set_self_budget();
    void Set_self_participation_in_l_u();
    void Set_self_year_of_entry();

    bool Get_self_budget();
    string Get_self_participation_in_l_u();
    int Get_year_of_entry();

    void Print_info() override;

    void operator = (const Student& other);

    friend ostream& operator <<(ostream& os, Student& other); //Перегрузка оператора вывода
    friend istream& operator >>(istream& is, Student& other); //Перегрузка оператора ввода

    friend ostream& operator <<=(ostream& os, Student& other); //Перегрузка опретора ввода в файл
    friend istream& operator >>=(istream& is, Student& other); //Перегружка оператора вывода из файла
};


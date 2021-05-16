#pragma once
#include "Person.h"
class Enrollee:public Person
{
protected:
    double average_mark_of_the_certificate;
    string privileges;
    string specialty;
public:
    Enrollee();
    Enrollee(const Enrollee& other);
    
    void Print_info() override;

    void Set_all_info() override;
    void Set_self_average_mark();
    void Set_self_privilages();
    void Set_self_specialty();

    void Set_self_average_mark(double);
    void Set_self_privilages(string);
    void Set_self_specialty(string);

    double Get_self_average_mark();
    string Get_self_privilages();
    string Get_self_specialty();

    void Opportunity_enter_specialty();
    //После создания класа кафедра, добавить сдесь объект этого класса и проверять если средний бал не меньше чем требуемый на кафедре
    //то может поступить туда, если ниже то нет

    void operator = (const Enrollee& other);

    friend ostream& operator <<(ostream& os, Enrollee& other); //Перегрузка оператора вывода
    friend istream& operator >>(istream& is, Enrollee& other); //Перегрузка оператора ввода

    friend ostream& operator <<=(ostream& os, Enrollee& other); //Перегрузка опретора ввода в файл
    friend istream& operator >>=(istream& is, Enrollee& other); //Перегружка оператора вывода из файла

    ~Enrollee();
};


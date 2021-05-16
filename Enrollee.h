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
    //����� �������� ����� �������, �������� ����� ������ ����� ������ � ��������� ���� ������� ��� �� ������ ��� ��������� �� �������
    //�� ����� ��������� ����, ���� ���� �� ���

    void operator = (const Enrollee& other);

    friend ostream& operator <<(ostream& os, Enrollee& other); //���������� ��������� ������
    friend istream& operator >>(istream& is, Enrollee& other); //���������� ��������� �����

    friend ostream& operator <<=(ostream& os, Enrollee& other); //���������� �������� ����� � ����
    friend istream& operator >>=(istream& is, Enrollee& other); //���������� ��������� ������ �� �����

    ~Enrollee();
};


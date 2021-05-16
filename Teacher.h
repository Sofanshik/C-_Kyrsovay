#pragma once
#include "Person.h"
class Teacher :
    protected Person
{
protected: 
    string subject_taught;
    string position;// �������� ���� ������� � �.�

public:
    Teacher();
    Teacher(const Teacher& other);
    
    void Print_info() override;

    void Set_all_info() override;
    void Set_self_subject_taught();
    void Set_self_position();

    void Set_self_subject_taught(string);
    void Set_self_position(string);

    string Get_self_subject_taught();
    string Get_self_position();

    void operator = (const Teacher& other);

    friend ostream& operator <<(ostream& os, Teacher& other); //���������� ��������� ������
    friend istream& operator >>(istream& is, Teacher& other); //���������� ��������� �����

    friend ostream& operator <<=(ostream& os, Teacher& other); //���������� �������� ����� � ����
    friend istream& operator >>=(istream& is, Teacher& other); //���������� ��������� ������ �� �����

    ~Teacher();
};


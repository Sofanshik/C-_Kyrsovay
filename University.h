#pragma once
#include "Organisation.h"
#include "Student.h"
#include "�athedra.h"

class University :
    protected Organisation
{
protected:
    int place_in_international_ranking;
    bool military_department;
    Vector<Student> list_of_persons;
    �athedra* cathedrals;
    int size_cathedrals;
public:

    University();
    University(const University& other);
    ~University();

    void Set_all_info() override;
    void Set_self_place_in_ranking();
    void Set_self_military_department();
    void Set_self_cathidrals();
    void Set_list_of_students();

    int Get_self_place_in_ranking();
    bool Get_self_military_department();

    void Add_student();
    void Deduct_student();
    void Deduct_all_students();

    void operator = (const University& other);

    friend ostream& operator <<(ostream& os, University& other); //���������� ��������� ������
    friend istream& operator >>(istream& is, University& other); //���������� ��������� �����

    friend ostream& operator <<=(ostream& os, University& other); //���������� �������� ����� � ����
    friend istream& operator >>=(istream& is, University& other); //���������� ��������� ������ �� �����
};


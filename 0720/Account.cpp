//Account.cpp

#include <iostream>
using namespace std;
#include "Account.h"

Account::Account(int _id, string _name) : id(_id), name(_name), balance(0)
{}Account::Account(int _id, string _name, int _balance) 
: id(_id), name(_name), balance(_balance)
{}Account::~Account()
{
}

void Account::InputMoney(int money){	balance = balance + money;}void Account::OutputMoney(int money){	balance = balance - money;}void Account::Print(){	cout << "[���¹�ȣ] " << id << "\t";	cout << "[�̸�] " << name.c_str() << "\t";	cout << "[�ܾ�] " << balance << "��" << "\t";}

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

void Account::InputMoney(int money){	balance = balance + money;}void Account::OutputMoney(int money){	if (balance < money)		throw "�ܾ��� �����մϴ�.";	balance = balance - money;}void Account::Print() const{	cout << "[���¹�ȣ] " << id << "\t";	cout << "[�̸�] " << name.c_str() << "\t";	cout << "[�ܾ�] " << balance << "��" << endl;}

void Account::Println() const{	cout << "[���¹�ȣ] " << id << endl;	cout << "[�̸�] " << name.c_str() << endl;	cout << "[�ܾ�] " << balance << "��" << endl;}

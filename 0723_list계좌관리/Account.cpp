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

void Account::InputMoney(int money){	balance = balance + money;}void Account::OutputMoney(int money){	if (balance < money)		throw "ÀÜ¾×ÀÌ ºÎÁ·ÇÕ´Ï´Ù.";	balance = balance - money;}void Account::Print() const{	cout << "[°èÁÂ¹øÈ£] " << id << "\t";	cout << "[ÀÌ¸§] " << name.c_str() << "\t";	cout << "[ÀÜ¾×] " << balance << "¿ø" << endl;}

void Account::Println() const{	cout << "[°èÁÂ¹øÈ£] " << id << endl;	cout << "[ÀÌ¸§] " << name.c_str() << endl;	cout << "[ÀÜ¾×] " << balance << "¿ø" << endl;}

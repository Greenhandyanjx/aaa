#pragma once
#include"Person.h"
class Technician : public Person {
	int time;
public:
	Technician(){}
	Technician(string n, int id, int g = 1);
	void pay(int time);
	int gettime() { return time; }
	int settime(int time) {this->time= time; }
	int getsalary();
};
class Saleman : virtual public Person {
	int sale;
public:
	Saleman() {}
	Saleman(string n, int id, int g = 1);
	virtual void pay(int sum);
	int getsale() { return sale; }
	int setsale(int n) { sale = n; }
	int getsalary();
};
class Manager :virtual public Person {
public:
	Manager() {}
	Manager(string n, int id, int g = 1);
	virtual void pay(int num);
	int getsalary();
};
class Salemanager : public Saleman,public Manager{
	int sumsale;
public:
	Salemanager() {}
	Salemanager(string n, int id, int g = 1);
	virtual void pay (int sum);
	int getsumsale() { return sumsale; }
	int setsumsale(int n) { sumsale = n; }
	int getsalary();
};
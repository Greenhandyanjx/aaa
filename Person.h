#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Person {
protected:
	string name;
	int grade;
	int ID;
	double salary;
public:
	static int count;
	Person(){}
	Person(string n, int id,int g=1) {
		name = n;
		ID = id;
		grade = g;
	}
	void setgrade(int g) {
		grade = g;
	}
	string getname() {
		return name;
	}
	int getID() {
		return ID;
	}
	int getgrade() {
		return grade;
	}
	virtual void pay(int num)=0;
	virtual int getsalary() = 0;
};

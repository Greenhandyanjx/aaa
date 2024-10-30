#pragma once
#include"employee.h"
#include<vector>
using namespace std;
class work {
public:
	vector<Person*>vec;
	string filename;
	work() { filename = "1.xlsx"; }
	work(string f);
	void menu();
	void exitSystem();
	void enhance();
	void save();	
	int get_num();
	void monthpay();
	void showSalary();
	int EMPIsExist(int ID);
	void DeleteE(int index);
	void inputInfo();
	void find();
	void  Sort();
	void destroy();
	void write_to_excel(vector<Person*>vec);
	vector<Person*> read_from_excel();
	~work();
	bool FileIsEmpty = false;
};
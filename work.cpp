#define _CRT_SECURE_NO_WARNINGS 1
#include"Person.h"
#include"employee.h"
#include"work.h"
#include<vector>
#include<fstream>
#include<streambuf>
using namespace std;
int Person::count = 0;
Technician::Technician(string n, int id, int g) :Person(n,id){
	setgrade(3);
}
Saleman::Saleman(string n, int id, int g) :Person(n, id) {
	setgrade(1);
}
Manager::Manager(string n, int id, int g) :Person(n, id) {
	setgrade(4);
}
Salemanager::Salemanager(string n, int id, int g) :Person(n, id) {
	setgrade(2);
}
void Technician::pay(int time) {
	this->time= time;
}
void Saleman::pay(int sum) {
	sale = sum;
}
void Manager::pay(int num) {
	salary = num;
}
void Salemanager::pay(int sum) {
	sumsale = sum;
}
int Manager::getsalary() {
	return salary;
}
int Technician::getsalary() {
	return 100*time;
}
int Saleman::getsalary() {
	return 0.04*sale;
}
int Salemanager::getsalary() {
	return 5000+0.02*sumsale;
}
void work::menu()
{
	cout << "  公司职工薪酬管理系统  " << endl;
	cout << "***********************" << endl;
	cout << "*1   录入职工资料   ***" << endl;
	cout << "*2   增加职工       ***" << endl;
	cout << "*3   删除职工       ***" << endl;
	cout << "*4   月薪发放       ***" << endl;
	cout << "*5   显示工资表     ***" << endl;
	cout << "*0   退出系统       ***" << endl;
	cout << "***********************" << endl;
}
void work::exitSystem()
{
	cout << "您已经退出,欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void work::inputInfo() {
	cout << "录入职工资料将覆盖当前EXCEL文档的内容,选择是否继续:Y(yes)/N(no)" << endl;
	char choice;
	cout << "请选择:" << endl;
	cin >> choice;
	if (choice == 'N')return;
	cout << "输入职工的花名册:" << endl;
	cout << "-----------------------------------" << endl;
	cout << "经理姓名,输入@表示结束" << endl;
	string mname;
	cin >> mname;
	Person* p = new Manager(mname, 2001, 4);
	p->pay(18000);
	vec.push_back(p);
	Person::count++;
	cout << "输入技术人员姓名:输入@表示结束" << endl;
	while (true) {
		cout << "输入技术人员姓名:";
		string n;
		cin >> n;
		if (n.compare("@") == 0)break;
		Person* p1 = new Technician(n, 2000 + Person::count + 1, 3);
		vec.push_back(p1);
		Person::count++;
	}
	cout << "输入销售经理姓名:输入@表示结束" << endl;
	while (true) {
		cout << "输入销售经理姓名:";
		string n;
		cin >> n;
		if (n.compare("@") == 0)break;
		Person* p1 = new Salemanager(n, 2000 + Person::count + 1, 2);
		vec.push_back(p1);
		Person::count++;
	}
	cout << "输入推销人员姓名:输入@表示结束" << endl;
	while (true) {
		cout << "输入推销人员姓名:";
		string n;
		cin >> n;
		if (n.compare("@") == 0)break;
		Person* p1 = new Saleman(n, 2000 + Person::count + 1, 1);
		vec.push_back(p1);
		Person::count++;
	}
	write_to_excel(vec);
}
void work::write_to_excel(vector<Person*>vec) {
	ofstream of;
	of.open(filename);
	of << "姓名" << "\t" << "编号" << "\t" << "等级" << "\t" << "工资" << endl;
	for (auto& i : vec) {
		of << i->getname() << "\t" << i->getID() << "\t" << i->getgrade() << "\t" << i->getsalary() << endl;
	}
	of.close();
}
vector<Person*> work::read_from_excel() {
	ifstream ifs;
	ifs.open(filename,ios::in);
	if (!(ifs.is_open())) {
		cout << "file not founded" << endl;
		FileIsEmpty = true;
		return;
	}
	int g, int id;
	string n;
	while (ifs>>n&&ifs>>id&&ifs>>g) {

	}
}
void work::enhance() {
	string n;
	cout << "请输入想添加的名字:";
	cin >> n;
	cout << "输入岗位:1,推销人员;2,销售经理;3,技术人员;4,经理";
	int g;
	cin >> g;
	for (int i = 0; i < Person::count; i++) {
		if (vec[i]->getgrade() == g) {
			Person* temp;
			switch (g) {
			case 1:
			temp = new Saleman(n, 2000 + Person::count + 1, g);
			break;
			case 2:
			temp = new Salemanager(n, 2000 + Person::count + 1, g);
			break;
			case 3:
			temp = new Technician(n, 2000 + Person::count + 1, g);
			break;
			case 4:
			temp = new Manager(n, 2000 + Person::count + 1, g);
			break;
			}
			vec.insert(vec.begin() + i, temp);
			write_to_excel(vec);
			Person::count++;
			break;
		}
	}

}
work::work(string f){
	filename = f;
}
work::~work(){}
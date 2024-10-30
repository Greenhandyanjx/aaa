#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include"work.h"
#include"Person.h"
#include"employee.h"
using namespace std;
int main()
{
	system("chcp 65001");
	int a;
	work w1("1.xlsx");
	while (true)
	{
		w1.menu();
		cout << "请选择:   " << endl;
		cin >> a;
		switch (a)
		{
		case 0:
			w1.exitSystem();
			break;
		case 1:
			w1.inputInfo();
			break;
		case 2:
			w1.enhance();
			break;
		//case 3:{
		//while(true){
		//	int num = 0, index = 0;
		//	cout << "你想删除的员工编号:" << endl;
		//	cin >> num;
		//	index = w1.EMPIsExist(num);
		//	if (w1.EMPIsExist(num) == -1)
		//	{
		//		cout << "你输入的编号不存在!请重新输入!" << endl;
		//		continue;
		//	}
		//	else {
		//		w1.DeleteE(index);
		//		cout << "删除成功!" << endl;
		//		break;
		//	}
		//	}
		//break;
		//}
		//case 4:
		//	w1.monthpay();
		//	break;
		//case 5:
		//	w1.showSalary();
		//	break;
		default:
			system("cls");
			break;
		}
	}

	return 0;
}
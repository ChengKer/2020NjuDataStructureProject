#include"Controller.h"
#include<iomanip>
#include <stdlib.h>
#include<iostream>
using namespace std;

void Controller::show_main_page() {
	cout << "欢迎来到中国行政区域染色与信息查询系统！" << endl;
	cout << "本系统支持以下功能：" << endl;
	cout << std::left << setw(20) << "1. 打印行政区域列表" << std::left << setw(20) << "2. 查询行政区域信息"  << std::left << setw(20)<< "3. 对区域进行染色" << endl 
		<< std::left << setw(20) << "4. 建立通信网" << std::left << setw(20) << "5. 查询行政区域距离" << std::left << setw(20) << "6. 退出系统" << endl;
}

void Controller::clear() {
	system("cls");
}

void Controller::print_provience() {
	do {
		cout << "行政区域列表如下：" << endl;
		_g.print_province();
		if (!is_continue())break;
	} while (true);
	clear();
}

void Controller::paint_graph() {
	do {
		cout << "共使用颜色数：" << _g.paint_province() << endl;
		cout << "各个行政区域及其颜色如下：" << endl;
		_g.print_color();
		if (!is_continue())break;
	}while (true);
	clear();
}

void Controller::plan() {
	do {
		Vector<Edge> routes(100);
		cout << "通信线路铺设总费用为：:" << _g.plan(&routes) << endl;
		cout << "铺设路线如下：" << endl;
		for (int i = 0; i < routes.size(); i++) {
			cout << "x:" << _g.get_name_by_index(routes[i].get_x()) << " y:" << _g.get_name_by_index(routes[i].get_y()) << " " << "Distance:" << routes[i].get_distance() << endl;
		}
		if (!is_continue())break;
	} while (true);
	clear();
}

bool Controller::is_continue() {
	cout << "1：继续   2：返回上一页" << endl;
CH:	int choice;
	cin >> choice;
	bool continue_flag = true;
	switch (choice){
	case 1:
		break;
	case 2:
		continue_flag = false;
		break;
	default:
		cout << "输入错误，请重新输入" << endl;
		goto CH;
	}
	return continue_flag;
}

void Controller::distance() {
	do {
		cout << "请输入两个行政区域名称(用空格隔开，当前仅支持行政区域列表中的省名称，可以打印行政区域列表获取各行政区域名称)" << endl;
		string x;
		string y;
		Vector<string> route(10);
		cin >> x >> y;
		int dis = _g.get_distance(x, y, &route);
		if (dis != -1 && dis != MAX_DISTANCE && x!=y) {
			cout << "距离为：" << dis << " 公里" << endl;
			for (int i = route.size() - 1; i > 0; i--)cout<< route[i]<< "-->";
			cout << route[0] << endl;
		}
		if (dis == -1) {
			cout << "您输入的省名称有误！" << endl;
		}
		else if (dis == MAX_DISTANCE) {
			cout << "您输入的省之间无法连通！" << endl;
		}
		else if (x == y) {
			cout << "您输入的行政区域相同，距离为0！" << endl;
		}
		if (!is_continue())break;
	} while (true);
	clear();
}

void Controller::select_info() {
	do {
		cout << "请输入行政区域名称(当前仅支持行政区域列表中的行政区域名称，可以打印省列表获取各行政区域名称)" << endl;
		string temp;
		cin >> temp;
		cout << _g.select_info(temp) << endl;
		if (!is_continue())break;
	}while (true);
	clear();
}


void Controller::Control() {
	while (true) {
		show_main_page();
		int choice;
		bool quit_flag = false;
		cin >> choice;
		switch (choice) {
		case 1:
			print_provience();
			break;
		case 2:
			select_info();
			break;
		case 3:
			paint_graph();
			break;
		case 4:
			plan();
			break;
		case 5:
			distance();
			break;
		case 6:
			quit_flag = true;
			break;
		default:
			cout << "输入有误！请重新输入！" << endl;
			break;
		}
		if (quit_flag)break;
	}
	clear();
	cout << "程序结束！" << endl;
};




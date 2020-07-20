#include"Controller.h"
#include<iomanip>
#include <stdlib.h>
#include<iostream>
using namespace std;

void Controller::show_main_page() {
	cout << "��ӭ�����й���������Ⱦɫ����Ϣ��ѯϵͳ��" << endl;
	cout << "��ϵͳ֧�����¹��ܣ�" << endl;
	cout << std::left << setw(20) << "1. ��ӡ���������б�" << std::left << setw(20) << "2. ��ѯ����������Ϣ"  << std::left << setw(20)<< "3. ���������Ⱦɫ" << endl 
		<< std::left << setw(20) << "4. ����ͨ����" << std::left << setw(20) << "5. ��ѯ�����������" << std::left << setw(20) << "6. �˳�ϵͳ" << endl;
}

void Controller::clear() {
	system("cls");
}

void Controller::print_provience() {
	do {
		cout << "���������б����£�" << endl;
		_g.print_province();
		if (!is_continue())break;
	} while (true);
	clear();
}

void Controller::paint_graph() {
	do {
		cout << "��ʹ����ɫ����" << _g.paint_province() << endl;
		cout << "����������������ɫ���£�" << endl;
		_g.print_color();
		if (!is_continue())break;
	}while (true);
	clear();
}

void Controller::plan() {
	do {
		Vector<Edge> routes(100);
		cout << "ͨ����·�����ܷ���Ϊ��:" << _g.plan(&routes) << endl;
		cout << "����·�����£�" << endl;
		for (int i = 0; i < routes.size(); i++) {
			cout << "x:" << _g.get_name_by_index(routes[i].get_x()) << " y:" << _g.get_name_by_index(routes[i].get_y()) << " " << "Distance:" << routes[i].get_distance() << endl;
		}
		if (!is_continue())break;
	} while (true);
	clear();
}

bool Controller::is_continue() {
	cout << "1������   2��������һҳ" << endl;
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
		cout << "�����������������" << endl;
		goto CH;
	}
	return continue_flag;
}

void Controller::distance() {
	do {
		cout << "����������������������(�ÿո��������ǰ��֧�����������б��е�ʡ���ƣ����Դ�ӡ���������б��ȡ��������������)" << endl;
		string x;
		string y;
		Vector<string> route(10);
		cin >> x >> y;
		int dis = _g.get_distance(x, y, &route);
		if (dis != -1 && dis != MAX_DISTANCE && x!=y) {
			cout << "����Ϊ��" << dis << " ����" << endl;
			for (int i = route.size() - 1; i > 0; i--)cout<< route[i]<< "-->";
			cout << route[0] << endl;
		}
		if (dis == -1) {
			cout << "�������ʡ��������" << endl;
		}
		else if (dis == MAX_DISTANCE) {
			cout << "�������ʡ֮���޷���ͨ��" << endl;
		}
		else if (x == y) {
			cout << "�����������������ͬ������Ϊ0��" << endl;
		}
		if (!is_continue())break;
	} while (true);
	clear();
}

void Controller::select_info() {
	do {
		cout << "������������������(��ǰ��֧�����������б��е������������ƣ����Դ�ӡʡ�б��ȡ��������������)" << endl;
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
			cout << "�����������������룡" << endl;
			break;
		}
		if (quit_flag)break;
	}
	clear();
	cout << "���������" << endl;
};




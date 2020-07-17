#include <iostream>
using namespace std;
#include<string>
#include"Graph/graph.h"

void select_info_test(Graph &g) {
	cout << "开始测试！" << endl;
	while (true) {
		string temp;
		cin >> temp;
		cout << g.select_info(temp) << endl;
	}
}

int main()
{
	string province_addr = "D:/大三下/数据结构/期末项目/INFO.txt";
	string distance_addr = "D:/大三下/数据结构/期末项目/省距离.txt";
	Graph g(province_addr, distance_addr);
	select_info_test(g);
}

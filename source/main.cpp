#include"Controller/Controller.h"
#include<iostream>

int main(){
	Controller c("C:/Users/Orange/source/repos/2020NJUDS_Proj/2020NJUDS_Proj/data/INFO.txt",
		"C:/Users/Orange/source/repos/2020NJUDS_Proj/2020NJUDS_Proj/data/DISTANCE.txt");
	c.Control();
	return 0;
}



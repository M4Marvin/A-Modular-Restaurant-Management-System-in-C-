#ifndef STATS_H
#define STATS_H

#include"transaction.h"
#include"menu.h"

class stats {
	transaction tempTransac;
	float totalEarnings;
	float earningsPerItem[20] = {0};
	float earningsPerCategory[3];
	int bestItem;
	int bestCategory; // 0 : Main Course, 1 : drink, 2: dessert;
	string categoryList[3];
	menu m;
	
public:
	
	stats(){
		totalEarnings = 0;
		bestItem = -1;
		bestCategory = -1;
		string temp[3] = {"Main Course", "drink", "dessert"};
		for(int i=0;i<m.getLength();i++){
			earningsPerItem[i] = 0;
		}
		for(int i=0;i<3;i++){
			earningsPerCategory[i] = 0;
		}
		for(int i=0;i<3;i++){
			categoryList[i] = temp[i];
		}
		m.loadMenu("menu.txt");
	}
	void calculateStats();
	void printStats();
};

#endif  

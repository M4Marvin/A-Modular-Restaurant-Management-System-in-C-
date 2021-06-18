#ifndef MENU_H
#define MENU_H
#include<string>
#include"item.h"

using namespace std;

class menu{
	item itemList[100];
	int length;
	
public:
	menu(){
		length = 0;
	}
	// completed
	
	void createMenu(); 
	void printMenu();
	void storeMenu();
	void loadMenu(string fileName);
	void loadMenu();
	float getPriceForQuantity(int itemNo, int qauntity);
	bool isEmpty();	
	int getCategory(int itemNo);
	int getLength();
	string getName(int itemNo);

};


#endif 

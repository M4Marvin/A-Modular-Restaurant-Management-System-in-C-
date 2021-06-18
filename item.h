#ifndef ITEM_H
#define ITEM_H
#include<string>
#include<fstream>

class item{
	int itemNo;
	std::string category;
	std::string description;
	float price;
public:
	item(){
		itemNo = -1;
		category = "None";
		description = "None";
		price = 100;
	}
	void getItem(int );
	void print();
	float getPrice();
	int getCategory();
	std::string getName();
	void store(std::ofstream &outfile);
	void read(std::ifstream &infile);	
};

#endif 

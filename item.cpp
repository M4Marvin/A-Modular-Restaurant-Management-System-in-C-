#include"item.h"
#include<cassert>
#include<string>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

void item::getItem(int itemNo){
	string description, category;
	float price;
	if(itemNo>1){
		cin.ignore();
	}
	cout<<"Enter the desciption : ";
	getline(cin,description);
	cout<<"Enter the category : ";
	getline(cin,category);
	
	assert(strcmpi("Main Course",category.c_str())==0 ||
		   strcmpi("Dessert",category.c_str())==0 ||
		   strcmpi("Drink",category.c_str())==0);
	
	cout<<"Enter the price : ";
	cin>>price;
	
	assert( price > 0);
	
	this->itemNo = itemNo;
	this->description = description;
	this->category = category;
	this->price = price;
}

void item::print(){
	cout<<setw(4)<<right<<itemNo<<".      ";
	cout.width(40);
	cout<<left<<description;
	cout<<price<<endl;
}

float item::getPrice(){
	return price;
}

void item::store(ofstream &outfile){
	outfile<<itemNo<<":"<<category<<":"<<description<<":"<<price<<"\n";
}

void item::read(ifstream &infile){
	infile>>itemNo;
	infile.ignore();
	getline(infile,category,':');
	getline(infile,description,':');
	infile>>price;
}

string item::getName(){
	return description;
}

int item::getCategory(){
	if(strcmpi("Main Course",category.c_str())==0){
		return 0;
	}
	else if(strcmpi("drink",category.c_str())==0){
		return 1;
	}
	return 2;
}


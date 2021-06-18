#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<cassert>
#include"menu.h"

using namespace std;

void menu::createMenu(){
	cout<<"\nCreating a new Menu...........\n";
	cout<<"\nEnter length of the menu : ";
	cin>>length;
	
	assert(length<=100);
	
	cin.ignore();
	for(int i=0;i<length;i++){
		cout<<"\n\nItem No. "<<i+1<<endl;
		itemList[i].getItem(i+1);
	}
	cout<<"\n\nMenu has been created!\n";
}

void menu::printMenu(){
	
	cout<<"Printing the Menu......\n\n\n";
	
	for(int i=0;i<length;i++){
		itemList[i].print();
	}
	
	cout<<"\n\n------------------------------------------------------\n";
}

float menu::getPriceForQuantity(int itemNo , int quantity)
{
	int p = itemList[itemNo - 1].getPrice();
	
	return quantity*p;
}

void menu::storeMenu(){
	
	cout<<"Storing the Menu.........\n";
	if(isEmpty())
		cout<<"Menu is currently Empty!!\nInvalid Input!!\n";
	else
	{
		string fileName;
		cout<<"Enter the name of menu file.(Spaces are not allowed.)  (Store menu): ";
		cin>>fileName;
		fileName += ".txt";
		
		ofstream outfile(fileName.c_str());
	
		for(int i=0;i<length;i++){
			itemList[i].store(outfile);
		}
		outfile.close();
		
		cout<<"Menu is stored.\n\n";
	}
}

void menu::loadMenu(){
	
	string fileName;
	cout<<"Enter the name of menu file.(Spaces are not allowed.) (Load menu) : ";
	cin>>fileName;
	fileName += ".txt";
	ifstream infile(fileName.c_str());
	
	assert(infile);
	
	while(!infile.eof()){
		itemList[length].read(infile);
		length++;
	}
	length--;
	
	cout<<"\n\nA menu with "<< length<<" items has been loaded.\n\n";
}

void menu::loadMenu(string fileName){
	ifstream infile(fileName.c_str());
	while(!infile.eof()){
		itemList[length].read(infile);
		length++;
	}
	length--;
}

bool menu::isEmpty(){
	return length==0;
}

int menu::getCategory(int itemNo){
	return itemList[itemNo - 1].getCategory();
}

string menu::getName(int itemNo){
	return itemList[itemNo - 1].getName();
}

int menu::getLength(){
	return length;
}
	

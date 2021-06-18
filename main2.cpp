#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include <ctime>  

#include"menu.h"
#include"item.h"
#include"transaction.h"
#include"bill.h"

using namespace std;

int main(){
	
	bill b;
	int choice = 0;
	ofstream  outfile("allTransaction.txt");
	
	cout<<"Welcome to the cashier program!!\n\n";
	cout<<"Storing transaction details in the file name : allTransacion.txt\n\n";
	
	do{
		b.addTransaction(outfile);
		cout<<"Do you want to add more transactions?\n0 for yes\n1 for no : ";
		cin>>choice;
	}while(choice == 0);
}

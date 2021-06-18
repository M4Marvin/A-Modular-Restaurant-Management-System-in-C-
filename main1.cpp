#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

#include"item.h"
#include"menu.h"

void printChoices(){
	cout<<" 1 : Create a new Menu.\n";
	cout<<" 2 : Store the Menu.\n";
	cout<<" 3 : Print the Menu.\n";
	cout<<" 4 : Load Menu from a file.\n";
	cout<<" 5 : Get Price for certain Quantity of an item.\n";
	cout<<" 6 : Exit.\n\n";
}

void start(){
	menu m;
	int choice;
	
	cout<<"Welcome to the Menu Program.......\n\n";
	
	do{
		printChoices();
		cout<<"\nEnter your choice : ";
		
		cin>>choice;
		cout<<endl;
		
		switch( choice ){
			case 1:
				m.createMenu();
				break;
			case 2:
				m.storeMenu();
				break;
			case 3:
				m.printMenu();
				break;
			case 4:
				m.loadMenu();
				break;
			case 5:
				int in,q;
				float ans;
				cout<<"Enter the item number and desired quantity.\n";
				cin>>in>>q;
				ans = m.getPriceForQuantity(in, q);
				cout<<"\nResult = "<<ans<<endl<<endl;
				break;
			case 6:
				cout<<"\n\nExiting..................\n\n";
				cout<<"Have a nice day!!\n";
				break;
		}
	}while(choice != 6);
}

int main(){
	start();
}

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include <ctime> 

#include"menu.h"
#include"transaction.h"
#include"stats.h"

using namespace std;

void stats::calculateStats(){
	int count = 1;
	ifstream infile("allTransaction.txt");
	
	for(int i=0;i<m.getLength();i++){
		earningsPerItem[i] = 0;
	}
	for(int i=0;i<3;i++){
		earningsPerCategory[i] = 0;
	}
	while(!infile.eof()){
		tempTransac.read(infile);
		
		cout<<"Printing Transaction No."<< count++ <<"\n\n";
		tempTransac.print();
		
		int length = tempTransac.getLength();
		
		totalEarnings += tempTransac.getGrandTotal();
		
		int *itemArray = tempTransac.getItemArray();
		int *quantityArray = tempTransac.getQuantityArray();
		int *priceArray = tempTransac.getPriceArray();
		
		for(int i=0;i<length;i++){
			
			int itemNo = itemArray[i];
			earningsPerItem[itemNo - 1] += priceArray[i];
			
			int category = m.getCategory(itemNo);
			earningsPerCategory[category] += priceArray[i];
		}
	}
	int menuLength = m.getLength();
	int maxEarningsItem = 0;
	for(int i=0;i<menuLength;i++){
		if(maxEarningsItem < earningsPerItem[i])
		{
			bestItem = i+1;
			maxEarningsItem = earningsPerItem[i];
		}
	}
	int maxEarningsCategory = 0;
	for(int i=0;i<3;i++){
		if(maxEarningsCategory < earningsPerCategory[i])
		{
			bestCategory = i;
			maxEarningsCategory = earningsPerCategory[i];
		}
	}
	
	cout<<"Calculations for the transactions of the day are complete...\n\n";
	getchar();
}

void stats::printStats(){
	int menuLength = m.getLength();
	
	m.printMenu();
	getchar();
	
	cout<<"\nEarnings per item are as follows:\n\n";
	for (int i=0;i<menuLength;i++){
		cout<<setw(4)<<right<<i+1<<".  "<<setw(20)<<left<<m.getName(i+1)<<earningsPerItem[i]<<endl;
	}
	getchar();
	
	cout<<"\n\nEarnings per category are as follows:\n\n";
	for(int i=0;i<3;i++){
		cout<<categoryList[i]<<"  "<<earningsPerCategory[i]<<endl;
	}
	getchar();
	
	string bestItemName = m.getName(bestItem);
	
	cout<<"Item giving maxixmum earnings : "<<bestItem<<" "<<bestItemName<<endl;
	cout<<"Category giving maximum earnings : "<<categoryList[bestCategory];
}

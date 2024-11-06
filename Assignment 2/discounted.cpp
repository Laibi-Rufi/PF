#include<iostream>
using namespace std;
int main(){
	
	int quantityA,quantityB,quantityC;
	
	
	double PriceA=50.0;
	double PriceB=40.0;
	double PriceC=90.0;
	
	cout<<"Enter the quantity of product A : ";
	cin>>quantityA;
	
	cout<<"Enter the quantity of product B : ";
	cin>>quantityB;
	
	cout<<"Enter the quantity of product C : ";
	cin>>quantityC;
	
	double total=(PriceA*quantityA)+(PriceB*quantityB)+(PriceC*quantityC);
	
		double finalTotal = (total > 200) ? total*0.9 : total;
	
	cout<<"Total after discount : "<<finalTotal;
}
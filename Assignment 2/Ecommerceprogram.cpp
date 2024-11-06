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
	
    cout<<"Total Price :"<<total<<endl;
	
		double finalTotal = (total > 200) ? total*0.9 : total;
		
		cout<<"Total after discount : "<<finalTotal<<endl;
		
		     double shipping= (total > 150) ?  15 : 0.0;
		     	   double Total=finalTotal+shipping;
			 cout<<"Total after discount and shipping : "<<Total<<endl;
			 
			         double loyaltypoints= (Total>300) ? 50 : 20;
			         cout<<"Loyalty Points :"<<loyaltypoints<<endl;
			         
			     }
			           
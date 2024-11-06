#include<iostream>
using namespace std;
int main(){
	
	int quantityA,quantityB,quantityC;
	int paymethod;
	
	
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
	
	    double shipping= (total > 150) ?  15 : 0.0;
	    
	   double Total=finalTotal+shipping;
	    
	    double loyaltypoints= (Total>300) ? 50 : 20;
	    
	   cout<<"Select a payment method : (1 for credit card , 2 for PayPal , 3 for cash)";
	   cin>>paymethod;
	   
	   double transactionfee=(paymethod==1)?Total*0.02 :
	   	(paymethod==2)?Total*0.03:0.0;
	   	
	   double	TotalafterPayment=Total+transactionfee;
	   
	   cout<<"Total after applying transaction fee : "<<TotalafterPayment;
	   
	   return 0;
}
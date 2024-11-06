#include<iostream>
using namespace std;
int main(){
	
	int quantityA,quantityB,quantityC;
	int customertype;
	int location,paymethod;
	string couponcode,Save10;
	
	
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
	    
	    double Finalamount=(customertype==2) ? Total*0.95:Total;
	    
	     double transactionfee=(paymethod==1)?Total*0.02 :
	   	(paymethod==2)?Total*0.03:0.0;
	   	
	   double	TotalafterPayment=Total+transactionfee;
	   
		
		
		double couponDiscount=(couponcode==Save10)? 10.0:Finalamount;
		double AmountafterDiscount=Finalamount-couponDiscount;
		
			double Taxrate = (location == 1) ? 0.05 : 
                 (location == 2) ? 10.0 : 0.08;

			double TotalwithTax=Finalamount*(1+Taxrate);
			
			int StockA=5;
			int StockB=7;
			int StockC=10;
			
			if(quantityA>StockA){
				cout<<"Sorry only "<<StockA<<" units of product A are avaliable"<<endl;
			}
			if(quantityB>StockB){
				cout<<"Sorry only "<<StockB<<" units of product B are avaliable"<<endl;
			}
			if(quantityC>StockC){
				cout<<"Sorry only "<<StockC<<" units of product C are avaliable"<<endl;
			}
		
			
			cout << "Product A (x" << quantityA << "): $" << PriceA * quantityA <<endl;
			cout << "Product B (x " <<quantityB<< "): $" <<PriceB * quantityB <<endl;
			cout << "Product C (x" <<quantityC<< "):$" <<PriceC * quantityC <<endl;
			
			cout<<"Subtotal : $"<<total<<endl;
			cout<<"Discount : $"<<total-finalTotal<<endl;
			cout<<"Shipping : $"<<shipping<<endl;
			cout<<"Transaction Fee : $"<<transactionfee<<endl;
			cout<<"Coupon Discount : $"<<couponDiscount<<endl;
			cout<<"Sales Tax : $"<<TotalwithTax-AmountafterDiscount<<endl;
			cout<<"Total Amount to pay : $"<<TotalwithTax<<endl;
			
			
			
	   return 0;
}
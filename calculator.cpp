#include <iostream>
using namespace std;

int main(){
	
	float num1 , num2 , result;
	char operation;
	char choice;
	
	do{
		
		cout<<"Enter first number: ";
		cin>>num1;
		
		cout<<"Enter second number: ";
		cin>>num2;
		
		cout<<"Choose an operation (+,-,*,/)";
		cin>>operation;
		
		switch (operation) {
			
			case '+':
				result = num1+num2;
				cout<<"Result= "<<num1<<"+"<<num2<<"="<<result<<endl;
				break;
				
			case '-' :
			     result = num1-num2;
				 cout<<"Result= "<<num1<<"-"<<num2<<"="<<result<<endl;
				 break;
				 
			case '*':
			     result = num1*num2;
			     cout<<"Result= "<<num1<<"*"<<num2<<"="<<result<<endl;
				 break;
				 
			case '/':
			    if (num2 !=0){
			    		     
				  result = num1/num2;
				  cout<<"Result= "<<num1<<"/"<<num2<<"="<<result<<endl;
				  
			} else {
				      cout<< "Error: Division by zero! " <<endl;
				      	      
			}
			  break;
			  
			  default:
			  	      cout<< "Invalid Operation!"<<endl;
			  	      break;
			  	  }
			  	      
				  cout << "Do you want to perform another calculation? (y/n): ";
                  cin >> choice;

              }  
			   while (choice == 'y' || choice == 'Y');

              cout << "Thank you for using the calculator!" << endl;

              return 0;
     }
    

		
     


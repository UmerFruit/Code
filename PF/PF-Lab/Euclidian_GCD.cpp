#include<iostream>
using namespace std;
int main(){
	int gcd, num1, num2;
	int i=1;
	cout<<"Enter 2 numbers"<<endl;
	cin>>num1>>num2;
	if(num1>num2){
		while(i<=num1){
		
			if((num1%i==0) && (num2%i == 0)){
				gcd = i;
		
			}
			i = i + 1;
		}
		cout<<"Greatest Common Divisor is "<<gcd<<endl;
		
	}
	else {
		while(i<=num2){
		
			if((num1%i==0) && (num2%i == 0)){
				gcd = i;
		
			}
			i = i + 1;
		}
		cout<<"Greatest Common Divisor is "<<gcd<<endl;
		
	}
}

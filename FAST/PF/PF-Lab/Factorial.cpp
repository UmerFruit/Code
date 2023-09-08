#include<iostream>
using namespace std;
int main(){
	int num,i=1,fac=1;
	cout<<"Enter number for factorial : "<<endl;
	cin>>num;
	if(num<20){
	while(i<=num){
		
		fac = fac*i;
		i++;
	
	}
	cout<<"Factorial of "<<num<<" = "<<fac<<endl;
}
	else{
	cout<<"error"<<endl;}

}

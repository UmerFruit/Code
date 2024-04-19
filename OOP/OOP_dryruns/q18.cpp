#include<iostream>
using namespace std;

class Number{
public:
	int* value;
	Number(int v) {
		value = new int(v);
		cout << "Value: " << *value << endl;
	}
	~Number() {
		cout << "Killed: " << *value << endl;
		delete value;
	}
};
class Question{
public:
	Number marks;
	Question(int A) : marks(A) {
		cout << "New Object \n";
	}
	Question(const Question &X) : marks(*X.marks.value + 10){
		cout << "ItsEasy" << endl;
	}
};
void Difficult(Question why){
	Question Quest = why;
}
int main(){
	Question Answer(1);
	Difficult(Answer);	
}
/*
Value: 1
New Object
Value: 11
ItsEasy
Value: 21
ItsEasy
Killed: 21
Killed: 11
Killed: 1
*/
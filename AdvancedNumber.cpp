/* Create a base class Number and derived class AdvancedNumber.
a. Overload + in derived class */

#include<iostream>
using namespace std;

class Number{
	protected:
		int num;
	public:
	Number(int n = 0){
		num = n;
	}
	void Display(){
		cout << "Value : " << num <<endl;
	}
};

class AdvancedNumber : public Number{
	public:
		AdvancedNumber(int n = 0) : Number(n){};
		
		AdvancedNumber operator+ (const AdvancedNumber& obj){
			AdvancedNumber sum;
			sum.num = num+obj.num;
			return sum; 
		}
};

int main(){
	AdvancedNumber num1(5), num2(7);
	AdvancedNumber result = num1+num2;
	result.Display();
	
	return 0;
}

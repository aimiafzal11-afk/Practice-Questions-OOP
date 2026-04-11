/* Create a class Employee with static variable to count employees. */

#include<iostream>
using namespace std;

class Employee{
	private:
		static int count;
	public:
		Employee(){
			count++;
		}
		void Dispaly(){
			cout<<count<<" Employee object is created!"<<endl;
			cout<<"Count = "<<count<<endl;
		}
};

int Employee :: count=0;

int main(){
	Employee e1;
	e1.Dispaly();
	Employee e2;
	e2.Dispaly();
	Employee e3;
	e3.Dispaly();
	
	return 0;
}

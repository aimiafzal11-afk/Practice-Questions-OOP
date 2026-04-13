/* Create a class Temperature with conversion (Celsius <--> Fahrenheit). */

#include<iostream>
using namespace std;

class Temperature{
	private:
		double temp;
		char unit;
	public:
		Temperature(double t, char u){
			temp = t;
			unit = u;
		}
		Temperature setTemp(){
			if(unit == 'C' || unit == 'c'){
				double f = (temp * 9/5)+32;
				return Temperature(f, 'F');
			}else{
				double c = (temp - 32) * 5/9;
				return Temperature(c, 'C');
			}
		}
		Temperature operator+ (const Temperature& obj){
			return Temperature (temp + obj.temp, unit);
		}
		void display(){
			cout<<temp<<" "<<unit<<endl;
		}
};

int main(){
	Temperature t1(100, 'C');
	Temperature t2(37, 'C');
	
	t1.display();
	Temperature aft1=t1.setTemp();
	cout<<"After converting: "<<endl;
	aft1.display();
	
	t2.display();
	Temperature aft2=t2.setTemp();
	cout<<"After converting: "<<endl; 
	aft2.display();
	
	Temperature t3 = t1+t2;
	t3.display();
	return 0;
}

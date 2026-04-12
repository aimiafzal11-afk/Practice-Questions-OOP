/* Create a String class and overload concatenation operator. */

#include<iostream>
#include<string.h>
using namespace std;

class String{
	private:
		char str[100];
	public:
		String(const char s[] = ""){
			strcpy(str, s);
		}
		String operator+ (const String& obj){
			String combine;
			strcpy(combine.str, str);
			strcat(combine.str, obj.str);
			return combine;
		}
		void display(){
			cout<<str<<endl;
		}
};

int main(){
	String s1("Aiman ");
	String s2("Afzal");
	
	cout << "String 1 : ";
    s1.display();

    cout << "String 2 : ";
    s2.display();
    
	String s3 = s1+s2;
	
	cout << "Combined : ";
	s3.display();
	return 0;
}

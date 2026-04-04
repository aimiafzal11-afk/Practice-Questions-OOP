/* Create a function (Hint: Make it a friend fuction) which take two point objects and computes the distance between those 2 points */

#include<iostream>
#include<cmath>
using namespace std;

class Point{
	private:
		int x, y;
	public:
		Point(int a, int b){
			x = a;
			y = b;
		}	
		void Display(){
			cout<<"Point (x, y) = ("<<x<<" , "<<y<<")"<<endl;
		}
		friend float Diff(Point a, Point b);
};
        float Diff(Point a, Point b){
			int x1 = b.x - a.x;
			int y1 = b.y - a.y;
			float diff = sqrt((x1*x1) + (y1*y1)); 
			return diff;
		}
		
int main(){
	Point obj1 = Point(0, 1);
	obj1.Display();
	
	Point obj2 = Point(0, 6);
	obj2.Display();
	
	cout<<"Difference between points: "<<Diff(obj1, obj2);
	
	return 0;
;}

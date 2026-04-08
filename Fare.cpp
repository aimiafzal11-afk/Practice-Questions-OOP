/* A base class Fare stores distance and base fare. A derived class PremiumFare
adds luxury charges and tax. The system should combine fare components using
operator overloading to compute total fare. Implement inheritance and overload
operator for final fare. */

#include<iostream>
using namespace std;

class Fare{
	protected:
		double distance;
		int baseFare;
	public:
		Fare(double d=0.0, int bF=0){
			distance = d;
			baseFare = bF;
		}
		double getBaseFare(){
			return distance * baseFare;
		}
};

class PremiumFare : public Fare{
	private:
		int luxuryCharges;
		double tax;
	public:
		PremiumFare(double d=0.0, int bF=0, int luxCharges=0, double t=0 ) : Fare(d, bF){
		    luxuryCharges = luxCharges;
		    tax = t;
		};
		double getTotalFare(){
			double base = getBaseFare();
			return base + luxuryCharges + tax;
		}
		PremiumFare operator+ (const PremiumFare& obj){
			return PremiumFare(
				distance + obj.distance,
			    baseFare + obj.baseFare,
			    luxuryCharges + obj.luxuryCharges,
			    tax + obj.tax
			);
			//final.getTotalFare() = getTotalFare() + obj.getTotalFare();
			//return final;
		}
		void display(){
			cout<<"Distance =  "<<distance<<" km"<<endl;
			cout<<"Base Fare = Rs "<<getBaseFare()<<endl;
			cout<<"Luxury Charges = Rs "<<luxuryCharges<<endl;
			cout<<"Tax = Rs "<<tax<<endl;
			
			double total = getTotalFare();
			cout<<"Total Fare = Rs "<<total<<endl<<endl;
		}
};

int main(){
	PremiumFare p1(10, 5, 50, 20);
	PremiumFare p2(15, 5, 80, 30);
	
	cout << "---FARE 1---" << endl;
    p1.display();

    cout << "---FARE 2---" << endl;
    p2.display();

    // Combine fares using overloaded + operator
    PremiumFare p3 = p1 + p2;

    cout << "---COMBINED FARE (f1 + f2)---" << endl;
    p3.display();

    return 0;

}

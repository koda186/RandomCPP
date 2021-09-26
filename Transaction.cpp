#include<iomanip>
#include<iostream>
#include<string>
#include<cmath>
#include<sstream>
#include<algorithm>	//???
using namespace std;

class Transaction{
public:
	Transaction(unsigned doughnuts = 0, unsigned carburetors = 0, unsigned racquets = 0);
	unsigned getDoughnuts() const;			//return the number of doughnuts purchased in this transaction
	unsigned getCarburetors() const;		//return the number of carburetors purchased in this transaction
	unsigned getRacquets() const;			//return the number of raquets purchased in this transaction
	double getSubtotal() const;				//return the total cost of this purchase, excluding sales tax
	double getTotal() const;				//return the total cost of this purchase, including sales tax
private:
	unsigned Doughnuts;
	unsigned Carburetors;
	unsigned Racquets;
};

void report(const Transaction transaction[], unsigned elements);

int main()
{
	Transaction march[] = { Transaction(1, 2, 3), Transaction(10, 1), Transaction(12), Transaction(0, 2, 5) };
	//unsigned july[5] = { 1, 4, 5, 8, 8 };		//test this
	report(march, 4);
}//end main

void report(const Transaction transaction[], unsigned elements)		//NON-MEMBER FUNCTION
{
	unsigned totalDoughnuts = 0;
	unsigned totalCarburetors = 0;
	unsigned totalRacquets = 0;
	for (unsigned count = 0; count < 4; count++)
	{
		//cout << transaction[count].getDoughnuts() << endl;
		totalDoughnuts +=  transaction[count].getDoughnuts();		//# of donuts total
		totalCarburetors += transaction[count].getCarburetors();	//# of carburetors total
		totalRacquets += transaction[count].getRacquets();			//#of racquets total
	}

	cout << "Doughnuts: " << totalDoughnuts << endl;				//# of donuts total output
	cout << "Carburetors: " << totalCarburetors << endl;			//#of carburetors total output
	cout << "Racquets: " << totalRacquets << endl;					//#of racquets total output

	//FROM HERE TO END REPORT THE getSubtotal AND getTotal MEMBER FUNCTIONS ARE NOT BEING USED!!!
	double doughnuts_extax = totalDoughnuts * 0.4;
	double carburetors_extax = totalCarburetors * 200;
	double racquets_extax = totalRacquets * 75;
	double subTotal = doughnuts_extax + carburetors_extax + racquets_extax;


	double doughnuts_tax = doughnuts_extax + (doughnuts_extax * 0.09);
	double carburetors_tax = carburetors_extax + (carburetors_extax * 0.09);
	//racquets are not taxed
	double total = doughnuts_tax + carburetors_tax + racquets_extax;

	cout << subTotal << endl;
	cout << total << endl;

	//cout << transaction[4].getSubtotal() << endl;		//HELP
	//cout << transaction[4].getTotal() << endl;		//HELP

}//end report

Transaction::Transaction(unsigned doughnuts, unsigned carburetors, unsigned racquets)	//CONSTRUCT OF THE CLASS
{
	Doughnuts = doughnuts;
	Carburetors = carburetors;
	Racquets = racquets;

	//subtotal = (Doughnuts * 0.4) + (Carburetors * 200) + (Racquets * 75);
	//excluding tax
	//double doughnuts_extax = doughnuts * 0.4;
	//double carburetors_extax = carburetors * 200;
	//double racquets_extax = racquets * 75;
	//subtotal = doughnuts_extax + carburetors_extax + racquets_extax;	//subtotal is a private in our class


	//including tax
	//double doughnuts_tax = doughnuts_extax + (doughnuts_extax * 0.09);
	//double carburetors_tax = carburetors_extax + (carburetors_extax * 0.09);
	//double racquets_tax = racquets * 75;	//racquets are not taxed
	//total = doughnuts_tax + carburetors_tax + racquets_tax;
}

unsigned Transaction::getDoughnuts() const			//return the number of doughnuts purchased in this transaction
{
	return Doughnuts;
}

unsigned Transaction::getCarburetors() const		//return the number of carburetors purchased in this transaction
{
	return Carburetors;
}

unsigned Transaction::getRacquets() const			//return the number of raquets purchased in this transaction
{
	return Racquets;
}

double Transaction::getSubtotal() const				//return the total cost of this purchase, excluding sales tax
{
	return subtotal;	//NOT BEING USED
}

double Transaction::getTotal() const				//return the total cost of this purchase, including sales tax
{
	return total;		//NOT BEING USED
}

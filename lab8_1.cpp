#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){	
	double loan, rateperyear, payperyear;
	cout << "Enter initial loan: ";
	cin >> loan;
	cout << "Enter interest rate per year (%): ";
	cin >> rateperyear;
	cout << "Enter amount you can pay per year: ";
	cin >> payperyear;

	double PrevBalance = loan;
	double Payment = payperyear;
	double interest,total,Newbalance;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	
	//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect
	for(int x=0; x>=0; x++){
		cout << fixed << setprecision(2); 
		cout << setw(13) << left << x+1; 
		cout << setw(13) << left << PrevBalance;
		interest = PrevBalance * (rateperyear/100);
		cout << setw(13) << left << interest;
		total = PrevBalance+interest;
		cout << setw(13) << left << total;
		if(total<Payment) Payment=total;
		cout << setw(13) << left << Payment;
		Newbalance = total-Payment;
		cout << setw(13) << left << Newbalance;
		cout << "\n";
		PrevBalance = Newbalance;
		if(Newbalance <= 0) break;
	}
	return 0;
}
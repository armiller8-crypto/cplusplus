//includes header file as well as iostream and iomanip(the latter to do things like allow precision on output
#include "AirgeadBanking.h"
#include <iostream>
#include <iomanip>
using namespace std;
//Airgead Banking constructor with variables formatted to specs required by client
AirgeadBanking::AirgeadBanking() {
	m_initialInvestment = 0;
	m_monthlyDeposit = 0;
	m_annualInterest = 0;
	m_numYears = 0;

}
//defines getUserInput function
void AirgeadBanking::getUserInput() {
	//each of these outputs a question to the user about different information about they savings decisions
	cout << "How much do you want to invest to start out with?" << endl;
	cin >> m_initialInvestment;

	cout << "How much would you like to deposit monthly?" << endl;
	cin >> m_monthlyDeposit;

	cout << "What is the annual percentage interest rate?" << endl;
	cin >> m_annualInterest;

	cout << "How many years will this be for?" << endl;
	cin >> m_numYears;

}
//defines display input function which shows the user what they have entered. 
void AirgeadBanking::displayInput() const {
	cout << "******************************" << endl;
	cout << "**********Data Input**********" << endl;
	cout << "Initial Investment Amount: " << m_initialInvestment << endl;
	cout << "Monthly Deposit: " << m_monthlyDeposit << endl;
	cout << "Annual Interest: " << m_annualInterest << endl;
	cout << "Number of Years: " << m_numYears << endl;
	cout << "Press any key to continue..." << endl;

}
//defines print report for if user does not make extra monthly deposits
void AirgeadBanking::printNoMonthlyDepositReport() const {
	cout << "     Balance and Interest Without Additional Monthly Deposits     " << endl;
	cout << "==================================================================" << endl;
	cout << "Year           Year End Balance           Year End Earned Interest" << endl;
	cout << "------------------------------------------------------------------" << endl;
	//variables for the three items. Sets balance to initial investment to start, and sets the other two to 0
	double balance = m_initialInvestment;
	double monthlyInterest = 0;
	double yearlyInterest = 0;
	//sets output to appear like the normal dollars and cents style of money
	cout << fixed << setprecision(2);
	//loops that run through years and months that interest is accrued
	for (int i = 1; i <= m_numYears; i++) {
		yearlyInterest = 0;
		for (int j = 1; j <= 12; j++) {
			monthlyInterest = balance * (m_annualInterest / 100) / 12;
			balance = balance + monthlyInterest;
			yearlyInterest = yearlyInterest + monthlyInterest;

		}
		//took some trial and error here but essentially this sets the columns so that they are spaced evenly. 
		cout << setw(8) << i << setw(18) << balance << setw(26) << yearlyInterest << endl;
	}
}
//defines function for when user deposits extra money monthly. Mostly the same as previous function except this adds monthly deposit to balance
void AirgeadBanking::printMonthlyDepositReport() const {
	cout << "      Balance and Interest With Additional Monthly Deposits       " << endl;
	cout << "==================================================================" << endl;
	cout << "Year           Year End Balance           Year End Earned Interest" << endl;
	cout << "------------------------------------------------------------------" << endl;

	double balance = m_initialInvestment;
	double monthlyInterest = 0;
	double yearlyInterest = 0;

	cout << fixed << setprecision(2);

	for (int i = 1; i <= m_numYears; i++) {
		yearlyInterest = 0;
		for (int j = 1; j <= 12; j++) {
			balance = balance + m_monthlyDeposit;
			monthlyInterest = balance * (m_annualInterest / 100) / 12;
			balance = balance + monthlyInterest;
			yearlyInterest = yearlyInterest + monthlyInterest;

		}
		cout << setw(8) << i << setw(18) << balance << setw(26) << yearlyInterest << endl;
	}
}
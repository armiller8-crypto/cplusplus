//including header file as well as iomanip  to be able to modify output and set precision and width. 
#include "AirgeadBanking.h"
#include <iostream>
#include <iomanip>
using namespace std;
//main function
int main() {
	//create object of Airgead Banking class
	AirgeadBanking app;
	//calls getUserInput function
	app.getUserInput();
	//calls displayInput function
	app.displayInput();
	//this I had to look up on Google. Had no idea how to get the program to pause and wait for input. I was originally thinking a while loop. Google recommended this 
	std::cin.ignore();
	std::cin.get();
	//calls function which displays chart that shows user savings without extra deposit
	app.printNoMonthlyDepositReport();
	//calls function which displays chart that shows user savings with extra deposits
	app.printMonthlyDepositReport();

	return 0;
}

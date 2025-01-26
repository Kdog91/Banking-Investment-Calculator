// AirgeadBanking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <iostream>
#include "Investment.h"

using namespace std;

int main() {
    double initialAmount, monthlyDeposit, annualInterestRate;
    int numYears;

    // Display welcome message
    cout << "Welcome to Airgead Banking Investment Calculator!" << endl;
    cout << "Please enter the following details to calculate your investment growth." << endl;

    // Get user input for initial investment, monthly deposit, interest rate, and years
    cout << "Initial Investment Amount: $";
    cin >> initialAmount;

    cout << "Monthly Deposit: $";
    cin >> monthlyDeposit;

    cout << "Annual Interest Rate (in %): ";
    cin >> annualInterestRate;

    cout << "Number of Years: ";
    cin >> numYears;

    // Create an Investment object
    Investment myInvestment(initialAmount, monthlyDeposit, annualInterestRate, numYears);

    // Display results without monthly deposits
    cout << "Press any key to continue..." << endl;
    cin.get(); // Pause to allow user to read
    cin.get(); // For an additional press

    myInvestment.calculateBalanceWithoutDeposits();

    // Display results with monthly deposits
    cout << "Press any key to continue..." << endl;
    cin.get(); // Pause to allow user to read
    myInvestment.calculateBalanceWithDeposits();

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
#include <iostream>
#include <iomanip>   // For formatting output
#include "Investment.h"

using namespace std;

// Constructor to initialize the investment
Investment::Investment(double initial, double monthly, double interestRate, int numYears) {
    initialAmount = initial;
    monthlyDeposit = monthly;
    annualInterestRate = interestRate;
    years = numYears;
}

// Function to calculate and display balance without monthly deposits
void Investment::calculateBalanceWithoutDeposits() {
    double balance = initialAmount;
    double interest;

    cout << "\nBalance and Interest Without Additional Monthly Deposits" << endl;
    cout << "================================================================" << endl;
    cout << "Year\t\tYear End Balance\t\tYear End Earned Interest" << endl;
    cout << "----------------------------------------------------------------" << endl;

    for (int i = 1; i <= years; ++i) {
        interest = balance * (annualInterestRate / 100);
        balance += interest;

        cout << fixed << setprecision(2);
        cout << i << "\t\t" << balance << "\t\t\t" << interest << endl;
    }
}

// Function to calculate and display balance with monthly deposits
void Investment::calculateBalanceWithDeposits() {
    double balance = initialAmount;
    double interest;

    cout << "\nBalance and Interest With Additional Monthly Deposits" << endl;
    cout << "================================================================" << endl;
    cout << "Year\t\tYear End Balance\t\tYear End Earned Interest" << endl;
    cout << "----------------------------------------------------------------" << endl;

    for (int i = 1; i <= years; ++i) {
        double totalInterest = 0.0;

        for (int j = 0; j < 12; ++j) {
            interest = (balance + monthlyDeposit) * ((annualInterestRate / 100) / 12);
            totalInterest += interest;
            balance += monthlyDeposit + interest;
        }

        cout << fixed << setprecision(2);
        cout << i << "\t\t" << balance << "\t\t\t" << totalInterest << endl;
    }
}

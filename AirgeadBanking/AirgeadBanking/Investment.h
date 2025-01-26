#ifndef INVESTMENT_H
#define INVESTMENT_H

class Investment {
private:
    double initialAmount;
    double monthlyDeposit;
    double annualInterestRate;
    int years;

public:
    // Constructor to initialize investment data
    Investment(double initial, double monthly, double interestRate, int years);

    // Function to calculate and display balance without monthly deposits
    void calculateBalanceWithoutDeposits();

    // Function to calculate and display balance with monthly deposits
    void calculateBalanceWithDeposits();
};

#endif


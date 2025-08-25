#include <iostream>
#include "InvestmentCalculator.h"
#include "ReportPrinter.h"
//By: Kyle McCrea

int main() {
    double initialInvestment, monthlyDeposit, annualInterestRate;
    int numYears;
    char choice;

    do {
        // Display program header
        std::cout << "=============================================\n";
        std::cout << "        Airgead Banking Investment App       \n";
        std::cout << "=============================================\n";

        // ===== Input Validation =====
        // Ensure Initial Investment is positive
        do {
            std::cout << "Enter Initial Investment Amount (must be > 0): $";
            std::cin >> initialInvestment;
            if (initialInvestment <= 0) {
                std::cout << "Error: Please enter a positive value.\n";
            }
        } while (initialInvestment <= 0);

        // Ensure Monthly Deposit is not negative
        do {
            std::cout << "Enter Monthly Deposit (must be >= 0): $";
            std::cin >> monthlyDeposit;
            if (monthlyDeposit < 0) {
                std::cout << "Error: Please enter a non-negative value.\n";
            }
        } while (monthlyDeposit < 0);

        // Ensure Annual Interest Rate is positive
        do {
            std::cout << "Enter Annual Interest Rate (must be > 0): ";
            std::cin >> annualInterestRate;
            if (annualInterestRate <= 0) {
                std::cout << "Error: Please enter a positive value.\n";
            }
        } while (annualInterestRate <= 0);

        // Ensure Number of Years is positive
        do {
            std::cout << "Enter Number of Years (must be > 0): ";
            std::cin >> numYears;
            if (numYears <= 0) {
                std::cout << "Error: Please enter a positive integer.\n";
            }
        } while (numYears <= 0);
        // ============================

        // Create InvestmentCalculator object with validated inputs
        InvestmentCalculator calculator(initialInvestment, monthlyDeposit, annualInterestRate, numYears);

        // Generate and print report without monthly deposits
        auto noDepositResults = calculator.calculateGrowthWithoutDeposits();
        ReportPrinter::printReport(noDepositResults, "Balance and Interest Without Additional Monthly Deposits");

        // Generate and print report with monthly deposits
        auto withDepositResults = calculator.calculateGrowthWithDeposits();
        ReportPrinter::printReport(withDepositResults, "Balance and Interest With Additional Monthly Deposits");

        // Ask user if they want to run another scenario
        std::cout << "\nWould you like to try different values? (Y/N): ";
        std::cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    // Exit message
    std::cout << "\nThank you for using Airgead Banking Investment App!\n";
    return 0;
}
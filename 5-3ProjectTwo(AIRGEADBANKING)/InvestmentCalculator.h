#ifndef AIRGEAD_BANKING_INVESTMENTCALCULATOR_H_
#define AIRGEAD_BANKING_INVESTMENTCALCULATOR_H_

#include <vector>
//By: Kyle McCrea

// Struct to store results for each year
struct YearlyReport {
    int year;               // Current year number
    double yearEndBalance;  // Balance at the end of the year
    double yearEndInterest; // Interest earned during that year
};

// Class responsible for performing all investment growth calculations.
// This class contains no output code to ensure reusability and separation of concerns.
class InvestmentCalculator {
public:
    /**
     * Constructor
     * Initializes investment details.
     * @param t_initialInvestment Starting investment amount.
     * @param t_monthlyDeposit Amount deposited every month.
     * @param t_annualInterestRate Annual interest rate in percentage.
     * @param t_numYears Duration of the investment in years.
     */
    InvestmentCalculator(double t_initialInvestment,
        double t_monthlyDeposit,
        double t_annualInterestRate,
        int t_numYears);

    /**
     * Calculates yearly balances and interest without additional monthly deposits.
     * @return A vector of YearlyReport structs containing year, ending balance, and interest earned.
     */
    std::vector<YearlyReport> calculateGrowthWithoutDeposits() const;

    /**
     * Calculates yearly balances and interest with additional monthly deposits.
     * @return A vector of YearlyReport structs containing year, ending balance, and interest earned.
     */
    std::vector<YearlyReport> calculateGrowthWithDeposits() const;

private:
    double m_initialInvestment;   // Starting investment amount
    double m_monthlyDeposit;      // Monthly deposit amount
    double m_annualInterestRate;  // Annual interest rate (%)
    int m_numYears;               // Investment duration in years
};

#endif // AIRGEAD_BANKING_INVESTMENTCALCULATOR_H_
#include "InvestmentCalculator.h"
//By: Kyle McCrea

// Constructor sets investment parameters upon object creation
InvestmentCalculator::InvestmentCalculator(double t_initialInvestment,
    double t_monthlyDeposit,
    double t_annualInterestRate,
    int t_numYears)
    : m_initialInvestment(t_initialInvestment),
    m_monthlyDeposit(t_monthlyDeposit),
    m_annualInterestRate(t_annualInterestRate),
    m_numYears(t_numYears) {
}

/**
 * Performs compound interest calculations without monthly deposits.
 * Loops through each year, compounding interest monthly based only on the balance.
 */
std::vector<YearlyReport> InvestmentCalculator::calculateGrowthWithoutDeposits() const {
    std::vector<YearlyReport> reports;
    double balance = m_initialInvestment;

    for (int year = 1; year <= m_numYears; ++year) {
        double interestAccrued = 0.0;

        for (int month = 1; month <= 12; ++month) {
            double monthlyInterest = balance * ((m_annualInterestRate / 100) / 12);
            balance += monthlyInterest;
            interestAccrued += monthlyInterest;
        }

        reports.push_back({ year, balance, interestAccrued });
    }

    return reports;
}

/**
 * Performs compound interest calculations with monthly deposits.
 * Each month, a deposit is added before calculating interest.
 */
std::vector<YearlyReport> InvestmentCalculator::calculateGrowthWithDeposits() const {
    std::vector<YearlyReport> reports;
    double balance = m_initialInvestment;

    for (int year = 1; year <= m_numYears; ++year) {
        double interestAccrued = 0.0;

        for (int month = 1; month <= 12; ++month) {
            balance += m_monthlyDeposit;
            double monthlyInterest = balance * ((m_annualInterestRate / 100) / 12);
            balance += monthlyInterest;
            interestAccrued += monthlyInterest;
        }

        reports.push_back({ year, balance, interestAccrued });
    }

    return reports;
}
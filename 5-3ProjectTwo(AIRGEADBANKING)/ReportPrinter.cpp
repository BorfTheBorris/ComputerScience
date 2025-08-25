#include "ReportPrinter.h"
#include <iostream>
#include <iomanip>

//By: Kyle McCrea

/**
 * Prints investment results in a clean, formatted table.
 * Includes a title, headers, and yearly data aligned in columns.
 */
void ReportPrinter::printReport(const std::vector<YearlyReport>& t_reports,
    const std::string& t_title) {
    std::cout << "\n" << t_title << "\n";
    std::cout << "===================================================\n";
    std::cout << std::setw(5) << "Year"
        << std::setw(20) << "Year End Balance"
        << std::setw(20) << "Year End Interest" << "\n";
    std::cout << "---------------------------------------------------\n";

    for (const auto& report : t_reports) {
        std::cout << std::setw(5) << report.year
            << std::setw(20) << std::fixed << std::setprecision(2) << report.yearEndBalance
            << std::setw(20) << report.yearEndInterest << "\n";
    }
}
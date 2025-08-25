#ifndef AIRGEAD_BANKING_REPORTPRINTER_H_
#define AIRGEAD_BANKING_REPORTPRINTER_H_

#include <vector>
#include <string>
#include "InvestmentCalculator.h"

//By:Kyle McCrea

// Handles printing of formatted investment reports to the console.
class ReportPrinter {
public:
    /**
     * Displays a formatted report table to the console.
     * @param t_reports A vector of YearlyReport structs to be displayed.
     * @param t_title Title of the report (e.g., "Without Monthly Deposits").
     */
    static void printReport(const std::vector<YearlyReport>& t_reports,
        const std::string& t_title);
};

#endif // AIRGEAD_BANKING_REPORTPRINTER_H_

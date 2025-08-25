# ComputerScience
**Project Summary**

The Airgead Banking Investment App models compound interest growth with and without monthly deposits. The program addresses the problem of illustrating how investment strategies differ when deposits are added monthly compared to allowing only the initial investment to grow. By validating user inputs and producing tabular yearly reports, the application helps demonstrate the long-term benefits of consistent saving and compounding interest.

**Strengths of the Project**

One of the strongest aspects of this project is the modular design. The InvestmentCalculator class is fully dedicated to performing the core financial calculations, while the ReportPrinter class is responsible only for formatting and output. This separation of concerns ensures reusability and maintainability. Variable names and functions are descriptive, and inline comments clarify the purpose of each code block. Input validation loops also add reliability by preventing invalid investment amounts, deposits, or interest rates from being accepted.

**Areas for Enhancement**

Although the program functions correctly, several areas could be improved. Using integer cents or a fixed-point type would prevent floating-point rounding errors and provide more precise financial results. Efficiency could be improved by precomputing the monthly interest rate instead of recalculating it inside every loop iteration. Vector performance could be optimized further by reserving space equal to the number of years in advance. In terms of robustness, the code could be enhanced by checking for std::cin input failures to prevent crashes when non-numeric input is entered. Lastly, scalability could be addressed by separating program configuration into a file or structured object, making it easier to adapt the program to future graphical or web-based interfaces. These improvements would lead to more accurate, efficient, and adaptable software.

**Challenges and Solutions**

The most challenging aspect of the project was determining the proper order of operations when calculating balances with monthly deposits. Interest had to be applied after deposits were added, and this distinction is critical for accurate results. Careful testing against expected outcomes and financial calculators was necessary to confirm the correct sequence. Another challenge was properly tracking yearly interest totals while compounding monthly. This was resolved by introducing a dedicated accumulator variable within the yearly loop, ensuring that reported yearly interest was distinct from the overall balance growth.

**Transferable Skills**

This project reinforced several important skills that will be transferable to future coursework and professional development. The design emphasized modular programming practices, which are widely applicable in software engineering. The experience of handling user input validation and formatting results into clear tabular output will be valuable for other interactive programs. Additionally, reasoning through time-based simulations and ensuring correct loop logic builds a deeper understanding of algorithm design and testing.

**Maintainability, Readability, and Adaptability**

The program was designed with maintainability and clarity as primary goals. Each class has a single responsibility, making the program easier to update and extend. The YearlyReport struct provides a consistent data contract, allowing for straightforward expansion if new reporting metrics are needed in the future. Comments and documentation throughout the codebase make the logic easy to follow, and descriptive variable names further enhance readability. Because calculation logic is isolated from input and output operations, the program can be adapted for automated testing, different input methods, or even integration into a larger financial planning system without major restructuring.

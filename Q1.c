#include <stdio.h>
#include <math.h>

double totalRepayment = 0.0;

double estimateInstallment(double principal, double rate, int years) {
    if (rate == 0.0) {
        return principal / years;
    }
    return (principal * rate) / (1.0 - pow(1.0 + rate, -years));
}

double calculateRepayment(double loan, double interestRate, int remainingYears, int currentYear, double installment, double extraPayment) {
    if (remainingYears <= 0 || loan <= 0.01) {
        printf("--- Loan Repayment Complete ---\n");
        return 0.0;
    }

    double interest = loan * interestRate;
    double totalPayment = installment + extraPayment;
    
    totalRepayment += totalPayment;

    double newLoan;
    
    if (loan + interest < totalPayment) {
        totalRepayment -= (totalPayment - (loan + interest));
        newLoan = 0.0;
    } else {
        newLoan = loan + interest - totalPayment;
    }

    printf("Year %d: Remaining loan = %.2f $\n", currentYear, newLoan);

    return calculateRepayment(newLoan, interestRate, remainingYears - 1, currentYear + 1, installment, extraPayment);
}

int main() {
    double initialLoan = 100000.0;
    double interestRate = 0.05;
    int totalYears = 3;
    
    double fixedInstallment = estimateInstallment(initialLoan, interestRate, totalYears);
    
    printf("--- Repayment Trace (100,000 at 5%% over 3 years) ---\n");
    printf("Fixed Annual Installment: %.2f $\n", fixedInstallment);
    
    totalRepayment = 0.0; 
    
    calculateRepayment(initialLoan, interestRate, totalYears, 1, fixedInstallment, 0.0);
    
    printf("Total Repayment Over %d Years: %.2f $\n", totalYears, totalRepayment);
    
    return 0;
}

/*Create a class called LoanHelper, which helps the user calculate their loan payments. The class should have a variable that stores interest rate for the loan as a user defined constant value. Aside from the that, it also stores the amount for the loan taken and amount of months that the user will repay the loan in. The loan repayment should be calculated on a monthly basis, and the interest rate should be applied over the monthly return amount. The output should be something like: 
“You have to pay 999 every month for 12 monthsto repay your loan” 
Note: first divide loan amount by number of months, then apply the interest rate on it. Interest rate should be a value between 0-0.5%*/

#include <iostream>
using namespace std;

class LoanHelper {
private:
    const float interestRate;
    float loanAmount;
    int numOfMonths;

public:
    LoanHelper(float rate, float amount, int months) : interestRate(rate), loanAmount(amount), numOfMonths(months) {
        if (interestRate < 0.0 || interestRate > 0.5) {
            cout << "Interest rate must be between 0 and 0.5" << endl;
            return;
        }
    }

    void calculateMonthlyRepayment() const {
        float x = loanAmount / numOfMonths;
        float monthlyRepayment = x * (1 + interestRate);
        cout << "You have to pay " << monthlyRepayment << " every month for "
             << numOfMonths << " months to repay your loan." << endl;
    }
};

int main() {
    float loanAmount = 10000.0;
    int numOfMonths = 12;
    float interestRate = 0.005; 

    LoanHelper loan(interestRate, loanAmount, numOfMonths);
    loan.calculateMonthlyRepayment();
}
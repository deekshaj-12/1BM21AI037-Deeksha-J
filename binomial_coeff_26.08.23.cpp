#include <iostream>
using namespace std;

class BinomialCoefficientCalculator {
private:
    int inputN, inputK;

public:
    void getInput();
    int getMinimum(int a, int b);
    void calculateBinomialCoefficient();
};

void BinomialCoefficientCalculator::getInput() {
    cout << "Enter value of n: ";
    cin >> inputN;
    cout << "Enter value of k: ";
    cin >> inputK;
}

int BinomialCoefficientCalculator::getMinimum(int a, int b) {
    return a < b ? a : b;
}

void BinomialCoefficientCalculator::calculateBinomialCoefficient() {
    int Coefficients[inputN + 1][inputK + 1];
    int i, j, l = 2;

    for (i = 0; i < inputN + 1; i++) {
        if (i < inputK + 1) {
            Coefficients[i][i] = 1;
        }
        Coefficients[i][0] = 1;
    }

    for (i = 2; i <= inputN; i++) {
        j = 1;
        while (j < l) {
            if (l <= getMinimum(i - 1, inputK)) {
                l++;
            }
            Coefficients[i][j] = Coefficients[i - 1][j - 1] + Coefficients[i - 1][j];
            j++;
        }
    }

    cout << "Value of " << inputN << "C" << inputK << " is: " << Coefficients[inputN][inputK];
}

int main(void) {
    BinomialCoefficientCalculator calculator;
    calculator.getInput();
    calculator.calculateBinomialCoefficient();
}

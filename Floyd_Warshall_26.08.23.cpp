#include <iostream>
#include <vector>
using namespace std;

class KnapSolver {
private:
    int numItems, knapsackCapacity;
    vector<int> weights;
    vector<int> profits;

public:
    void getInput();
    int getMax(int a, int b);
    void solveKnap();
};

void KnapSolver::getInput() {
    cout << "Enter the number of items: ";
    cin >> numItems;
    weights.resize(numItems);
    profits.resize(numItems);
    
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < numItems; i++) {
        cin >> weights[i];
    }
    
    cout << "Enter the profits of the items: ";
    for (int i = 0; i < numItems; i++) {
        cin >> profits[i];
    }
    
    cout << "Enter the knapsack capacity: ";
    cin >> knapsackCapacity;
}

int KnapSolver::getMax(int a, int b) {
    return a > b ? a : b;
}

void KnapSolver::solveKnap() {
    vector<vector<int>> dp(numItems + 1, vector<int>(knapsackCapacity + 1));
    
    for (int i = 0; i <= numItems; i++) {
        for (int j = 0; j <= knapsackCapacity; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (j >= weights[i - 1]) {
                dp[i][j] = getMax(profits[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
            
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
    
    cout << "Maximum possible value: " << dp[numItems][knapsackCapacity];
}

int main(void) {
    KnapSolver solver;
    solver.getInput();
    solver.solveKnap();
}

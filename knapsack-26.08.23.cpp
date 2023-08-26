#include <iostream>
#include <vector>
using namespace std;

class Knapsack {
private:
    int itemCount, capacity;
    vector<int> weights;
    vector<int> profits;

public:
    void getInput();
    int max(int a, int b);
    void solveKnapsack();
};

void Knapsack::getInput() {
    cout << "Enter the number of items: ";
    cin >> itemCount;
    weights.resize(itemCount);
    profits.resize(itemCount);
    
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < itemCount; i++) {
        cin >> weights[i];
    }
    
    cout << "Enter the profits of the items: ";
    for (int i = 0; i < itemCount; i++) {
        cin >> profits[i];
    }
    
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;
}

int Knapsack::max(int a, int b) {
    return a > b ? a : b;
}

void Knapsack::solveKnapsack() {
    vector<vector<int>> dp(itemCount + 1, vector<int>(capacity + 1));
    
    for (int i = 0; i <= itemCount; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (j >= weights[i - 1]) {
                dp[i][j] = max(profits[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
            
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
    
    cout << "Max possible value: " << dp[itemCount][capacity];
}

int main(void) {
    Knapsack solver;
    solver.getInput();
    solver.solveKnapsack();
}

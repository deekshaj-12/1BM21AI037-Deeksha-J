#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class HorsepoolMatcher {
private:
    string inputText, searchPattern;
    unordered_map<char, int> shiftTable;

public:
    void getInput();
    void fillShiftTable();
    void matchPattern();
};

void HorsepoolMatcher::getInput() {
    cout << "Enter the input text: ";
    cin >> inputText;
    cout << "Enter the pattern to match: ";
    cin >> searchPattern;
}

void HorsepoolMatcher::fillShiftTable() {
    int patternLength = searchPattern.length();
    for (int i = 0; i < patternLength - 1; i++) {
        shiftTable[searchPattern[i]] = patternLength - i - 1;
    }
}

void HorsepoolMatcher::matchPattern() {
    int textLength = inputText.length();
    int patternLength = searchPattern.length();
    int i = patternLength - 1;
    int x;

    while (i <= textLength - 1) {
        int k = 0;
        while (k < patternLength && inputText[i - k] == searchPattern[patternLength - k - 1]) {
            k++;
        }

        if (k == patternLength) {
            cout << "Pattern match found at string index: " << i - patternLength + 1 << "\n";
            cout << "Pattern match found at absolute position: " << i - patternLength + 2 << "\n";
            return;
        } else {
            x = shiftTable[inputText[i]];
            if (x == 0)
                i += patternLength;
            else
                i += x;
        }
    }

    cout << "Pattern not found in the input string." << endl;
}

int main(void) {
    HorsepoolMatcher matcher;
    matcher.getInput();
    matcher.fillShiftTable();
    matcher.matchPattern();
    return 0;
}

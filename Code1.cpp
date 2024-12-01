#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

// extract a numeric value from the string
double extractNumeric(const string& str) {
    if (str.length() > 20) {
        return -999999.99; // length exceeds 20
    }
    
    bool hasDecimal = false;
    bool hasSign = false;
    bool valid = true;
    size_t i = 0;

    // check for leading '+' or '-'
    if (str[i] == '+' || str[i] == '-') {
        hasSign = true;
        i++;
    }

    if (i >= str.length()) { // check if string is just '+' or '-'
        return -999999.99;
    }

    string numericPart;
    for (; i < str.length(); i++) {
        char c = str[i];
        if (isdigit(c)) {
            numericPart += c;
        } else if (c == '.' && !hasDecimal) {
            hasDecimal = true;
            numericPart += c;
        } else {
            valid = false;
            break;
        }
    }

    // validate the numeric part
    if (!valid || numericPart.empty() || (numericPart == ".")) {
        return -999999.99;
    }

    // convert to double
    try {
        double result = stod(numericPart);
        return result;
    } catch (...) {
        return -999999.99; // conversion failed
    }
}

int main() {
    string input;
    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;
        if (input == "END") {
            break;
        }
        double number = extractNumeric(input);
        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }
    return 0;
}

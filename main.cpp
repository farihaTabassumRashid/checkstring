#include <iostream>

#include <fstream>

#include <string>

#include <cctype> // for isalpha() and isspace()

using namespace std;

// Function to check if a string is valid

bool isValidString(const string& line) {

    for (char c : line) {

        if (!isalpha(c) && !isspace(c)) {

            // if character is not a letter and not a space → invalid

            return false;

        }

    }

    return true;

}

int main() {

    ifstream file("sample.txt");

    string line;

    int lineNumber = 0;

    bool hasError = false;

    if (!file) {

        cout << "Error: Could not open sample.txt file!" << endl;

        return 1;

    }

    cout << "Checking sample.txt for invalid strings...\n\n";

    while (getline(file, line)) {

        lineNumber++;

        if (isValidString(line)) {

            cout << "✅ Line " << lineNumber << " is valid: " << line << endl;

        } else {

            cout << "❌ Line " << lineNumber << " is invalid: " << line << endl;

            hasError = true;

        }

    }

    if (!hasError) {

        cout << "\nAll strings are valid! ✅" << endl;

    } else {

        cout << "\nOne or more strings are invalid! ⚠️" << endl;

    }

    file.close();

    return 0;

}


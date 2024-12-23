#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>  // For controlling output format
#include <thread>   // For sleep function
#include <chrono>   // For time management
#include <random>   // For random number generation
#include <numeric>  // For accumulate function

using namespace std;

// Function prototypes
void simulateTypingAnimation(const string& text);
bool isValidNumber(const string& str);
void parseInput(const string& input, vector<string>& words, vector<int>& numbers);
string identifyOperation(const vector<string>& words, const vector<string>& additions, const vector<string>& subtractions, const vector<string>& multiplications, const vector<string>& divisions, vector<int>& numbers);
double performOperation(const string& operation, vector<int>& numbers);
void mathematicalOperations();

// Main function for mathematical operations
void mathematicalOperations() {
    cout << "\033[93mChatbot:\033[0m ";
    simulateTypingAnimation("Welcome to Mathematical Operations!\n");
    cout << "\033[93mChatbot:\033[0m ";
    simulateTypingAnimation("Type your query (e.g., 'add 5 and 3') or enter \033[34m'0'\033[0m to return to the main menu.\n");

    vector<string> additions = {"sum", "add", "plus", "addition", "+"};
    vector<string> subtractions = {"subtract", "minus", "-", "subtraction", "sub", "cut"};
    vector<string> multiplications = {"multiply", "times", "multiplication","*"};
    vector<string> divisions = {"divide", "divided" , "/"};

    string input;
    while (true) {
        cout << "You: ";
        getline(cin, input);

        // Trim input to handle accidental spaces
        input.erase(0, input.find_first_not_of(" \t"));
        input.erase(input.find_last_not_of(" \t") + 1);

        if (input == "0") {
            cout << "\033[93mChatbot:\033[0m ";
            simulateTypingAnimation("Returning to the main menu...\n");
            break;
        }

        vector<string> words;
        vector<int> numbers;
        parseInput(input, words, numbers);

        if (numbers.size() < 2) {
            cout << "\033[93mChatbot:\033[0m ";
            simulateTypingAnimation("Error - Could not find two valid numbers in the input.\n");
            continue;
        }

        string operation = identifyOperation(words, additions, subtractions, multiplications, divisions, numbers);

        if (operation.empty()) {
            cout << "\033[93mChatbot:\033[0m ";
            simulateTypingAnimation("Sorry, I didn't understand the operation.\n");
            continue;
        }

        if (operation == "Division" && find(numbers.begin() + 1, numbers.end(), 0) != numbers.end()) {
            cout << "\033[93mChatbot:\033[0m ";
            simulateTypingAnimation("Error - Division by zero.\n");
            continue;
        }

        double result = performOperation(operation, numbers);

        stringstream resultMessage;
        resultMessage << fixed;

        if (result == static_cast<int>(result)) {
            resultMessage << "The result of " << operation << " is: \033[32m"
                          << static_cast<int>(result) << "\033[0m\n";
        } else {
            resultMessage << "The result of " << operation << " is: \033[32m"
                          << setprecision(2) << result << "\033[0m\n";
        }

        cout << "\033[93mChatbot:\033[0m ";
        simulateTypingAnimation(resultMessage.str());
    }
}

// Function definitions
void simulateTypingAnimation(const string& text) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(50, 70); // Random delay between 50ms to 70ms

    for (char c : text) {
        cout << c << flush; // Print each character without a newline
        this_thread::sleep_for(chrono::milliseconds(dis(gen))); // Wait for a random time
    }
    this_thread::sleep_for(chrono::seconds(1)); // Add an additional 1-second delay after each message
}

bool isValidNumber(const string& str) {
    if (str.empty()) return false;

    stringstream ss(str);
    double d;
    ss >> d;
    return ss.eof() && !ss.fail(); // Checks if the conversion is successful and no extra characters
}

void parseInput(const string& input, vector<string>& words, vector<int>& numbers) {
    stringstream ss(input);
    string word;

    while (ss >> word) {
        words.push_back(word);
        if (isValidNumber(word)) {
            numbers.push_back(stoi(word));
        }
    }
}

string identifyOperation(const vector<string>& words, const vector<string>& additions, const vector<string>& subtractions, const vector<string>& multiplications, const vector<string>& divisions, vector<int>& numbers) {
    string operation;

    for (const auto& w : words) {
        if (ranges::find(additions, w) != additions.end()) {
            operation = "Addition";
        } else if (ranges::find(subtractions, w) != subtractions.end()) {
            if (ranges::find(words, "from") != words.end() && numbers.size() >= 2) {
                swap(numbers[0], numbers[1]);
            }
            operation = "Subtraction";
        } else if (ranges::find(multiplications, w) != multiplications.end()) {
            operation = "Multiplication";
        } else if (ranges::find(divisions, w) != divisions.end()) {
            operation = "Division";
        }
    }
    return operation;
}

double performOperation(const string& operation, vector<int>& numbers) {
    if (operation == "Addition") {
        return accumulate(numbers.begin(), numbers.end(), 0);
    } else if (operation == "Subtraction") {
        double result = numbers[0];
        for (size_t i = 1; i < numbers.size(); ++i) {
            result -= numbers[i];
        }
        return result;
    } else if (operation == "Multiplication") {
        double result = 1;
        for (int num : numbers) {
            result *= num;
        }
        return result;
    } else if (operation == "Division") {
        double result = numbers[0];
        for (size_t i = 1; i < numbers.size(); ++i) {
            result /= numbers[i];
        }
        return result;
    } else {
        return numeric_limits<double>::quiet_NaN(); // Return NaN for unsupported operations
    }
}

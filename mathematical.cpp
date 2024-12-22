#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>  // For controlling output format
#include <thread>   // For sleep function
#include <chrono>   // For time management
#include <random>   // For random number generation

using namespace std;

// Function to simulate random typing delay for each character
void simulateTypingAnimation(const string& text) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(50, 70); // Random delay between 50ms to 70ms

    for (char c : text) {
        cout << c << flush; // Print each character without a newline
        this_thread::sleep_for(chrono::milliseconds(dis(gen))); // Wait for a random time
    }
}

// Function to validate if a string represents a valid number
bool isValidNumber(const string& str) {
    // if (str.empty()) return false;
    //
    // size_t start = 0;
    // if (str[0] == '-' || str[0] == '+') {
    //     start = 1;  // Skip sign for further checks
    // }
    //
    // return all_of(str.begin() + start, str.end(), ::isdigit);  // Check if all characters are digits

    // Function to validate if a string represents a valid number (integer or floating-point)

        if (str.empty()) return false;

        stringstream ss(str);
        double d;
        // char c;
        ss >> d;
        return ss.eof() && !ss.fail(); // Checks if the conversion is successful and no extra characters
}

void mathematicalOperations() {
    cout << "\033[93mChatbot: Welcome to Mathematical Operations!\033[0m\n";
    cout << "Type your query (e.g., 'add 5 and 3') or enter \033[34m'0'\033[0m to return to the main menu.\n";

    string input;
    while (true) {
        cout << "You: ";
        getline(cin, input);

        // Trim input to handle accidental spaces
        input.erase(0, input.find_first_not_of(" \t"));
        input.erase(input.find_last_not_of(" \t") + 1);

        if (input == "0") {
            cout << "\033[93mChatbot: Returning to the main menu...\033[0m\n";
            break;
        }

        // Define operations
        vector<string> additions = {"sum", "add", "plus", "addition", "+"};
        vector<string> subtractions = {"subtract", "minus", "-", "subtraction", "sub", "cut"};
        vector<string> multiplications = {"multiply", "times", "multiplication","*"};
        vector<string> divisions = {"divide", "divided" , "/"};

        vector<string> words;
        stringstream ss(input);
        string word;

        while (ss >> word) {
            words.push_back(word);
        }
        vector<int> numbers;
        for (auto & each : words) {
            if (isValidNumber(each)) {
                numbers.push_back(stoi(each));
            }
        }
        if (numbers.size() < 2) {
            cout << "\033[91mChatbot: Error - Could not find two valid numbers in the input.\033[0m\n";
            continue;
        }

        string operation;
        for (const auto& w : words) {
            if (ranges::find(additions, w) != additions.end())
            {
                operation = "Addition";
            }
            else if (ranges::find(subtractions, w) != subtractions.end()) {
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

        // Early validation for division by zero
        if (operation == "Division") {
            bool zeroDivisorFound = false;
            for (auto & each : words) {
                if (isValidNumber(each)) {
                    if (int num = stoi(each); num == 0) {
                        zeroDivisorFound = true;
                        break;
                    }
                }
            }
            if (zeroDivisorFound) {
                cout << "\033[91mChatbot: Error - Division by zero.\033[0m\n";
                continue; // Skip further calculations for division by zero
            }
        }

        double result = 0;
        if (operation == "Addition") {
            result = accumulate(numbers.begin(), numbers.end(), 0);
        } else if (operation == "Subtraction") {
            result = numbers[0];
            for (size_t i = 1; i < numbers.size(); ++i) {
                result -= numbers[i];
            }
        } else if (operation == "Multiplication") {
            result = 1;
            for (int num : numbers) {
                result *= num;
            }
        } else if (operation == "Division") {
            result = numbers[0];
            for (size_t i = 1; i < numbers.size(); ++i) {
                result /= numbers[i];
            }
        } else {
            cout << "\033[91mChatbot: Sorry, I didn't understand the operation.\033[0m\n";
            continue;
        }

        // Simulate a 1-second delay before showing the result (but no delay for "Chatbot:" label)
        this_thread::sleep_for(chrono::seconds(1));

        // Check if the result is an integer or a floating-point number
        stringstream resultMessage;
        resultMessage << fixed;

        // If result is an integer, avoid showing decimal places
        if (result == static_cast<int>(result)) {
            resultMessage << "\033[93mChatbot: The result of " << operation << " is: \033[32m"
                          << static_cast<int>(result) << "\033[0m\n";
        } else {
            resultMessage << "\033[93mChatbot: The result of " << operation << " is: \033[32m"
                          << setprecision(2) << result << "\033[0m\n";
        }

        // Print the result with typing animation (simulate the typing effect)
        simulateTypingAnimation(resultMessage.str());  // Display result with typing animation
    }
}

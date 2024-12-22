#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <cctype>
#include <random>
#include <thread>
#include <chrono>
// Use the standard namespace
using namespace std;

// Function Declarations (Prototypes)
string cleanString(string input);
void printAnswer(int randomChoice, const string& firstAnswer, const string& secondAnswer);
void loadQuestions(array<string, 5>& questions);
void loadAnswers(array<pair<string, string>, 5>& answers);
void simulateTypingAnimation(const string& text);

// Main function
void generalDiscussion() {
    random_device rd;
    mt19937 gen(rd());
    int minRange = 0, maxRange = 1;
    uniform_int_distribution dis(minRange, maxRange);

    // Array of questions
    array<string, 5> questions;
    // Array of answers (pairs of answers for each question)
    array<pair<string, string>, 5> answers;

    // Load questions and answers
    loadQuestions(questions);
    loadAnswers(answers);

    string userInput;

    simulateTypingAnimation("\033[93mChatbot: Hello! Type \033[34m'bye'\033[0m to exit.\n");

    while (true) {
        cout << "You: ";
        getline(cin, userInput);

        // Exit condition if the user types 'bye'
        if (userInput == "bye") {
            simulateTypingAnimation("\033[93mChatbot: Goodbye!\033[0m\n");
            break;
        }

        // Clean the user input
        string cleanedInput = cleanString(userInput);
        bool questionFound = false;

        // Process the input against questions
        for (int i = 0; i < questions.size(); ++i) {
            // Clean the question
            string cleanedQuestion = cleanString(questions[i]);
            // If the cleaned user input matches a cleaned question
            if (cleanedInput == cleanedQuestion) {
                // Generate a random number between minRange and maxRange
                const int randomChoice = dis(gen);

                // Use switch to print the answer based on random choice
                printAnswer(randomChoice, answers[i].first, answers[i].second);

                questionFound = true;
                break;
            }
        }

        // If no match found, the chatbot doesn't understand
        if (!questionFound) {
            simulateTypingAnimation("Chatbot: Sorry, I don't understand that question. Try asking something like 'What is your name?' or 'How are you?'\n");
        }
    }
}

// Function to simulate random typing delay for each character
void simulateTypingAnimation(const string& text) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(50, 70); // Random delay between 50ms to 70ms

    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(dis(gen)));
    }
}

// Function to clean and format the input: make it lowercase and remove punctuation
string cleanString(string input) {
    // Convert to lowercase
    transform(input.begin(), input.end(), input.begin(), ::tolower);

    // Remove punctuation (including '?' and '!')
    input.erase(remove_if(input.begin(), input.end(), ::ispunct), input.end());

    return input;
}

// Function to print a random answer based on a random number (Yellow colored text)
void printAnswer(const int randomChoice, const string& firstAnswer, const string& secondAnswer) {
    // ANSI escape code for yellow color
    const string yellow = "\033[93m";  // Yellow
    const string reset = "\033[0m";    // Reset to default color

    switch (randomChoice) {
        case 0:
            simulateTypingAnimation(yellow + firstAnswer + reset + "\n");
            break;
        case 1:
            simulateTypingAnimation(yellow + secondAnswer + reset + "\n");
            break;
        default:
            simulateTypingAnimation("Chatbot: Sorry, an error occurred.\n");
    }
}

// Function to load predefined questions into the questions array
void loadQuestions(array<string, 5>& questions) {
    questions = {
        "How are you?",
        "What is your name?",
        "Where do you live?",
        "What do you do?",
        "How old are you?"
    };
}
// Function to load predefined answers into the answers array
void loadAnswers(array<pair<string, string>, 5>& answers) {
    answers = {{
        {"I am doing well, thank you!", "I'm good, how about you?"},
        {"I'm Chatbot!", "My name is ChatGPT."},
        {"I live in the cloud!", "I exist in the digital space."},
        {"I am here to help you!", "I assist with your questions."},
        {"I don't age, I'm timeless!", "I am a machine, I have no age."}
    }};
}

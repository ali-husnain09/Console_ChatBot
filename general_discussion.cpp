#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <cctype>
#include <random>
// Use the standard namespace
using namespace std;

// Function Declarations (Prototypes)
string cleanString(string input);
void printAnswer(int randomChoice, const string& firstAnswer, const string& secondAnswer);
void loadQuestions(array<string, 5>& questions);
void loadAnswers(array<pair<string, string>, 5>& answers);

// Main function
void generalDiscussion() {
    // srand(time(nullptr)); // Seed for random number generation
    // Create a random device and a random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution dis(0, 1);

    // Load the first answer and second answer for the first question

    // Array of questions
    array<string, 5> questions;
    // Array of answers (pairs of answers for each question)
    array<pair<string, string>, 5> answers;

    // Load questions and answers
    loadQuestions(questions);
    loadAnswers(answers);

    string userInput;

    cout << "\033[93mChatbot: Hello! Type \033[34m'bye'\033[0m to exit.\n";

    // Start the conversation loop
    do {
        cout << "You: ";
        getline(cin, userInput);

        // Exit condition if the user types 'bye'
        if (userInput == "bye") {
            cout << "\033[93mChatbot: Goodbye!\033[0m" << endl;
            break;
        }

        bool questionFound = false;

        // Clean the user input
        string cleanedInput = cleanString(userInput);

        // Loop through the questions to find a match
        for (int i = 0; i < questions.size(); ++i) {
            // Clean the question
            string cleanedQuestion = cleanString(questions[i]);
            // If the cleaned user input matches a cleaned question
            if ( cleanedInput == cleanedQuestion) {
                // Generate a random number between 0 and 1
                // const int randomChoice = rand() % 2;
                const int randomChoice = dis(gen);

                // Use switch to print the answer based on random choice
                printAnswer(randomChoice, answers[i].first, answers[i].second);

                questionFound = true;
                break;
            }
        }

        // If no match found, the chatbot doesn't understand
        if (!questionFound) {
            cout << "Chatbot: Sorry, I don't understand that question." << endl;
        }

    } while (userInput != "bye");  // Keep the chatbot running until 'bye' is entered

}
// Function to clean and format the input: make it lowercase and remove punctuation
string cleanString(string input) {
    // Convert to lowercase
    ranges::transform(input, input.begin(), ::tolower);

    // Remove punctuation (including '?' and '!')
    erase_if(input, ::ispunct);

    return input;
}

// Function to print a random answer based on a random number (Yellow colored text)
void printAnswer(const int randomChoice, const string& firstAnswer, const string& secondAnswer) {
    // ANSI escape code for yellow color
    const string yellow = "\033[93m";  // Yellow
    const string reset = "\033[0m";    // Reset to default color

    switch (randomChoice) {
        case 0:
            cout <<  "Chatbot: " << yellow << firstAnswer  << reset << endl;
            break;
        case 1:
            cout <<  "Chatbot: " << yellow << secondAnswer << reset << endl;
            break;
        default:
            cout << "Chatbot: Sorry, I don't understand." << endl;
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

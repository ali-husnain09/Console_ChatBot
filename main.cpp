#include <limits>
#include <iostream>
#include <string>
#include "mathematical.h"
#include "general_discussion.h"

using namespace std;

// Function prototypes
void displayFigletFont(); // Displays the chatbot's figlet-style banner with design and version details
void displayMenu(); // Shows the main menu options to the user
int getUserChoice(); // Handles user input for selecting menu options
void handleUserChoice(const int choice, bool& exitProgram); // Processes the user's choice and navigates accordingly

// Main function
// This function initializes the chatbot by displaying the menu and handling user input.
// The program runs in a loop until the user chooses to exit.
int main() {
    bool exitProgram = false; // Flag to control the main loop
    while (!exitProgram) {
        displayMenu(); // Display the main menu
        const int choice = getUserChoice(); // Get user's choice
        handleUserChoice(choice, exitProgram); // Handle the user's choice
    }
    return 0;
}

// Function definitions

// Displays the chatbot's banner in a visually appealing figlet font style
void displayFigletFont() {
    cout << "\033[93m"; // yellow text
    cout << R"(

			 ██████╗██╗  ██╗ █████╗ ████████╗██████╗  ██████╗ ████████╗     █████╗ ██████╗ ██████╗
			██╔════╝██║  ██║██╔══██╗╚══██╔══╝██╔══██╗██╔═══██╗╚══██╔══╝    ██╔══██╗██╔══██╗██╔══██╗
			██║     ███████║███████║   ██║   ██████╔╝██║   ██║   ██║       ███████║██████╔╝██████╔╝
			██║     ██╔══██║██╔══██║   ██║   ██╔══██╗██║   ██║   ██║       ██╔══██║██╔═══╝ ██╔═══╝
			╚██████╗██║  ██║██║  ██║   ██║   ██████╔╝╚██████╔╝   ██║       ██║  ██║██║     ██║
			 ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═════╝  ╚═════╝    ╚═╝       ╚═╝  ╚═╝╚═╝     ╚═╝
    )" << endl;
    cout << "\033[0m";
    cout << "\t\t\t\t\t\t\t\t\033[94m[Design][Code] by [TRueKoders]\033[0m" << endl;
    cout << "\t\t\t\t\t\t\t\t[Version 2.0]" << endl;
    cout << "\033[92m[TEAM MEMBERS]\033[0m\n";
    cout << "\t\t\t[1] ALI HUSNAIN (SOFTWARE ENGINEER)\n";
    cout << "\t\t\t[2] ANSHRAH NADEEM (SOFTWARE ENGINEER)\n";
    cout << "\t\t\t[---------------------------------------------------------------------------------------------]\n";
    cout << "\033[91m\t\t\t[Disclaimer]: A simple chatbot that provides mathematical operations and general discussions.\033[0m\n";
}

// Displays the main menu options for the chatbot
void displayMenu() {
    cout << "\n\t\t\t\033[93mWelcome to the Chatbot!\033[0m\n";
    displayFigletFont(); // Show the banner
    cout << "\nPlease choose a topic: \n";
    cout << "1. \033[94mMathematical operations\033[0m\n";
    cout << "2. \033[92mGeneral discussion\033[0m\n";
    cout << "3. \033[91mExit\033[0m\n";
    cout << "\033[93mEnter your choice: \033[0m";
}

// Prompts the user to select a menu option and validates the input
int getUserChoice() {
    int choice;
    while (true) {
        cin >> choice;
        if (cin.fail() || (choice < 1 || (choice > 3 && choice != 0))) {
            cin.clear(); // Clear error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "\033[91mInvalid input. Please enter a valid choice (1-3, or 0 to return to the main menu): \033[0m";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            break; // Exit loop if input is valid
        }
    }
    return choice;
}

// Handles the user's selected menu option and navigates accordingly
void handleUserChoice(const int choice, bool& exitProgram) {
    switch (choice) {
    case 1:
        mathematicalOperations(); // Navigate to mathematical operations
        break;
    case 2:
        generalDiscussion(); // Navigate to general discussion
        break;
    case 3:
        cout << "\n\t\t\t\t\033[93mChatbot:\033[0m ";
        this_thread::sleep_for(chrono::milliseconds(500)); // Brief delay
        cout << "Goodbye!\n";
        this_thread::sleep_for(chrono::milliseconds(500)); // Brief delay
        exitProgram = true; // Exit the main loop
        break;
    case 0:
        cout << "\033[93mReturning to the main menu...\033[0m\n"; // Return to menu
        break;
    default:
        cout << "\033[91mUnexpected error.\033[0m\n"; // Handle unexpected errors
        break;
    }
}

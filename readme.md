# Chatbot App

![Chatbot Banner](./assets/chatbot_banner.png)  
*An engaging and interactive chatbot that combines mathematical operations and general discussions.*

---

## Project Description

The **Chatbot App** is a user-friendly, console-based chatbot designed for educational and functional purposes. The app offers:

- **Mathematical Operations**: Solve mathematical queries and perform computations seamlessly.
- **General Discussions**: Engage in simple, casual conversations.

This chatbot was developed with a clean, interactive interface and color-coded options for better usability. The project demonstrates an effective implementation of C++ programming principles, modular design, and cross-platform compatibility.

---

## Features

1. **Interactive Menu**:
   - A visually appealing ANSI Shadow title font.
   - Color-coded topics for better readability.
2. **Mathematical Module**:
   - Perform basic mathematical operations.
   - Accept unlimited queries in a single session.
3. **General Discussion Module**:
   - Respond to user input dynamically.
   - Offer casual and informative responses.
4. **Cross-Platform Support**:
   - Compatible with both Linux and Windows.
5. **Looped Sessions**:
   - Continuous interaction until the user exits.
6. **Error Handling**:
   - Handles invalid inputs with user-friendly prompts.

---

## Use Cases

1. **Educational Tools**: Help students practice basic programming concepts.
2. **Demonstration Projects**: Showcase modular and object-oriented programming.
3. **Interactive Learning**: Provide an engaging way to learn coding fundamentals.

---

## Tech Stack

- **Programming Language**: C++
- **Libraries Used**: Standard Template Library (STL)
- **Font Design**: Figlet (ANSI Shadow)
- **OS Compatibility**:
  - Linux
  - Windows (using OS-specific instructions)

---

## Project Structure

```plaintext
Chatbot_App/
├── main.cpp                # Main file for the chatbot
├── mathematical.cpp        # Handles mathematical operations
├── general_discussion.cpp  # Manages general discussion functionality
├── assets/
│   └── chatbot_banner.png  # Banner image for GitHub
└── README.md               # Project documentation
```

---

## Installation and Usage

### Prerequisites

- **Linux**: Ensure `figlet` is installed for ANSI Shadow font rendering.
- **Windows**: Follow the steps to integrate Figlet functionality manually.

### Steps

1. Clone the repository:
   ```bash
   git clone https://github.com/ali-husnain09/Console_ChatBot.git
   ```
2. Navigate to the project directory:
   ```bash
   cd Console_ChatBot
   ```
3. Compile the program:
   ```bash
   g++ main.cpp mathematical.cpp general_discussion.cpp -o chatbot
   ```
4. Run the program:
   ```bash
   ./chatbot
   ```

### For Windows Users

1. Download Figlet for Windows.
2. Add the Figlet binary to your system's PATH.
3. Modify the font-rendering function in `main.cpp` as per Figlet Windows integration.

---

## Screenshots

![Chatbot Interface](./assets/chatbot_screenshot.png)  
*Figure: Interactive chatbot menu with ANSI Shadow font.*

---

## Team Members

- **Ali Husnain** (Software Engineer)
- **Anshrah Nadeem** (Software Engineer)

---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## Future Enhancements

- **GUI Integration**: Convert the console app into a graphical application.
- **Advanced AI**: Add natural language processing capabilities.
- **Extended Mathematical Support**: Introduce complex mathematical operations.

---

## Acknowledgments

- **Figlet**: For the amazing text-rendering fonts.
- **C++ Community**: For extensive resources and support.


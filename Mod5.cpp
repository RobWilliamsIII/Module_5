/*
 * Mod5.cpp
 *
 *  Created on: Aug 15, 2024
 *      Author: robwilliams
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// Function to add inputed text to CSC450_CT5_mod5.txt
void addToFile(const std::string& filename, const std::string& userInput) {
    std::ofstream outFile;
    outFile.open(filename, std::ios::app);
        outFile << userInput << std::endl;
        outFile.close();

}

// reverse the text of CSC450_CT5_mod5.txt and store it in CSC450-mod5-reverse.txt
void reverseText(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);
        std::string fileContents((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());

        // Reverse the text
        std::reverse(fileContents.begin(), fileContents.end());

        // Write the reversed text to CSC450-mod5-reverse.txt
        outFile << fileContents;

        inFile.close();
        outFile.close();
}

int main() {
    std::string userText;
    std::string addFile = "CSC450_CT5_mod5.txt";
    std::string reverseFile = "CSC450-mod5-reverse.txt";

    // Get user input
    std::cout << "Enter text to add to CSC450_CT5_mod5.txt: ";
    std::getline(std::cin, userText);

    // Add user input to the text CSC450_CT5_mod5.txt
    addToFile(addFile, userText);

    // Reverse the text of the file and save it to CSC450-mod5-reverse.txt
    reverseText(addFile, reverseFile);

    std::cout << "Your text: " << userText << "\nwas added to: " << addFile << "\nand the reversed text was created in: " << reverseFile << "." << std::endl;

    return 0;
}

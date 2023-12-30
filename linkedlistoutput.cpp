#include <iostream>
#include <fstream>
#include <unordered_map>
#include <list>

struct Node {
    char character;
    Node* next;
    Node(char ch) : character(ch), next(nullptr) {}
};

int main() {

    // Open the input file
    std::ifstream inputFile("input.txt"); // This is where the input file is placed you might be able to turn it into a place where a prompt to input into this file here

    if (!inputFile.is_open()) { // here in the space where the input file should be is what might cause an error
        std::cerr << "Error opening the input file." << std::endl;
        return 1;
    }

    // Open the output file for the linked list
    std::ofstream outputListFile("output_list.txt");

    if (!outputListFile.is_open()) {
        std::cerr << "Error opening the output file for the linked list." << std::endl;
        inputFile.close();  // Close the input file
        return 1;
    }

    // Initialize variables
    char ch;
    int num;
    std::unordered_map<int, int> countMap;
    std::list<Node*> linkedList;

    // Read characters from the input file
    while (inputFile.get(ch)) {
        if (isdigit(ch)) {
            // Convert the character to an integer
            num = ch - '0';

            // Display the array number
            std::cout << "Array[" << num << "] ";

            // Count the occurrences
            countMap[num]++;
        } else if (isalpha(ch)) {
            // Display the character
            std::cout << ch << " ";

            // Add character to the linked list
            linkedList.push_back(new Node(ch));
        } else if (ch == '\n') {
            // Move to a new line
            std::cout << "\n";
        }
    }

    // Close the input file
    inputFile.close();

    // Display the count of each integer
    std::cout << "\nInteger Counts:\n";
    for (const auto& entry : countMap) {
        std::cout << "Array[" << entry.first << "]: " << entry.second << "\n";
    }

    // Display the characters in the linked list and write to the output file
    std::cout << "\nLinked List Characters:\n";
    for (Node* node : linkedList) {
        std::cout << node->character << " ";
        outputListFile << node->character << " ";
        delete node;  // Clean up allocated nodes
    }

    // Close the output file for the linked list
    outputListFile.close();

    return 0;
}

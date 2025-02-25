#include <string>
#include <iostream>
#include <fstream>    
#include <regex>

// Given a string line
// Finds every instance of mul(3-digit num, 3-digit num) and
// returns the sum of the the product of all those pairs of 3-digit numbers
int findMul(std::string line){
    std::regex pattern("mul\\(\\d{1,3},\\d{1,3}\\)");
    std::smatch matches;
    int ans = 0;
    while(std::regex_search(line, matches, pattern)){
        size_t posComma = matches.str().find(",");
        int input1 = std::stoi((matches.str().substr(4, posComma - 4)));
        int input2 = std::stoi(matches.str().substr(posComma + 1, matches.str().find(")") - posComma - 1));
        ans += input1 * input2;
        line = matches.suffix();
    }
    return ans;
}


std::string removeContent(const std::string& input, 
                         const std::string& a, 
                         const std::string& b) {
    std::string result = input;
    size_t startPos = 0;
    
    while ((startPos = result.find(a, startPos)) != std::string::npos) {
        size_t endPos = result.find(b, startPos + a.length());
        if (endPos != std::string::npos) {
            // Remove from A to B (including A and B)
            size_t len = endPos - startPos + b.length();
            result.erase(startPos, len);
            // Don't update startPos - continue searching from same position
        } else {
            // Remove from A to end (including A)
            result.erase(startPos);
            break;  // Nothing more to process
        }
    }
    
    return result;
}

int main(){

    std::ifstream input("input.txt");      
    std::string line; 
    int total = 0;
    while(std::getline(input, line)){
        std::string editedLine = removeContent(line, "don't()", "do()");
        if(editedLine.find("don't()") != std::string::npos){
            std::cout << editedLine.find("don't()") << "\n";
            std::cout << editedLine << "\n";
        }
        if(editedLine.find("do())") != std::string::npos){
            std::cout << editedLine.find("do()") << "\n";
            std::cout << editedLine << "\n";
        }
        total += findMul(editedLine);
        // while(std::regex_search(line, matches, pattern)){
        //     size_t posComma = matches.str().find(",");
        //     int input1 = std::stoi((matches.str().substr(4, posComma - 4)));
        //     int input2 = std::stoi(matches.str().substr(posComma + 1, matches.str().find(")") - posComma - 1));
        //     total += input1 * input2;
        //     line = matches.suffix();
        // }
    }
    std::cout << total << "\n";
    return 0;
}
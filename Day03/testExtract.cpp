#include <vector>
#include <iostream>
#include <string>
#include <fstream>


// std::vector<std::string> extractBetween(const std::string& input, const std::string& a = "do()", const std::string& b = "don't()") {

//     std::vector<std::string> results;
//     size_t posA = 0;
//     size_t posB = 0;
//     size_t start = 0;
//     size_t end = 0;
//     while (input.find(b, posB) < input.length()) {

//         start = input.find(a, posA);
//         if(start == std::string::npos){
//             results.push_back(input.substr(start, input.size() - end - start - 1))
//         } 
//         start += a.length(); // Move past pattern a
//         posA ++;
//         end = input.find(b, posB);
//         posB ++;
//         results.push_back(input.substr(start, input.size() - end - start - 1));

//     }

//     return results;
// }

// void filterContent(std::string& input, const std::string& a, const std::string& b) {
//     std::string result = input;
//     size_t pos = 0;
//     size_t posA = 0;
//     size_t i = 0;
//     size_t j = 0;

//     while(pos < input.size()){
//         pos = input.find(b, j);
//         std::cout << pos << " pos" << "\n";
//         posA = input.find(a, i);
//         std::cout << posA << " posa" << "\n";
//         if(posA == std::string::npos  && pos == std::string::npos){
//             std::cout << "Both strings not in input\n";
//             break;
//         }
//         if(posA == std::string::npos){
//             std::cout << "A string not in input\n";
//             result.erase(pos, input.size() - pos - 1);
//             break;
//         }
//         if(pos == std::string::npos){
//             std::cout << "B string not in input\n";
//             break;
//         }
//         else{
//             while(pos < posA){
//                 i++;
//                 posA = input.find(a, i);
//                 if(posA == std::string::npos){
//                     result.erase(pos, input.size() - pos - 1);
//                     break;
//                 }
//             }
//             result.erase(pos, posA - pos);
//             std::cout << "Both Strings in input pos: " << pos << ", posA: " << posA << "\n";
//             i++;
//             j++;

//         }
//     }
// }

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

int main() {

    std::ifstream input("testInput.txt");
    std::string line;
    std::string testStr = "hello hello there hello";
    while(std::getline(input, line)){
        std::string ans = removeContent(line, "don't()", "do()");
        std::cout << ans << "\n";
        std::cout << line << "\n";

    }

    return 0;
}
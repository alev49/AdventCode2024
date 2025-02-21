#include <fstream>
#include <vector>
#include <string>
#include <iostream>


// Given a string of integers seperated by spaces
// Returns a vector of those integers
std::vector<int> stringToVec(std::string input){
    size_t prev = 0;
    size_t pos = input.find(" ");
    std:: vector<int> ans;
    while(pos != std::string::npos){
        ans.push_back(std::stoi(input.substr(prev, pos - prev)));
        prev = pos + 1;
        pos = input.find(" ", prev);
    }
    ans.push_back(std::stoi(input.substr(prev, input.size())));
    return ans;
}

// Given a vector of ints of at least 2
// Returns true if the numbers are in increasing or decreasing order
// and any two adjacent numbers differ between 1 and 3
bool isSafe(std::vector<int>& nums){
    if (nums.size() <= 2) return true;
    
    bool inc = true;
    bool dec = true;

    for (size_t i = 1; i < nums.size(); i++){
        if (nums[i] > nums[i-1]) dec = false;
        if (nums[i] < nums[i-1]) inc = false;
        if (std::abs(nums[i] - nums[i-1]) < 1 || std::abs(nums[i] - nums[i-1]) > 3) return false;
        if (!inc && !dec) return false;   
    }
    return true;

}

int main() {

    // Reading in the file input
    std::ifstream input("input.txt");
    std::string line;
    size_t safeCount = 0;
    while (std::getline(input, line)) {
        std::vector<int> nums = stringToVec(line);
        if (isSafe(nums)) safeCount++;

    }

    std::cout << safeCount << "\n";
}
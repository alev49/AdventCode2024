#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void calcTotalDiff(vector<int>& left, vector<int>& right){
    // Calculate total absoloute difference between the lists
    // Assumes both left and right size are the same
    int totalDiff = 0;
    for (int i = 0; i < left.size(); i++){
        totalDiff += abs(left.at(i) - right.at(i)); 
    }
    cout << "Total Absoloute Difference: " << totalDiff << "\n";
}

void calcSimilarityScore(vector<int>& left, vector<int> right){
    int totalScore = 0;
    for (int i = 0; i < left.size(); i++){
        totalScore += count(left.begin(), left.end(), right.at(i))*right.at(i);
    }

    cout << "Similarity Score: " << totalScore << "\n";

}

int main() {

    // Reading in the file input
    ifstream input("input.txt");
    string line;
    vector<int> left;
    vector<int> right;
    while (getline(input, line)) {
        int space = line.find("   ");
        left.push_back(stoi(line.substr(0,space)));
        right.push_back(stoi(line.substr(space+3, line.size())));
    }
    // Sorting each list in increasing order
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    calcTotalDiff(left, right);
    calcSimilarityScore(left, right);

    return 0;
}


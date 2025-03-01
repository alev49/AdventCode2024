#include <iostream>
#include <vector>

//Just testing some functions

void printDiagonal(const std::vector<std::vector<char>>& matrix, const size_t& size) {
    if (size > matrix.size() || size > matrix[0].size()){
        std::cerr << "printDiagonal: size parameter too large\n";
        return;
    }
    int rows = matrix.size();
    if (rows == 0) return; // Handle empty matrix
    int cols = matrix[0].size();

    // Loop through each diagonal starting from the first row
    for (int col = size-1; col < cols; col++) {
        int start_col = col;
        int start_row = 0;
        while (start_col >= 0 && start_row < rows) {
            std::cout << matrix[start_row][start_col] << " ";
            start_col--;
            start_row++;
        }
        std::cout << std::endl; // New line after each diagonal
    }

    // Loop through each diagonal starting from the first column (excluding the first element)
    for (int row = 1; row <= rows - size; row++) {
        int start_col = cols - 1;
        int start_row = row;
        while (start_row < rows && start_col >= 0) {
            std::cout << matrix[start_row][start_col] << " ";
            start_col--;
            start_row++;
        }
        std::cout << std::endl; // New line after each diagonal
    }

    std::cout << std::endl;

    for (int start_row = rows - size; start_row >= 0; start_row--) {
        int row = start_row;
        int col = 0;
        while (row < rows && col < cols) {
            std::cout << matrix[row][col] << " ";
            row++;
            col++;
        }
        std::cout << std::endl; // New line after each diagonal
    }

    // Loop through each diagonal starting from the first row (excluding the last element)
    for (int start_col = 1; start_col <= cols - size; start_col++) {
        int row = 0;
        int col = start_col;
        while (row < rows && col < cols) {
            std::cout << matrix[row][col] << " ";
            row++;
            col++;
        }
        std::cout << std::endl;
    }
}


std::string reverseString(std::string& input){
    size_t midPoint = (input.length())/2;
    char temp;
    std::string ans = input;
    for(size_t i = 0; i < midPoint; i++){
        temp = ans[ans.length() - i - 1];
        ans[ans.length() - i - 1] = ans[i];
        ans[i] = temp;
    }
    return ans;
}

size_t countOccurences(const std::string& input,  const std::string& pattern){
    size_t pos = 0;
    if (pos == std::string::npos){
        return 0;
    }
    size_t count = 0;
    while (pos != std::string::npos) {
        count++;
        std::cout << input.substr(pos) << std::endl;
        pos = input.find(pattern, pos + pattern.size());
    }
    return count;

}




int main() {

    std::vector<std::vector<char>> test = {{'t', 'h', 'i', 'a'},
                                          {'s', 'I', 'S', 'b'},
                                          {'B', 'r', 'o', '9'},
                                          {'j', 'n', 'm', '5'}};

    // printDiagonal(test, 2);
    std::string teString = "hellohellotherehellowhywhohello";
    std::string teString2 = "xhellotherehellowhywhohello";
    std::cout << countOccurences(teString, "hello") << std::endl;
    std::cout << countOccurences(teString2, "hello") << std::endl;
    return 0;
}
#include <iostream>
#include <fstream>


/// @param fileName 
/// The name of the file
/// @return 
/// One long string of all the file contents, omits newline characters
/// If fileName does not exist or can't be reached, returns a NULL string
std::string readInFile(const std::string& fileName){
    std::fstream file(fileName);
    std::string line;
    if (!file.is_open()) {
        std::cerr << "Error opening the file.\n";
        return NULL;
    }
    std::string ans;
    while(getline(file, line)){
        ans += line;
    }
    return ans;
}




// Given a string input that 
//  - Has size that is squarable i.e. 4,9 16 etc
// return a char matrix that is sqrt(input.size()) by sqrt(input.size())
// Ex: input = "thisIsBro"
// returns {{"t", "h", "i"},
//          {"s", "I", "s"},
//          {"B", "r", "o"}}
std::vector<std::vector<char>> getStringMatrix(const std::string& input){
    size_t size = input.size();
    if(size == 0 || std::floor(std::sqrt(size)) != std::sqrt(size)){
        std::cerr << " getStringMatrix: input string not correct size" << "\n";
        return {};
    }
    size = std::sqrt(size);
    std::vector<std::vector<char>> ans;
    std::vector<char> temp;  
    for (size_t i = 0; i < size; i++){
        temp.clear();
        for (size_t j = 0; j < size; j++){
            temp.push_back(input.at(i*size+j));
        }
        ans.push_back(temp);
    }
   return ans; 
}

/// @brief 
/// Changes the input parameter string by reversing it
/// @param input 
/// Any string input
/// @return 
/// Returns reversed string input
std::string reverseString(const std::string& input){
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

/// @param input 
/// ipnut is a n length char vector
/// @return 
/// Returns n length string where each char is combined into one string
std::string vecCharToStr(const std::vector<char>& input){
    if(input.size() == 0){
        return "";
    }
    std::string ans;
    ans.reserve(input.size());
    for(size_t i = 0; i < input.size(); i++){
        ans += input[i];
    }
    return ans;

}

/// @param input 
/// input is any string of size n
/// @param pattern 
/// pattern is any other string if size <=n
/// @return 
/// returns the number of occurences pattern is found within input
size_t countOccurences(const std::string& input,  const std::string& pattern){
    size_t pos = input.find(pattern);
    if(pos == std::string::npos){
        return 0;
    }
    size_t count = 0;
    while (pos != std::string::npos) {
        count++;
        pos = input.find(pattern, pos + pattern.size());
    }
    return count;

}

/// @param matrix 
/// A char 2d  matrix of row rows and columns cols
/// @param size 
/// The size of the min length of the string c
/// @return 
/// Returns string vector of the the diagonals from top left to bottom right and from bottom left to top right
/// whose size are at least size size
/// Returns empty vector if size is greater than row or column or if the matrix is size 0
std::vector<std::string> getDiagonal(const std::vector<std::vector<char>>& matrix, const size_t& size) {
    int rows = matrix.size();
    if (rows == 0){
        std::cerr << __func__ << ": matrix parameter is has size 0";
        return {};
    }  
    int cols = matrix[0].size();
    if (size > rows || size > cols){
        std::cerr << __func__ << ": size parameter is too large\n";
        return {};
    }

    std::vector<std::string> ans; 
    for (int col = size-1; col < cols; col++) {
        int start_col = col;
        int start_row = 0;
        std::vector<char> temp;
        while (start_col >= 0 && start_row < rows) {
            temp.push_back(matrix[start_row][start_col]);
            start_col--;
            start_row++;
        }
        ans.push_back(vecCharToStr(temp));
    }

    for (int row = 1; row <= rows - size; row++) {
        int start_col = cols - 1;
        int start_row = row;
        std::vector<char> temp;
        while (start_row < rows && start_col >= 0) {
            temp.push_back(matrix[start_row][start_col]);
            start_col--;
            start_row++;
        }
        ans.push_back(vecCharToStr(temp));
    }


    for (int start_row = rows - size; start_row >= 0; start_row--) {
        int row = start_row;
        int col = 0;
        std::vector<char> temp;
        while (row < rows && col < cols) {
            temp.push_back(matrix[row][col]);
            row++;
            col++;
        }
        ans.push_back(vecCharToStr(temp));
    }

    for (int start_col = 1; start_col <= cols - size; start_col++) {
        int row = 0;
        int col = start_col;
        std::vector<char> temp;
        while (row < rows && col < cols) {
            temp.push_back(matrix[row][col]);
            row++;
            col++;
        }
        ans.push_back(vecCharToStr(temp));
    }


    return ans;
}

/// @param matrix 
/// A 2d char matrix of rows r and columns c
/// @return 
/// A string vector of r rows from matrix
/// Returns empty vector if matrix has 0 rows
std::vector<std::string> getHorizontal(const std::vector<std::vector<char>>& matrix) {
    
    if (matrix.size() <= 0){
        return {};
    }

    std::vector<std::string> ans;
    for (std::vector<char> row : matrix){
        ans.push_back(vecCharToStr(row));
    }
    return ans;
}

/// @param matrix 
/// A 2d char matrix of rows r and columns c
/// @return 
/// A string vector of the c columns from matrix
/// Returns empty vector if matrix is empty
std::vector<std::string> getVertical(const std::vector<std::vector<char>>& matrix) {
    
    if (matrix.size() <= 0){
        return {};
    }

    std::vector<std::string> ans;
    for (size_t i = 0; i < matrix.size(); i++){
        std::string temp;
        for( size_t j = 0; j < matrix.at(i).size(); j++){
            temp += matrix.at(j).at(i);
        }
        ans.push_back(temp);
    }
    return ans;
}

/// @param input 
/// input is a 2d square matrix of chars
/// @param pattern 
/// a string pattern whose length is smaller than input's rows
/// @return 
/// Returns the count of how many times the pattern appears horizontally, vertically 
/// diagonally both forwards and backwards
/// Returns -1 if input is not square matrix or pattern size is not smaller than input rows
int countMatrixOccurences(const std::vector<std::vector<char>>& input, const std::string pattern){
    if (pattern.size() > input.size() || input.size() != input.at(0).size()){
        return -1;
    }
    size_t count = 0;
    std::string revString = reverseString(pattern);
    for(std::string stwing : getDiagonal(input, pattern.size())){
        count+= countOccurences(stwing, pattern);
        count+= countOccurences(stwing, revString);
    }
    size_t diag = count;
    std::cout << "Diagonals: " << diag << std::endl;

    for(std::string stwing : getHorizontal(input)){
        count+= countOccurences(stwing, pattern);
        count+= countOccurences(stwing, revString);
    }
    size_t horiz = count - diag;
    std::cout << "Horizontals: " << horiz << std::endl;

    for(std::string stwing : getVertical(input)){
        count+= countOccurences(stwing, pattern);
        count+= countOccurences(stwing, revString);
    }
    std::cout << "Verticals: " << count - horiz - diag << std::endl;

    return count;
}



int main() {

    std::string inputFile = "input.txt";
    std::string input = readInFile(inputFile);
    std::vector<std::vector<char>> matrix = getStringMatrix(input);
    std::string pattern = "XMAS";
    std::cout << countMatrixOccurences(matrix, pattern) << std::endl;
    // std::string firstRow = vecCharToStr(matrix.at(69));
    // std::cout << firstRow << std::endl;
    // std::cout << countOccurences(firstRow, (pattern)) << std::endl;

    return 0;
}
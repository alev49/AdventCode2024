#include <iostream>
#include <string>


bool isSafe(std::vector<int>& nums){
    int diff = nums.at(1) - nums.at(0);
    if (std::abs(nums.at(1) - nums.at(0)) < 1 || std::abs(nums.at(1) - nums.at(0)) > 3){
        std::cout << "Not spaced right" <<  0 << "\n";
        return false;
    }
    for(int i = 1; i < nums.size()-1; i++){
        if(!(((nums.at(i+1) - nums.at(i+1)) >=0) == (diff >=0))){
            std::cout << "Not ordered right " << i  << "\n";
            return false;
        }
        if(std::abs(nums.at(i) - nums.at(i+1)) < 1 || std::abs(nums.at(i) - nums.at(i+1)) > 3){
            std::cout << "Not spaced right " << i  << "\n";
            return false;
        }
    }
    return true;

}

int main() {
    std::string str = "Hello World I am a test sentence";
    
    // Find first occurrence of "World"
    size_t prevPos = 0;
    size_t pos = str.find(" ");

    std::vector<int> nums0 = {1,2,5,6,8,12};
    std::vector<int> nums1 = {1,2,5,6,8,10};
    std::vector<int> nums2 = {10,8,4,2};
    std::vector<int> nums3 = {10,8,5,2, 1, -1};
    std::vector<int> nums4 = {1,2,5,6,5,8};

    std::cout << true << "\n";
    std::cout << isSafe(nums0) << " " << 0 << "\n";
    std::cout << isSafe(nums1) << " " << 1 << "\n";
    std::cout << isSafe(nums2) << " " << 2 << "\n";
    std::cout << isSafe(nums3) << " " << 3 << "\n";
    std::cout << isSafe(nums4) << " " << 4 << "\n";

    // while(pos != std::string::npos){
    //     std::cout << prevPos <<  " " << pos << "\n";
    //     std::cout << str.substr(prevPos, pos-prevPos) << "\n";
    //     prevPos = pos+1;
    //     pos = str.find(" ",prevPos+1);
    // } 
    // std::cout << prevPos <<  " " << pos << "\n";
    // std::cout << str.substr(prevPos, str.size()-1) << "\n";
    
    return 0;
}

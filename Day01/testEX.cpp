#include <sstream>
#include <forward_list>
#include <list>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // Input Iterator Example (reading from istream_iterator)
    istringstream iss("1 2 3 4 5");
    istream_iterator<int> input_it(iss);
    istream_iterator<int> input_end;
    cout << "Input Iterator Example: ";
    while (input_it != input_end) {
        cout << *input_it << " ";
        ++input_it;
    }
    cout << endl;

    // Output Iterator Example (writing to ostream_iterator) 
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << "Output Iterator Example: ";
    ostream_iterator<int> output_it(cout, " ");
    copy(nums.begin(), nums.end(), output_it);
    cout << endl;
// 
    //Forward Iterator Example (forward_list)
    forward_list<int> flist = {1, 2, 3, 4, 5};
    cout << "Forward Iterator Example: ";
    for (auto it = flist.begin(); it != flist.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
// 
    // Bidirectional Iterator Example (list)
    list<int> blist = {1, 2, 3, 4, 5};
    cout << "Bidirectional Iterator Example: ";
    for (auto it = blist.begin(); it != blist.end(); ++it) {
        cout << *it << " ";
    }
    // Can also go backwards
    for (auto it = blist.rbegin(); it != blist.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
// 
    // Random Access Iterator Example (vector)
    vector<int> vec = {1, 2, 3, 4, 5};
    cout << "Random Access Iterator Example: ";
    auto it = vec.begin();
    cout << it[2] << " "; // Direct access
    it += 2; // Jump multiple positions
    cout << *it << " ";
    it -= 1; // Go backwards multiple positions
    cout << *it << " ";
    cout << endl;
                                                                                                                                        
}

// Now words contains ["hello", "world", "example"]

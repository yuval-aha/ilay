#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int diff(string s) {
    unordered_map<char, int> char_counts;

    for (const auto &c : s) {
        if (char_counts.count(c) == 0) {
            char_counts[c] = 1;
        } else {
            char_counts[c]++;
        }
    }

    return char_counts.size();
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);
    
    int diff_chars = diff(input);
    std::cout << diff_chars << std::endl;

    return 0;
}
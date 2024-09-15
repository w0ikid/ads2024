#include <iostream>
#include <string>

std::string processString(std::string s) {
    std::string result;
    for (char ch : s) {
        if (ch == '#') {
            if (!result.empty()) {
                result.pop_back();
            }
        } else {
            result.push_back(ch);
        }
    }
    return result;
}

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    if (processString(s1) == processString(s2)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}

#include <iostream>
#include <string>

bool isBalanced(std::string s) {
    int n = s.size();

    std::string stack;

    for (int i = 0; i < n; ++i) {
        if (!stack.empty() && s[i] == stack.back()) {
            stack.pop_back();
        } else {
            stack.push_back(s[i]);
        }
    }

    return stack.empty();
}

int main() {
    std::string s;
    std::cin >> s;

    if (isBalanced(s)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}

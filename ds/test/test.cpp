#include <iostream>
#include <stack>

int main(){
    std::stack <int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.push(9);
    std::cout << s.top() << "\n";
}
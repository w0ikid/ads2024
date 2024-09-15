#include <iostream>
#include <deque>

int main(){
    std::deque <int> deq;
    char input;
    while(input != '!'){
        std::cin >> input;
        int num;
        if (input == '+'){
            std::cin >> num;
            deq.push_front(num);
        }
        else if (input == '-'){
            std::cin >> num;
            deq.push_back(num);
        }
        else if (input == '*'){
            if (deq.empty()){
                std::cout << "error" << "\n";
                continue;
            }
            num = deq.front() + deq.back();
            std::cout << num << "\n";
            if (deq.size() > 1){
                deq.pop_front();
                deq.pop_back();     
            }
            else {
                deq.pop_back();
            }
        }
    }
    return 0;
}
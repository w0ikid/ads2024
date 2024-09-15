#include <iostream>
#include <vector>
#include <stack>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for(int i=0; i<N; ++i){
        std::cin >> A[i];
    }
    
    std::stack<int> s;
    std::vector<int> result(N);
    for(int i=0; i<N; ++i){
        // Pop elements from the stack while the top element is greater than the current age
        while(!s.empty() && s.top() > A[i]){
            s.pop();
        }
        if(s.empty()){
            result[i] = -1;
        } else {
            result[i] = s.top();
        }
        s.push(A[i]);
    }
    
    for(int i=0; i<N; ++i){
        std::cout << result[i];
        if(i != N-1) std::cout << " ";
    }
    std::cout << std::endl;
    return 0;
}

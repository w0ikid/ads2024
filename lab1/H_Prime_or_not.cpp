#include <iostream>

bool isPrime(int num){
    if (num < 2){
        return false;
    }
    for (int i = 2; i * i <= num; i++)
    {
        if -{
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    std::cin >> n;

    std::cout << (isPrime(n) ? "YES":"NO");
    return 0;    
}

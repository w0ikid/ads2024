#include <iostream>

bool isPrime(int num){
    if (num < 2){
        return false;
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0){
            return false;
        }
    }
    return true;
}

int primeNth(int n){
    int prime_num = 2;
    int primenth = 0; 
    while (primenth != n)
    {
        if (isPrime(prime_num)){
            primenth++;
        }
        prime_num++;
    }
    return prime_num - 1;
}

int main(){
    int n;
    std::cin >> n;

    std::cout << primeNth(n);
    return 0;    
}


/*
    Prime numbers
    2 3 5 7 11
*/
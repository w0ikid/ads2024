#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string factions;
    cin >> factions;

    queue<int> s_queue, k_queue;

    // Заполнение очередей индексами студентов
    for(int i = 0; i < n; ++i){
        if(factions[i] == 'S') {
            s_queue.push(i);
        }
        else {
            k_queue.push(i);
        }
    }

    // Симуляция процесса исключения
    while(!s_queue.empty() && !k_queue.empty()){
        int s_idx = s_queue.front();
        s_queue.pop();
        int k_idx = k_queue.front();
        k_queue.pop();

        if(s_idx < k_idx){
            // S действует первым и исключает K
            s_queue.push(s_idx + n);
        }
        else{
            // K действует первым и исключает S
            k_queue.push(k_idx + n);
        }
    }

    // Определение победителя
    if(!s_queue.empty()){
        cout << "SAKAYANAGI";
    }
    else{
        cout << "KATSURAGI";
    }

    return 0;
}

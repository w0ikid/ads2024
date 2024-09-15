#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//#include Bismillah!!!!
//WARNING: say Bismillah before working
//shit by mishanya bfg

vector <int> deck_gen (int size){
    deque <int> deck;
    for (int i = size; i >= 1; i--){
        deck.push_front(i);
        
        for(int j = 0; j < i; j++){
                deck.push_front(deck.back());
                deck.pop_back();
            }
        }

    return vector<int>(deck.begin(), deck.end());
}

int main(){
    int n, row; cin >> n;

    while(n--){
        cin >> row;
        for(auto i : deck_gen(row)){
            cout << i << " ";
        }

        cout << "\n";
    }
   
    return 0;
}
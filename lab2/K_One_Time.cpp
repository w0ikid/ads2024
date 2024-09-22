#include <iostream>
#include <queue>
#include <map>
using namespace std;

void process(int size) {
    queue <char> check;
    map <char, int> mp;
    char c;

    for(int i = 0; i < size; i++) {
        cin >> c;
        mp[c]++;
        check.push(c);

        while(!check.empty() && mp[check.front()] > 1) {
            check.pop();
        }

        if(check.empty()) cout << -1;
        else cout << check.front();
        cout << " ";
    }
}

int main() { 
    int n, k; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> k;
        process(k);
        cout << endl;
    }
    return 0;
}
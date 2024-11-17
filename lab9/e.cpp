#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long kmp(string& patt, int n, int k){
    if(patt.size() == 0){
        return 0;
    }
    vector<int> lps(patt.size(), 0);

    //lps implementation
    int prevLPS = 0, i = 1;
    while(i < patt.size()){
        if(patt[i] == patt[prevLPS]){
            lps[i] = prevLPS + 1;
            prevLPS += 1;
            i += 1;
        }
        else if(prevLPS == 0){
            lps[i] = 0;
            i += 1;
        }
        else{
            prevLPS = lps[prevLPS - 1];
        }
    }

    long long size = (n - lps[n - 1]) * (k - 1) + n;
    return size;
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        long long k;
        cin >> k;

        cout << kmp(s, s.size(), k) << endl;
    }
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int kmp(string& text, string& patt){
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

    int i1 = 0; // iterator for text
    int i2 = 0; // iterator for pattern

    while(i1 < text.size()){
        if(text[i1] == patt[i2]){
            i1++;
            i2++;
        }
        else{
            if(i2 == 0){
                i1 += 1;
            }
            else{
                i2 = lps[i2- 1];
            }
        }
        if(i2 == patt.size()){
            return i1 - patt.size();
        }
    }

    return -1;
}

int main(){
    string text, patt;
    cin >> text >> patt;
    
    patt += patt;

    cout << kmp(patt, text);
}
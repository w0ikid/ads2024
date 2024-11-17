#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// unordered_set<string> insertSubstrings(const string& inputString, int n) {
//     unordered_set<string> substringsSet;

//     // Ensure n is a valid length
//     if (n <= 0 || n > inputString.length()) {
//         return substringsSet;  // Return an empty set if n is not valid
//     }

//     // Iterate over the input string to extract substrings of length n
//     for (int i = 0; i <= inputString.length() - n; ++i) {
//         string substring = inputString.substr(i, n);
//         substringsSet.insert(substring);
//     }

//     return substringsSet;
// }


int kmp(string& a, string& b){
    if(b.size() == 0){
        return 0;
    }

    string temp = a;
    int cnt = 1;

    while(a.size() < b.size()){
        a += temp;
        cnt++;
        // if(kmp(a, b) > -1){
        //     cout << cnt;
        //     return 0;
        // }
        
    }
    vector<int> lps(b.size(), 0);

    //lps implementation
    int prevLPS = 0, i = 1;
    while(i < b.size()){
        if(b[i] == b[prevLPS]){
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

    int j = 0;
    while(j < 2){
        int i1 = 0; // iterator for a
        int i2 = 0; // iterator for pattern
        while(i1 < a.size()){
            if(a[i1] == b[i2]){
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
            if(i2 == b.size()){
                return cnt;
            }
        }

        a += temp;
        cnt++;
        j++;
    }

    return -1;
}

int main(){
    string a, b;
    cin >> a >> b;
    

    // unordered_set<char> hashSet;

    // if()

    cout << kmp(a, b);
    // if(a.size() > b.size()){
    //     if(kmp(a, b) > -1){
    //         cout << cnt;
    //         return 0;
    //     }
    // }
    
    
    // while(a.size() <= b.size()){
    //     a += temp;
    //     cnt++;
    //     if(kmp(a, b) > -1){
    //         cout << cnt;
    //         return 0;
    //     }
        
    // }

    // a += temp;
    // cnt++;

    // if(kmp(a, b) > -1){
    //     cout << cnt;
    //     return 0;
    // }

    // a += temp;
    // cnt++;

    // if(kmp(a, b) > -1){
    //     cout << cnt;
    //     return 0;
    // }

    // cout << -1;

    // cout << a << " " << b << endl;

    // if(kmp(a, b) > -1){
    //     cout << cnt;
    // }
    // else{
    //     a += temp;
    //     cnt++;
    //     if(kmp(a, b) > -1){
    //         cout << cnt;
    //     }
    //     else{
    //         cout << cnt;
    //     }
    // }


}
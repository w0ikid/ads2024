#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool check (string s, int m) {
    int i = 0;
    string ref = s;
    for (int j = 0; j < m; j++) {
        s += s[i++];
    }
    if (s.substr(m, s.size()) == ref)
        return true;
    return false;
}

void kmp (string text) {   
    vector<int> lps(text.size(), 0);
    int prevLPS = 0;
    int i = 1;
    int n = text.size();
    while (i < n) {
        if (text[i] == text[prevLPS]) {
            lps[i] = prevLPS + 1;
            prevLPS++;
            i++;
        }
        else if (prevLPS != 0) {
            prevLPS = lps[prevLPS - 1];
        }
        else {
            lps[i] = 0;
            i++;
        }
    }
    
    
    int j = 0, k = 1, cnt = 0;
    bool ok = true;
    while (k < n) {
        if (lps[k] == 0) {
            if (ok)
                j++;
            else
                j = k;
            ok = true;
        }
        else if (j + 1 == lps[k] || (lps[k] % 2 == 0 && ((lps[k]/2) % (j + 1)) == 0)) {
            ok = false;
            cnt++;
        }
        k++;
    }
    if (j != n - 1 && check(text, j + 1))
        cnt--;
    cout << cnt;
}

int main() {
    string s; cin >> s;
    if (s.size() < 3) {
        cout << 0;
        return 0;
    }
    kmp(s);
}
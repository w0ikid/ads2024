#include <bits/stdc++.h>
#include <cmath>
using namespace std;


vector<int> prefix_func(string text, string pat){
    string s = pat + "#" + text;
    vector<int> pref(s.size()); 
    cout<<s<<endl;

    pref[0] = 0;

    int k;

    for (int i = 1; i < pref.size(); i++)
    {
        k = pref[i-1];
        while (k>0)
        {
            if(s[i] == s[k]){
                k++;
                break;
            }
            k = pref[k-1];
        }
        if(k == 0 && s[i] == s[k])
            k=1;
        pref[i] = k;
    }
    
    for (int i = 0; i < pref.size(); i++)
    {
        cout<<pref[i]<<"|";
    }
    cout<<endl;

    return pref;
}

vector<int> kmp(vector<int> pref, int pat_size){
    vector<int> v;
    for (int i = 0; i < pref.size(); i++)
    {
        if(pref[i] == pat_size){
            v.push_back(i-2*pat_size);
        }
    }
    return v;
}


int main()
{   
    string text = "abracadabra";
    string pat = "abra";
    vector<int> v = prefix_func(text,pat);
    vector<int> found = kmp(v,pat.size());
    for (int i = 0; i < found.size(); i++)
    {
        cout<<found[i]<<"|";
    }
    
    return 0;
}
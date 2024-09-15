#include <queue>
#include <iostream>
using namespace std;

int main(){
     int temp; 
     int borsik,nursik;
     queue<int> B; queue<int> N;

     for (int16_t i = 0; i < 5; i++){
          cin >> temp; B.push(temp);
     }

     for (int16_t i = 0; i < 5; i++){
          cin >> temp; N.push(temp);
     }     
/*
     for (int16_t i = 0; i < 5; i++){
          cout << B.front() << " ";
          B.pop();
     }
     cout << endl;
     for (int16_t i = 0; i < 5; i++){
          cout << N.front() << " ";
          N.pop();
     }
*/

for (int64_t i = 0; i < 1000000; i++){
     borsik = B.front() == 0 && N.front() == 9 ? 10 : B.front();
     nursik = N.front() == 0 && B.front() == 9 ? 10 : N.front();

     if(nursik > borsik){
          N.push(B.front());
          N.push(N.front());
          N.pop();
          B.pop();
     }else{
          B.push(B.front());
          B.push(N.front());
          N.pop();
          B.pop();
     }

      if(B.empty()){
          cout << "Nursik " << i+1;
           return 0;
     }
     else if(N.empty()){
          cout << "Boris " << i+1; 
           return 0;
     }
     

}

     cout << "blin nichya";
     return 0;
}
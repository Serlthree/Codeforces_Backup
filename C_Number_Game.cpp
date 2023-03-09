#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int t, n;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        //if 1 then ashishgup loses
        if(n == 1){
            cout << "FastestFinger" << endl;
        }
        //if 2 then ashishgup wins
        else if(n == 2){
            cout << "Ashishgup" << endl;
        }
        //if odd then ashishgup wins
        else if(n & 1){ 
            cout << "Ashishgup" << endl;
        }
        /*
            1 4 6 8 10 14 16 22 26 32 34 38
            if 2*prime or power of 2 then FastestFinger wins
        */
        else if (!(n & (n-1))){
            cout << "FastestFinger" << endl;
        }
        else{
            //check for prime factors
            n /= 2;
            int cnt = 0;
            for(int i = 2; i*i <= n; i++){
                if(n % i == 0){
                    cnt++;
                    while(n % i == 0){
                        n /= i;
                    }
                }
            }
            if(cnt == 0){
                cout << "FastestFinger" << endl;
            }
            else{
                cout << "Ashishgup" << endl;
            }
        }
    }
}
/*
1 4 6 8 10 14 16 22 26 32 34 38
//if 2*prime or power of 2 then FastestFinger wins
*/
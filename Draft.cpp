#include <iostream>

using namespace std;

int main(){
    int n;

    cin >> n;

    int num[n];

    for(int i=0; i<n; i++){
        if( i >= 2 ){
            num[i] = num[i-2] + num[i-1];
            cout << num[i];
        }else{
            cout << i;
            num[i] = i;
        }

        if( i != n-1 ){
            cout << " ";
        }
    }

    cout << endl;

    return 0;
}

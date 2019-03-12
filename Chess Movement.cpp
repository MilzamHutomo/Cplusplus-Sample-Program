#include <iostream>

using namespace std;

int main(){
    int x1,x2,y1,y2,X,Y;

    cout << "Masukkan posisi awal: ";
    cin >> x1 >> y1;

    cout << "Masukkan posisi akhir: ";
    cin >> x2 >> y2;

    X = x2 - x1;
    Y = y2 - y1;

    if( X == 0 && Y == 0 ){
        cout << 0 << endl;
    }else if( X/Y == 1 || X/Y == -1 ){
        cout << 1 << endl;
    }else if( X == 0 && Y != 0 ){
        cout << 1 << endl;
    }else if( X != 0 && Y == 0 ){
        cout << 1 << endl;
    }else{
        cout << 2 << endl;
    }
}

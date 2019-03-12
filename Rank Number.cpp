#include <iostream>

using namespace std;

int rankNumber(int n, int rankNum);

int main(){
    int num, rankNum;

    cout << "Input primary number: ";
    cin >> num;

    cout << "Input the number of rank: ";
    cin >> rankNum;

    cout << rankNumber(num, rankNum);
}

int rankNumber(int n, int rankNum){
    if( rankNum == 0 ){
        return 1;
    }else{
        return n * rankNumber(n, rankNum-1);
    }
}

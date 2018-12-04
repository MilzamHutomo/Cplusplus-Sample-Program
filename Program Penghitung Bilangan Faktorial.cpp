#include <iostream>

using namespace std;

bool validation(int num);
void factorial(int num);
int count(int num);

int main(){
    int num;

    cout << "Masukkan Angka: "; cin >> num;

    if(!validation(num)){
        factorial(num);
    }
}

bool validation(int num){
    if(num < 0){
        cout << "Input tidak valid" << endl;
        return 1;
    }else if(num == 0){
        cout << "0! = 1" << endl;
        return 1;
    }
}

void factorial(int num){
    cout << num << "! = ";
    for(int i=num; i>0; i--){
        cout << i;
        if(i != 1){
            cout << " x ";
        }
        if(i == 1){
            cout << " = ";
        }
    }
    cout << count(num);
}

int count(int num){
    int counter = 1;
    for(int i=num; i>0; i--){
        counter = counter*i;
    }
}

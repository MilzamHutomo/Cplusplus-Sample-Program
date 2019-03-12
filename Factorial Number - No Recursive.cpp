#include <iostream>

using namespace std;

/**
 * Input validation since factorial only for positive number
 **/
bool validation(int num);

/**
 * sub-program to show "X! = A x B x C = RESULT"
 **/
void factorial(int num);

/**
 * Function to count the result of its factorial
 **/
int count(int num);

int main(){
    int num;

    cout << "Input Number: "; cin >> num;

    if(!validation(num)){
        factorial(num);
    }
}

bool validation(int num){
    if(num < 0){
        cout << "Input not valid" << endl;
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
    return counter;
}

#include <iostream>

using namespace std;

int main(){
    string word;

    cin >> word;
    int length = word.length();
    for(int i=0; i<length; i++){
        if( word[i] != word[length-(i+1)] ){
            cout << word << " is not palindrome" << endl;
            return 0;
        }
    }
    cout << word << " is palindrome" << endl;
    return 0;
}


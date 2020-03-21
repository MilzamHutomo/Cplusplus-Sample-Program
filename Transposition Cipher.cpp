#include <iostream>
#include <sstream>

using namespace std;

int main(){
    string key, plainText;

    cout << "Input key: ";
    cin >> key;

    cout << endl << "Input Plaintext: ";
    cin >> plainText;

    char keyMap[key.length()];
    string keyOrigin = key;

    for( int i=0; i < key.length(); i++ ){
        for( int j = i+1; j < key.length(); j++ ){
            if( key[i] >= key[j] ){
                swap( key[i], key[j] );
            }
        }
        keyMap[i] = key[i];
    }

    int matrixRow = plainText.length();

    while( matrixRow%key.length() != 0 ){
        matrixRow++;
    }

    matrixRow = matrixRow/key.length();
    int matrixColumn = key.length();

    char cipherMatrix[matrixRow][matrixColumn];

    int plainTextIter = 0;

    for( int i = 0; i < matrixRow; i++ ){
        for( int j = 0; j < matrixColumn; j++ ){
            cipherMatrix[i][j] = plainText[plainTextIter];
            plainTextIter++;
            if( plainTextIter > plainText.length()-1 ){
                plainTextIter = 0;
            }
        }
    }

    cout << endl << "The Matrix Will Be Like This:" << endl;

    for( int i=0; i < matrixRow; i++ ){
        for( int j=0; j < matrixColumn; j++ ){
            cout << cipherMatrix[i][j] << " ";
        }
        cout << endl;
    }

    stringstream cipher;

    for( int i=0; i < key.length(); i++ ){
        for( int j=0; j < key.length(); j++ ){
            if( keyMap[i] == keyOrigin[j] ){
                for( int k=0; k < matrixRow; k++ ){
                    cipher << cipherMatrix[k][j];
                }
                keyOrigin[j] = NULL;
                break;
            }
        }
    }

    cout << cipher.str() << endl;

}

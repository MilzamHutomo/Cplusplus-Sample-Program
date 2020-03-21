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
                //If the matrix column is bigger than the length of the plaintext
                //The rest of the column will filled with letter from the beginning of the plaintext
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
                //Remove compared letter in the key to prevent duplicate comparasion
                keyOrigin[j] = NULL;
                break;
            }
        }
    }

    cout << cipher.str() << endl;

}

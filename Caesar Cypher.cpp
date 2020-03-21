#include <iostream>
#include <sstream>

using namespace std;

string encrypt(string, int);
string decrypt(string, int);

int main(){
    string plainText;
    cin >> plainText;
    int shift;
    cin >> shift;
    cout << encrypt(plainText, shift) << endl << endl;

    string cypherText;
    cin >> cypherText;
    cin >> shift;
    cout << decrypt(cypherText, shift) << endl;
}

string encrypt(string plain, int shift){
    int textLength = plain.size();
    stringstream cypherText;
    string newPlain;
    char cypherChar;
    for( int i = 0; i < textLength; i++ ){
        if( int(plain[i]) >= 97 && int(plain[i]) <= 122){
            if( (int(plain[i])+shift)%122 == 0 ){
                cypherChar = 122;
            }else if( (int(plain[i])+shift)%122 < 97 ){
                cypherChar = ((int(plain[i])+shift)%122) + 96;
            }else{
                cypherChar = ((int(plain[i])+shift)%122);
            }
        }else if( int(plain[i]) >= 65 && int(plain[i]) <= 90 ){
            if( (int(plain[i])+shift)%90 == 0 ){
                cypherChar = 90;
            }else if( (int(plain[i])+shift)%90 < 65 ){
                cypherChar = ((int(plain[i])+shift)%90) + 64;
            }else{
                cypherChar = ((int(plain[i])+shift)%90);
            }
        }
        cypherText << newPlain << cypherChar;
    }
    return cypherText.str();
}

string decrypt(string cypher, int shift){
    int textLength = cypher.size();
    stringstream plainText;
    string newCypher;
    char plainChar;
    for( int i = 0; i < textLength; i++ ){
        if( int(cypher[i]) >= 97 && int(cypher[i]) <= 122){
            if( (int(cypher[i])-shift)%122 == 0 ){
                plainChar = 122;
            }else if( (int(cypher[i])-shift)%122 < 97 ){
                plainChar = ((int(cypher[i])-shift)%122) + 96;
            }else{
                plainChar = ((int(cypher[i])-shift)%122);
            }
        }else if( int(cypher[i]) >= 65 && int(cypher[i]) <= 90 ){
            if( (int(cypher[i])-shift)%90 == 0 ){
                plainChar = 90;
            }else if( (int(cypher[i])-shift)%90 < 65 ){
                plainChar = ((int(cypher[i])-shift)%90) + 64;
            }else{
                plainChar = ((int(cypher[i])-shift)%90);
            }
        }
        plainText << newCypher << plainChar;
    }
    return plainText.str();
}

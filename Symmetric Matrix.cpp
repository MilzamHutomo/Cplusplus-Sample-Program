#include <iostream>

using namespace std;

int main(){

    bool symmetric = true;

    //Bonus 1; 5 poin
    int size;
    cout << "Determine matrix size: ";
    cin >> size;

    int matrix[size][size];

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cin >> matrix[i][j];
        }
    }

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if( matrix[i][j] != matrix[j][i] ){
                if(symmetric){
                    symmetric = false;
                    cout << "Matrix not symmetric" << endl;
                }
                // Bonus 2; 20 poin
                if(!symmetric){
                    cout << "[" << i << "][" << j << "]" << "not equal with [" << i << "][" << j << "]" << endl;
                }
            }
        }
    }
    if(symmetric){
        cout << "Matriks symmetric" << endl;
    }
    cout << "Finished" << endl;
}

#include <iostream>

using namespace std;

int main(){

    bool symmetric = true;

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
                //Display which coordinate that make the matrix not symmetric
                if(!symmetric){
                    cout << "[" << i << "][" << j << "]" << "not equal with [" << j << "][" << i << "]" << endl;
                    /**
                    Alternative
                    cout << "[" << i << "][" << j << "]" << endl;
                    **/
                }
            }
        }
    }
    if(symmetric){
        cout << "Matrix symmetric" << endl;
    }
    cout << "Finished" << endl;
}
#include <iostream>

using namespace std;

int main(){

    bool symmetric = true;

    int x,y;
    cout << "Determine matrix size: ";
    cin >> x >> y;

    int matrix[x][y];

    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            cin >> matrix[i][j];
        }
    }
    
    if( x == y ){
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                if( matrix[i][j] != matrix[j][i] ){
                    if(symmetric){
                        symmetric = false;
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
    }else simetric = false;
    
    if(symmetric){
        cout << "Matrix symmetric" << endl;
    }else{
        cout << "Matrix not symmetric" << endl;
    }
    
    cout << "Finished" << endl;
}

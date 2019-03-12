#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

    char initialHour[5];
    cout << "Start Training (hh:mm) : ";
    gets(initialHour);

    int startHour = ((initialHour[0]-48)*10) + (initialHour[1]-48);
    int startMinute = ((initialHour[3]-48)*10) + (initialHour[4]-48);

    int easyPace = 8 + (15/60.0);
    int tempo = 7 + (12/60.0);

    int numPace;
    cout << "Easy Pace = ";
    cin >> numPace;
    easyPace = easyPace * numPace;


    int numTempo;
    cout << "Tempo = ";
    cin >> numTempo;
    tempo = tempo * numTempo;

    startHour = startHour + (easyPace/60) + (tempo/60);
    startMinute = startMinute + (easyPace%60) + (tempo%60);
    if ( startMinute > 60 ){
        startHour = startHour + (startMinute/60);
        startMinute = startMinute%60;
    }

    if( startHour < 10 ){
        cout << "0";
    }
    cout << startHour << ":" << startMinute;

}

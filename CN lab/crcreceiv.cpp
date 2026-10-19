#include<iostream>
using namespace std;

int main(){
    int n, m, i, j;

    cout << "Enter the size of received frame: ";
    cin >> n;

    int frame[n];

    cout << "Enter the received frame: ";
    for(i = 0; i < n; i++){
        cin >> frame[i];
    }

    cout << "Enter the size of divisor: ";
    cin >> m;

    int divisor[m];

    cout << "Enter the divisor: ";
    for(i = 0; i < m; i++){
        cin >> divisor[i];
    }

    int message[n];

    for(i = 0; i < n; i++){
        message[i] = frame[i];
    }


    for(i = 0; i <= n - m; i++){
        if(message[i] == 1){
            for(j = 0; j < m; j++){
                message[i + j] = message[i + j] ^ divisor[j];
            }
        }
    }

    cout << "Remainder: ";
    for(i = n - (m - 1); i < n; i++){
        cout << message[i];
    }

    int error = 0;

    for(i = n - (m - 1); i < n; i++){
        if(message[i] == 1){
            error = 1;
            break;
        }
    }

    if(error == 0){
        cout << "\nNo Error Detected. Data Received Successfully!";
    }
    else{
        cout << "\nError Detected in Received Frame!";
    }

    return 0;
}

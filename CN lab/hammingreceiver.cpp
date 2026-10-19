#include<iostream>
using namespace std;

int main()
{
    int C[11], S1, S2, S4, S8;
    int errorPosition;
    
    cout << "Enter received 11 bits: ";
    for(int i = 0; i < 11; i++)
    {
        cin >> C[i];
    }

    S1 = C[0] ^ C[2] ^ C[4] ^ C[6] ^ C[8] ^ C[10];
    S2 = C[1] ^ C[2] ^ C[5] ^ C[6] ^ C[9] ^ C[10];
    S4 = C[3] ^ C[4] ^ C[5] ^ C[6];
    S8 = C[7] ^ C[8] ^ C[9] ^ C[10];
    errorPosition = S1 + (S2 * 2) + (S4 * 4) + (S8 * 8);

    if(errorPosition == 0)
    {
        cout << "No error detected." << endl;
    }
    else
    {
        cout << "Error detected at position: " << errorPosition << endl;

        C[errorPosition - 1] = C[errorPosition - 1] ^ 1;

        cout << "Corrected codeword: ";
        for(int i = 0; i < 11; i++)
        {
            cout << C[i];
        }
        cout << endl;
    }

    cout << "Original message: ";
    cout << C[0] << C[1] << C[2]
         << C[4] << C[5] << C[6] << C[8];

    cout << endl;

    return 0;
}
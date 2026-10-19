#include <iostream>
using namespace std;

int main()
{
    int i, j = 0, n, counter = 0;

    cout << "Enter size of frame 1: ";
    cin >> n;

    int frame1[n], frame2[2 * n];

    cout << "Enter the bits for frame 1: ";
    for (i = 0; i < n; i++)
    {
        cin >> frame1[i];
    }

    for (i = 0; i < n; i++)
    {
        if (frame1[i] == 1)
        {
            counter++;
            frame2[j] = frame1[i];
            j++;

            if (counter == 5)
            {
                frame2[j] = 0;   // Stuff a 0
                j++;
                counter = 0;
            }
        }
        else
        {
            counter = 0;
            frame2[j] = frame1[i];
            j++;
        }
    }

    cout << "Frame 1: ";
    for (i = 0; i < n; i++)
    {
        cout << frame1[i];
    }

    cout << endl;

    cout << "Frame 2 (After Bit Stuffing): ";
    for (i = 0; i < j; i++)
    {
        cout << frame2[i];
    }

    cout << endl;

    return 0;
}
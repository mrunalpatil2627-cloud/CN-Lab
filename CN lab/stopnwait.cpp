#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
int frame[11],i;
int timeout=5;
int delay;
srand(time(0));
cout<<"Enter 11 bit frame: ";
for(i=0;i<11;i++)
{
cin>>frame[i];
}
delay=rand()%10;
if(timeout<delay)
{
cout<<"Acknowledgement received!";
}
else
{
cout<<"Waiting!";
}
return 0;
} 
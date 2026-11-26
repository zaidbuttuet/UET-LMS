#include <iostream>
using namespace std;
int main()
{
    int marks[5];
    int sort[5];
    int maximum = marks[0];

    marks[0] = 10;
    marks[1] = 20;
    marks[2] = 30;
    marks[3] = 40;
    marks[4] = 50;

    for (int i = 1; i < 5; i++)
    {
        if (marks[i] > maximum)
        {
            sort[i - 1] = marks[i];
        }
    }
    for(int i=0; i<5;i++)
    {
        cout <<sort[i]<<" ";
    }

    return 0;
}
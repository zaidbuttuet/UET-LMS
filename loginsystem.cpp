
#include <iostream>
using namespace std;
int main()
{

    string username = "Zaid", pass = "Zaid123";
    for (int i = 3; i >= 1; i--)
    {
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> pass;

        if (username != "Zaid" || pass != "Zaid123")
        {
            cout << "Incorrect Username or Password" << endl;
            cout << "You have " << i - 1 << " Attempts Left.." << endl;

            if (i == 1)
            {
                cout << "Sorry! The Program is closed." << endl;
                return 0;
            }
        }
        else
        {
            cout << "You have successfully Logged in.." << endl;
            break;
        }
    }
    return 0;
}
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

void banner()
{
    cout << right << setw(70) << "***********************************************" << endl;
    cout << right << setw(70) << "*           Welcome To UET LMS Portal         *" << endl;
    cout << right << setw(70) << "***********************************************" << endl;
    cout << endl;
}

string menu()
{
    cout << "Select one of the following options from the Menu..." << endl;
    cout << "1. Add name" << endl;
    cout << "2. Update Data" << endl;
    cout << "3. Delete name" << endl;
    cout << "4. Search name" << endl;
    cout << "5. Total Student Count" << endl;
    cout << "6. List of All names" << endl;
    cout << "7. Exit";
    cout << endl;

    string choice;
    cout << "Enter Your Choice: ";
    cin >> choice;

    return choice;
}

int main()
{
    system("cls");
    string name[100];
    string reg_no[100];
    int marks[100];
    string username, pasword;

    for (int i = 0; i < 100; i++)
    {
        name[i] = "NV";
        reg_no[i] = "NV";
        marks[i] = -1;
    }

    int std_count = 0;
    string choice;

    banner();

    {
        choice = menu();

        if (choice == "1")
        {
            bool added = false;
            for (int i = 0; i < 100; i++)
            {
                if (name[i] == "NV" && reg_no[i] == "NV" && marks[i] == -1)
                {
                    cout << right << setw(70) << "**************** ADD STUDENT ****************" << endl;

                    cout << "Enter Full Name: ";
                    cin.ignore(1000, '\n');
                    getline(cin, name[i]);

                    cout << "Enter Registration Number: ";
                    cin >> reg_no[i];

                    cout << "Enter Marks: ";
                    cin >> marks[i];

                    cout << "\n******** Student is Added Succesfully ********" << endl;
                    cout << endl;

                    added = true;
                    break;
                }
            }
            if (added == false)
            {
                cout << "Memory is Full. Student cannot be Added" << endl;
            }
        }
        else if (choice == "2")
        {
            string regNo, new_regNo, new_name;
            int new_marks;
            bool edit = false;

            cout << right << setw(70) << "**************** UPDATE RECORD ****************" << endl;
            cout << "Enter Registration Number to Search: ";
            cin >> regNo;

            for (int i = 0; i < 100; i++)
            {
                if (reg_no[i] == regNo)
                {
                    cout << endl;
                    cout << " ---------------------------------------- " << endl;
                    cout << " ------------ STUDENT RECORD ------------ " << endl;
                    cout << " ---------------------------------------- " << endl;
                    cout << " Student Name: " << name[i] << endl;
                    cout << " Student Marks: " << marks[i] << endl;
                    cout << endl;

                    cout << "Enter new full Name to update: ";
                    cin >> new_name;

                    name[i] = new_name;

                    cout << "Enter Student New marks: ";
                    cin >> new_marks;

                    marks[i] = new_marks;

                    cout << "Updated Succesfully.." << endl;
                    edit = true;
                    break;
                }
            }

            if (!edit)
            {
                cout << "\nSorry!No Student Exists with that Registration Number." << endl;
            }
        }

        // To delete a Student
        else if (choice == "3")
        {
            bool found = false;
            string Reg_no;

            cout << right << setw(70) << "**************** DELETE STUDENT ****************" << endl;

            cout << "Enter Registration Number: ";
            cin >> Reg_no;

            for (int i = 0; i < 100; i++)
            {
                if (reg_no[i] == Reg_no)
                {
                    cout << endl;
                    cout << " ---------------------------------------- " << endl;
                    cout << " ------------ STUDENT RECORD ------------ " << endl;
                    cout << " ---------------------------------------- " << endl;
                    cout << " Student Name: " << name[i] << endl;
                    cout << " Student Marks: " << marks[i] << endl;
                    cout << endl;
                    cout << "Press any key to Delete Record....";
                    cout << endl;

                    getch();

                    name[i] = "NV";
                    reg_no[i] = "NV";
                    marks[i] = -1;
                    cout << "Record is Deleted Succesfully.." << endl;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Student Record Not Found..";
            }
        }
        else if (choice == "4")
        {
            bool is_found = false;
            string Reg_no;

            cout << "Enter Registration Number To Search: ";
            cin >> Reg_no;

            for (int i = 0; i < 100; i++)
            {
                if (reg_no[i] == Reg_no)
                {

                    cout << endl;
                    cout << " ---------------------------------------- " << endl;
                    cout << " ------------ STUDENT RECORD ------------ " << endl;
                    cout << " ---------------------------------------- " << endl;
                    cout << " Student Name: " << name[i] << endl;
                    cout << " Student Marks: " << marks[i] << endl;
                    cout << endl;
                    is_found = true;
                    break;
                }
            }
            if (!is_found)
            {
                cout << "******** Record Not Found ********" << endl;
                cout << endl;
            }
        }

        else if (choice == "5")
        {
            cout << right << setw(70) << "**************** TOTAL STUDENTS ****************" << endl;
            for (int i = 0; i < 100; i++)
            {
                if (name[i] != "NV" && marks[i] != -1 && reg_no[i] != "NV")
                {
                    std_count += 1;
                }
            }
            cout << "Number of Students in a System: " << std_count << endl;
            cout << endl;
        }
        else
        {
            cout << "******** Invalid Input ********" << endl;
            cout << endl;
        }
    }
}

#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototypes
void banner();
int menu();
int studentMenu();
void CourseMenu();
void InstructorMenu();

// Main Function
int main()
{
    system("cls");
    banner();

    while (true)
    {
        // LMS Menu (student,course,instructor)
        int choice = menu();

        // Student Menu
        if (choice == 1)
        {
            int total_marks[5], obt_marks[5], no_of_std = 0;
            string name[5], reg_no[5];
            string student[5] = {"NV", "NV", "NV", "NV", "NV"};

            while (true)
            {
                // student Menu
                int std_choice = studentMenu();

                // To add a Student
                if (std_choice == 1)
                {
                    for (int i = 0; i < 5; i++)
                    {
                        if (student[i] == "NV")
                        {
                            cout << "Enter Student Name: ";
                            cin.ignore(); 
                            getline(cin, name[i]);
                            student[i] = name[i];

                            cout << "Enter Registration Number: ";
                            cin >> reg_no[i];
                            

                            cout << "Enter Total Marks: ";
                            cin >> total_marks[i];

                            cout << "Enter Obtained Marks: ";
                            cin >> obt_marks[i];

                            cout << "\n******Student is Added Succesfully ******" << endl;
                            no_of_std += 1;

                            break;
                        }
                        else
                        {
                            cout << "Memory is full. No Student can be Added!";
                        }
                    }
                }

                // To view Number of Students in a System
                else if (std_choice == 2)
                {

                    cout << "Number Of Students In A System: " << no_of_std << endl;
                }

                else if (std_choice == 3)
                {
                    cout << "Name: " << name[0] << endl;
                    cout << "Registration Number: " << reg_no[0] << endl;
                    cout << "Marks: " << obt_marks[0] << endl;
                }

                else if (std_choice == 4)
                {
                    cout << "\nYou are Exited from the Student menu";
                    break;
                }

                else
                {
                    cout << "\n****** INVALID INPUT ******" << endl;
                }
            }
        }
        else if (choice == 2)
        {
            CourseMenu();
        }

        else if (choice == 3)
        {
            InstructorMenu();
        }

        else if (choice == 4)
        {
            cout << "\n ****** Your Program is Closed Succesfully ******";
            return 0;
        }
        else
        {
            cout << "****** INVALID INPUT ******" << endl;
        }
    }

    return 0;
}
void banner()
{
    cout << right << setw(70) << "***********************************************" << endl;
    cout << right << setw(70) << "*           Welcome To UET LMS Portal         *" << endl;
    cout << right << setw(70) << "***********************************************" << endl;
    cout << endl;
}

int menu()
{
    int choice;

    cout << "Select one of the following options from the Menu: " << endl;
    cout << "1. Student Management" << endl;
    cout << "2. Course Mangement" << endl;
    cout << "3. Instructor Management" << endl;
    cout << "4. Close Program\n"
         << endl;

    cout << "Enter Your Choice...";
    cin >> choice;

    return choice;
}

int studentMenu()
{
    int choice;

    cout << "\nSelect one of the following options from the given menu:" << endl;
    cout << "1.To Add Student Data" << endl;
    cout << "2.To View Number of students in a system" << endl;
    cout << "3.To View Student Results " << endl;
    cout << "4.To Exit from Student Menu " << endl;

    cout << "Enter Your Choice...";
    cin >> choice;

    return choice;
}
void CourseMenu()
{
    cout << "Enter 1 to Add Course " << endl;
    cout << "Enter 2 to View All Courses" << endl;
}
void InstructorMenu()
{

    cout << "Enter 1 to Add Instructor Data" << endl;
    cout << "Enter 2 to View all Instructors " << endl;
}

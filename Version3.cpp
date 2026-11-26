#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

void banner()
{
    cout << right << setw(70) << "***********************************************" << endl;
    cout << right << setw(70) << "*           Welcome To UET LMS Portal         *" << endl;
    cout << right << setw(70) << "***********************************************" << endl;
    cout << endl;
}
void loginmenu()
{

    cout << endl;
    cout << right << setw(60) << "----------------------------" << endl;
    cout << right << setw(60) << "        Admin Login         " << endl;
    cout << right << setw(60) << "----------------------------" << endl;
    cout << endl;
}

bool loginsystem()
{ // Admin Password
    const string Username = "Zaid";
    const string Password = "Zaid123";

    string username, password;
    int attempts = 3;

    cout << "Dear User! You have three attempts to login " << endl;
    cout << endl;

    for (int i = 1; i <= 3; i++)
    {
        cout << "Enter Username: ";
        cin >> username;

        cout << "Enter Password: ";
        cin >> password;

        if (username == Username && password == Password)
        {
            cout << endl;
            cout << right << setw(70) << "******** You have Successfully Logged In ********" << endl;
            return true;
        }
        else
        {
            attempts--;
            cout << endl;
            cout << right << setw(70) << "********** Incorrect Username or Password **********" << endl;
            cout << endl;

            if (attempts != 0)
            {
                cout << "You have " << attempts << " attempts Left" << endl;
            }

            if (attempts == 0)
            {
                cout << "Sorry! The Program is Closed..." << endl;
                return false;
            }
        }
    }
}
char grade_cal(int marks)
{
    char grade;

    if (marks > 85)
        grade = 'A';
    else if (marks > 65)
        grade = 'B';
    else if (marks > 30)
        grade = 'C';
    else if (marks > 30)
        grade = 'D';
    else
        grade = 'F';

    return grade;
}

string menu()
{
    cout << endl;
    cout << right << setw(60) << "----------------------------" << endl;
    cout << right << setw(60) << "          Main Menu         " << endl;
    cout << right << setw(60) << "----------------------------" << endl;
    cout << endl;

    cout << "Select one of the following options from the Menu..." << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Update Data" << endl;
    cout << "3. Delete name" << endl;
    cout << "4. Search name" << endl;
    cout << "5. List of All Students with Grade" << endl;
    cout << "6. Class Statistics" << endl;
    cout << "7. Exit";
    cout << endl;

    string choice;
    cout << "Enter Your Choice: ";
    cin >> choice;

    return choice;
}

main()
{
    system("cls");
    string name[100];
    string reg_no[100];
    int marks[100];

    for (int i = 0; i < 100; i++)
    {
        name[i] = "NV";
        reg_no[i] = "NV";
        marks[i] = -1;
    }

    int std_count = 0;
    string choice;

    banner();
    loginmenu();

    // Login system

    bool result = loginsystem();
    {
        if (result == false)
            return 0;
    }

    while (true)
    {
        choice = menu();

        if (choice == "1")
        {
            bool added = false;

            string reg_No;
            int Marks;
            for (int i = 0; i < 100; i++)
            {
                if (name[i] == "NV" && reg_no[i] == "NV" && marks[i] == -1)
                {
                    cout << right << setw(70) << "**************** ADD STUDENT ****************" << endl;

                    cout << "Enter Full Name: ";
                    cin.ignore(1000, '\n');
                    getline(cin, name[i]);

                    while (true)
                    {
                        bool is_found = false; // To check that enterered RegNO already exists or not

                        cout << "Enter Registration Number: ";
                        cin >> reg_No;

                        for (int j = 0; j < i; j++)
                        {
                            if (reg_no[j] == reg_No)
                            {
                                cout << endl;
                                cout << "Student with that Registration Number already Exists" << endl;
                                is_found = true;
                                break;
                            }
                        }
                        if (!is_found)
                        {
                            reg_no[i] = reg_No;
                            break;
                        }
                    }

                    while (true)
                    {
                        cout << "Enter Marks(Out of 100): ";
                        cin >> Marks;

                        if (Marks > -1 and Marks <= 100)
                        {
                            marks[i] = Marks;
                            cout << endl;
                            cout << right << setw(70) << "******** Student is Added Succesfully ********" << endl;
                            cout << endl;
                            break;
                        }
                        else
                        {
                            cout << endl;
                            cout << "Marks Should Be Greater or Equal to 0 " << endl;
                        }
                    }

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

                    cout << "Enter New Name to Update: ";
                    cin >> new_name;

                    name[i] = new_name;

                    cout << "Enter Student New Marks: ";
                    cin >> new_marks;

                    marks[i] = new_marks;

                    cout << right << setw(70) << "**************** UPDATED SUCCESSFULLY****************";
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

        // List of All Students with Grade
        else if (choice == "5")
        {
            bool is_found = false;
            
            for (int i = 0; i < 100; i++)
            {
                if (name[i] != "NV" && marks[i] != -1)
                {
                    cout << endl;
                    cout << " ---------------------------------------------------------- " << endl;
                    cout << " ------------ List of All Students with Grade: ------------ " << endl;
                    cout << " ---------------------------------------------------------- " << endl;
                    cout << endl;
                    cout << left << setw(15) << "Name" << right << setw(10) << "REG.No" << right << setw(10) << "Grade" << endl;
                    cout << endl;
                    break;
                }
            }
            for (int i = 0; i < 100; i++)
            {

                if (name[i] != "NV" && marks[i] != -1)
                {
                    char grade = grade_cal(marks[i]);
                    cout << left << setw(15) << name[i] << right << setw(10) << reg_no[i] << right << setw(10) << grade << endl;
                    is_found = true;
                }
            }
            if (!is_found)
            {
                cout << right << setw(70) << "****** No Student Exist in this System ******" << endl;
                cout << endl;
            }
        }
        else if (choice == "6")
        {
            float avg_marks = 0;
            float total_marks = 0;
            float total_obt_Marks = 0;
            float percentage;
            int highest_marks = 0;
            int lowest_marks = 100;

            string choice;

            while (true)
            {
                cout << endl;
                cout << "Select one of the following options from the Menu..." << endl;
                cout << "1.Total Students" << endl;
                cout << "2.Average Marks" << endl;
                cout << "3.Overall Class Percentage" << endl;
                cout << "4.Highest Marks" << endl;
                cout << "5.Lowest Marks" << endl;
                cout << "6. Exit From Class Statistics" << endl;

                cout << "Enter Your Choice: ";
                cin >> choice;

                if (choice == "1") // Total students
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

                else if (choice == "2") // Average Marks of a class
                {
                    cout << right << setw(70) << "**************** Average Marks ****************" << endl;

                    for (int i = 0; i < 100; i++) // To calculate Total Marks
                    {
                        if (marks[i] != -1)
                        {
                            avg_marks += marks[i];
                        }
                    }

                    avg_marks /= std_count;

                    cout << "Average Marks: " << avg_marks << endl;
                }

                else if (choice == "3") // Overall percentage
                {
                    cout << right << setw(70) << "**************** Overall Percentage ****************" << endl;

                    for (int i = 0; i < 100; i++) // Calculate Total Marks of all students
                    {
                        if (marks[i] != -1)
                        {
                            total_marks += 100;
                            total_obt_Marks += marks[i];
                        }
                    }

                    percentage = (total_obt_Marks / total_marks) * 100.0;

                    cout << "Overall Percentage: " << percentage << "%" << endl;
                }

                else if (choice == "4") // Highest Marks In Class
                {
                    string Name;
                    cout << right << setw(70) << "**************** Highest Marks****************" << endl;
                    cout << endl;

                    for (int i = 0; i < 100; i++)
                    {
                        if (marks[i] != -1 && name[i] != "NV" && reg_no[i] != "NV")
                        {
                            if (marks[i] > highest_marks)
                            {
                                highest_marks = marks[i];
                                Name = name[i];
                            }
                        }
                    }
                    cout << left << setw(15) << "Name" << right << setw(10) << "Highest Marks" << endl;

                    cout << left << setw(15) << Name << right << setw(10) << highest_marks << endl;
                }

                else if (choice == "5") // Lowest Marks in a class
                {
                    string Name;
                    cout << right << setw(70) << "**************** Lowest Marks****************" << endl;
                    cout << endl;

                    for (int i = 0; i < 100; i++)
                    {
                        if (marks[i] != -1 && name[i] != "NV")
                        {
                            if (marks[i] < lowest_marks)
                            {
                                lowest_marks = marks[i];
                                Name = name[i];
                            }
                        }
                    }
                    cout << left << setw(15) << "Name" << right << setw(10) << "Lowest Marks" << endl;

                    cout << left << setw(15) << Name << right << setw(10) << lowest_marks << endl;
                }

                else if (choice == "6")
                {
                    cout << endl;
                    cout << "**************** You have Exited from the Class Statistics ****************" << endl;
                    break;
                }
                else
                {
                    cout << "Invalid Input" << endl;
                }
            }
        }

        else if (choice == "7")
        {
            cout << right << setw(70) << "****** The Program Is Closed ******" << endl;
            return 0;
        }

        else
        {
            cout << right << setw(70) << "****** Invalid Input ******" << endl;
            cout << endl;
        }
    }
}

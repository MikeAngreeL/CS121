// CS121-03 Assignment #1 
// Michael Long
// This assignment reads from an external file and translates salaries for hours worked for employees. given that they are in the same 4 line format throughout

#include <iostream>     // needed for main operations
#include <string>       // allows string operations
#include <fstream>      // allows for reading and writing from a file.
#include <iomanip>      // allows for formatting of numbers

using namespace std;

int main()
{       // beginning of main and declaration of variables 
    ifstream myfile;
    string employeeId;
    string employeeName;
    string hours;
    string pay;
    float totalpay;
    
    cout << fixed;           // sets the base for the numbers to allow precision formatting
    cout << setprecision(2); // sets the decimal count to 2 for formatting

    myfile.open("hours.txt");       // opens hours.txt to allow use of the file

    cout << "\t\t[EMPLOYEE PAYROLL FOR THE WEEK]" << endl;      //top of header
    cout << "*************************************************************************" << endl;       //serperator line
    
    while(!myfile.eof())    //loops as long as we are not at the end of the file
    {// the beginning of while loop to read through the file
        getline(myfile,employeeId);
        //cout << employeeId << endl;                   tested to see if it printed correctly
        
        getline(myfile, employeeName);
        //cout << employeeName << endl;                 tested to see if printed correctly
        
        getline(myfile, hours);
        float hoursWorked = stof(hours);                 // conversion of string to float
        
        getline(myfile, pay);
        float payForWork = stof(pay);                    // conversion of string to float
        
        totalpay = hoursWorked * payForWork;            // math to calculate total pay for the week
        //cout << totalpay; tested if pay calculation worked

        //cout << "Employee ID: " << employeeId << '\t' << "Employee Name: " << employeeName << '\t' << "Total pay: " << totalpay << endl;
        //was getting an extra line so had to add an if statement to nullify the extra line from the file.

        if(employeeId.length() != 0){
            cout << "Employee ID: " << employeeId << '\t' << "Employee Name: " << employeeName << '\t' << "Total pay: " << totalpay << endl;
        }
    }//end of while loop
   
    cout << "*************************************************************************" << endl;       //bottom seperator line

    myfile.close();     //closes the txt file.
    
    //system("pause"); //{FIXME FOR WINDOWS MACHINES}


    return 0;
}//end of main
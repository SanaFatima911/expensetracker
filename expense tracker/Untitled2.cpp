#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    double totalExpenses = 0;
    string description;
    double amount;
    int choice;
do{
    
 cout<<"Expenses Tracker"<<endl;
 cout<<"1.Add an Expense"<<endl;
 cout<<"2.View an Expenses "<<endl;
 cout<<"3.View Total Expenses"<<endl;
 cout<<"4.Exit"<<endl;
 cout<<"enter a choice"<<endl;
 cin>>choice;
 cin.ignore(); // Clear the input buffer after reading choice
 switch(choice)
 {
     
 case 1:{
    // Open the file in append mode
    ofstream file("expenses.txt", ios::app);

    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    cout << "Enter expense description: ";
    getline(cin, description);

                cout << "Enter expense amount: ";
                while (!(cin >> amount)) {
                    cin.clear(); // Clear the error flag
                    cin.ignore(1000, '\n'); // Ignore the invalid input
                    cout << "Invalid amount entered. Please enter a positive number: ";
}
   

    // Get current date and time
    time_t now = time(0);
    tm *ltm = localtime(&now);

    // Append the expense details to the file
    file << "Description: " << description << " | Amount: $" << fixed << setprecision(2) << amount 
	<< " | Date: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << " " << ltm->tm_hour
	 << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
    
    file.close();
    break;
}
case 2:
{
    // Display all recorded expenses from the file
    string line;
    ifstream readFile("expenses.txt");

    if (readFile.is_open()) {
        while (getline(readFile, line)) {
            cout << line << endl;
        }
        readFile.close();
    }
    break;
}
case 3:
{

    // Summarize total expenses from the file
    ifstream totalFile("expenses.txt");
     totalExpenses = totalExpenses+amount;
    double expense;

    while (totalFile >> description >> amount) {
        totalExpenses += amount;
    }

    cout << "Total expenses: $" << fixed << setprecision(2) << totalExpenses << endl;
break;
}
case 4:

    cout<<"Exiting "<<endl;
    break;
    default:
    cout<<"Invalid choice"<<endl;
}}while(choice!=4);
    return 0;
}

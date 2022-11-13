#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/* Step 0. */
// Read customer information from external file
// Make no changes to the following code
void ReadCustomerData(vector<string>& names, vector<string>& states, vector<double>& debt) {
    // Create Variable
    ifstream inFS;

    // Read all data from file into three parallel vectors
    try {
        // Open File
        inFS.open("CustomerData.csv");

        // Add Data From File
        for (long unsigned index = 0; index < names.size(); ++index) {
            inFS >> names.at(index); // last name
            inFS >> states.at(index); // state of residence
            inFS >> debt.at(index);   // amount of debt
        }
    } catch (string err) {
        // File Not Found
        cout << "Failed to read the data file: " << err << endl;
    }//end try-catch

    // Close File
    inFS.close();
}//end ReadCustomerData()

int main() {
    // Step 0 Variable
    int numOfCustomers = 0;
    // Step 1 Variables
    int debtLimit = 0;
    char firstLetterOfCustomerName;
    string stateAbbrev;

    // Input # of customers and create parallel vectors
    /* Type your code */
    // Get Requested Number of Customers
    cout << "How many customers are there? ";
    cin >> numOfCustomers;

    // Create Parallel Vectors
    vector<string> names(numOfCustomers);
    vector<string> states(numOfCustomers);
    vector<double> debt(numOfCustomers);

    // Fill vectors with data from another external file
    /* Type your code here */  
    // Read File Data into the Vectors
    ReadCustomerData(names, states, debt);

    /* Step 1. */
    // Input debt limit, search phrase, and state
    // Get the Debt Limit
    cout << "Enter the debt limit: ";
    cin >> debtLimit;
    // Get a Letter to Search with
    cout << "Enter a first initial to search with: ";
    cin.ignore();
    cin.get(firstLetterOfCustomerName);
    // Get a State Abbreviation
    cout << "Enter a State Abbreviation: ";
    cin.ignore();
    getline(cin, stateAbbrev);

    // Test Code to Check that Step 0 and Step 1 Works
    // cout << "\nTest Inputs: " << endl;
    // cout << "Number of Customers: " << numOfCustomers << endl;
    // cout << "Debt Limit: " << debtLimit << endl;
    // cout << "First Initial Letter: " << firstLetterOfCustomerName << endl;
    // cout << "State Abbreviation: " << stateAbbrev << endl;


   return 0;
}//end main()

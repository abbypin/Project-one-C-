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
        inFS.open("CustomerData.numbers");

        // Add Data From File
        for (long unsigned index = 0; index < names.size(); ++index) {
            inFS >> names.at(index); // last name
            inFS >> states.at(index); // state of residence
            inFS >> debt.at(index);   // amount of debt
        }//end for-loop
    } catch (string err) {
        // File Not Found
        cout << "Failed to read the data file: " << err << endl;
    }//end try-catch

    // Close File
    inFS.close();
}//end ReadCustomerData()

void printInputs(int &numOfCustomers, int &debtLimit, char &firstLetterOfCustomerName, string &stateAbbrev) {
    cout << "\nTest Inputs: " << endl;
    cout << "Number of Customers: " << numOfCustomers << endl;
    cout << "Debt Limit: " << debtLimit << endl;
    cout << "First Initial Letter: " << firstLetterOfCustomerName << endl;
    cout << "State Abbreviation: " << stateAbbrev << endl;
}//end printInputs()

/* Step 2. */
// Get Customer with Highest Debt
void printNameWithMaxDebt(vector<double> &debt, vector<string> &names, int numOfCustomers) {
    // Step 2 Variables
    string name = names[0];
    double maxDebt = debt[0];

    // Loop through Debt and Names to find the Customer with the Highest Debt
    for (unsigned long i = 1; i < numOfCustomers; i++) {
        if (maxDebt < debt[i]) {
            maxDebt = debt[i];
            name = names[i];
        }//end if
    }//end for-loop

    // Output
    cout << "U.S. Report" << endl;// Report Header
    cout << "Customers: " << numOfCustomers << endl;
    cout << "Highest Debt: " << name << endl;
}//end printNameWithMaxDebt()

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
    //printInputs(numOfCustomers, debtLimit, firstLetterOfCustomerName, stateAbbrev);

    /* Step 2. */
    printNameWithMaxDebt(debt, names, numOfCustomers);

   return 0;
}//end main()

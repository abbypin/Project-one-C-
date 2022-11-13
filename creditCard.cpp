#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

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
    int numOfCustomers = 0;
    // Input # of customers and create parallel vectors
    /* Type your code */
    
    // Get Requested Number of Customers
    cout << "How many customers are there?" << endl;
    cin >> numOfCustomers;
    // Create Parallel Vectors
    vector<string> names(numOfCustomers);
    vector<string> states(numOfCustomers);
    vector<double> debt(numOfCustomers);

    // Fill vectors with data from another external file
    /* Type your code here */  
    // Read File Data into the Vectors
    ReadCustomerData(names, states, debt);

   // Input debt limit, search phrase, and state



   return 0;
}//end main()

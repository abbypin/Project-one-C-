#include <iostream>
#include <string>
using namespace std;

int main() {
    /* STEP 0. Variables */
    const int ROCK = 0;
    const int PAPER = 1;
    const int SCISSORS = 2;
    /* STEP 1. Variables */
    string name1;
    string name2;
    int rounds;

    /* Step 0. */ 
    int seed;
    cin >> seed;
    srand(seed);

    /* Type your code here. */
    /* STEP 1. */
    // Input Setup Game
    cin >> name1;
    cin >> name2;
    cin >> rounds;
    // Check Rounds
    while (rounds < 0) {
        cout << "Rounds must be > 0" << endl;
        cin >> rounds;
    }//end while-loop

    // Print Beginning Message
    cout << name1 << " vs " << name2 << " for " << rounds << " rounds" << endl;

    return 0;
}
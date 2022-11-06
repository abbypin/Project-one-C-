#include <iostream>
#include <string>
using namespace std;

/* STEP 2. */
// Generate Random Number 0-2
int weapon() {
    return rand() % 3;
}//end weapon

bool tie(int rand1, int rand2) {
    bool isTie = false;
    if (rand1 == rand2) {
        cout << "Tie" << endl;
        isTie = true;
        cout << "Anna: " << rand1 << " Bert: " << rand2 << endl;
    } else {
        cout << "Else: Anna: " << rand1 << " Bert: " << rand2 << endl;
    }//end if
    return isTie;
}//end tie()

int main() {
    /* STEP 0. Variables */
    const int ROCK = 0;
    const int PAPER = 1;
    const int SCISSORS = 2;
    /* STEP 1. Variables */
    string name1;
    string name2;
    int rounds;
    /* STEP 2. Variables */


    /* Step 0. */ 
    int seed;
    cin >> seed;
    // Setup Random Number
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

    /* STEP 2. */
    // Tie Status
    bool isTie = false;
    do {
        isTie = tie(weapon(), weapon());
    } while (isTie);

    return 0;
}
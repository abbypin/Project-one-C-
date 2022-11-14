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
        //cout << "Anna: " << rand1 << " Bert: " << rand2 << endl;
    } //else {
        //cout << "Else: Anna: " << rand1 << " Bert: " << rand2 << endl;
    //}//end if
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
    /* STEP 3. Variables */
    int rand1;
    int rand2;
    /* STEP 4. Variables */
    int totalWins1 = 0;
    int totalWins2 = 0;

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

    for (int i = 0; i < rounds; i++) {
        /* STEP 2. */
        // Tie Status
        bool isTie = false;
        do {
            rand1 = weapon();
            rand2 = weapon();
            isTie = tie(rand1, rand2);
        } while (isTie);

        /* STEP 3. */
        // Print Result
        if (rand1 == ROCK && rand2 == SCISSORS) {
            cout << name1 << " wins with rock" << endl;
            totalWins1++;
        } else if (rand1 == SCISSORS && rand2 == PAPER) {
            cout << name1 << " wins with rock" << endl;
            totalWins1++;
        } else if (rand1 == PAPER && rand2 == ROCK) {
            cout << name1 << " wins with paper" << endl;
            totalWins1++;
        }//end else-if
        if (rand2 == ROCK && rand1 == SCISSORS) {
            cout << name2 << " wins with rock" << endl;
            totalWins2++;
        } else if (rand2 == SCISSORS && rand1 == PAPER) {
            cout << name2 << " wins with rock" << endl;
            totalWins2++;
        } else if (rand2 == PAPER && rand1 == ROCK) {
            cout << name2 << " wins with paper" << endl;
            totalWins2++;
        }//end else-if
    }//end for-loop
    
    if (totalWins1 > totalWins2) {
        cout << name1 << " wins " << totalWins1 << " and " << name2 << " wins " << totalWins2 << endl;
    } else if (totalWins1 < totalWins2) {
        cout << name2 << " wins " << totalWins2 << " and " << name1 << " wins " << totalWins1 << endl;
    } else if (totalWins1 == totalWins2) {
        cout << name1 << " wins " << totalWins1 << " and " << name2 << " wins " << totalWins2 << endl;
    } else {
        cout << name1 << " wins " << totalWins1 << " and " << name2 << " wins " << totalWins2 << endl;
    }//end else-if

    return 0;
}
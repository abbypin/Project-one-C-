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
    /* STEP 2. Variables */
    int rand1;
    int rand2;

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
    // Generate Round One with Tie Status
    do {
        // Generate Two Random Numbers 0-2
        rand1 = rand() % 3;
        rand2 = rand() % 3;
        // Print Tie result
        if (rand1 == rand2) {
            cout << "Tie" << endl;
        }//end if  
    } while (rand1 == rand2);//end do-while
    
    if (rand1 == ROCK && rand2 == SCISSORS) {
        cout << name1 << " wins with rock" << endl;
    } else if (rand1 == SCISSORS && rand2 == PAPER) {
        cout << name1 << " wins with scissors" << endl;
    } else if (rand1 == PAPER && rand2 == ROCK) {
        cout << name1 << " wins with paper" << endl;
    } else if (rand2 == ROCK && rand1 == SCISSORS) {
        cout << name2 << " wins with rock" << endl;
    } else if (rand2 == SCISSORS && rand1 == PAPER) {
        cout << name2 << " wins with scissors" << endl;
    } else if (rand2 == PAPER && rand1 == ROCK) {
        cout << name2 << " wins with paper" << endl;
    } else {
        cout << "An error occured." << endl;
    }//end else-if

    return 0;
}
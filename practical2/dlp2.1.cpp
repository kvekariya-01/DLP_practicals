
#include<iostream>
using namespace std;

bool isFinalState(int currentState, int finalStates[], int numFinalStates) {
    for (int i = 0; i < numFinalStates; ++i) {
        if (currentState == finalStates[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    int numStates, initialState, numFinalStates;
    int finalStates[10];
    int transitions[10][128];

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 128; ++j) {
            transitions[i][j] = -1;
        }
    }

    cout << "Enter the number of states: ";
    cin >> numStates;

    cout << "Enter the initial state: ";
    cin >> initialState;

    cout << "Enter the number of final states: ";
    cin >> numFinalStates;

    cout << "Enter the final states: ";
    for (int i = 0; i < numFinalStates; ++i) {
        cin >> finalStates[i];
    }

    int numTransitions;
    cout << "Enter the number of transitions: ";
    cin >> numTransitions;
    cout << "Enter transitions (current_state input_symbol next_state):\n";
    for (int i = 0; i < numTransitions; ++i) {
        int currentState, nextState;
        char inputSymbol;
        cin >> currentState >> inputSymbol >> nextState;
        transitions[currentState][(int)inputSymbol] = nextState;
    }

    string input;
    cout << "Enter the input string: ";
    cin >> input;

    int currentState = initialState;
    for (char symbol : input) {
        currentState = transitions[currentState][(int)symbol];
        if (currentState == -1) {
            cout << "Rejected\n";
            return 0;
        }
    }


    if (isFinalState(currentState, finalStates, numFinalStates)) {
        cout << "Accepted\n";
    } else {
        cout << "Rejected\n";
    }

    return 0;
}


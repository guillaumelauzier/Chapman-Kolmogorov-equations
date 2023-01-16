# Chapman-Kolmogorov-equations

The Chapman-Kolmogorov equations are a set of recursive equations used to find the probability of being in a certain state at a certain time, given the initial state. The equations are given by:

P(X(t) = i | X(0) = j) = sum over k of [P(X(t) = i | X(t-1) = k) * P(X(t-1) = k | X(0) = j)]

where P is the probability of being in state i at time t, given that the initial state is j and X(t) is the state of the Markov chain at time t. The sum is taken over all possible states k.

In C++, the Chapman-Kolmogorov equations can be implemented using a nested loop to iterate over the states and calculate the probability at each time step. Here's an example of how to use the Chapman-Kolmogorov equations in C++:

```
#include <iostream>
using namespace std;

const int N = 3; // Number of states
const int T = 2; // Number of time steps

double transitionMatrix[N][N] = {
    {0.7, 0.2, 0.1},
    {0.1, 0.6, 0.3},
    {0.2, 0.3, 0.5}
};

int main() {
    double probability[N][T+1];
    int initialState = 0; // initial state
    int finalState = 2; // final state
    int time = 2; // time
    // Initialize the probability of being in the initial state
    for (int i = 0; i < N; i++) {
        probability[i][0] = (i == initialState) ? 1 : 0;
    }
    // Iterate over time steps
    for (int t = 1; t <= T; t++) {
        // Iterate over states
        for (int i = 0; i < N; i++) {
            double sum = 0;
            // Iterate over possible previous states
            for (int k = 0; k < N; k++) {
                sum += transitionMatrix[i][k] * probability[k][t-1];
            }
            probability[i][t] = sum;
        }
    }
    // The probability of being in the final state at the given time
    double result = probability[finalState][time];
    cout << "Probability of being in state " << finalState << " at time " << time << ": " << result << endl;
    return 0;
}


```

This code defines a transition matrix with 3 states and 2 time steps, and uses the Chapman-Kolmogorov equations to calculate the probability of being in a specific state at a specific time, given an initial state. The nested loops iterate over the states and time steps and calculate the probability at each step. The result is stored in the probability array and the final result is printed out in the end.

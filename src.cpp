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

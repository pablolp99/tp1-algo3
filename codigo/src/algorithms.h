#include <vector>
#include <array>

using namespace std;

// Brute Force algorithm
// Parametres:
//      cinta& c => Elements available (reference)
//      int
int brute_force(vector<array<int, 2>>& tape, int elems, int resistance, int partial_weight);

// Backtracking algorithm
// Same params as BF bc idk backtacking yet
//int backtracking(int c[], int i, int p, int k);

// Dynamic Programming algorithm
//int dynamic_programming();
#include <vector>

typedef std::vector<std::vector<int>> cinta;

// Brute Force algorithm
// Parametres:
//      cinta& c => Elements available (reference)
//      int
int brute_force(cinta& c, int i, int p, int k);

// Backtracking algorithm
// Same params as BF bc idk backtacking yet
int backtracking(cinta& c, int i, int p, int k);

// Dynamic Programming algorithm
int dynamic_programming();
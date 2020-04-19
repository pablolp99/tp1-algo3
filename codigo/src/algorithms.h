#include <vector>
#include <array>

#define WGH_INDEX 0
#define RES_INDEX 1

using namespace std;

/* Cinta
    < [weight , resistance]_0,
        ...
      [weight , resistance]_i >
*/

/* Brute Force algorithm
    Parametros:
        cinta         => La cinta
        resistencia   => Resistencia de la Bolsa
        cur_elem      => i-esimo elemento a ver
        res_vect      => Vector de resistencias resultante por elemento

    Complejidad O(n x 2^n)
*/
int brute_force(vector<array<int, 2>>& tape, int resistance, int cur_elem, vector<int> res_vect);

// Backtracking algorithm
// Same params as BF bc idk backtacking yet
//int backtracking(int c[], int i, int p, int k);

// Dynamic Programming algorithm
//int dynamic_programming();
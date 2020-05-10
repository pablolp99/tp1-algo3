#include <vector>
#include <array>
#include <string.h>

#define WGH_INDEX 0
#define RES_INDEX 1
#define MENOS_INFINITO -999999999

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



int brute_force(vector<array<int, 2>>& tape, int resistance, int cur_elem, int cant_elem);

// Backtracking algorithm
// Same params as BF bc idk backtacking yet
int backtracking_factibilidad(vector<array<int, 2>>& tape, int resistance, int cur_elem, int cant_elem);

int backtracking_optimalidad(vector<array<int, 2>>& tape, int resistance, int cur_elem, int cant_elem);

// Dynamic Programming algorithm
int dynamic_programming_noFuncional(vector<array<int, 2>>& tape, int resistance);

int dynamic_programming(vector<array<int, 2>>& tape, int resistance);
int dynamic_programming_td(vector<array<int, 2>>& tape, int resistance);
int _dynamic_programming_td(vector<array<int, 2>>& tape, vector<vector<int>>& m, int R, int cur_elem);
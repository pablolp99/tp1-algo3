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

int FB(vector<array<int, 2>>& tape, int resistance, int cur_elem, int cant_elem);
// Backtracking algorithm
// Same params as BF bc idk backtacking yet
int BTF(vector<array<int, 2>>& tape, int resistance, int cur_elem, int cant_elem);
int BTO(vector<array<int, 2>>& tape, int resistance, int cur_elem, int cant_elem);
int PD(vector<array<int, 2>>& tape, int resistance);
int _PD(vector<array<int, 2>>& tape, vector<vector<int>>& m, int R, int cur_elem);
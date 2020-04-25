#include <bits/stdc++.h>
//#include <iostream>
#include "src/algorithms.h"
#include <vector>
#include <array>

using namespace std;

void get_tape(vector<array<int, 2>>& tape, int ec){
    for(int i = 0; i < ec; ++i){
        int temp_weight, temp_resistance;
        cin >> temp_weight >> temp_resistance;
        array<int, 2> temp = {temp_weight, temp_resistance};
        tape.push_back(temp);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int elem_count, resistance;
    cin >> elem_count >> resistance;

    vector<array<int, 2>> tape;
    get_tape(tape, elem_count);

    vector<int> res_vect;
    int res = brute_force(tape, resistance, 0, res_vect);
    cout << "BruteForce: " << res << endl;
    res = 0;
    res = backtracking_factibilidad(tape, resistance, 0, res_vect);
    cout << "BT Fact: " << res << endl;
    res = 0;
    res = backtracking_optimalidad(tape, resistance, 0, res_vect);
    cout << "BT Optim: " << res << endl;
    res = 0;
    res = backtracking_optimalidad(tape, resistance, 0, res_vect);
    cout << "BT Optim: " << res << endl;
    res = 0;
    res = dynamic_programming(tape, resistance);
    cout << "DP: " << res << endl;
    return 0;
}
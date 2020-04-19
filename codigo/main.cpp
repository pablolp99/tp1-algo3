#include <bits/stdc++.h>
//#include <iostream>
#include "src/algorithms.h"

using namespace std;

void get_tape(int **param, int ec){
    for(int i = 0; i < ec; ++i){
        int temp_weight, temp_resistance;
        cin >> temp_weight >> temp_resistance;
        param[i] = new int [2];
        param[i][0] = temp_weight;
        param[i][1] = temp_resistance;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int elem_count, resistance;
    cin >> elem_count >> resistance;

    int **tape;
    tape = new int *[elem_count];
    get_tape(tape, elem_count);

    brute_force(tape, elem_count, resistance, 0);

    return 0;
}
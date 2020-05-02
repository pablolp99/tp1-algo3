#include <array>
#include <bits/stdc++.h>
#include <chrono>
#include <iostream>
#include <fstream>
#include "src/algorithms.h"
#include <vector>

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
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int tests;
    cin >> tests;
    for (int j=0; j < tests; ++j){
        int elem_count, resistance;
        cin >> elem_count >> resistance;

        vector<array<int, 2>> tape;
        get_tape(tape, elem_count);
        vector<int> res_vect;

        auto t1 = chrono::high_resolution_clock::now();
        int r = brute_force(tape, resistance, 0, 0);
//        int r = backtracking_factibilidad(tape, resistance, 0, 0);
//        int r = backtracking_optimalidad(tape, resistance, 0, 0);
//        int r = dynamic_programming(tape, resistance);
        auto t2 = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
        cout << tape.size() << " " << resistance << " " << r << " " << duration << endl;
    }


//    res = 0;
//    t1 = chrono::high_resolution_clock::now();
//    res = backtracking_factibilidad(tape, resistance, 0, 0);
//    t2 = chrono::high_resolution_clock::now();
//    duration = chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
//    cout << "BT Fact: " << res << endl;
//    cout << duration << endl;
//
//    res = 0;
//    t1 = chrono::high_resolution_clock::now();
//    res = backtracking_optimalidad(tape, resistance, 0, 0);
//    t2 = chrono::high_resolution_clock::now();
//    duration = chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
//    cout << "BT Optim: " << res << endl;
//    cout << duration << endl;
//
//    res = 0;
//    res = dynamic_programming(tape, resistance);
//    cout << "DP: " << res << endl;
    return 0;
}

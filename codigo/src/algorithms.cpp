#include "algorithms.h"
#include <vector>
#include <array>

using namespace std;


int brute_force(vector<array<int, 2>>& tape, int resistance, int cur_elem, vector<int> res_vect){
    if(cur_elem == tape.size()-1){
        for(int i = 0; i < res_vect.size(); ++i){
            res_vect[i]-=tape[cur_elem][WGH_INDEX];
            if(res_vect[i]<0){ // aca hay que ver si no se rompe el vector res_vect
                return resistance >= 0 ? res_vect.size() : 0;
            }
        }
        return resistance - tape[cur_elem][WGH_INDEX] >= 0 ? res_vect.size() + 1 : 0;
    } else {
        int dont_add_elem = brute_force(tape, resistance, cur_elem+1, res_vect);

        for(int i = 0; i < res_vect.size(); ++i){
            res_vect[i]-=tape[cur_elem][WGH_INDEX];
        }
        res_vect.push_back(tape[cur_elem][RES_INDEX]);

        int add_elem = brute_force(tape, resistance-tape[cur_elem][WGH_INDEX], cur_elem+1, res_vect);
        return max(add_elem, dont_add_elem);
    }
}

int backtracking_factibilidad(vector<array<int, 2>>& tape, int resistance, int cur_elem, vector<int> res_vect){
    if(cur_elem == tape.size()-1){
        for(int i = 0; i < res_vect.size(); ++i){
            res_vect[i]-=tape[cur_elem][WGH_INDEX];
            if(res_vect[i]<0){ // aca hay que ver si no se rompe el vector res_vect
                return resistance >= 0 ? res_vect.size() : 0;
            }
        }
        return resistance - tape[cur_elem][WGH_INDEX] >= 0 ? res_vect.size() + 1 : 0;
    } else {
        int dont_add_elem = backtracking_factibilidad(tape, resistance, cur_elem+1, res_vect);

        for(int i = 0; i < res_vect.size(); ++i){
            res_vect[i]-=tape[cur_elem][WGH_INDEX];
            // Factibilidad
            if(res_vect[i] < 0 || resistance < 0) {
                return 0;
            }
        }
        res_vect.push_back(tape[cur_elem][RES_INDEX]);

        int add_elem = backtracking_factibilidad(tape, resistance-tape[cur_elem][WGH_INDEX], cur_elem+1, res_vect);
        return max(add_elem, dont_add_elem);
    }
}

int MAX_SOLUTION = 0;

int backtracking_optimalidad(vector<array<int, 2>>& tape, int resistance, int cur_elem, vector<int> res_vect){
    if(cur_elem == tape.size()-1){
        for(int i = 0; i < res_vect.size(); ++i){
            res_vect[i]-=tape[cur_elem][WGH_INDEX];
            if(res_vect[i]<0){ // aca hay que ver si no se rompe el vector res_vect
                return resistance >= 0 ? res_vect.size() : 0;
            }
        }
        return resistance - tape[cur_elem][WGH_INDEX] >= 0 ? res_vect.size() + 1 : 0;
    } else {
        // Optimalidad
        if(res_vect.size() + (tape.size()-cur_elem) <= MAX_SOLUTION){
            // calculo si agregando los 2 ult elementos superaria mi maximo
            return 0;
        }

        int dont_add_elem = backtracking_factibilidad(tape, resistance, cur_elem+1, res_vect);

        for(int i = 0; i < res_vect.size(); ++i){
            res_vect[i]-=tape[cur_elem][WGH_INDEX];
            if(res_vect[i] < 0 || resistance < 0) {
                return 0;
            }
        }

        ++MAX_SOLUTION;
        res_vect.push_back(tape[cur_elem][RES_INDEX]);

        int add_elem = backtracking_factibilidad(tape, resistance-tape[cur_elem][WGH_INDEX], cur_elem+1, res_vect);
        return max(add_elem, dont_add_elem);
    }
}
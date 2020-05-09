#include "algorithms.h"
#include <vector>
#include <array>

using namespace std;


int brute_force(vector<array<int, 2>>& tape, int resistance, int cur_elem, int cant_elem){
    if(cur_elem == tape.size()) {
        if (resistance < 0){
            return 0;
        }
        return cant_elem;
    } else {
        return max(brute_force(tape, min(resistance-tape[cur_elem][WGH_INDEX], tape[cur_elem][RES_INDEX]), cur_elem+1, cant_elem+1),
                   brute_force(tape, resistance, cur_elem+1, cant_elem));
    }
}

int backtracking_factibilidad(vector<array<int, 2>>& tape, int resistance, int cur_elem, int cant_elem){
    if(cur_elem == tape.size()){
        if (resistance < 0){
            return 0;
        }
        return cant_elem;
    } else {
        // Si la resistencia sin agregar el elemento se rompe, entonces este camino no es factible
        if (resistance < 0) {
            return 0;
        }
        return max(backtracking_factibilidad(tape, resistance, cur_elem+1, cant_elem),
                   backtracking_factibilidad(tape, min(resistance-tape[cur_elem][WGH_INDEX], tape[cur_elem][RES_INDEX]), cur_elem+1, cant_elem+1));
    }
}

int MAX_SOLUTION = 0;

int backtracking_optimalidad(vector<array<int, 2>>& tape, int resistance, int cur_elem, int cant_elem){
    if(cur_elem == tape.size()){
        if (resistance < 0){
            return 0;
        }
        return cant_elem;
    } else {
        if (cur_elem == 0){
            MAX_SOLUTION = 0;
        }
        // Si la resistencia sin agregar el elemento se rompe, entonces este camino no es factible
        if(resistance < 0) {
            return 0;
        }

        MAX_SOLUTION = MAX_SOLUTION > cant_elem ? MAX_SOLUTION : cant_elem;
        // Optimalidad
        if(cant_elem + (tape.size()-cur_elem) <= MAX_SOLUTION){
            // calculo si agregando los elementos hasta el final superaria mi maximo
            // En caso negativo, significa que no encontrare una solucion mejor a la que ya tengo
            return 0;
        }
        return max(backtracking_optimalidad(tape, resistance, cur_elem+1, cant_elem),
                   backtracking_optimalidad(tape, min(resistance-tape[cur_elem][WGH_INDEX], tape[cur_elem][RES_INDEX]), cur_elem+1, cant_elem+1));
    }
}

int dynamic_programming_td(vector<array<int, 2>>& tape, int resistance) {
//    vector<vector<int>> m(tape.size() + 1, vector<int>(resistance + 1, -1));
    vector<vector<int>> m(tape.size(), vector<int>(resistance+1, -1));
//    int tmp = _dynamic_programming_td(tape, m, resistance, 0, resistance);
    int tmp = _dynamic_programming_td_bis(tape, m, resistance, 0);
    return tmp;
}

//int _dynamic_programming_td(vector<array<int, 2>>& tape, vector<vector<int>>& m , int R, int cur_elem, int min_res){
//    if(R<0) return MENOS_INFINITO;
//    if(min_res<0) return MENOS_INFINITO;
//    if(cur_elem==tape.size()) return 0;
//    if(m[cur_elem][R]==-1) m[cur_elem][R] = max(_dynamic_programming_td(tape, m, R, cur_elem+1, min_res),
//                                               1+_dynamic_programming_td(tape, m, R-tape[cur_elem][WGH_INDEX], cur_elem+1, min(min_res-tape[cur_elem][WGH_INDEX], tape[cur_elem][RES_INDEX])));
//    return m[cur_elem][R];
//}


int _dynamic_programming_td_bis(vector<array<int, 2>>& tape, vector<vector<int>>& m , int R, int cur_elem){
    if(R<0) return MENOS_INFINITO;
    if(cur_elem==tape.size()) return 0;
    if(m[cur_elem][R]==-1) m[cur_elem][R] = max(_dynamic_programming_td_bis(tape, m, R, cur_elem+1),
                                                1+_dynamic_programming_td_bis(tape, m, min(R-tape[cur_elem][WGH_INDEX], tape[cur_elem][RES_INDEX]), cur_elem+1));
    return m[cur_elem][R];
}
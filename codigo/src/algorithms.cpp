#include "algorithms.h"
#include <vector>
#include <array>

using namespace std;


int FB(vector<array<int, 2>>& tape, int resistance, int cur_elem, int cant_elem){
    if(cur_elem == tape.size()) {
        if (resistance < 0){
            return 0;
        }
        return cant_elem;
    } else {
        return max(FB(tape, min(resistance-tape[cur_elem][WGH_INDEX], tape[cur_elem][RES_INDEX]), cur_elem+1, cant_elem+1),
                   FB(tape, resistance, cur_elem+1, cant_elem));
    }
}

int BTF(vector<array<int, 2>>& tape, int resistance, int cur_elem, int cant_elem){
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
        return max(BTF(tape, resistance, cur_elem+1, cant_elem),
                   BTF(tape, min(resistance-tape[cur_elem][WGH_INDEX], tape[cur_elem][RES_INDEX]), cur_elem+1, cant_elem+1));
    }
}

int MAX_SOLUTION = 0;

int BTO(vector<array<int, 2>>& tape, int resistance, int cur_elem, int cant_elem){
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
//        return max(BTO(tape, resistance, cur_elem+1, cant_elem),
//                   BTO(tape, min(resistance-tape[cur_elem][WGH_INDEX], tape[cur_elem][RES_INDEX]), cur_elem+1, cant_elem+1));
        return max(BTO(tape, min(resistance-tape[cur_elem][WGH_INDEX], tape[cur_elem][RES_INDEX]), cur_elem+1, cant_elem+1),
                   BTO(tape, resistance, cur_elem+1, cant_elem));

    }
}

int PD(vector<array<int, 2>>& tape, int resistance) {
    vector<vector<int>> m(tape.size(), vector<int>(resistance+1, -1));
    int tmp = _PD(tape, m, resistance, 0);
    return tmp;
}

int _PD(vector<array<int, 2>>& tape, vector<vector<int>>& m , int R, int cur_elem){
    if(R<0) return MENOS_INFINITO;
    if(cur_elem==tape.size()) return 0;
    if(m[cur_elem][R]==-1) m[cur_elem][R] = max(_PD(tape, m, R, cur_elem+1),
                                                1+_PD(tape, m, min(R-tape[cur_elem][WGH_INDEX], tape[cur_elem][RES_INDEX]), cur_elem+1));
    return m[cur_elem][R];
}
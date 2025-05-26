#include "edit_distance_recursive.h"

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int editDistanceRecursive(const string& S, const string& T, int i, int j) {
    if (i == 0) return j;
    if (j == 0) return i;
    
    if (S[i-1] == T[j-1]) {
        return editDistanceRecursive(S, T, i-1, j-1);
    }
    
    return 1 + min(
        editDistanceRecursive(S, T, i-1, j),   // Borrar
        editDistanceRecursive(S, T, i, j-1)    // Insertar
    );
}

int editDistanceRecursive(const string& S, const string& T) {
    return editDistanceRecursive(S, T, S.length(), T.length());
}
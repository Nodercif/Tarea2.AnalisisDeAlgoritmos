#include <iostream>
#include <vector>
#include <string>
using namespace std;

int editDistanceDP(const string& S, const string& T) {
    int n = S.length();
    int m = T.length();

    // Aseguramos que T sea la cadena más corta para usar menos espacio
    if (m > n) return editDistanceDP(T, S);

    vector<int> prev(m + 1), curr(m + 1);

    // Inicializar la primera fila
    for (int j = 0; j <= m; ++j)
        prev[j] = j;

    for (int i = 1; i <= n; ++i) {
        curr[0] = i;
        for (int j = 1; j <= m; ++j) {
            if (S[i - 1] == T[j - 1]) {
                curr[j] = prev[j - 1];  // sin operación
            } else {
                curr[j] = 1 + min(prev[j], curr[j - 1]);  // borrar o insertar
            }
        }
        swap(prev, curr);  // avanzar fila
    }

    return prev[m];
}

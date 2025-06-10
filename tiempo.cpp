#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>  // std::accumulate
#include <string>
#include <algorithm>
#include <fstream>  // Para escribir en archivos
#include <sstream>
#include "edit_distance_memo.h"
#include "edit_distance_recursive.h"
#include "edit_distance_DP.h"
#include "edit_distance_DP_optimized.h"

using namespace std;

//EDIT DISTANCE MEMO
/*int editDistanceMemo(const string& S, const string& T, int i, int j, vector <vector<int>>& memo){

    //Si ya se calculo, lo devolvemos
    if(memo[i][j] != -1){
        return memo[i][j];
    }

    //Caso base
    if(i == 0){
        return memo[i][j] = j;
    }
    if(j == 0){
        return memo[i][j] = i;
    }

    //Si los caracteres finales coinciden continuamos
    if(S[i-1] == T[j-1]){
        return memo[i][j] = editDistanceMemo(S,T,i-1,j-1,memo);
    }

    //Si no coinciden probamos borrando e insertando
    return memo[i][j] = 1 + min(
        editDistanceMemo(S,T,i-1,j,memo),   //Borrar
        editDistanceMemo(S,T,i,j-1,memo)    //insertar
    );
}

int editDistanceMemo(const string& S, const string& T){

    int n = S.length(), m = T.length();

    //Tabla de memoria con -1 de valor inicial
    vector<vector<int>> memo(n+1, vector<int>(m+1,-1));

    return editDistanceMemo(S,T,n,m,memo);

}*/

//EDIT DISTANCE DP
/*int EditDistanceDeleteInsertDP(const std::string& S, const std::string& T) {
    int m = S.length();
    int n = T.length();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));  // creamos la tabla DP

    // Caso base: convertir S[0..i-1] a cadena vacía requiere i eliminaciones
    for (int i = 0; i <= m; ++i)
        dp[i][0] = i;

    // Caso base: convertir cadena vacía a T[0..j-1] requiere j inserciones
    for (int j = 0; j <= n; ++j)
        dp[0][j] = j;

    // Rellenar tabla DP
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (S[i - 1] == T[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];  // Si los caracteres son iguales, no hacemos ninguna operación
            } else {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + 1;  // definimos como dp[i][j] como el mínimo entre eliminar S[i-1] o insertar T[j-1] (+1)
            }
        }
    }

    return dp[m][n];  // entrega la tabla de número de operaciones necesarias para convertir S en T
}*/

//EDIT DISTANCE DP OPTIMIZED
/*int EditDistanceDeleteInsertDPoptimized(const std::string& S, const std::string& T) {
    int m = S.length(), n = T.length();
    std::vector<int> prev(n + 1), curr(n + 1);

    for (int j = 0; j <= n; ++j)
        prev[j] = j;

    for (int i = 1; i <= m; ++i) {
        curr[0] = i;  
        for (int j = 1; j <= n; ++j) {
            if (S[i - 1] == T[j - 1]) {
                curr[j] = prev[j - 1];  
            } else {
                curr[j] = std::min(prev[j], curr[j - 1]) + 1; 
            }
        }
        std::swap(prev, curr);
    }

    return prev[n];
}*/

std::string leerArchivoComoString(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    std::stringstream buffer;
    buffer << archivo.rdbuf();
    return buffer.str();
}

int main() {
    using namespace std;
    using namespace std::chrono;

    string textoA = leerArchivoComoString("texto1.txt");
    string textoB = leerArchivoComoString("texto2.txt"); 
    int r;

    const int repeticiones = 10;
    vector<long long> tiempos_ns;

    ofstream archivo("tiempos.csv", ios::app);  // 'app' = append
    archivo << "Ejecución | Tiempo (ns)\n";  // Encabezado CSV

    for (int i = 0; i < repeticiones; ++i) {
        auto inicio = high_resolution_clock::now();

        // Llamada al algoritmo que quieres medir:
        //r = editDistanceMemo(textoA,textoB);
        //r = EditDistanceDeleteInsertDP(textoA,textoB);
        //r = EditDistanceDeleteInsertDPoptimized(textoA,textoB);

        auto fin = high_resolution_clock::now();
        auto duracion = duration_cast<nanoseconds>(fin - inicio).count();
        tiempos_ns.push_back(duracion);
        archivo << i + 1 << " | " << duracion << "\n";  // Guardar en CSV
    }

    archivo.close();  // Cerrar el archivo

    // Calcular y mostrar promedio
    long long suma = accumulate(tiempos_ns.begin(), tiempos_ns.end(), 0LL);
    double promedio = static_cast<double>(suma) / repeticiones;
    cout << r << endl;
    cout << "Tiempo promedio de ejecución: " << promedio << " ns" << endl;

    return 0;
}

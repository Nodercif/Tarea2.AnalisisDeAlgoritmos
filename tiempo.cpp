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
        //r = editDistanceDP(textoA,textoB);
        //r = editDistanceDPOptimized(textoA,textoB);

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

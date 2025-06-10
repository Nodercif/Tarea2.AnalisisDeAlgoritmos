Este proyecto implementa distintos algoritmos para la implementación del problema Delete Insert Edit Distance.

## Archivos importantes
-"edit_distance_recursive.cpp"
-"edit_distance_memo.cpp"
-"edit_distance_DP.cpp"
-"dit_distance_DP_optimized.cpp"
-"tiempo.cpp" (Archivo principal)

## Pasos para ejecutar

0. **Es necesario tener dos archicos archivos .txt que contengan las lineas de texto que se quiera comparar**
        - Deben llevar por nombre "tenxto1.txt" y "texto2.txt"
    
    1. **Abrir "tiempo.cpp"**
        - Desplazarse hatsa la sección **"FUNCIONES"**.
        - Quitar el comentario a la función que desee probar ("editDistanceRecursive","editDistanceMemo","editDistanceDP" y "editDistanceDPOptimized").
        - **Solo una función debe estar sin comentar** para evitar conflictos.

    2. **Guardar los cambios**  
        - Una vez haya seleccionado la función, guarde el archivo "tiempo.cpp".

   3. **Compilación de archivos**
        - Abra una terminal en WSL y navegue hasta la carpeta del proyecto.
        - Ejecute el siguiente comando para compilar:

        g++ -std=c++11 tiempo.cpp edit_distance_memo.cpp edit_distance_recursive.cpp edit_distance_DP.cpp edit_distance_DP_optimized.cpp -o "Nombre del ejecutable"

    4. **Ejecutar el programa**
        - Una vez compilado, corra el siguiente comando para ejecutar:

            ./"Nombre del ejecutable"

    ## Notas
        - El programa generara un un archivo llamado "tiempos.csv", que llevará el registro de los tiempos que tardó la función probada
        - Asegúrese de tener `g++` instalado en su WSL. Si no lo tiene, instálelo con:

        sudo apt update && sudo apt install g++

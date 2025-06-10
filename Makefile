# Nombre del compilador
CXX = g++

# Flags de compilación
CXXFLAGS = -std=c++17 -Wall -O2

# Archivos fuente
SRC = tiempo.cpp \
      edit_distance_DP.cpp \
      edit_distance_DP_optimized.cpp \
      edit_distance_memo.cpp \
      edit_distance_recursive.cpp

# Archivos de cabecera (solo para referencia)
HEADERS = edit_distance_DP.h \
          edit_distance_DP_optimized.h \
          edit_distance_memo.h \
          edit_distance_recursive.h

# Nombre del ejecutable
TARGET = experimento

# Regla por defecto
all: $(TARGET)

# Cómo compilar el ejecutable
$(TARGET): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Limpiar archivos generados
clean:
	rm -f $(TARGET) *.o tiempos.csv

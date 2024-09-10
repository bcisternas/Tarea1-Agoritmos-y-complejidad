# Variables
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
OBJFILES = main.o algoritmos/selectionSort.o algoritmos/mergeSort.o algoritmos/quickSort.o
TARGET = sort_programa

# Regla por defecto para construir el programa
all: $(TARGET)

# Regla para construir el ejecutable
$(TARGET): $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJFILES)

# Reglas para compilar los archivos .cpp en archivos .o
main.o: main.cpp algoritmos/sortAlgorithms.h
	$(CXX) $(CXXFLAGS) -c main.cpp

algoritmos/selectionSort.o: algoritmos/selectionSort.cpp algoritmos/sortAlgorithms.h
	$(CXX) $(CXXFLAGS) -c algoritmos/selectionSort.cpp -o algoritmos/selectionSort.o

algoritmos/mergeSort.o: algoritmos/mergeSort.cpp algoritmos/sortAlgorithms.h
	$(CXX) $(CXXFLAGS) -c algoritmos/mergeSort.cpp -o algoritmos/mergeSort.o

algoritmos/quickSort.o: algoritmos/quickSort.cpp algoritmos/sortAlgorithms.h
	$(CXX) $(CXXFLAGS) -c algoritmos/quickSort.cpp -o algoritmos/quickSort.o

# Regla para limpiar los archivos generados
clean:
	rm -f $(OBJFILES) $(TARGET)

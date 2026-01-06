# Opciones de compilación
CXX = g++
CXXFLAGS = -Wall -g

# Regla principal (compila todo)
all: bin/testTableEntry bin/testHashTable bin/testBSTree bin/testBSTreeDict

# 1. Test de TableEntry
bin/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/testTableEntry testTableEntry.cpp

# 2. Test de HashTable (Incluye referencia a P1)
bin/testHashTable: testHashTable.cpp HashTable.h Dict.h TableEntry.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/testHashTable testHashTable.cpp -I../PRA_2526_P1

# 3. Test de BSTree (Árbol Básico)
bin/testBSTree: testBSTree.cpp BSTree.h BSNode.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/testBSTree testBSTree.cpp

# 4. Test de BSTreeDict (Diccionario sobre Árbol)
bin/testBSTreeDict: testBSTreeDict.cpp BSTreeDict.h BSTree.h Dict.h TableEntry.h BSNode.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/testBSTreeDict testBSTreeDict.cpp

# Limpieza
clean:
	rm -f bin/*

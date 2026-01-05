#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <iostream>

using namespace std;

template <typename V>
class TableEntry {
    public:
        
        string key;
        V value;

        // Constructor con clave y valor
        TableEntry(std::string key, V value) : key(key), value(value) {}

        // Constructor solo con clave
        TableEntry(std::string key) : key(key), value() {}

        // Coonstructor clave vacía
        TableEntry() : key(""), value() {}

        // Comparación de igualdad: Solo mira la clave
        friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2) {
            return te1.key == te2.key;
        }

        // Comparación de desigualdad: Solo mira la clave
        friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2) {
            return te1.key != te2.key;
        }

        // Operador de salida: Imprime el par clave->valor
        friend std::ostream& operator<<(std::ostream &out, const TableEntry<V> &te) {
            out << "('" << te.key << "' => " << te.value << ")";
            return out;
        }
};

#endif

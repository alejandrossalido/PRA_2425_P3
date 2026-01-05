#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

template <typename V>
class TableEntry {
    public:
        // Atributos
        std::string key;
        V value;

        // Constructores
        // 1. Con clave y valor
        TableEntry(std::string key, V value) : key(key), value(value) {}
        
        // 2. Solo con clave (valor por defecto)
        TableEntry(std::string key) : key(key), value() {}
        
        // 3. Constructor por defecto
        TableEntry() : key(""), value() {}

        // Sobrecarga de operadores (Friends definidos inline)
        
        // Solo compara las claves
        friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2) {
            return te1.key == te2.key;
        }

        // Solo compara las claves
        friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2) {
            return te1.key != te2.key;
        }

        // Imprime el contenido
        friend std::ostream& operator<<(std::ostream &out, const TableEntry<V> &te) {
            out << "('" << te.key << "' => " << te.value << ")";
            return out;
        }
};

#endif

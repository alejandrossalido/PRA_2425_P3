#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include <string>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
        BSTree<TableEntry<V>>* tree; // ABB que gestiona los datos

    public:
        // Constructor:  arbol vacío
        BSTreeDict() {
            tree = new BSTree<TableEntry<V>>();
        }

        // Destructor
        ~BSTreeDict() {
            delete tree;
        }

        // Insertar
        void insert(std::string key, V value) override {
            TableEntry<V> entry(key, value);
            tree->insert(entry);
        }

        // Buscar
        V search(std::string key) override {
            TableEntry<V> entry(key); // Creamos entrada solo con clave
            return tree->search(entry).value; // devuelve el nodo completo, sacamos el valor
        }

        // Eliminar
        V remove(std::string key) override {
            V val = search(key);	 // Guardadmos el valor antes de borrar
            TableEntry<V> entry(key);
            tree->remove(entry);
            return val;
        }

        // Número de elementos
        int entries() override {
            return tree->size();
        }

        // metodos propios

        // Operador []
        V operator[](std::string key) {
            return search(key);
        }

        // Salida por pantalla
        friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs) {
            out << *(bs.tree); 
            return out;
        }
};

#endif

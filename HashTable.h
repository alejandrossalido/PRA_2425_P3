#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include <string>
#include "Dict.h"
#include "TableEntry.h"

#include "../PRA_2425_P1/ListLinked.h" 	// PONER RUTA DE PRACTICA 1

template <typename V>
class HashTable : public Dict<V> {

    private:
        int n; 		  // Elementos almacenados
        int max;	 // Tamaño total tabla
        ListLinked<TableEntry<V>>* table;		 // Array de listas

        // Función Hash: suma ASCII % tamaño
        int h(std::string key) {
            int sum = 0;
            for (int i = 0; i < key.length(); i++) {
                sum += int(key[i]);
            }
            return sum % max;
        }

    public:

        // Constructor
        HashTable(int size) {
            n = 0;
            max = size;
            table = new ListLinked<TableEntry<V>>[size];
        }

        // Destructor
        ~HashTable() {
            delete[] table;
        }

        // Devuelve capacidad
        int capacity() {
            return max;
        }

        // Insertar valor
        void insert(std::string key, V value) override {
            int pos = h(key);
            TableEntry<V> entry(key, value);

            // Si ya existe, lanzamos error
            if (table[pos].search(entry) != -1) {
                throw std::runtime_error("La clave ya existe");
            }

            // Insertamos al principio (más rápido)
            table[pos].prepend(entry);
            n++;
        }

        // Buscar valor
        V search(std::string key) override {
            int pos = h(key);
            TableEntry<V> entry(key); // Solo necesitamos la clave para buscar

            int index = table[pos].search(entry);
            if (index == -1) {
                throw std::runtime_error("Clave no encontrada");
            }

            return table[pos].get(index).value;
        }

        // Eliminar valor
        V remove(std::string key) override {
            int pos = h(key);
            TableEntry<V> entry(key);

            int index = table[pos].search(entry);
            if (index == -1) {
                throw std::runtime_error("Clave no encontrada");
            }

            V val = table[pos].get(index).value;
            table[pos].remove(index);
            n--;
            return val;
        }

        // Cantidad de elementos
        int entries() override {
            return n;
        }

        // Operador []
        V operator[](std::string key) {
            return search(key);
        }

        // Imprimir tabla 
        friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th) {
            out << "HashTable: entradas: " << th.n << ", capacidad: " << th.max << "\n";
            out << "==============\n";
            for (int i = 0; i < th.max; i++) {
                out << "== [" << i << "] ==\n";
                out << th.table[i] << "\n";
            }
            out << "==============\n";
            return out;
        }
};

#endif

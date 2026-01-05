#ifndef DICT_H
#define DICT_H

#include <string>
#include <stdexcept> // Necesario para std::runtime_error

template <typename V>
class Dict {
    public:

        // Destructor
        virtual ~Dict() {}
        
        // Inserta el par key->value. 
        virtual void insert(std::string key, V value) = 0;

        // Busca el valor asociado a key.
        virtual V search(std::string key) = 0;

        // Elimina el par asociado a key.
        virtual V remove(std::string key) = 0;

        // Devuelve el número de elementos
        virtual int entries() = 0;
};

#endif

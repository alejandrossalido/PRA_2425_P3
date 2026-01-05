#ifndef DICT_H
#define DICT_H

#include <string>
#include <stdexcept> // Necesario para std::runtime_error

template <typename V>
class Dict {
    public:
        // Destructor virtual (importante para interfaces)
        virtual ~Dict() {}

        // Métodos virtuales puros (= 0)
        
        // Inserta el par key->value. Lanza error si ya existe.
        virtual void insert(std::string key, V value) = 0;

        // Busca el valor asociado a key. Lanza error si no lo encuentra.
        virtual V search(std::string key) = 0;

        // Elimina el par asociado a key. Lanza error si no lo encuentra.
        virtual V remove(std::string key) = 0;

        // Devuelve el número de elementos
        virtual int entries() = 0;
};

#endif

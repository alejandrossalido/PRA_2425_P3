#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

template <typename T>
class BSNode {
    public:
        // Atributos
        T elem;
        BSNode<T>* left;
        BSNode<T>* right;

        // Constructor
        BSNode(T elem, BSNode<T>* left = nullptr, BSNode<T>* right = nullptr) {
            this->elem = elem;
            this->left = left;
            this->right = right;
        }

        // Sobrecarga del operador <<
        friend std::ostream& operator<<(std::ostream &out, const BSNode<T> &bsn) {
            out << bsn.elem;
            return out;
        }
};

#endif

#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T>
class BSTree {
    private:
        int nelem;          // Número de elementos
        BSNode<T>* root;    // Raíz del árbol

        // Buscar nodo
        BSNode<T>* search(BSNode<T>* n, T e) const {
            if (n == nullptr) {
                throw std::runtime_error("Elemento no encontrado");
            }
            if (n->elem == e) {
                return n;
            }
            if (n->elem > e) {
                return search(n->left, e);
            } else {
                return search(n->right, e);
            }
        }

        // Insertar nodo
        BSNode<T>* insert(BSNode<T>* n, T e) {
            if (n == nullptr) {
                return new BSNode<T>(e);
            }
            if (n->elem == e) {
                throw std::runtime_error("Elemento duplicado");
            }
            if (n->elem > e) {
                n->left = insert(n->left, e);
            } else {
                n->right = insert(n->right, e);
            }
            return n;
        }

        // Recorrido Inorden (Izquierda -> Raíz -> Derecha)
        void print_inorder(std::ostream &out, BSNode<T>* n) const {
            if (n != nullptr) {
                print_inorder(out, n->left);
                out << n->elem << " ";
                print_inorder(out, n->right);
            }
        }

        // Eliminar un nodo
        BSNode<T>* remove(BSNode<T>* n, T e) {
            if (n == nullptr) {
                throw std::runtime_error("Elemento no encontrado");
            }
            if (n->elem > e) {
                n->left = remove(n->left, e);
            } else if (n->elem < e) {
                n->right = remove(n->right, e);
            } else {
                // Encontrado. Caso 1: Tiene hijos a ambos lados
                if (n->left != nullptr && n->right != nullptr) {
                    n->elem = max(n->left);
                    n->left = remove_max(n->left);
                } 
                // Caso 2: Solo un hijo o ninguno
                else {
                    BSNode<T>* temp = n;
                    n = (n->left != nullptr) ? n->left : n->right;
                    delete temp;
                }
            }
            return n;
        }

        // Buscar máximo (el de más a la derecha)
        T max(BSNode<T>* n) const {
            if (n == nullptr) {
                throw std::runtime_error("Árbol vacío");
            }
            if (n->right != nullptr) {
                return max(n->right);
            }
            return n->elem;
        }

        // Eliminar máximo
        BSNode<T>* remove_max(BSNode<T>* n) {
            if (n->right == nullptr) {
                BSNode<T>* temp = n->left;
                delete n;
                return temp;
            }
            n->right = remove_max(n->right);
            return n;
        }

        // Borrado en cascada (destructor)
        void delete_cascade(BSNode<T>* n) {
            if (n != nullptr) {
                delete_cascade(n->left);
                delete_cascade(n->right);
                delete n;
            }
        }

    public:
        // --- MÉTODOS PÚBLICOS ---

        // Constructor
        BSTree() {
            nelem = 0;
            root = nullptr;
        }

        // Tamaño
        int size() const {
            return nelem;
        }

        // Búsqueda
        T search(T e) const {
            return search(root, e)->elem;
        }

        // Operador []
        T operator[](T e) const {
            return search(e);
        }

        // Inserción
        void insert(T e) {
            root = insert(root, e);
            nelem++;
        }

        // Eliminación
        void remove(T e) {
            root = remove(root, e);
            nelem--;
        }

        // Sobrecarga salida
        friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst) {
            bst.print_inorder(out, bst.root);
            return out;
        }

        // Destructor
        ~BSTree() {
            delete_cascade(root);
        }
};

#endif

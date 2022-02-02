//
// Created by Hunter Stephens on 2/2/22.
//

#ifndef SPARSEMATRIX_SPARSEMATRIX_H
#define SPARSEMATRIX_SPARSEMATRIX_H
#include <iostream>

/*
 * Node Structure
 *
 */
template <typename T>
struct Node {
    unsigned long int row;
    unsigned long int col;
    T value;
    Node *next;
};

template <typename T>
class SparseMatrix {
private:
    Node<T> *head, *tail;

public:
    // Destructor
    ~SparseMatrix();

    // Constructors
    SparseMatrix();

    // Methods
    void append(unsigned long row, unsigned long col, T value);
    void print();

};

template <typename T>
SparseMatrix<T>::~SparseMatrix() {
    if(!(head == nullptr && tail == nullptr)){
        Node<T> *currentPtr = head;
        Node<T> *tempPtr;
        while(currentPtr != 0){
            tempPtr = currentPtr;
            currentPtr = currentPtr->next;
            delete tempPtr;
        }

    }
}


template <typename T>
SparseMatrix<T>::SparseMatrix() {
    head = nullptr;
    tail = nullptr;
}

template<typename T>
void SparseMatrix<T>::append(unsigned long row, unsigned long col, T value) {
    Node<T> *tmp = new Node<T>;
    tmp->row = row;
    tmp->col = col;
    tmp->value = value;

    if(head == nullptr)
    {
        head = tmp;
        tail = tmp;
    }
    else{
        tail->next = tmp;
        tail = tmp;
    }
}

template<typename T>
void SparseMatrix<T>::print() {
    Node<T> *tmp;
    tmp = head;
    while (tmp != nullptr){
        std::cout << tmp->row << " " << tmp->col << " " << tmp->value << std::endl;
        tmp = tmp->next;
    }

}


#endif //SPARSEMATRIX_SPARSEMATRIX_H

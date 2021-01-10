//
//  vector_template.cpp
//  Prog3_exer_4_vector_template
//
//  Created by Charissa Abegail M. Morales on 1/10/21.
//

#include <stdio.h>
#include "vector_template.h"


//! The class should provide default constructor
template <class T>
vectorTemplate<T>::vectorTemplate(){};

//! Constructor, that assigns a given value to a given number of vector elements.
template <class T>
vectorTemplate<T>::vectorTemplate(size_t size){
    this->size = size;
    this->values = new T[this->size];
    for(size_t i = 0; i <= size; i++){
        this->values[i] = this->values[i]; //initialize default value
        
    }
    
};

//!In addition, any other needed constructor shall be defined.
template <class T>
vectorTemplate<T>::vectorTemplate(size_t size, T* vector){
    this->size = size;
    this->values = new T[size];
    for(size_t i = 0; i <= size; i++){
        this->values[i] = vector[i];
    }
}

//!size: returns the number of elements of the vector. const reference
template <class T>
const size_t& vectorTemplate<T>::getSize(){
    return this->size;
}

//! resize: allows you to dynamically adjust the size of the vector
template <class T>
void vectorTemplate<T>::resize(size_t newSize){
    //!save original size;
    size_t original_size = this->size;
    //!save original values
    T* original_values = this->values;
    
    //! dynamically allocate new memory
    this->values = new T[newSize];
    for(size_t i = 0; i <= original_size; i++){
        this->values[i] = original_values[i];
    }
    
    //! release temporary memory
    delete[] original_values;
    
};

//! swap: swaps two vectors (swapping administrative data is enough!! No need to copy all values!)
template <class T>
void vectorTemplate<T>::swap(vectorTemplate<T> &vec1, vectorTemplate<T> &vec2){
    //! check if swappable or same size;
    T temp;
    if(vec1.size == vec2.size) {
        for(size_t i = 0; i <= getSize(); i++){
            temp = vec1[i];
            vec1[i] = vec2[i];
            vec2[i] = temp;
        }
    }
};


//! overload index operator
template <class T>
T& vectorTemplate<T>::operator[ ](std::size_t index) const{
    //! check if index is valid
    if(index >= this->size || index < 0 ) {
        throw std::out_of_range("index out of range");
    }
    
    return this->values[index];
}


//! overload index operator with constant vector
//// for non-const objects: can be used for assignment??
/*template <class T>
const T& vectorTemplate<T>::operator[ ](std::size_t index) const{
    
    if(index >= this->size || index < 0 ) {
        std::out_of_range("index out of range");
    }
    
    return this->values[index];
} */

//! overload assignment operator
template <class T>
vectorTemplate<T> & vectorTemplate<T>::operator=(const vectorTemplate<T> &rhsVec) const{
    //! assignment operator replaces the contents of an object and not initializing new objects
    //! check if this is not equal to itself
        if(this != &rhsVec) {
            this->size = rhsVec.size;
            delete[] this->values;
            this->values = new T[this->size];
            for(size_t i = 0; i < this->size; i++){
                this->values[i] =  rhsVec[i];
            }
        }

    
    
    return *this;
    
}

//! overload output opertaor
template <class T>
void vectorTemplate<T>::display(){
    for(size_t i = 0; i < this->size; i++){
        std::cout << " ----- vector contents ---- \n" << std::endl;
        std::cout << this->values[i] << "\n" << std::endl;
        std::cout << " ----- end of output ------ \n" << std::endl;
        
    }
}

//! remove
template <class T>
void vectorTemplate<T>::remove(size_t index) {
    
    //!  validate index
    if(index >= this->size || index < 0) {
        throw std::out_of_range("index is out of range");
    }
    //! save original size
    size_t original_size = this->size;
    //! save original values
    T* original_values = this->values;
    
    //! allocate new memory
    this->size -= 1;
    this->values = new T[this->size];
    
    for(size_t i = 0; i < original_size; i++){
        if(i != index){
            this->values[i] =original_values[i];
        }
    }
    delete[] original_values;
}; //why the value of index is size_t>

//! insert
template <class T>
void vectorTemplate<T>::insert(const vectorTemplate<T>& vector, size_t index){
    //! validate index
    if(index >= this->size) {
        //adjust size automatically when there's no space
        resize(this->size + vector.size);
    } else if (index < 0 ) {
        throw std::out_of_range("index is out of range");
        return;
    }
    
    //save original size
    size_t original_size = this->size;
    
    //resize vector
    resize(vector.size);
    
    //shift to the right
    for(size_t i = original_size; i >= index;){
        this->values[i+vector.size] = this->values[i];
        if(i > 0) {
            --i;
        } else {
            break;
        }
    }
    
    //insert vector to the newly resized array
    for(size_t i = index, j=0 ; j < vector.size; j++, i++){
        this->values[i] = vector.values[j];
    }
};

//! release
template <class T>
vectorTemplate<T>::~vectorTemplate(){
    delete[] this->values;
};

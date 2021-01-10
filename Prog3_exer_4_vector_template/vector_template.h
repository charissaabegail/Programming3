//
//  vector_template.h
//  Prog3_exer_4_vector_template
//
//  Created by Charissa Abegail M. Morales on 1/10/21.
//

#ifndef vector_template_h
#define vector_template_h
#include <iostream>

template <typename T>

//! Develop the declaration for the class template Vector
class vectorTemplate{
private:
    size_t size;
    T* vectorValues;
    
    //! overloaded output
    friend std::ostream &operator<<(std::ostream & os, const vectorTemplate<T>& vector) {
        os << vector.toString() << std::endl;
        return os;
    }
public:
    //! The class should provide default constructor
    vectorTemplate();
    
    //! Constructor, that assigns a given value to a given number of vector elements.
    vectorTemplate(size_t size);
    
    //!In addition, any other needed constructor shall be defined.
    vectorTemplate(size_t size, T* vector);
    
    //!size: returns the number of elements of the vector. const reference
    const size_t& getSize();
    
    //! resize: allows you to dynamically adjust the size of the vector
    void resize(size_t newSize);
    
    //! swap: swaps two vectors (swapping administrative data is enough!! No need to copy all values!)
    void swap(vectorTemplate<T> & vec2);
    
    
    
    //! overload index operator
    vectorTemplate<T>& operator[ ](std::size_t index);
    
    //! overload index operator with constant vector
    //const T& operator[ ](std::size_t index) const;     
    
    //! overload assignment operator
    vectorTemplate<T> &operator=(const vectorTemplate<T> &rhsVec) const;
    
    //! overload output opertaor
    void display();
    
    //! remove
    void remove(size_t index); //why the value of index is size_t>
    
    //! insert
    void insert(const vectorTemplate<T>& vector, size_t index);
    
    //! release
    ~vectorTemplate();
    
    //! toString
    std::string toString() const;
    
    
};


//inline functions

//! The class should provide default constructor
template <class T>
vectorTemplate<T>::vectorTemplate(){};

//! Constructor, that assigns a given value to a given number of vector elements.
template <class T>
vectorTemplate<T>::vectorTemplate(size_t size){
    this->size = size;
    this->vectorValues = new T[this->size];
    for(size_t i = 0; i <= size; i++){
        this->vectorValues[i] = this->vectorValues[i]; //initialize default value
        
    }
    
};

//!In addition, any other needed constructor shall be defined.
template <class T>
vectorTemplate<T>::vectorTemplate(size_t size, T* vector){
    this->size = size;
    this->vectorValues = new T[size];
    for(size_t i = 0; i <= size; i++){
        this->vectorValues[i] = vector[i];
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
    //!save original vectorValues
    T* original_vectorValues = this->vectorValues;
    
    //! dynamically allocate new memory
    this->vectorValues = new T[newSize];
    for(size_t i = 0; i <= original_size; i++){
        this->vectorValues[i] = original_vectorValues[i];
    }
    
    //! release temporary memory
    delete[] original_vectorValues;
    
};

//! swap: swaps two vectors (swapping administrative data is enough!! No need to copy all vectorValues!)
template <class T>
void vectorTemplate<T>::swap(vectorTemplate<T> &vec2){
    //! check if swappable or same size;
    T temp;
    if(this->size == vec2.size) {
        for(size_t i = 0; i <= this->size; i++){
            temp = this->vectorValues[i];
            this->vectorValues[i] = vec2[i];
            vec2[i] = temp;
        }
    }
};


//! overload index operator
template <class T>
vectorTemplate<T>& vectorTemplate<T>::operator[ ](std::size_t index) {
    //! check if index is valid
    if(index >= this->size || index < 0 ) {
        throw std::out_of_range("index out of range");
    }
    
    return this->vectorValues[index];
}


//! overload index operator with constant vector
//// for non-const objects: can be used for assignment??
/*template <class T>
const T& vectorTemplate<T>::operator[ ](std::size_t index) const{
    
    if(index >= this->size || index < 0 ) {
        std::out_of_range("index out of range");
    }
    
    return this->vectorValues[index];
} */

//! overload assignment operator
template <class T>
vectorTemplate<T> & vectorTemplate<T>::operator=(const vectorTemplate<T> &rhsVec) const{
    //! assignment operator replaces the contents of an object and not initializing new objects
    //! check if this is not equal to itself
        if(this != &rhsVec) {
            this->size = rhsVec.size;
            delete[] this->vectorValues;
            this->vectorValues = new T[this->size];
            for(size_t i = 0; i < this->size; i++){
                this->vectorValues[i] =  rhsVec[i];
            }
        }

    
    
    return *this;
    
}

//! overload output opertaor
template <class T>
void vectorTemplate<T>::display(){
    //std::cout << " ----- vector contents ---- \n" << std::endl;
    for(size_t i = 0; i < this->size; i++){
        std::cout << this->vectorValues[i] << "\n" << std::endl;
    }
    //std::cout << " ----- end of output ------ \n" << std::endl;
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
    //! save original vectorValues
    T* original_vectorValues = this->vectorValues;
    
    //! allocate new memory
    this->size -= 1;
    this->vectorValues = new T[this->size];
    
    for(size_t i = 0; i < original_size; i++){
        if(i != index){
            this->vectorValues[i] =original_vectorValues[i];
        }
    }
    delete[] original_vectorValues;
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
        this->vectorValues[i+vector.size] = this->vectorValues[i];
        if(i > 0) {
            --i;
        } else {
            break;
        }
    }
    
    //insert vector to the newly resized array
    for(size_t i = index, j=0 ; j < vector.size; j++, i++){
        this->vectorValues[i] = vector.vectorValues[j];
    }
};

//! release
template <class T>
vectorTemplate<T>::~vectorTemplate(){
    delete[] this->vectorValues;
};

//!toString: returns a string representation of the vector in the form (elem1, elem2, ..., elemN)
template <class T>
std::string vectorTemplate<T>::toString() const{
    std::string temp_values_to_output;
    temp_values_to_output += "(";
    for(size_t i = 0; i < this->size; i++){
        
        if(i == (this->size-1)){
            temp_values_to_output += std::to_string(this->vectorValues[i]);
        } else {
            temp_values_to_output += std::to_string(this->vectorValues[i])+",";
        }
    }
    temp_values_to_output += ")";
    return temp_values_to_output;
    
}

#endif /* vector_template_h */

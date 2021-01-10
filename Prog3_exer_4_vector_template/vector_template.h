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
    T* vector;
    
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
    void swap(vectorTemplate<T> &vec1, vectorTemplate<T> &vec2);
    
    //! toString: returns a string representation of the vector in the form (elem1, elem2, ..., elemN)
    friend std::ostream &operator<<(std::ostream &os, const vectorTemplate<T>& vector) {
        os << vector.toString() << std::endl;
        return os;
    }
    
    //! overload index operator
    T& operator[ ](std::size_t index) const;
    
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
    
    
};

#endif /* vector_template_h */

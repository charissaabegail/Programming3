//
//  vectordouble.h
//  Prog3_exer_4_vectordouble
//
//  Created by Charissa Abegail M. Morales on 11/15/20.
//

#ifndef vectordouble_h
#define vectordouble_h


template <class T>
class Vector{
private:
    int vectorDimension;
    T* vectorArr;
    
public:
    //! Vector which parameter is not specified. Vector size will be set 2.
    Vector();
    //! Vector with vectorDimension parameter. Here, initial values of the vector shall be 0
    Vector(int vectorDimension);
    //! Vector with vectorDimension and values as parameters
    Vector(int vectorDimension, T * values);
    //! Copy Constructor (Deep copy)
    //Vector(const Vector & vectorObj);
    Vector(const Vector & vectorObj);
    //! Set value at the specified index i
    void setValueAt(int index, T value);
    //! Read value at the specified index i
    double getValueAt(int index);
    //! Destructor. To release memory on the heap
    ~Vector();
    //! with the << operator, a vector is represented in the form: (2.71, 3.14, 9.81)
    void output();
    
    
    
};

#endif /* vectordouble_h */

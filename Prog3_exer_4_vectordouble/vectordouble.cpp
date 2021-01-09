//
//  vectordouble.cpp
//  Prog3_exer_4_vectordouble
//
//  Created by Charissa Abegail M. Morales on 11/15/20.
//

#include <stdio.h>
#include "vectordouble.h"

#include <iostream>
using namespace std;


//! Vector which parameter is not specified. Vector size will be set 2, element values shall be initialized to 0.
Vector::Vector(){
    vectorDimension = 2;
    vectorArr = new double[vectorDimension];
    for(int i=0; i < vectorDimension; i++){
        vectorArr[i] = 0.0;
    }
};

//! Vector with vectorDimension parameter. Here, initial values of the vector shall be 0.
Vector::Vector(int vectorDimension){
    this->vectorDimension = vectorDimension;
    vectorArr = new double[this->vectorDimension];
    for(int i=0; i < vectorDimension; i++){
        vectorArr[i] = 0.0; //initial values set to 0
    }
};

//! Vector with vectorDimension and values as parameters.
Vector::Vector(int vectorDimension, double * value){
    this->vectorDimension = vectorDimension;
    vectorArr = new double[this->vectorDimension];
    for(int i=0; i < vectorDimension; i++){
        vectorArr[i] = value[i]; //initial values set to 0
    }
};

//! Copy Constructor (deep copy)
Vector::Vector(const Vector & vectorObj){
    
    //If the dimensions of the vectors are not the same, realign vector dimension
    if (this->vectorDimension != vectorObj.vectorDimension) {
        this->vectorDimension = vectorObj.vectorDimension;
    }
    vectorArr = new double[this->vectorDimension];
    
    for(int i = 0; i < vectorDimension; i++){
        vectorArr[i] = vectorObj.vectorArr[i];
    }
};

//! Destructor. To release memory on the heap
Vector::~Vector(){
    delete[] vectorArr;
};

//! Set value at the specified index i
void Vector::setValueAt(int index, double value){
    if(index >= 0 && index < vectorDimension){
        vectorArr[index] = value;
    } else {
        cout << "out of range" << endl;
    }
};

//! Read value at the specified index i
double Vector::getValueAt(int index){

    if(index >= 0 && index < this->vectorDimension){
        return this->vectorArr[index];
    } else {
        cout << "out of range" << endl;
        return 0.0;
    }
};

//! with the << operator, a vector is represented in the form: (2.71, 3.14, 9.81)
void Vector::output() {
    cout << "(";
    for (int i = 0; i < vectorDimension -1 ; i++) {
        cout << vectorArr[i] << ", ";
    }
    cout << vectorArr[vectorDimension - 1] << ")" << endl;

}


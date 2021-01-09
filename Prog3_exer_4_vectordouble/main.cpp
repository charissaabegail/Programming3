//
//  main.cpp
//  Prog3_exer_4_vectordouble
//
//  Created by Charissa Abegail M. Morales on 11/15/20.
//

#include <iostream>
#include "vectordouble.h"
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    
   
    //! Test Cases:
    double *arrValues = new double[3];
    arrValues[0] = 2.14;
    arrValues[1] = 3.14;
    arrValues[2] = 9.18;
    
    //! Constructor without parameter.
        //Vector();
    //!Constructor with vectorDimension parameter
        //Vector v(3);
    //!Constructor with vectorDimension and arrayValues parameters
    Vector v(3,arrValues);
    
    cout << "Initial output ------------------------- " << endl;
        v.output(); //initial output
  
    
    v.setValueAt(0, 1.1); //set index 0 to value
    v.setValueAt(1, 2.2); //set index 1 to value
    v.setValueAt(1, 2.2); //set index 2 to value
    
    cout << "Get values ----------------------------- " << endl;
        cout << v.getValueAt(0) << endl;
        cout << v.getValueAt(1) << endl;
        cout << v.getValueAt(2) << endl;

    //output all vectors in the form:  (2.71, 3.14, 9.81)
    cout << "After set output ----------------------- " << endl;
        v.output(); //initial output
   
    
    //!Deep Copy
    Vector v1(v); //Copy constructor (deep copy)
    Vector v2 = v; // assignment operator that makes (deep copy)
    
    cout << "Output of copies ----------------------- " << endl;
    v1.output();
    v2.output();
    
    cout << "Addresses ------------------------------ " << endl;
    cout << &v1 << endl;
    cout << &v2 << endl;

    
    std::cout << "Hello, World!\n";
    return 0;
}

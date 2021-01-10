//
//  main.cpp
//  Prog3_exer_4_vector_template
//
//  Created by Charissa Abegail M. Morales on 1/10/21.
//

#include <iostream>
#include "vector_template.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    //! TESTING FOR ELEMENTARY DATA TYPES
    double * vectorDouble1 = new double[3];
    
    vectorDouble1[0] = 1.1;
    vectorDouble1[1] = 2.2;
    vectorDouble1[1] = 3.3;
    
    double * vectorDouble2 = new double[3];
    
    vectorDouble2[0] = 4.44;
    vectorDouble2[1] = 5.55;
    vectorDouble2[1] = 6.66;
    
    //instantiate vectorTemplate class with constructor that accepts object size
    vectorTemplate<double> * vt_double = new vectorTemplate<double>(3);
    
    vt_double->display();
    
    
    
    
    std::cout << "Hello, World!\n";
    return 0;
}

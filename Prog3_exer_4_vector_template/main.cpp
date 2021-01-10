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
    vectorDouble1[2] = 3.3;
    
    double * vectorDouble2 = new double[3];
    
    vectorDouble2[0] = 4.44;
    vectorDouble2[1] = 5.55;
    vectorDouble2[2] = 6.66;
    
    //instantiate vectorTemplate class with constructor that accepts object size and vector
    std::cout << "VECTOR 1:" << std::endl;
    vectorTemplate<double> * vt_double1 = new vectorTemplate<double>(3,vectorDouble1);
    vt_double1->display();
    
    std::cout << "VECTOR 2:" << std::endl;
    vectorTemplate<double> * vt_double2 = new vectorTemplate<double>(3,vectorDouble2);
    vt_double2->display();
    
    std::cout << "VECTOR1 = VECTOR2 [overloaded assignment operator]" << std::endl;
    // copying vt_double2 to vt_double1
    vt_double1 = vt_double2;
    vt_double1->display();
    
    std::cout << "REMOVE LAST ELEMENT in VECTOR 1" << std::endl;
   /*
    vt_double1->remove(1);
    vt_double1->display(); */
    
   /* std::cout << "SWAPS VECTOR1 and VECTOR2" << std::endl;
    vt_double1->swap(vt_double2); */
    
    std::cout << "VECTOR 1 toString:" << std::endl;
    std::cout << vt_double1->toString() << std::endl;
    
    std::cout << "GET THE SIZE VECTOR 1:" << std::endl;
    std::cout << vt_double1->getSize() << std::endl;
    
    
    std::cout << "GET ELEMENT BY INDEX:" << std::endl;
    vectorTemplate<double> a = vt_double1[0];
    std::cout << a << std::endl;
    
    
    
    
   
    
    std::cout << "ADD VECTOR3 to VECTOR1" << std::endl;
    double * vectorDouble3 = new double[3];
    
    vectorDouble2[0] = 10.99;
    vectorDouble2[1] = 11.99;
    vectorDouble2[2] = 12.99;
    vectorTemplate<double> * vt_double3 = new vectorTemplate<double>(3,vectorDouble3);
    vt_double3->display();
    
    vt_double1->insert(vt_double3,1); //[][insert here][]
    vt_double1->display(); 
    
    
    
    
    
    
    
    
    
    
    
    std::cout << "Hello, World!\n";
    return 0;
}

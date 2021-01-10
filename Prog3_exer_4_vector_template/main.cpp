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
   
    vt_double1->remove(1);
    vt_double1->display();
    
   
    
    std::cout << "VECTOR 1 toString:" << std::endl;
    std::cout << vt_double1->toString() << std::endl;
    
    std::cout << "GET THE SIZE VECTOR 1:" << std::endl;
    std::cout << vt_double1->getSize() << std::endl;
    
    
    std::cout << "ADD VECTOR3 to VECTOR1" << std::endl;
    double * vectorDouble3 = new double[3];
    
    vectorDouble3[0] = 10.99;
    vectorDouble3[1] = 11.99;
    vectorDouble3[2] = 12.99;
    vectorTemplate<double> vt_double3 (3,vectorDouble3);
    //std::cout << vt_double3 << std::endl;
    vt_double3.display();
    std::cout << "----- before vt_double1" << std::endl;
    vt_double1->display();
    
    vt_double1->insert(vt_double3,1); //[][insert here][]
    std::cout << "----- after insert" << std::endl;
    vt_double1->display();
    
    
    
    std::cout << "GET ELEMENT BY INDEX:" << std::endl;
    std::cout << vt_double3[0] << std::endl;
    
    
    
    std::cout << "SWAPS VECTOR4 and VECTOR5" << std::endl;
    double * vectorDouble4 = new double[3];
    
    vectorDouble4[0] = 31.99;
    vectorDouble4[1] = 32.99;
    vectorDouble4[2] = 33.99;
    vectorTemplate<double> vt_double4 (3,vectorDouble4);
    std::cout << "VECTOR 4:" << std::endl;
    vt_double4.display();
    
    double * vectorDouble5 = new double[3];
    
    vectorDouble5[0] = 41.99;
    vectorDouble5[1] = 42.99;
    vectorDouble5[2] = 43.99;
    vectorTemplate<double> vt_double5 (3,vectorDouble5);
    std::cout << "VECTOR 5:" << std::endl;
    vt_double5.display();
    
    std::cout << "SWAPPED Vector4 NEW VALUES:" << std::endl;
    vt_double4.swap(vt_double5);
    vt_double4.display();
    
    
   // vt_double1->~vectorTemplate();
    // vt_double2->~vectorTemplate();;
    //vt_double3.~vectorTemplate();
    //vt_double4.~vectorTemplate();
    //vt_double5.~vectorTemplate();
    std::cout << "Hello, World!\n";
    return 0;
}

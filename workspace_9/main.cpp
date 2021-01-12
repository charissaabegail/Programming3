//
//  main.cpp
//  workspace_9
//
//  Created by Charissa Abegail M. Morales on 1/11/21.
//

#include <iostream>
#include <map>

using namespace std;
multimap<string,string> phonebook(){
    multimap<string,string> maps;
    
    maps.insert(pair<string,string>("Cha","home number: 1212313"));
    maps.insert(pair<string,string>("Cha","work number: 1923123"));
    maps.insert(pair<string,string>("Cha","mobile number: 345345"));
    
    maps.insert(pair<string,string>("Miha","home number: 1212313"));
    maps.insert(pair<string,string>("Miha","work number: 1923123"));
    maps.insert(pair<string,string>("Miha","mobile number: 345345"));

    
    return maps;
}

string search(string name) {
    
    //load phonebook once. Static variable should be used
static multimap<string, string> phones = phonebook(); //this method will be called just once
    //create a variable to return the result of the search
    string result = name + "\n\n";
    //search for the name
    int num = 0;
    for(multimap<string,string>::iterator iter = phones.begin(); iter != phones.end(); iter++){
        num++;
        // iter is a special kind of pointer
        if(iter->first == name){
            //or (*iter).first == name
            result += " definition " + to_string(num) + '\n';
            result += iter->second + "\n\n";
        }
        
    }
    if(num == 0) {
        result += " No results found for " + name + '\n';
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    string result = search("Miha");
    
    std::cout << result << std::endl;
    // insert code here...

    std::cout << "Hello, World!\n";
    return 0;
}

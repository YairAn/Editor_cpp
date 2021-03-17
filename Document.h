#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;



class Document
{
    
public:
    Document(){};
    
    vector<string> vec;

    void jump_to(); 

    void jump_up(); 

    void jump_down(); 

    void add_after(); 

    void insert_before(); 

    void replace_line(); 

    void delete_line(); 

    void find(); 

    void switch_to(); 

    void connect(); 

    void write();

    void print(); 
    
    int position;

    

};



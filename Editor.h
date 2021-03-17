#include <iostream>
#include <stdexcept>
#include <fstream>
#include "Document.h"
#include <string>
using namespace std;



class Editor
{

public:

    Document doc;
 
 Editor(string file)
    {
        ifstream f(file);

        if (!f)
            cout << "no file with that name" << endl;

        for (string line; getline(f, line);)
        {

            doc.vec.push_back(line);
        }
        f.close();
    }
Editor(){
       doc.position = 0;
    }

   

    
    ~Editor(){}
   
    void loop();
};



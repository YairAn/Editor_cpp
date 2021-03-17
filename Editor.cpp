#include <iostream>
#include <stdexcept>
#include "Editor.h"
using namespace std;


void Editor::loop()
{
    while (true)
    {
        char a = getchar();

        switch (a)
        {

        case '1':
            doc.jump_to();
            break;

        case '+': 
            doc.jump_down();
            break;

        case '-': 
            doc.jump_up();
            break;

        case '$':
            doc.position = doc.vec.size() - 1;
            break;

        case 'a':
           doc.add_after();
            break;

        case 'i':
            doc.insert_before();
            break;

        case 'c':
            doc.replace_line();
            break;

        case 'd':
           doc.delete_line();
            break;

        case '/': 
           doc.find();
            break;

        case 's': 
            doc.switch_to();
            break;

        case 'j':
            doc.connect();
            break;

        case 'w': 
            doc.write();
            break;

        case 'q':
            exit(EXIT_FAILURE);

        case 'p':
        doc.print();
        break;
    
        case 'r':
        std::cout << "row = " << doc.position<< std::endl;
        break;

        default:
            if (a != '\n')
                cout << "?" << std::endl;

            break;
        }
    }
}
       
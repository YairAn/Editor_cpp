#include <iostream>
#include <stdexcept>
#include "Editor.h"
using namespace std;

int main(int argc,char* argv[]){

     if (argc == 2)  {
        Editor ed(argv[1]);
        ed.loop();
    } else {
        Editor ed;
        ed.loop();
    }

return 0;
}

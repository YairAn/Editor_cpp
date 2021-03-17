#include <iostream>
#include <stdexcept>
#include "Document.h"
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <iterator>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


 void Document::jump_to(){
     position = 0;
 }

    void Document::jump_up(){
        char c = getchar();
        if(c == '3'){ position -=3;}
        else{
        position -= 2;
        }
    } 

    void Document::jump_down(){

        position += 1;
        char c = getchar();

    }

    void Document::add_after(){
        for (string line; getline(cin, line);)
    {        
        if (!line.empty())
        {
             if (line == "."){
                return;
             }
            if(vec.size() > 0){
                vec.insert(vec.begin() + (position + 1), line);
                position++;
            } else {
                vec.push_back(line);
                position = 0;         
        }
    }
    }
    }

    void Document::insert_before(){
         for (string line; getline(cin, line);)
    {
        
         if (!line.empty())
        {  
             if (line == "."){
                position--;
                return;  
             }
          vec.emplace(vec.begin() + (position), line);
            position++;
        }
    }
    
    }

    void Document::replace_line(){
        vec.erase(vec.begin() + position);

         for (string line; getline(cin, line);)
    {
        
        if (!line.empty())
        {
            if (line == ".")
                return;
            vec.emplace(vec.begin() + (position), line);
        }
    }
    } 

    void Document::delete_line(){
        vec.erase(vec.begin() + position);
    }

    void Document::find(){
       string text;
       getline(cin, text);
       text = text.substr(1,text.size()-2);
       
       string s;
       int temp_pos = position;
       for(;temp_pos < vec.size()-1;temp_pos++){
           s = vec.at(temp_pos+1);
           if(s.find(text) != std::string::npos){
               position = temp_pos+1;
               // cout << "this is line   "<< s << endl;
               return;
           }

           
       }
       if(position!= 0){
           temp_pos = 0;
          for(;temp_pos <= position;temp_pos++){
              s = vec.at(temp_pos);
          if(s.find(text) != std::string::npos){
               position = temp_pos;
           //  cout << "this is line   "<< s << endl;

               return;
           }

       } 
       }
       
       
    }
    vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}


    void Document::switch_to(){
       string text;
       getline(cin, text);
       text = text.substr(1);
       char delimiter = '/';
       ///cout << "er 1 " << endl;

       vector<string> v = split(text, delimiter);
      // cout << "er 2 " << endl;

       int i = vec.at(position).find(v.at(0));
      // cout << "er 3 " << endl;

       vec.at(position).replace(i,v.at(0).size(),v.at(1));
                 // cout << "er 4 " << endl;
   
    } 



    void Document::connect(){
        string s;
        if(position == vec.size()-1){
           s = vec.at(position) + vec.at(0);
           vec.at(position) = s;
           vec.erase(vec.begin());
           position--;
        } else {
             s = vec.at(position) + vec.at(position + 1);
                        vec.at(position) = s;

             vec.erase(vec.begin() + position + 1);
            
        }
    }

    void Document::write(){
    string line;
    getline(std::cin, line);

    if (!line.empty())
    {
        line = line.substr(1, line.size()); 

        ofstream out_f(line);
        ostream_iterator<string> out_i(out_f, "\n");
        copy(vec.begin(), vec.end(), out_i);
    }

    }

    void Document :: print(){
    for (auto const& l : vec)
{
    std::cout << l << std::endl;
}
    }
    




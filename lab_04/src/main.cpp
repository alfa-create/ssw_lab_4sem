#include <iostream>
#include <fstream>
#include <string>
#include "map.h"

using namespace std;

int main() {

    std::fstream fin;
    fin.open(R"(C:\Users\User\Desktop\ssw_lab_4sem\lab_04\src\name.txt)");
    map<int, string> map_names;
    int i = 0;
    string str;

    if (fin){
        while(!fin.eof()){
            getline(fin,str);
            map_names.Emplace(i,str);
            i++;
        }
        fin.close();

    }
    else cout << endl << "error!" << endl;

    return 0;
}

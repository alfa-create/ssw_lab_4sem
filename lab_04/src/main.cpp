#include <iostream>
#include <fstream>
#include <string>
#include "map.h"

using namespace std;

int main() {

    try{
        fstream fin;
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

        map_names.Erase(i - 1);//deleting the last empty string
        i -= 2;

        auto key_longest_name = 0;
        auto max_name_size = 0;

        for ( int key = i; key > 0; key--){
            str = map_names.Find(key);
            auto name_size = str.rfind (' ') - str.find(' ');
            if ( name_size > max_name_size ){
                max_name_size = name_size;
                key_longest_name = key;
            }
        }

        cout << "Longest name is:\n" << map_names.Find(key_longest_name);
        cout << endl;


        cout << "Enter the last name for searching numbers: ";
        string str2;
        cin >> str2;
        cout << endl;

        for ( int key = i; key >= 0; key--){
            str = map_names.Find(key);
            if ( str.find (str2) != -1){
                cout << str.assign(str, str.rfind (',') + 1, 11) << endl;
            }
        }


    }catch (const std::exception &exp ) {
        cout << exp.what() << endl;
    }

    return 0;
}

#include "Map.h"
#include <fstream>
#include <filesystem>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using namespace std::filesystem;

int main()
{
    filesystem::path in (L"C:/Users/Novas/Documents/GitHub/ssw_lab_4sem/lab_04/src/name.txt");
   
    ifstream readFile;
    readFile.open(in);

    string name;
    string phone;

    Map<string, string> map;

    //struct main_struct { string name_str; string phone_str; };
    
    while (getline(readFile, name))
    {

        phone.insert(0, name, name.find(",") + 1, name.size() - name.find(","));
        name.erase(name.find(","), name.size() - name.find(","));
        map.emplace({name, phone});
        phone.clear();
        name.clear();
    }

    readFile.close();


    size_t size = 0;
    string test_name;
    string cmp;
    size_t save_pos;
    for (auto ptr = map.begin(); ptr != map.end(); ++ptr)
    {
        test_name = (*ptr).first;
        save_pos = test_name.find(" ");
        test_name.erase(save_pos, 1);
        if (test_name.find(" ")-save_pos > size) { size = test_name.find(" ") - save_pos; };
        test_name.insert(save_pos, " ");
    }

    cout << "Users with the longest name: " << endl;

    for (auto ptr = map.begin(); ptr != map.end(); ++ptr)
    {
        test_name = (*ptr).first;
        save_pos = test_name.find(" ");
        test_name.erase(save_pos, 1);
 
        if ((test_name.find(" ")-save_pos) == size)
        {
            test_name.insert(save_pos, " ");
            cout << (*ptr).first << " : " << (*ptr).second << endl;
        }
    }

    cout << endl << "Number of users with the same last name: " << endl;

    for (auto ptr = map.begin(); ptr != map.end();++ptr)
    {
        auto ptr_next = ptr;
        ++ptr_next;
        test_name.clear();
        test_name.insert(0, (*ptr).first, 0, (*ptr).first.find(" "));
        cout << test_name << ": " << endl;
        cout << "\t" <<(*ptr).second << endl;
        for (auto ptr2 = ptr_next; ptr2 != map.end();)
        {
            auto ptr2_next = ptr2;
            ++ptr2_next;

            cmp.clear();
            cmp.insert(0, (*ptr2).first, 0, (*ptr2).first.find(" "));
            if (cmp == test_name)
            {
                cout << "\t" << (*ptr2).second << endl;
                map.erase((*ptr2).first);
            }
            ptr2 = ptr2_next;
        }
    }
}

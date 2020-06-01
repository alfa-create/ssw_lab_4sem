#include "Map.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;
    string phone;
	ifstream in("C://Users/Novas/Documents/GitHub/ssw_lab_4sem/lab_04/src/name.txt");

    struct main_struct { string name_str; string phone_str; };
    int i = 0;

    Map<int, main_struct> map;
    if (in.is_open())
    {
        while (getline(in, name))
        {
            phone.insert(0, name, name.find(",") + 1, name.size() - name.find(","));
            name.erase(name.find(","), name.size() - name.find(","));
            map.emplace({ i, {name, phone} });
            phone.clear();
            name.clear();
            i++;
        }
    }
    in.close();

}

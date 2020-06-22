#include <iostream>
#include "TEST.h"
#include <fstream>
#include <string>


int main() {
    try{
        vector<int> numbers;

        cout << "\n Open file";
        fstream fin;
        fin.open(R"(C:\Users\User\Desktop\ssw_lab_4sem\lab_05\src\nums.txt)");

        int i = 0;
        if (fin){
            cout <<"\n Add numbers";
            while(!fin.eof() && i < 1000){
                string str;
                getline(fin,str);
                numbers.push_back(atoi(str.c_str()));
                i++;
            }
            fin.close();
        }
        else cout << endl << "error!" << endl;
        cout << "\nvector with 1000 el-t' was create";
        vector<int> nums10000;
        cout << "\ncreating vector with 10k element's";
        for ( int i =0; i < 50; i++){
            for (int j = 0; j < 1000; j++){
                nums10000.push_back(numbers.begin()[j]);
            }
            cout << "\n" << i << "/10";
        }
        test(nums10000);



    }catch (const std::exception &exp ) {
        cout << exp.what() << endl;
    }
    return 0;
}

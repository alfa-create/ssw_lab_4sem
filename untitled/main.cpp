#include <iostream>
#include "generator.h"
#include "my_stack.h"
#include "my_vector.h"
#include "my_queue.h"
using namespace std;

int main() {
    try {
        cout<<"\n"<<"My stack with 15 elements\ncomparison(>/<=), input/output\n";
        my_stack<int> test1;
        for (int i=0;i<15;i++)
        {
            cout<<i*2<<"\t";
            test1.push(i*2);
        };
        if (test1>test1)cout<<"1Yes";
        if (test1<=test1)cout<<"2Yes";
        cout<<endl;
        for (int i=0;i<15;i++)
        {
            cout<<test1.pop()<<"\t";
        };
        cout<<"\n"<<"My queue with 21 elements\ncomparison(!=)and count, input/output\n";
        my_queue<float> test2;
        for (int i=0;i<21;i++)
        {
            cout<<i*2.2<<"\t";
            test2.push(i*2.2);
        };
        if (test2!=test2)cout<<"Yes";
        cout<<"\n"<<test2.count()<<endl;
        for (int i=0;i<21;i++)
        {
            cout<<test2.pop()<<"\t";
        };
        cout<<"\n"<<"My vector with 5 elements\nat(2)and sum, input/output\n";
        my_vector<int> test3;
        for (int i=0;i<5;i++)
        {
            cout<<i*2<<"\t";
            test3.push(i*2);
        };
        cout<<"\tsum="<<test3.sum()<<"at(2)"<<test3.at(2)<<endl;
        for (int i=0;i<4;i++)
        {
            cout<<test3.pop()<<"\t";
        };
    }
    catch (const std::exception &exp) {
        cout << exp.what() << endl;
    }

    return 0;
}

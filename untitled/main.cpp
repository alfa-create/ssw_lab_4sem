#include <iostream>
#include <chrono>
#include <stack>
#include <queue>
#include <vector>
#include "generator.h"
#include "my_stack.h"
#include "my_vector.h"
#include "my_queue.h"

using namespace std;

int main() {
    try {
        using ms=std::chrono::milliseconds;
        cout << endl << "My stack with 15 elements" << endl << "comparison(>/<=), input/output" << endl;
        my_stack<int> test1;
        for (int i = 0; i < 15; i++) {
            cout << i * 2 << "\t";
            test1.Push(i * 2);
        };
        if (test1 > test1)cout << "1Yes" << endl;
        if (test1 <= test1)cout << "2Yes" << endl;
        for (int i = 0; i < 15; i++) {
            cout << test1.Pop() << "\t";
        };
        cout << endl << "My queue with 21 elements" << endl << "comparison(!=)and count, input/output" << endl;
        my_queue<float> test2;
        for (int i = 0; i < 21; i++) {
            cout << i * 2.2 << "\t";
            test2.Push(i * 2.2);
        };
        if (test2 != test2)cout << "Yes" << endl;
        cout << endl << "Count=" << test2.Count() << endl;
        for (int i = 0; i < 21; i++) {
            cout << test2.Pop() << "\t";
        };
        cout << endl << "My vector with 5 elements" << endl << "at(2)and sum, input/output" << endl;
        my_vector<int> test3;
        for (int i = 0; i < 5; i++) {
            cout << i * 2 << "\t";
            test3.Push(i * 2);
        };
        cout << "\tsum=" << test3.Sum() << "\tat(2)=" << test3.At(2) << endl;
        for (int i = 0; i < 5; i++) {
            cout << test3.Pop() << "\t";
        };


        cout<<endl<<"performance test"<<endl<<"my stack:";
        auto start = std::chrono::high_resolution_clock::now();
        my_stack<int> test_time;
        for (int i = 0; i < 9999; i++) {
            test_time.Push(i * 2);
        };
        if (test_time > test_time);
        if (test_time <= test_time);
        for (int i = 0; i < 9999; i++) {
            test_time.Pop();
        };
        auto end = std::chrono::high_resolution_clock::now();
        auto res=std::chrono::duration_cast<ms>(end-start).count();
        cout<<res<<endl<<"STL stack: ";

        start = std::chrono::high_resolution_clock::now();
        std::stack<int> test_time2;
        for (int i = 0; i < 9999; i++) {
            test_time2.push(i * 2);
        };
        if (test_time2 > test_time2);
        if (test_time2 <= test_time2);
        for (int i = 0; i < 9999; i++) {
            test_time2.pop();
        };
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ms>(end-start).count();
        cout<<res;

        cout<<endl<<"my queue: ";
        start = std::chrono::high_resolution_clock::now();
        my_queue<int> test_time3;
        for (int i = 0; i < 9999; i++) {
            test_time3.Push(i * 2);
        };
        if (test_time3 > test_time3);
        if (test_time3 <= test_time3);
        for (int i = 0; i < 9999; i++) {
            test_time3.Pop();
        };
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ms>(end-start).count();
        cout<<res<<endl<<"STL queue: ";

        start = std::chrono::high_resolution_clock::now();
        std::queue<int> test_time4;
        for (int i = 0; i < 9999; i++) {
            test_time4.push(i * 2);
        };
        if (test_time4 > test_time4);
        if (test_time4 <= test_time4);
        for (int i = 0; i < 9999; i++) {
            test_time4.pop();
        };
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ms>(end-start).count();
        cout<<res;

        cout<<endl<<"my vector: ";
        start = std::chrono::high_resolution_clock::now();
        my_vector<int> test_time5;
        for (int i = 0; i < 9999; i++) {
            test_time5.Push(i*2);
        };
        if (test_time5 > test_time5);
        if (test_time5 <= test_time5);
        for (int i = 0; i < 9999; i++) {
            test_time5.Pop();
        };
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ms>(end-start).count();
        cout<<res<<endl<<"STL vector: ";

        start = std::chrono::high_resolution_clock::now();
        std::vector<int> test_time6;
        for (int i = 0; i < 9999; i++) {
            test_time6.push_back(i * 2);
        };
        if (test_time6 > test_time6);
        if (test_time6 <= test_time6);
        for (int i = 0; i < 9999; i++) {
            test_time6.pop_back();
        };
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ms>(end-start).count();
        cout<<res;
    }
    catch (const std::exception &exp) {
        cout << exp.what() << endl;
    }

    return 0;
}

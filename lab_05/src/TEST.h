#ifndef LAB_05_TEST_H
#define LAB_05_TEST_H

#include <iostream>
#include "my_stack.h"
#include "my_queue.h"
#include "my_vector.h"
#include "my_double_linked_list.h"
#include "bin_tree.h"
#include <vector>
#include <chrono>


using namespace std;
using ns=std::chrono::milliseconds;

vector<int> test_stack ( vector<int> numbers ){
    cout << "\nstart testing stack:";
    my_stack<int> stack;
    vector<int> ret;
    ret.push_back(sizeof ( stack ));

    cout << "\ntest push el-t's";
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numbers.size(); i++){
        stack.Push(numbers.begin()[i]);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto res=std::chrono::duration_cast<ns>(end-start).count();
    ret.push_back(res);

    cout << "\ntest pop el-t's";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numbers.size(); i++){
        stack.Pop();
    }
    end = std::chrono::high_resolution_clock::now();
    res=std::chrono::duration_cast<ns>(end-start).count();
    ret.push_back(res);

    for (int i = 0; i < numbers.size(); i++){
        stack.Push(numbers.begin()[i]);
    }

    cout <<"\ntest peek el-t's";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numbers.size(); i++){
        stack.Peek();
    }
    end = std::chrono::high_resolution_clock::now();
    res=std::chrono::duration_cast<ns>(end-start).count();
    ret.push_back(res);

    cout << "\nend test stack";
    return ret;
}

vector<int> test_queue ( vector<int> numbers ){
    cout << "\nstart test queue:";
    my_queue<int> queue;
    vector <int> ret;
    ret.push_back(sizeof( queue ));

    cout << "\ntest push el-t's";
    auto start = std::chrono::high_resolution_clock::now();
    for ( int i = 0; i < numbers.size(); i++){
        queue.Push(numbers.begin()[i]);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto res = std::chrono::duration_cast<ns>(end-start).count();
    ret.push_back(res);

    cout << "\ntest pop el-t's";
    start = std::chrono::high_resolution_clock::now();
    for ( int i = 0; i < numbers.size(); i++){
        queue.Pop();
    }
    end = std::chrono::high_resolution_clock::now();
    res = std::chrono::duration_cast<ns>(end-start).count();
    ret.push_back(res);

    for ( int i = 0; i < numbers.size(); i++){
        queue.Push(numbers.begin()[i]);
    }

    cout << "\ntest peek el-t's";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numbers.size(); i++){
        queue.Peek();
    }
    end = std::chrono::high_resolution_clock::now();
    res=std::chrono::duration_cast<ns>(end-start).count();
    ret.push_back(res);

    cout << "\nend test queue";
    return ret;
}

vector<int> test_vector ( vector<int> numbers ){
    cout << "\nstart test vector";
    my_vector<int> vec;
    vector<int> ret;
    ret.push_back(sizeof( vec ));

    cout << "\npush el-t's";
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numbers.size(); i++){
        vec.Push(numbers.begin()[i]);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto res = std::chrono::duration_cast<ns>(end-start).count();
    ret.push_back(res);

    cout << "\npop el-t's";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numbers.size(); i++){
        vec.Pop();
    }
    end = std::chrono::high_resolution_clock::now();
    res = std::chrono::duration_cast<ns>(end-start).count();
    ret.push_back(res);

    for (int i = 0; i < numbers.size(); i++){
        vec.Push(numbers.begin()[i]);
    }

    cout << "\nat el-t's";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numbers.size(); i++){
        vec.At(numbers.size()/2);
    }
    end = std::chrono::high_resolution_clock::now();
    res = std::chrono::duration_cast<ns>(end-start).count();
    ret.push_back(res);

    cout << "\nend test vector";
    return ret;
}

vector<int> test_double_linked_list ( vector<int> numbers ){
    cout << "\nstart test list";
    my_double_linked_list<int> list;
    vector<int> ret;
    ret.push_back(sizeof( list ));

    cout << "\npush front el-t's";
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numbers.size(); i++){
        list.PushFront(numbers.begin()[i]);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto res = std::chrono::duration_cast<ns>(end-start).count();
    ret.push_back(res);

    cout << "\npush back el-t's";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numbers.size(); i++){
        list.PushBack(numbers.begin()[i]);
    }
    end = std::chrono::high_resolution_clock::now();
    res = std::chrono::duration_cast<ns>(end-start).count();
    ret.push_back(res);

    cout << "\npop front el-t's";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numbers.size(); i++){
        list.PopFront();
    }
    end = std::chrono::high_resolution_clock::now();
    res = std::chrono::duration_cast<ns>(end-start).count();
    ret.push_back(res);

    cout << "\npop back el-t's";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numbers.size(); i++){
        list.PopBack();
    }
    end = std::chrono::high_resolution_clock::now();
    res = std::chrono::duration_cast<ns>(end-start).count();
    ret.push_back(res);

    for (int i = 0; i < numbers.size(); i++){
        list.PushFront(numbers.begin()[i]);
    }

    cout << "\nfind index";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numbers.size() ; i++){
        list.FindIndex(numbers.begin()[i]);
    }
    end = std::chrono::high_resolution_clock::now();
    res = std::chrono::duration_cast<ns>(end-start).count();
    ret.push_back(res);

    cout << "end test list";
    return ret;
}


vector<int> test_bin_tree ( vector<int> numbers ){
    cout << "\nstart testing bin_tree";
    vector<int> ret;
    bin_tree<int> tree;
    ret.push_back(sizeof(tree));

    cout << "\ntest push el-t's" << endl;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numbers.size(); i++){
        cout << i << endl;
        tree.Push(numbers.begin()[i]);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto res = std::chrono::duration_cast<ns>(end-start).count();
    ret.push_back(res);

    cout << "\ntest find el-t's";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numbers.size(); i++){
        cout << i << endl;
        tree.Find(numbers.begin()[i]);
    }
    end = std::chrono::high_resolution_clock::now();
    auto res2 = std::chrono::duration_cast<ns>(end-start).count();


    cout << "\ntest pop el-t's";
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numbers.size() - 1 ; i++){
        cout << i << endl;
        tree.Pop();
    }
    end = std::chrono::high_resolution_clock::now();
    res = std::chrono::duration_cast<ns>(end-start).count();
    ret.push_back(res);
    ret.push_back(res2);
    cout << "\nend testing bin_tree";
    return ret;
}

void test ( vector<int> numbers ){
    cout << "\nstart test";
    auto st = test_stack ( numbers );//size/push/pop/peek
    auto queue = test_queue( numbers );//size/push/pop/peek
    auto vec = test_vector ( numbers );//size/push/pop/at
    auto list = test_double_linked_list( numbers );//size/pushFr/pushBack/PopFr/PopBack/FindIndex
    auto bin_tree = test_bin_tree( numbers );//size/push/pop/find

    cout << "\nend testing";
    cout << endl;
    cout << "type\tstack\tqueue\tvector\tlist\tbin_tree\n";

    for (int i = 0; i < 6; i++){
        if ( i == 0 ){
            cout << "size:\t" << st[i] << "\t" << queue[i] <<"\t";
            cout << vec[i] <<"\t" <<list[i]<<"\t" << bin_tree[i] << endl;
        }
        if ( i == 1 ){
            cout << "pushFr\t" << st[i] << "\t---\t---\t";
            cout << list[i] << "\t" << bin_tree[i];
            cout << endl;
        }
        if ( i == 2 ){
            cout << "pushBk\t---\t" << queue[1] << "\t" << vec[1] << "\t";
            cout << list[i] << "\t---";
            cout << endl;
        }
        if ( i == 3 ){
            cout << "popFr\t" << st[2] << "\t" << queue[2] << "\t---\t";
            cout << list[i] << "\t" << bin_tree[2];
            cout << endl;
        }
        if ( i == 4 ){
            cout << "popBk\t---\t---\t" << vec[2] << "\t";
            cout << list[i] << "\t---";
            cout << endl;
        }
        if ( i == 5 ){
            cout << "findEl\t" << st[3] << "\t" << queue[3] << "\t" << vec[3] << "\t";
            cout << list[i] << "\t" << bin_tree[3];
            cout << endl;
        }
    }
}
#endif //LAB_05_TEST_H

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

        using ns=std::chrono::nanoseconds;

        my_stack<int> stack1;
        std::stack<int> stack2;
        my_queue<float> queue1;
        std::queue<float> queue2;
        my_vector<int> vector1;
        std::vector<int> vector2;

        cout<<endl;
        cout<<"\t\t\tPerformance comparison results"<<endl;
        cout<<"\t\t\t  (all results in nanoseconds)"<<endl;
        cout<<"type\t\t"<<"push\t\t"<<"pop\t\t"<<"peek\t\t"<<"count\t\t"<<"at"<<endl;
        cout<<"my_stack\t";

        auto start = std::chrono::high_resolution_clock::now();
        stack1.Push(99);
        auto end = std::chrono::high_resolution_clock::now();
        auto res=std::chrono::duration_cast<ns>(end-start).count();
        cout<<res<<"\t\t";

        start = std::chrono::high_resolution_clock::now();
        stack1.Pop();
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ns>(end-start).count();
        cout<<res<<"\t\t";

        stack1.Push(23);

        start = std::chrono::high_resolution_clock::now();
        stack1.Peek();
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ns>(end-start).count();
        cout<<res<<"\t\t";

        start = std::chrono::high_resolution_clock::now();
        stack1.Count();
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ns>(end-start).count();
        cout<<res<<"\t\t";
        cout<<"----"<<endl;

        cout<<"STL stack\t";

        start = std::chrono::high_resolution_clock::now();
        stack2.push(99);
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ns>(end-start).count();
        cout<<res<<"\t\t";

        start = std::chrono::high_resolution_clock::now();
        stack2.pop();
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ns>(end-start).count();
        cout<<res<<"\t\t";

        stack2.push(23);
        int b = 0;

        start = std::chrono::high_resolution_clock::now();
        b = stack2.top();
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ns>(end-start).count();
        cout<<res<<"\t\t";

        stack2.push(23);

        start = std::chrono::high_resolution_clock::now();
        b=stack2.size();
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ns>(end-start).count();
        cout<<res<<"\t\t";
        cout<<"----"<<endl;

        cout<<"my_queue\t";
        start = std::chrono::high_resolution_clock::now();
        queue1.Push(2.1);
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ns>(end-start).count();
        cout<<res<<"\t\t";

        start = std::chrono::high_resolution_clock::now();
        queue1.Pop();
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ns>(end-start).count();
        cout<<res<<"\t\t";

        start = std::chrono::high_resolution_clock::now();
        queue1.Peek();
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ns>(end-start).count();
        cout<<res<<"\t\t";

        start = std::chrono::high_resolution_clock::now();
        queue1.Count();
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ns>(end-start).count();
        cout<<res<<"\t\t";
        cout<<"----"<<endl;

        cout<<"STL queue\t";

        start = std::chrono::high_resolution_clock::now();
        queue2.push(2.2);
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ns>(end-start).count();
        cout<<res<<"\t\t";

        start = std::chrono::high_resolution_clock::now();
        queue2.pop();
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ns>(end-start).count();
        cout<<res<<"\t\t";

        float b2=0;
        queue2.push(22);

        start = std::chrono::high_resolution_clock::now();
        b2=queue2.front();
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ns>(end-start).count();
        cout<<res<<"\t\t";

        start = std::chrono::high_resolution_clock::now();
        b=queue2.size();
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ns>(end-start).count();
        cout<<res<<"\t\t";
        cout<<"----"<<endl;

        cout<<"my_vector\t";

        start = std::chrono::high_resolution_clock::now();
        vector1.Push(22);
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ns>(end-start).count();
        cout<<res<<"\t\t";

        start = std::chrono::high_resolution_clock::now();
        vector1.Pop();
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ns>(end-start).count();
        cout<<res<<"\t\t";
        cout<<"----\t\t";

        vector1.Push(22);

        start = std::chrono::high_resolution_clock::now();
        vector1.Count();
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ns>(end-start).count();
        cout<<res<<"\t\t";

        start = std::chrono::high_resolution_clock::now();
        vector1.At(0)=1;
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ns>(end-start).count();
        cout<<res<<"\t\t"<<endl;

        cout<<"STL vector\t";

        start = std::chrono::high_resolution_clock::now();
        vector2.push_back(22);
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ns>(end-start).count();
        cout<<res<<"\t\t";

        start = std::chrono::high_resolution_clock::now();
        vector2.pop_back();
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ns>(end-start).count();
        cout<<res<<"\t\t";
        cout<<"----\t\t";

        vector2.push_back(22);

        start = std::chrono::high_resolution_clock::now();
        b=vector2.size();
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ns>(end-start).count();
        cout<<res<<"\t\t";

        start = std::chrono::high_resolution_clock::now();
        vector2.at(0)=1;
        end = std::chrono::high_resolution_clock::now();
        res=std::chrono::duration_cast<ns>(end-start).count();
        cout<<res<<"\t\t";
    }
    catch (const std::exception &exp) {
        cout << exp.what() << endl;
    }

    return 0;
}

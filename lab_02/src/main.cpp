#include <iostream>
#include"simple_list.h"
#include"forward_list.h"
#include"my_ring_buffer.h"

using namespace std;

int main() {
    try{

        cout<<"\t\t\tTEST list:\n";
        my_list<int> test1;

        cout<<"numbers for push front in list:\n";
        for (int i = 0; i < 15; i++){
            test1.PushFront(i*2);
            cout<<i*2<<"\t";
        }
        cout<<"\nList: \n"<<test1<<endl;

        cout<<"numbers for push back in list:\n";
        for (int i = 0; i < 5; i++){
            test1.PushBack(i);
            cout<<i<<"\t";
        }
        cout<<"\nList: \n"<<test1<<endl;

        cout<<"list pop front:\n";
        for (int i = 0; i < 8; i++){
            cout<<test1.PopFront()<<"\t";
        }
        cout<<"\n List: \n"<<test1<<endl;


        cout<<"list pop Back:\n";
        for (int i = 0; i < 8; i++){
            cout<<test1.PopBack()<<"\t";
        }
        cout<<"\n List: \n"<<test1<<endl;

        cout<<"insert 25 with index 1\n";
        test1.Insert(25,1);
        cout<<test1<<endl;

        cout<<"Erase 25 with index 1\n";
        test1.Erase(1);
        cout<<test1<<endl;

        cout<<"First and last el-t's:\n";
        cout<<*test1.Begin()<<"\t"<<*test1.End()<<endl;

        cout<<"Count:\n"<<test1.Count()<<endl;

        my_list<int> test1_ {20,12,3};

        cout<<endl;
        cout<<"first list:\n"<<test1<<endl;
        cout<<"second list: \n"<<test1_<<endl;

        if (test1 > test1_) cout<<"First more then second\n";
        else cout<<"Second more then first\n";

        if (test1 == test1_) cout<<"first == second"<<endl;
        else cout<<"first != second"<<endl;


        cout<<endl<<endl;
        cout<<"TEST forward list:\n";

        my_double_linked_list<int> test2;

        cout<<"number for push front in list:\n";
        for (int i = 0; i < 15; i++){
            test2.PushFront(i*2);
            cout<<i*2<<"\t";
        }
        cout<<"\nList: \n"<<test2<<endl;

        cout<<"number for push back in list:\n";
        for (int i = 0; i < 5; i++){
            test2.PushBack(i);
            cout<<i<<"\t";
        }
        cout<<"\nList: \n"<<test2<<endl;

        cout<<"list pop front:\n";
        for (int i = 0; i < 8; i++){
            cout<<test2.PopFront()<<"\t";
        }
        cout<<"\n List: \n"<<test2<<endl;


        cout<<"list pop Back:\n";
        for (int i = 0; i < 8; i++){
            cout<<test2.PopBack()<<"\t";
        }
        cout<<"\n List: \n"<<test2<<endl;

        cout<<"insert 25 with index 1\n";
        test2.Insert(25,1);
        cout<<test2<<endl;

        cout<<"Erase 25 with index 1\n";
        test2.Erase(1);
        cout<<test2<<endl;

        cout<<"First and last el-t's:\n";
        cout<<*test2.Begin()<<"\t"<<*test2.End()<<endl;

        cout<<"Count:\n"<<test2.Count()<<endl;

        my_double_linked_list<int> test2_ {20,12,3};

        cout<<endl;
        cout<<"first list:\n"<<test2<<endl;
        cout<<"second list: \n"<<test2_<<endl;

        if (test2 > test2_) cout<<"First more then second\n";
        else cout<<"Second more then first\n";

        if (test2 == test2_) cout<<"first == second"<<endl;
        else cout<<"first != second"<<endl;


        /////////////////////////////
        cout<<endl<<endl<<endl;
        cout<<"Test ring buffer:\n";
        my_ring_buffer<int> test3(5);

        cout<<"Element's for input to buffer(size = 5): \n";
        for (int i = 0; i < 8;i++){
            test3.PushBack(i*2);
            cout<<i*2<<"\t";
        }
        cout<<"\nbuffer:\n"<<test3<<endl;

        cout<<"head:\n";
        cout<<*test3.Begin()<<endl;
        cout<<"tail:\n";
        cout<<*test3.End()<<endl;

        cout<<"pop 4 el-t's:\n";
        for (int i = 0; i < 4; i++){
            cout<<test3.PopFront()<<"\t";
        }
        cout<<"\n Buffer:\n"<<test3<<endl;

        cout<<"Count: "<<test3.Count() << endl;


        my_ring_buffer<int> test3_{1,2,3,4,5};

        cout<<"buf 1: "<<test3<<endl;
        cout<<"buf 2: "<<test3_<<endl;

        if (test3 > test3_) cout<<"first more then second\n";
        else cout<<"second more then first\n";

        if (test3 == test3_) cout<<"first == second\n";
        else cout<<"second != first\n";

    } catch (const std::exception &exp) {
    cout << exp.what() << endl;
}
    return 0;
}

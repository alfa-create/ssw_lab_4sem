#include <iostream>
#include "bin_tree.h"
#include "gen_tree.h"

using namespace std;

int main() {
    try{
    /*bin_tree<int> tr1{11,22,33,33,43,53};
    bin_tree<int> tr2{11,22,33,22};

    if (tr1 == tr2 ) cout << "ravno";
    if (tr1 > tr2 ) cout << "more";
    tr1.Print();
    cout << endl;
    cout << tr1.Height();
    cout << endl;
    auto res = tr1.Path(22);
    cout << get<0>(res);*/

    gen_tree<int> tr3{1,3,2,4,5};
    gen_tree<int> tr4{1,3,2};
    tr3.Print();
    auto res = tr3.Find(2);
    tr3.Push(get<0>(res),22);
    tr3.Print();
    auto res3 = tr3.Path(22);
    cout << endl;
    cout << get<0>(res3);
    cout << endl;
    cout << tr3.SumTrees(tr3);
    cout << endl;
    if ( tr3 == tr3 ) cout << "equally";
    cout << endl;
    if ( tr3 > tr4 ) cout << "more";
} catch (const std::exception &exp ) {
        cout << exp.what() << endl;
    }
    return 0;
}

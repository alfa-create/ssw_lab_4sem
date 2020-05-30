#include <iostream>
#include "tree.h"
#include "bin_tree.h"

using namespace std;

int main() {
    try{


    /*bin_tree<int> tree;
    bin_tree<int> tree2;

    tree.Push(12);
    tree.Push(22);
    tree.Print();
    tree2.Push(5);
    tree2.Push(9);
    tree2.Print();
    tree.Swap(tree2);
    tree.Print();
    tree2.Print();
    cout << endl;
    cout << tree.SumTrees(tree2);
    if (tree > tree2) cout<<">";
    if (tree == tree2) cout<<"==";
    if (tree != tree2) cout<<"!=";*/
    /*std::variant<int> val;
    val = tree.Path(2);
    std::visit([](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        cout << "int with value " << arg << '\n';
    }, val);

    tree<int> tr{111, 22, 33, 55};
    tr.Print();
    tr.Print();
    cout << "sum="<<tr.SumTrees(tr);*/

    bin_tree<int> tr1{11,22,33,33};
    bin_tree<int> tr2{11,22,33,22};
    if (tr1 == tr2 ) cout << "ravno";
    if (tr1 > tr2 ) cout << "more";
    cout << "_______";
    tree<int> tr3 {11,22,33,33};
    tree<int> tr4 {11,22,33,1};
    tr3.Print();
    tr4.Print();
    if (tr3 == tr4 ) cout << "ravno";
    if (tr3 > tr4 ) cout << "more";

} catch (const std::exception &exp ) {
        cout << exp.what() << endl;
    }
    return 0;
}

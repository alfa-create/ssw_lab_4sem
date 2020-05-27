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
    }, val);*/

    tree<int> tr{111};
    tr.Print();

    tr.Push(11,2);
    tr.Push(2,8);
    tr.Push(2,8);
    tr.Push(2,8);
    tr.Print();
    cout << "sum="<<tr.SumTrees(tr);
} catch (const std::exception &exp ) {
        cout << exp.what() << endl;
    }
    return 0;
}

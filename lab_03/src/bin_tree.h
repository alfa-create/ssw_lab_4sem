#ifndef LAB_03_BIN_TREE_H
#define LAB_03_BIN_TREE_H

#include <variant>

template <class T>
class bin_tree {
private:
    class node{
    public:

        node* ptrLeft { nullptr };
        node* ptrRight { nullptr };
        T value { 0 };

        explicit node(T data, node* linkLeft = nullptr, node* linkRight = nullptr){
            ptrLeft = linkLeft;
            ptrRight = linkRight;
            value = data;
        }
        ~node() = default;
    };

    node* root {nullptr };
    size_t size { 0 };
    void PrintPreorder (node* head);
    size_t NodeHeight (node* head);

    int BalanceFactor (node* p){
        return NodeHeight(p->ptrRight)-NodeHeight(p->ptrLeft);
    };

    node* RotateRight (node* p){
        node* q = p->ptrLeft;
        p->ptrLeft = q->ptrRight;
        q->ptrRight = p;
        NodeHeight(p);
        NodeHeight(q);
        return q;
    }

    node* RotateLeft (node* q){
        node* p = q->ptrRight;
        q->ptrRight = p->ptrLeft;
        p->ptrLeft = q;
        NodeHeight(q);
        NodeHeight(p);
        return p;
    }

    node* BalanceNode (node* p){
        NodeHeight(p);
        if( BalanceFactor(p)==2 )
        {
            if( BalanceFactor(p->ptrRight) < 0 )
                p->ptrRight = RotateRight(p->ptrRight);
            return RotateLeft(p);
        }
        if( BalanceFactor(p)==-2 )
        {
            if( BalanceFactor(p->ptrLeft) > 0  )
                p->ptrLeft = RotateLeft(p->ptrLeft);
            return RotateRight(p);
        }
        return p;
    }

    T SumNodes (node* p);
    void DeleteTree (node* p);

public:
    bin_tree() = default;
    bin_tree(const std::initializer_list<T> &list);
    ~bin_tree(){
        DeleteTree(root);
    }
    void Push (T data );
    void Print();
    void Pop ( T data );
    size_t Height ();
    std::variant<T> Path (T data );
    T SumTrees(bin_tree<T> &m);

    node* Find( T data ){
        node* current = root;
        while ( current != nullptr ){
            if ( current->value == data ) return current;
            if ( data < current->value ) current = current->ptrLeft;
            else current = current->ptrRight;
        }
        throw std::out_of_range("tree haven't element with this value");
    };
    size_t Count(){
        return size;
    }
    void Swap (bin_tree<T> &m){
        node* p = this->root;
        this->root = m.root;
        m.root = p;
    }

    bool operator == (bin_tree<T> const &m);
    bool operator != (bin_tree<T> const &m){
        return !(this->operator==(m));
    };
    bool operator > (bin_tree<T> const &m);
    bool operator < (bin_tree<T> const &m){
        return !(this->operator>=(m));
    };
    bool operator >= (bin_tree<T> const &m){
        return (this->operator>(m) || this->operator==(m));
    };
    bool operator <= (bin_tree<T> const &m){
        return !(this->operator>(m));
    };

};

template<class T>
void bin_tree<T>::Push(T data) {
    if ( root == nullptr ){
        root = new node ( data );
    }
    else {
        node* current = root;
        node* previous = root;
        while ( current != nullptr) {
            previous = current;
            if ( data < current->value ) current = current->ptrLeft;
            else current = current->ptrRight;
        }
        if ( data < previous->value) previous->ptrLeft = new node (data);
        else previous->ptrRight = new node (data);

    }
    size++;
    root = BalanceNode(root);
}

template<class T>
void bin_tree<T>::Print() {
    if (size == 0) throw std::out_of_range("tree is empty");
    std::cout << std::endl;
    PrintPreorder ( root );
    std::cout << std::endl;
}

template<class T>
void bin_tree<T>::PrintPreorder(bin_tree::node *head) {
    if ( head == nullptr ){
        std::cout << ".";
        return;
    }
    std::cout << head->value << " ";
    PrintPreorder( head->ptrLeft);
    PrintPreorder( head->ptrRight);
}

template<class T>
void bin_tree<T>::Pop(T data) {
    if ( size == 0 ) throw std::out_of_range ("tree is empty");
    node* current = root;
    node* previous = root;
    while ( current != nullptr ){
        if ( current->value != data ) previous = current;
        if ( data < current->value ) current = current->ptrLeft;
        else {
            if ( data > current->value ) current = current->ptrRight;
            else break;
        }
    }
    if ( current == nullptr ) throw std::out_of_range("tree haven't element with this value");
    if ( current->ptrRight == nullptr && current->ptrLeft == nullptr) {
        delete current;
        if ( data < previous->value ) previous->ptrLeft = nullptr;
        else previous->ptrRight = nullptr;
    }
    else throw std::out_of_range ("tree haven't list with this value");

    size--;
    if ( size == 0 ) root = nullptr;
    else root = BalanceNode(root);
}

template<class T>
size_t bin_tree<T>::NodeHeight(bin_tree::node *head) {
    size_t s = 0, l = 0, r = 0;
    if ( head != nullptr ){
        l = NodeHeight( head->ptrLeft );
        r = NodeHeight( head->ptrRight );
        s = ((l > r) ? l : r) + 1;
    }
    return s;
}

template<class T>
size_t bin_tree<T>::Height() {
    return NodeHeight(root);
}

template<class T>
std::variant<T> bin_tree<T>::Path(T data) {
    node* current = root;
    std::variant<int> val;
    int hight = 0;
    while ( current != nullptr ){
        if ( data < current->value ) current = current->ptrLeft;
        else {
            if ( data > current->value ) current = current->ptrLeft;
            else val = hight;
        }
        hight++;
    }
    return val;
    //при вызове функции зависает программа (i need your heeeelp<3)
}

template<class T>
T bin_tree<T>::SumTrees(bin_tree<T> &m) {
    return SumNodes(this->root) + SumNodes(m.root);
}

template<class T>
T bin_tree<T>::SumNodes(bin_tree::node *p) {
    T sum = 0;
    if ( p == nullptr ){
        return sum;
    }
    else{
        sum += p->value;
        sum += SumNodes(p->ptrLeft);
        sum += SumNodes(p->ptrRight);
    }
    return sum;
}

template<class T>
void bin_tree<T>::DeleteTree(bin_tree::node *p) {
    if (p != nullptr ){
        DeleteTree(p->ptrLeft);
        DeleteTree(p->ptrRight);
        delete p;
        p = nullptr;
    }
    else return;
}

template<class T>
bool bin_tree<T>::operator==(const bin_tree<T> &m) {
    return true;
}

template<class T>
bool bin_tree<T>::operator>(const bin_tree<T> &m) {
    return false;
}

template<class T>
bin_tree<T>::bin_tree(const std::initializer_list<T> &list) {
    for ( int i = 0; i < list.size(); i++){
        Push(list.begin()[i]);
    }
}


#endif //LAB_03_BIN_TREE_H

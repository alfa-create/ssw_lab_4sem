#ifndef LAB_03_TREE_H
#define LAB_03_TREE_H

#include <variant>

template <class T>
class tree {
private:
    class node{
    public:
        T value;
        node* downLvl { nullptr };
        node* thisLvl { nullptr };

        explicit node (T data, node* ptrDown = nullptr, node* ptrThis = nullptr){
            value = data;
            downLvl = ptrDown;
            thisLvl = ptrThis;
        }
        ~node() = default;
    };

    node* root { nullptr };
    size_t size { 0 };

    void DeleteNode ( node* p);
    size_t HeightNode (node *p);
    void PrintPreorder(node *p);
    T SumNodes (node *p);

    node* FindNode ( T data, node* p){
        if (size == 0) throw std::out_of_range("tree is empty");
        if ( p->value == data ) return p;
        else {
            node *result = nullptr;
            for (node *current = p->downLvl; current; current = current->thisLvl) {
                node *ptr = FindNode(data, current);
                if (ptr != nullptr) result = ptr;
            }
            return result;
        }
    }


public:
    tree() = default;
    tree(const std::initializer_list<T> &list);
    ~tree(){
        DeleteNode(root);
    };
    void Push(T key, T data);
    void Print ();
    void Pop(T key);
    size_t Height();
    std::variant<T> Path (T data);
    T SumTrees(tree<T> &m);

    void Swap (tree<T> &m){
        node* p = this->root;
        this->root = m.root;
        m.root = p;
    }
    size_t Count (){
        return size;
    }
    node* Find(T data){
        return FindNode(data, root);
    }

};

template<class T>
void tree<T>::Push(T key, T data) {
    if ( size == 0 ) root = new node (data);
    else {
        node *current = FindNode(key, root);
        if ( current == nullptr) throw std::out_of_range("tree haven't this key");
        if (current->downLvl == nullptr) {
            current->downLvl = new node(data);
        } else {
            while (current->downLvl != nullptr) {
                current = current->downLvl;
            }
            current->downLvl = new node(data);
        }
    }
    size++;
}

template<class T>
void tree<T>::DeleteNode(tree::node *p) {
    if ( p != nullptr ){
        DeleteNode(p->downLvl);
        DeleteNode(p->thisLvl);
        size--;
        delete p;
        p = nullptr;
    }
}

template<class T>
size_t tree<T>::HeightNode(tree::node *p) {
    if ( p == nullptr ){
        return 0;
    }
    size_t maxHeight = 0;
    for (node* current = p->downLvl; current; current = current->thisLvl){
        size_t height = HeightNode(current);
        if (height > maxHeight) maxHeight = height;
    }
    return maxHeight + 1;
}

template<class T>
void tree<T>::Print() {
    if (size == 0 ) throw std::out_of_range("tree is empty");
    std::cout << std::endl;
    PrintPreorder(root);
    std::cout << std::endl;
}

template<class T>
void tree<T>::PrintPreorder(node* p) {
    if ( p == nullptr){
        std::cout << ".";
        return;
    }
    std::cout << p->value << " ";
    PrintPreorder(p->downLvl);
    PrintPreorder(p->thisLvl);
}

template<class T>
size_t tree<T>::Height() {
    return HeightNode(root);
}

template<class T>
void tree<T>::Pop(T key) {
    node* current = FindNode(key, root);
    if ( current == nullptr ) throw std::out_of_range("tree haven't this key");
    if ((current->thisLvl == nullptr) && (current->downLvl == nullptr))
        DeleteNode(current);
    else throw std::out_of_range("node have a potomki");
    if (size == 0 ) root = nullptr;
}

template<class T>
std::variant<T> tree<T>::Path(T data) {

}

template<class T>
T tree<T>::SumTrees(tree<T> &m) {
    return SumNodes(this->root) + this->root->value + SumNodes(m.root) + m.root->value ;
}

template<class T>
T tree<T>::SumNodes(tree::node *p) {
    T sum = 0;
    if ( p == nullptr ){
        return sum;
    }
    else{
        for (node* current = p->downLvl; current; current = current->thisLvl){
            sum+= current->value;
            sum+= SumNodes(current);
        }
    }
    return sum;
}

template<class T>
tree<T>::tree(const std::initializer_list<T> &list) {
    for ( int i = 0; i < list.size(); i++){
        if ( i == 0) Push(11, list.begin()[i]);
        else Push(root->value, list.begin()[i]);
        size++;
    }
}


#endif //LAB_03_TREE_H

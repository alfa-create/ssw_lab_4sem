#ifndef LAB_03_GEN_TREE_H
#define LAB_03_GEN_TREE_H
#include <vector>

template <class T>
class gen_tree {

private:
    class node{
    public:
        T value { 0 };
        std::vector<node*> points;

        explicit node (T data){
            value = data;
            points.clear();
        }
        ~node() = default;
    };

    std::vector<node*> forfind;
    std::vector<int> forhight;
    node* root { nullptr };
    size_t size { 0 };
    void PrintPreorder(const node* p);
    void FindNode(T data, node* p);
    void FindParent (node* p);
    size_t NodeHeight (const node* p);
    int NodePath (const node* p, T data);
    T SumNodes ( const node* p);
    bool ComparisonEqually(const node *p, const node *p1);
    bool ComparisonMore(const node *p, const node *p1);

public:
    gen_tree() = default;
    ~gen_tree() = default;
    gen_tree(const std::initializer_list<T> &list);
    void Push(node* p, T data);
    void Push(T data);
    void Print();
    void Pop(node* p);
    std::variant<int, std::vector<int>> Path (T data);
    size_t Count(){
        return size;
    }
    size_t Height ();

    std::variant<node*, std::vector<node*>> Find (T data){
        if ( size == 0) throw std::out_of_range("tree is empty");
        forfind.clear();
        FindNode(data, root);
        if ( forfind.empty()) throw std::out_of_range(" tree is haven't this element");
        if ( forfind.size() == 1 ) return forfind.front();
        return forfind;
    };

    void swap (gen_tree<T> &m);
    T SumTrees (gen_tree<T> const &m);

    bool operator == (gen_tree<T> const &m);
    bool operator != (gen_tree<T> const &m){
        return !(this->operator==(m));
    };
    bool operator > (gen_tree<T> const &m);
    bool operator < (gen_tree<T> const &m){
        return !(this->operator>=(m));
    };
    bool operator >= (gen_tree<T> const &m){
        return (this->operator>(m) || this->operator==(m));
    };
    bool operator <= (gen_tree<T> const &m){
        return !(this->operator>(m));
    };
};

template<class T>
gen_tree<T>::gen_tree(const std::initializer_list<T> &list) {
    for ( int i = 0; i < list.size(); i++){
        if ( i == 0) Push(list.begin()[i]);
        else Push(root, list.begin()[i]);
    }
}


template<class T>
void gen_tree<T>::Push(gen_tree::node *p, T data) {
    if ( size == 0) root = new node(data);
    else{
        p->points.push_back(new node(data));
    }
    size++;
}

template<class T>
void gen_tree<T>::Push(T data) {
    if ( size != 0 ) throw std::out_of_range("tree is not empty");
    else root = new node(data);
    size++;
}

template<class T>
void gen_tree<T>::Print() {
    if (size == 0) throw std::out_of_range("tree is empty");
    std::cout << std::endl;
    PrintPreorder(root);
    std::cout << std::endl;
}

template<class T>
void gen_tree<T>::PrintPreorder(const node* p) {
    if ( p == nullptr ) {
        std::cout << ".";
        return;
    }
    std::cout << " " << p->value << " ";
    for ( int i = 0; i< p->points.size(); i++ ){
        PrintPreorder(p->points.begin()[i]);
        std::cout << ".";
    }

}

template<class T>
void gen_tree<T>::FindNode(T data, gen_tree::node *p) {
    if ( p == nullptr ) return;
    if ( p->value == data ) forfind.push_back(p);
    for ( int i = 0; i< p->points.size(); i++ ){
        FindNode(data, p->points.begin()[i]);
    }
}

template<class T>
void gen_tree<T>::Pop(node* p) {
    if ( size == 0 ) throw std::out_of_range("tree is empty");
    if (p->points.size() != 0 ) throw std::out_of_range("this element is not list");
    forfind.clear();
    forfind.push_back(p);
    FindParent(root);
}

template<class T>
void gen_tree<T>::FindParent(node* p) {
    for ( int i = 0; i < p->points.size();i++){
        if ( p->points.begin()[i] == forfind.begin()[0] ) {
            forfind.push_back(p);
            auto res = p->points;
            res.erase(res.begin()[i]);
            break;
        }
        FindParent(p->points.begin()[i]);
    }
}

template<class T>
size_t gen_tree<T>::NodeHeight(const gen_tree::node *p) {
    if ( p == nullptr ) return 0;
    size_t maxHeight = 0;
    for ( int i = 0; i < p->points.size(); i++){
        size_t height = NodeHeight(p->points.begin()[i]);
        if ( height > maxHeight ) maxHeight = height;
    }
    return maxHeight + 1;
}

template<class T>
size_t gen_tree<T>::Height() {
    if ( size == 0 ) throw std::out_of_range("tree is empty");
    if ( size == 1 ) return 0;
    return NodeHeight(root);
}

template<class T>
std::variant<int, std::vector<int>> gen_tree<T>::Path(T data) {
    if ( size == 0 ) throw std::out_of_range("tree is empty");
    forhight.clear();
    NodePath(root, data);
    if (forhight.size() == 0) throw std::out_of_range("tree is haven't this element");
    if (forhight.size() == 1) return forhight.begin()[0];
    else return forhight;

}

template<class T>
int gen_tree<T>::NodePath(const node* p, T data) {
    int height = 0;
    for ( int i = 0; i < p->points.size(); i++){
        height = NodePath(p->points.begin()[i], data);
    }
    height++;
    if ( p->value == data ) forhight.push_back(height + 1);
    return height;
}

template<class T>
void gen_tree<T>::swap(gen_tree<T> &m) {
    node* cur = this->root;
    m.root = this->root;
    this->root = cur;
}

template<class T>
T gen_tree<T>::SumTrees(const gen_tree<T> &m) {
    return SumNodes(this->root) + SumNodes(m.root);
}

template<class T>
T gen_tree<T>::SumNodes(const gen_tree::node *p) {
    T sum = 0;
    if ( p == nullptr ) return sum;
    sum+= p->value;
    for (int i = 0; i < p->points.size(); i++){
        sum+= SumNodes (p->points.begin()[i]);
    }
    return sum;
}

template<class T>
bool gen_tree<T>::operator==(const gen_tree<T> &m) {
    if ( this->size == 0 || m.size == 0 ) throw std::out_of_range ("tree is empty");
    return ComparisonEqually(this->root, m.root);
}

template<class T>
bool gen_tree<T>::operator>(const gen_tree<T> &m) {
    if ( this->size == 0 || m.size == 0 ) throw std::out_of_range ("tree is empty");
    return ComparisonMore(this->root, m.root);
}

template<class T>
bool gen_tree<T>::ComparisonEqually(const gen_tree::node *p, const gen_tree::node *p1) {
    if (p == nullptr && p1 == nullptr) return true;
    if (p == nullptr || p1 == nullptr) return false;
    bool ans = true;
    ans = (p->value == p1->value);
    if (!ans) return false;
    ans = p->points.size() == p1->points.size();
    if (ans) {
        for (int i = 0; i < p->points.size(); i++) {
            ans = ComparisonEqually(p->points.begin()[i], p1->points.begin()[i]);
        }
    } else return false;
    return ans;
}

template<class T>
bool gen_tree<T>::ComparisonMore(const gen_tree::node *p, const gen_tree::node *p1) {
    if ( p != nullptr && p1 == nullptr ) return true;
    if ( p == nullptr && p1 != nullptr ) return false;
    if ( p == nullptr && p1 == nullptr ) return true;
    bool ans = true;
    ans = (p->value >= p1->value);
    if (!ans) return false;
    if (p->points.size() > p1->points.size()) return true;
    ans = p->points.size() == p1->points.size();
    if (ans) {
        for (int i = 0; i < p->points.size(); i++) {
            ans = ComparisonEqually(p->points.begin()[i], p1->points.begin()[i]);
        }
    } else return false;
    return ans;
}


#endif //LAB_03_GEN_TREE_H

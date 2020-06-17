#ifndef LAB_04_MAP_H
#define LAB_04_MAP_H

template <typename T_key, typename T_val>
class map {
private:
    struct data{
        T_key key;
        T_val val;
    };
    class node{
    public:
        data value;
        node* ptrLeft { nullptr };
        node* ptrRight { nullptr };

        explicit node(data data, node* linkLeft = nullptr, node* linkRight = nullptr){
            value = data;
            ptrLeft = linkLeft;
            ptrRight = linkRight;
        }
        ~node() = default;
    };
    node* root { nullptr };
    size_t size { 0 };

    node* RotateRight (node* p){
        node* q = p->ptrLeft;
        p->ptrLeft = q->ptrRight;
        q->ptrRight = p;
        return q;
    }

    node* RotateLeft (node* q){
        node* p = q->ptrRight;
        q->ptrRight = p->ptrLeft;
        p->ptrLeft = q;
        return p;
    }

    int BalanceFactor (const node* p){
        return NodeHeight(p->ptrRight)-NodeHeight(p->ptrLeft);
    };

    node* BalanceNode (node* p){
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

    node* BalanceBranch ( node* p ){
        if ( p == nullptr ) return nullptr;
        p->ptrLeft = BalanceBranch( p->ptrLeft );
        p->ptrRight = BalanceBranch( p->ptrRight );
        p = BalanceNode( p );
        return p;
    }

    size_t NodeHeight(const node *head) {
        size_t s = 0, l = 0, r = 0;
        if ( head != nullptr ){
            l = NodeHeight( head->ptrLeft );
            r = NodeHeight( head->ptrRight );
            s = ((l > r) ? l : r) + 1;
        }
        return s;
    }

    void PrintPreorder(const node* head);
    void DeleteMap (node* p);
    bool ComparisonEqually (const node* p, const node* p1);
    bool ComparisonMore (const node* p, const node* p1);

public:
    explicit map () = default;
    ~map() {
        DeleteMap(root);
    }

    void Emplace (T_key key, T_val value);
    void Erase ( T_key key);
    void Print();
    size_t Count () {
        return size;
    }
    node* Find(const T_key key){
        node* current = root;
        while ( current != nullptr ){
            if ( current->value.key == key ) return current;
            if ( key < current->value.key ) current = current->ptrLeft;
            else current = current->ptrRight;
        }
        throw std::out_of_range("map haven't element with this key");
    }
    bool operator== (map<T_key,T_val> const& m);
    bool operator> (map<T_key,T_val> const& m);
    bool operator!= (map<T_key,T_val> const& m){
        return !(this->operator==(m));
    }
    bool operator>= (map<T_key,T_val> const& m){
        return !(this->operator<);
    }
    bool operator< (map<T_key,T_val> const& m){
        return !(this->operator>(m) && this->operator==(m));
    }
    bool operator<= (map<T_key,T_val> const& m){
        return !(this->operator>(m));
    }
};

template<typename T_key, typename T_val>
void map<T_key, T_val>::Emplace( T_key key, T_val value) {
    if ( root == nullptr ){
        root = new node ({key, value});
    }
    else{
        node* current = root;
        node* previous = root;
        while ( current != nullptr ){
            previous = current;
            if ( key < current->value.key ) current = current->ptrLeft;
            else current = current->ptrRight;
        }
        if ( key < previous->value.key ) previous->ptrLeft = new node({key, value});
        else previous->ptrRight = new node ({key, value});
    }
    size++;
    root = BalanceBranch(root);
}

template<typename T_key, typename T_val>
void map<T_key, T_val>::Erase(T_key key) {
    if ( size == 0 ) throw std::out_of_range("map is empty");
    node* current = root;
    node* previous = root;

    while ( current != nullptr ){
        if ( current->value.key != key ) previous = current;
        if ( key < current->value.key ) current = current->ptrLeft;
        else {
            if ( key > current->value.key ) current = current->ptrRight;
            else break;
        }
    }
    if ( current == nullptr ) throw std::out_of_range ("map haven't el-t with this key");

    if ( current->ptrRight == nullptr || current->ptrLeft == nullptr ){
        if ( current->ptrRight == nullptr && current->ptrLeft == nullptr ){
            delete current;
            if ( key < previous->value.key ) previous->ptrLeft = nullptr;
            else previous->ptrRight = nullptr;
        }
        else{
            if ( current->ptrRight == nullptr){
                if ( key < previous->value.key ) previous->ptrLeft = current->ptrLeft;
                else previous->ptrRight = current->ptrLeft;
                delete current;
            }
            else{
                if ( key < previous->value.key ) previous->ptrLeft = current->ptrRight;
                else previous->ptrRight = current->ptrRight;
                delete current;
            }
        }
    }
    else{
        node* swap = current->ptrRight;
        node* swap_prev = nullptr;
        while ( swap->ptrLeft != nullptr ){
            swap_prev = swap;
            swap = swap->ptrLeft;
        }
        if ( swap_prev == nullptr ) current->ptrRight=current->ptrRight->ptrRight;
        else swap_prev->ptrLeft = nullptr;
        if ( key < previous->value.key ) previous->ptrLeft = new node( swap->value,current->ptrLeft,current->ptrRight);
        else previous->ptrRight = new node( swap->value,current->ptrLeft,current->ptrRight);
        delete current;
        delete swap;
        root = BalanceBranch(root);
    }
    size--;
}

template<typename T_key, typename T_val>
void map<T_key, T_val>::Print() {
    if (size == 0) throw std::out_of_range("tree is empty");
    std::cout << std::endl;
    PrintPreorder ( root );
    std::cout << std::endl;
}


template<typename T_key, typename T_val>
void map<T_key, T_val>::PrintPreorder(const map::node *head) {
    if ( head == nullptr ){
        std::cout << ".";
        return;
    }
    std::cout << head->value.key << " ";
    PrintPreorder( head->ptrLeft);
    PrintPreorder( head->ptrRight);
}

template<typename T_key, typename T_val>
void map<T_key, T_val>::DeleteMap(map::node *p) {
    if (p != nullptr ){
        DeleteMap(p->ptrLeft);
        DeleteMap(p->ptrRight);
        delete p;
    }
    else return;
}

template<typename T_key, typename T_val>
bool map<T_key, T_val>::operator==(const map<T_key,T_val> &m) {
    if ( this->size == 0 || m.size == 0 ) throw std::out_of_range ("map is empty");
    return ComparisonEqually(this->root, m.root);
}

template<typename T_key, typename T_val>
bool map<T_key, T_val>::operator>(const map<T_key,T_val> &m) {
    if ( this->size == 0 || m.size == 0 ) throw std::out_of_range ("map is empty");
    return ComparisonMore(this->root, m.root);
}

template<typename T_key, typename T_val>
bool map<T_key, T_val>::ComparisonEqually(const map::node *p, const map::node *p1) {
    if ( p == nullptr && p1 == nullptr ) return true;
    if ( p == nullptr || p1 == nullptr ) return false;
    bool ans = true;
    ans = (p->value == p1->value);
    if (!ans) return false;
    ans = WidthNode(p) == WidthNode(p1);
    if (ans){
        ans = ComparisonEqually (p->ptrLeft, p1->ptrLeft);
        ans = ComparisonEqually(p->ptrRight, p1->ptrRight);
    }
    else return false;
    return ans;
}

template<typename T_key, typename T_val>
bool map<T_key, T_val>::ComparisonMore(const map::node *p, const map::node *p1) {
    if ( p != nullptr && p1 == nullptr ) return true;
    if ( p == nullptr && p1 != nullptr ) return false;
    if ( p == nullptr && p1 == nullptr ) return false;
    bool ans = true;
    ans = (p->value >= p1->value);
    if (!ans) return false;
    ans = WidthNode(p) >= WidthNode(p1);
    if (ans){
        ans = ComparisonMore(p->ptrLeft, p1->ptrLeft);
        ans = ComparisonMore(p->ptrRight, p1->ptrRight);
    }
    else return false;
    return ans;
}

#endif //LAB_04_MAP_H

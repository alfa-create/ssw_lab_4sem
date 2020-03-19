#ifndef LAB2V2_SIMPLE_LIST_H
#define LAB2V2_SIMPLE_LIST_H

template<class T>
class my_list {
private:
    class node{
    public:
        T value { 0 };
        node *linkNext { nullptr };

        explicit node(T val,node *link=nullptr){
            value = val;
            linkNext = link;
        }

        ~node() =  default;
    };

    node *head { nullptr };
    size_t size { 0 };

public:
    my_list() = default;
    my_list(const std::initializer_list<T> &list);
    ~my_list();
    void PushBack(T data);
    void PushFront(T data);
    int Count ();
    T PopBack();
    T PopFront();
    void Insert(T value, int index);
    void Erase(int index);

    T* Begin(){
        return &head->value;
    }

    T* End(){
        node *current = head;
        while(current->linkNext != nullptr){
            current = current->linkNext;
        }
        return &current->value;
    }

    T FindValue(T val);//find the value of el-t, which after val

    T* FindIndex(T val){//find the index of el-t, which after val
        node *current = head;

        while (current->linkNext != nullptr){

            if(current->value == val){
                return &current->value;
            }

            current = current->linkNext;
        }
        throw std::out_of_range("list haven't el-t with this value");
    }

    T& operator[] (int index);

    friend bool operator> (const my_list<T> &m,const my_list<T> &m2){
        node *cur1 = m.head;
        node *cur2 = m2.head;

        while ((cur1->linkNext != nullptr) && (cur2->linkNext != nullptr)){
            if (cur1->value < cur2->value) return false;
            if (cur1->value > cur2->value) return true;
            cur1 = cur1->linkNext;
            cur2 = cur2->linkNext;
        }

        if (cur1->value > cur2->value) return true;
        if (cur1->value < cur2->value) return false;
        return (m.size > m2.size);
    }

    friend bool operator== (const my_list<T> &m,const my_list<T> &m2){
        node *cur1 = m.head;
        node *cur2 = m2.head;

        while ((cur1->linkNext != nullptr) && (cur2->linkNext != nullptr)) {

            if (cur1->value != cur2->value) {
                return false;
            }

            cur1 = cur1->linkNext;
            cur2 = cur2->linkNext;
        }
        if (cur1->value != cur2->value) {
            return false;
        }
        return (m.size == m2.size);
    }

    friend bool operator>= (const my_list<T> &m,const my_list<T> &m2){
        return ((m > m2) || (m == m2));
    }

    friend bool operator<= (const my_list<T> &m,const my_list<T> &m2){
        return !(m > m2);
    }

    friend bool operator!= (const my_list<T> &m,const my_list<T> &m2){
        return !(m == m2);
    }

    friend bool operator<(const my_list<T> &m,const my_list<T> &m2){
        return !(m >= m2);
    }

    friend std::ostream& operator<< (std::ostream &out, const my_list<T> &m){
        node *current = m.head;

        out<<"( ";
        while(current->linkNext != nullptr){
            out << current->value << ", ";
            current = current->linkNext;
        }
        out << current->value<<" )";
        return out;
    };

};


template<typename T>
my_list<T>::my_list(const std::initializer_list<T> &list) {
    for (int i = 0; i < list.size();i++){
        PushBack(list.begin()[i]);
    }
}

template<typename T>
my_list<T>::~my_list(){
    while (size){
        PopFront();
    }
    head = nullptr;
}

template<class T>
void my_list<T>::PushBack(T data) {
    if (head == nullptr){
        head = new node(data);
    }
    else{
        node *current = this->head;

        while (current->linkNext != nullptr) {
            current = current->linkNext;
        }
        current->linkNext = new node(data);
    }

    size++;
}

template<class T>
int my_list<T>::Count() {
    return size;
}

template<class T>
void my_list<T>::PushFront(T data) {
    if (head == nullptr){
        head = new node(data);
    }
    else{
        node *current = new node (data,head);
        head = current;
    }
    size++;
}

template<class T>
T my_list<T>::PopBack() {
    if (head == nullptr ) throw std::out_of_range("list is empty");

    node *del = nullptr;
    node *current = this->head;
    T ret;

    while (current->linkNext != nullptr) {
        del = current;
        current = current->linkNext;
    }

    if (del != nullptr) del->linkNext = nullptr;
    ret = current->value;
    delete current;
    size--;

    return ret;
}

template<class T>
T my_list<T>::PopFront() {
    if (head == nullptr ) throw std::out_of_range("list is empty");
    node *del = head;
    T ret = head->value;
    head = head->linkNext;
    delete del;
    size--;

    return ret;
}

template<class T>
T &my_list<T>::operator[](int index) {
    if (index >= size) throw std::out_of_range("index is more then size of list");
    if (index < 0) throw std::out_of_range("index will be positive number");

    int count = 0;
    node *current = head;

    while (current != nullptr){
        if (count == index){
            return current->value;
        }
        current = current->linkNext;
        count++;
    }
    throw std::out_of_range("out of range");
}

template<class T>
void my_list<T>::Insert(T value, int index) {
    if(index >= size) throw std::out_of_range("index is more then size of list");
    if (index < 0) throw std::out_of_range("index will be positive number");

    if (index == 0){
        PushFront(value);
    }else{
        node *prev = head;

        for (int i = 0; i < index - 1; i++){
            prev = prev->linkNext;
        }
        node* nextNode = new node (value,prev->linkNext);
        prev->linkNext = nextNode;

        size++;
    }

}

template<class T>
void my_list<T>::Erase(int index) {
    if(index >= size) throw std::out_of_range("index is more then size of list");
    if (index < 0) throw std::out_of_range("index will be positive number");

    if (index == 0){
       PopFront();
    }
    else{
        node *prev = head;
        node *del = nullptr;
        for (int i = 0; i < index -1 ;i++){
            prev = prev->linkNext;
        }
        del = prev->linkNext;
        prev->linkNext = del->linkNext;
        delete del;
        size--;
    }
}

template<class T>
T my_list<T>::FindValue(T val) {
    node *current = head;

    while(current->linkNext != nullptr){
        if (current->value == val){
            current = current->linkNext;
            return current->value;
        }
        current = current->linkNext;
    }
    throw std::out_of_range("List is haven't el-t with this value");
}

#endif //LAB2V2_SIMPLE_LIST_H
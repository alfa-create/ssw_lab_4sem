#ifndef LAB2V2_MY_RING_BUFFER_H
#define LAB2V2_MY_RING_BUFFER_H

template<class T>
class my_ring_buffer {
private:

    class node{
    public:
        T value { NULL };
        node *linkNext { nullptr };

        explicit node(T val,node *link=nullptr){
            value=val;
            linkNext=link;
        }
        ~node(){
        }
    };

    node *head { nullptr };
    node *tail { nullptr };
    int size { NULL };
    int maxSize { NULL };

public:
    explicit my_ring_buffer(int size);
    my_ring_buffer(int size,const std::initializer_list<T> &list);
    ~my_ring_buffer();
    void PushBack(T data);
    T PopFront();
    void Insert(T data, int index);
    T* Begin(){return &head->value;}
    T* End(){return &tail->value;}
    T FindValue(T data);
    T* FindIndex(T data);

    int Count(){
        return size;
    }

    friend std::ostream& operator<< (std::ostream &out, const my_ring_buffer<T> &m){
        if (m.size == 0) return out;
        node *current = m.head;
        int count = m.size;

        out<<"( ";
        while((current != m.tail) || (count != 0)){
            out<<current->value<<", ";
            current = current->linkNext;
            count--;
        }
        out<<" )";
        return out;
    }

    friend bool operator> (const my_ring_buffer<T> &m,const my_ring_buffer<T> &m2){
        node *cur1 = m.head;
        node *cur2 = m2.head;
        int count = m.size;


        while (((cur1 != m.tail) || (count != 0)) && ((cur2 != m2.tail) || (count != 0))){
            if (cur1->value < cur2->value) return false;
            cur1 = cur1->linkNext;
            cur2 = cur2->linkNext;
            count--;
        }
        if (cur1->value > cur2->value) return true;
        return (m.size > m2.size);
    }

    friend bool operator== (const my_ring_buffer<T> &m,const my_ring_buffer<T> &m2){
        node *cur1 = m.head;
        node *cur2 = m2.head;
        int count = m.size;

        while (((cur1 != m.tail) || (count != 0)) && ((cur2 != m2.tail) || (count != 0))) {

            if (cur1->value != cur2->value) {
                return false;
            }

            cur1 = cur1->linkNext;
            cur2 = cur2->linkNext;
            count--;
        }
        if (cur1->value != cur2->value) {
            return false;
        }
        return (m.size == m2.size);
    }

    friend bool operator>= (const my_ring_buffer<T> &m,const my_ring_buffer<T> &m2){
        return ((m > m2) || (m == m2));
    }

    friend bool operator<= (const my_ring_buffer<T> &m,const my_ring_buffer<T> &m2){
        return !(m > m2);
    }

    friend bool operator!= (const my_ring_buffer<T> &m,const my_ring_buffer<T> &m2){
        return !(m == m2);
    }

    friend bool operator<(const my_ring_buffer<T> &m,const my_ring_buffer<T> &m2){
        return !(m >= m2);
    }

};

template<class T>
my_ring_buffer<T>::my_ring_buffer(int size) {
    this->maxSize = size;
    head = new node (0);
    node *current = head;
    for (int i = 1; i<maxSize; i++){
        current->linkNext = new node(0);
        current = current->linkNext;
    }
    current->linkNext = head;
    tail = head;
}

template<class T>
my_ring_buffer<T>::~my_ring_buffer() {
    node *current = head;
    node *del = nullptr;
    while ((current != tail) || (size > 0)){
        del = current;
        current = current->linkNext;
        delete del;
        size--;
    }
    delete head;
    head = nullptr;
    delete tail;
    tail = nullptr;
}

template<class T>
void my_ring_buffer<T>::PushBack(T data) {
    if ((tail == head) && (size != 0)) head = head->linkNext;
    tail->value = data;
    tail = tail->linkNext;
    if (size != maxSize) size++;
}

template<class T>
T my_ring_buffer<T>::PopFront() {
    if (size == 0) throw std::out_of_range("the ring buffer is empty");
    T ret = head->value;
    head = head->linkNext;
    size --;
    return ret;
}

template<class T>
void my_ring_buffer<T>::Insert(T data, int index) {
    if (index > size) throw std::out_of_range("Index is more the size of buffer");
    if (index < 0) throw std::out_of_range("index will be positive number");

    node *current = head;
    for (int i = 0; i < index ; i++){
        current = current->linkNext;
    }
    current->value = data;
}

template<class T>
T my_ring_buffer<T>::FindValue(T data) {
    if (size == 0) throw std::out_of_range("buffer is empty");
    node *current = head;
    int count = size;

    while((current != tail) || (count != 0)){
        if (current->value == data){
            current = current->linkNext;
            return current->value;
        }
        current = current->linkNext;
        count--;
    }
    throw std::out_of_range("Forward list is haven't el-t with this value");
}

template<class T>
T *my_ring_buffer<T>::FindIndex(T data) {
    if (size == 0) throw std::out_of_range("buffer is empty");
    node *current = head;
    int count = size;

    while((current != tail) || (count != 0)){

        if(current->value == data){
            return &current->value;
        }

        current = current->linkNext;
    }
    throw std::out_of_range("list haven't el-t with this value");
}

template<class T>
my_ring_buffer<T>::my_ring_buffer(int size, const std::initializer_list<T> &list) {
    this->maxSize = size;
    if (size < list.size()) throw std::out_of_range("list size is more then size of ring buffer");
    this->size = list.size();
    head = new node (list.begin()[0]);
    node *current = head;
    for (int i = 1; i<maxSize; i++){
        current->linkNext = new node(list.begin()[i]);
        current = current->linkNext;
    }
    current->linkNext = head;
    tail = head;
}


#endif //LAB2V2_MY_RING_BUFFER_H

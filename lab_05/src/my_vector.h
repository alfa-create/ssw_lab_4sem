#ifndef UNTITLED_MY_VECTOR_H
#define UNTITLED_MY_VECTOR_H


template <class T>
class my_vector {
private:
    int size { 10 };
    int num { -1 };
    T *buf { nullptr };
    T *buf2 { nullptr };
    int n { 0 };
    void genNewBuf();
public:
    my_vector();
    ~my_vector();
    void Push(T b);//вставка
    T Pop();//выталкивание
    int Count();//возврат количества
    T Sum();//сумма всех элементов
    float Funk();//среднее арифметическое
    T& At(int m);//произвольный доступ к элементу

    friend bool operator == (const my_vector<T> &m1,const my_vector<T> &m2) {
        if ((m1.num==m2.num)&&(m1.size==m2.size)) {
            for (int i=0;i<=m1.num;i++) {
                if (m1.buf[i]!=m2.buf[i]) {
                    return false;
                }
                if (m1.buf2[i]!=m2.buf2[i]) {
                    return false;
                }
            }
            return true;
        }
        else return false;
    };

    friend bool operator !=(const my_vector<T> &m1,const my_vector<T> &m2) {
        return !(m1==m2);
    };

    friend bool operator > (const my_vector<T> &m1,const my_vector<T> &m2) {
        for (int i = 0 ;i <= m1.num && i<= m2.num; i++){
            if(m1.buf[i]>m2.buf[i]) return true;
            if(m1.buf2[i]>m2.buf2[i]) return true;
        }
        return((m1.size>m2.size)&&(m1.num>m1.num));
    };

    friend bool operator >= (const my_vector<T> &m1,const my_vector<T> &m2) {
        return ((m1>m2)||(m1==m2));
    };

    friend bool operator < (const my_vector<T> &m1,const my_vector<T> &m2) {
        return !(m1>=m2);
    };

    friend bool operator <= (const my_vector<T> &m1,const my_vector<T> &m2) {
        return !(m1>m2);
    };

};
template<typename T>
my_vector<T>::my_vector() {
    buf=new T[size];
    buf2=new T[1];
};

template<typename T>
my_vector<T>::~my_vector() {
    delete[] buf;
    delete[] buf2;
};

template<typename T>
void my_vector<T>::Push(T b) {
    genNewBuf();
    num++;
    if (n==0) {
        buf[num]=b;
    }
    else {
        buf2[num]=b;
    }
};

template<typename T>
T my_vector<T>::Pop() {
    if ( num < 0 ){
        throw std::out_of_range("vector is empty");
    }
    T g;
    if (n==0) {
        g=buf[num];
    }
    else {
        g=buf2[num];
    }
    num--;
    return g;
};

template<typename T>
int my_vector<T>::Count() {
    return (num+1);
};

template<typename T>
T my_vector<T>::Sum() {
    T s=0;
    for (int i=num;i>=0;i--) {
        if (n==0) s+=buf[i];
        else s+=buf2[i];
    }
    return s;
};

template<typename T>
float my_vector<T>::Funk() {
    return static_cast<float>( Sum() / Count() );
};

template<typename T>
T& my_vector<T>::At(int m) {
    if (m<0||m>num) {
        throw std::out_of_range("out of range in vector");
    }
    if(n==0) {
        return buf[m];
    }
    else return buf2[m];
};
template<typename T>
void my_vector<T>::genNewBuf() {
    if((num==(size-1))&&(n==0)) {
        size+=10;
        delete[] buf2;
        buf2=new T[size];
        for (int i=0;i<=num;i++) {
            buf2[i]=buf[i];
        }
        n=1;
    };
    if((num==(size-1))&&(n==1)) {
        size+=10;
        delete[] buf;
        buf=new T[size];
        for (int i=0;i<=num;i++) {
            buf[i]=buf2[i];
        }
        n=0;
    };
};
#endif //UNTITLED_MY_VECTOR_H

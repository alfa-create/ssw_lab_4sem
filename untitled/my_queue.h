#ifndef UNTITLED_MY_QUEUE_H
#define UNTITLED_MY_QUEUE_H

template <class T>
class my_queue {
private:
    int size {10};
    int num {-1};
    T *buf;
    T *buf2;
    int n {0};
    void genNewBuf();
    void shift_el();
public:
    my_queue();
    ~my_queue();
    void Push(T b);//вставка
    T Pop();//выталкивание
    T Peek();//возврат вершины
    int Count();//возврат количества
    T Sum();//сумма всех элементов
    float Funk();//среднее арифметическое
    friend bool operator ==(const my_queue<T> &m1,const my_queue<T> &m2)
    {
        if ((m1.num==m2.num)&&(m1.size==m2.size))
        {
            for (int i=0;i<=m1.num;i++)
            {
                if (m1.buf[i]!=m2.buf[i]) return (false);
                if (m1.buf2[i]!=m2.buf2[i]) return (false);
            }
            return (true);
        }
        else return (false);
    };
    friend bool operator !=(const my_queue<T> &m1,const my_queue<T> &m2)
    {
        return !(m1==m2);
    };
    friend bool operator > (const my_queue<T> &m1,const my_queue<T> &m2)
    {
        if ((m1.num==m2.num)&&(m1.size==m2.size))
        {
            for (int i=0;i<=m1.num;i++)
            {
                if(m1.buf[i]>m2.buf[i]) return true;
                if(m1.buf2[i]>m2.buf2[i]) return true;
            }
            return false;
        }
        else return((m1.size>m2.size)&&(m1.num>m1.num));
    };
    friend bool operator >= (const my_queue<T> &m1,const my_queue<T> &m2)
    {
        return ((m1>m2)||(m1==m2));
    };
    friend bool operator < (const my_queue<T> &m1,const my_queue<T> &m2)
    {
        return !(m1>=m2);
    };
    friend bool operator <= (const my_queue<T> &m1,const my_queue<T> &m2)
    {
        return !(m1>m2);
    };
};
template <typename T>
my_queue<T>::my_queue() {buf=new T[size];buf2=new T[1];};

template <typename T>
my_queue<T>::~my_queue() {delete[] buf,buf2;};

template <typename T>
void my_queue<T>::Push(T b)
{
    genNewBuf();
    num++;
    if(n==0) buf[num]=b;
    else buf2[num]=b;
};

template <typename T>
int my_queue<T>::Count() {return (num+1);};

template <typename T>
void my_queue<T>::shift_el()
{
    for (int i=0;i<num;i++)
    {
        if(n==0) buf[i]=buf[i+1];
        else buf2[i]=buf2[i+1];
    };
    num--;
};

template <typename T>
T my_queue<T>::Pop()
{
    T l;
    if(n==0) l=buf[0];
    else l=buf2[0];
    shift_el();
    return l;
};

template <typename T>
T my_queue<T>::Peek()
{
    if(n==0) return(buf[0]);
    else return(buf2[0]);
};
template<typename T>
void my_queue<T>::genNewBuf()
{
    if((num==(size-1))&&(n==0))
    {
        size+=10;
        delete[] buf2;
        buf2=new T[size];
        for (int i=0;i<=num;i++)
        {
            buf2[i]=buf[i];
        }
        n=1;
    };
    if((num==(size-1))&&(n==1))
    {
        size+=10;
        delete[] buf;
        buf=new T[size];
        for (int i=0;i<=num;i++)
        {
            buf[i]=buf2[i];
        }
        n=0;
    };
};

template <typename T>
T my_queue<T>::Sum() {
    T l=0;
    for(int i=0;i<num+1;i++)
    {
        if(n==0) l+=buf[i];
        else l+=buf2[i];
    }
    return l;
}
template <typename T>
float my_queue<T>::Funk() {return (Sum()/num);};
#endif //UNTITLED_MY_QUEUE_H
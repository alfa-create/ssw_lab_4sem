#ifndef UNTITLED_MY_QUEUE_H
#define UNTITLED_MY_QUEUE_H

template <class T>
class my_queue {
private:
    int Size=10;
    int num=-1;
    T *Buf;
    T *Buf2;
    int n=0;
public:
    my_queue();
    ~my_queue();
    void push(T b);//вставка
    T pop();//выталкивание
    T peek();//возврат вершины
    int count();//возврат количества
    T sum();//сумма всех элементов
    T funk();//среднее арифметическое
    void gen2();
    void f();
    friend bool operator ==(my_queue<T> &m1,my_queue<T> &m2)
    {
        bool s=1,s2=1;
        if (m1.num==m2.num)
        {
            for (int i=0;i<=m1.num;i++)
            {
                s*=m1.Buf[i]==m2.Buf[i];
                s2*=m1.Buf2[i]==m2.Buf2[i];
            }
        };
        return((m1.Size==m2.Size)&&(m1.num==m1.num)&&s&&s2);
    };
    friend bool operator !=(my_queue<T> &m1,my_queue<T> &m2)
    {
        return !(m1==m2);
    };
    friend bool operator > (my_queue<T> &m1,my_queue<T> &m2)
    {
        bool s=1,s2=1;
        if (m1.num==m2.num)
        {
            for (int i=0;i<m1.num;i++)
            {
                s*=m1.Buf[i]>=m2.Buf[i];
                s2*=m1.Buf2[i]>=m2.Buf2[i];
            }
            s*=m1.Buf[m1.num]>m2.Buf[m2.num];
            s2*=m1.Buf2[m1.num]>m2.Buf2[m2.num];
            return(s&&s2);
        };
        return((m1.Size>m2.Size)&&(m1.num>m1.num));
    };
    friend bool operator >= (my_queue<T> &m1,my_queue<T> &m2)
    {
        bool s=1,s2=1;
        if (m1.num==m2.num)
        {
            for (int i=0;i<=m1.num;i++)
            {
                s *= m1.Buf[i] >= m2.Buf[i];
                s2 *= m1.Buf2[i] >= m2.Buf2[i];
            };
            return(s&&s2);
        };
        return(m1.num>=m2.num&&m1.Size>=m2.Size);
    };
    friend bool operator < (my_queue<T> &m1,my_queue<T> &m2)
    {
        return !(m1>=m2);
    };
    friend bool operator <= (my_queue<T> &m1,my_queue<T> &m2)
    {
        return !(m1>m2);
    };
};
template <typename T>
my_queue<T>::my_queue() {Buf=new T[Size];Buf2=new T[1];};

template <typename T>
my_queue<T>::~my_queue() {delete[] Buf,Buf2;};

template <typename T>
void my_queue<T>::push(T b)
{
    gen2();
    num++;
    if(n==0) Buf[num]=b;
    else Buf2[num]=b;
};

template <typename T>
int my_queue<T>::count() {return (num+1);};

template <typename T>
void my_queue<T>::f()
{
    for (int i=0;i<num;i++)
    {
        if(n==0) Buf[i]=Buf[i+1];
        else Buf2[i]=Buf2[i+1];
    };
    num--;
};

template <typename T>
T my_queue<T>::pop()
{
    T l;
    if(n==0) l=Buf[0];
    else l=Buf2[0];
    f();
    return l;
};

template <typename T>
T my_queue<T>::peek()
{
    T l;
    if(n==0) l=Buf[num];
    else l=Buf2[num];
    num--;
    return l;
};
template<typename T>
void my_queue<T>::gen2()
{
    if((num==(Size-1))&&(n==0))
    {
        Size+=10;
        Buf2=new T[Size];
        for (int i=0;i<=num;i++)
        {
            Buf2[i]=Buf[i];
        }
        n=1;
    };
    if((num==(Size-1))&&(n==1))
    {
        Size+=10;
        Buf=new T[Size];
        for (int i=0;i<=num;i++)
        {
            Buf[i]=Buf2[i];
        }
        n=0;
    };
};

template <typename T>
T my_queue<T>::sum() {
    T l=0;
    for(int i=0;i<num+1;i++)
    {
        if(n==0) l+=Buf[i];
        else l+=Buf2[i];
    }
    return l;
}
template <typename T>
T my_queue<T>::funk() {return (sum()/num);};
#endif //UNTITLED_MY_QUEUE_H
#include <utility>
#include <initializer_list>
#include <iostream>
#include <string>
#include <exception>

//main class
template <typename T_key, typename T_val>
class Map
{
private:
	typedef std::pair< T_key, T_val> ValueType;//main data type (key + value)

	class Node
	{
	public:
		ValueType data;//main data type (key + value)
		Node* linkNext{ nullptr };//pointer to next element
		Node* linkPrev{ nullptr };//pointer to previous element

		explicit Node(const ValueType data_p) : linkNext(nullptr), linkPrev(nullptr)//constructors
		{
			data = data_p;
		};
		Node() = default;
		~Node() = default;//destructor
	};

	Node* head{ nullptr };//pointer to head
	Node* tail = new Node;//pointer to tail
	size_t size{ 0 };//size of map
	

public:
	class Iterator//class Iterator
	{
	private:
		Node* ptr;//pointer to node
	public:
		Iterator() noexcept : ptr(nullptr) {};//const
		explicit Iterator(Node* root) noexcept : ptr(root) {};
		~Iterator() = default;//destr
		Node* ret_ptr() { return ptr; };//return node
		Iterator& operator=(const Iterator& iter);//copy oper
		bool operator!=(const Iterator& iter);//comparison oper !=
		bool operator==(const Iterator& iter) { return !(*this != iter); };//comparison oper ==
		void operator++();//iterator increase
		void operator--();//iterarot reduction
		ValueType operator*();//return key+value
	};

	Map() = default; //constr. main class
	~Map();//dest. main class
	void emplace(ValueType val); //insert element
	void erase(T_key key);//delete element
	Iterator find(T_key key);//find element
	Iterator begin();//return iterator(begin)
	Iterator end();//return iterator(end)
	const int size_map();//return size(map)

	bool operator==(Map& o);//comparison oper.
	bool operator!=(Map& o) { return !(*this == o); };
	bool operator>(Map& o);
	bool operator<(Map& o);
	bool operator<=(Map& o) { return !(*this > o); };
	bool operator>=(Map& o) { return !(*this < o); };

	friend std::ostream& operator<<(std::ostream& out, Map<T_key, T_val>& mp)//streaming output
	{
		if (mp.head)
		{
			for (auto ptr = mp.begin(); ptr != mp.end(); ++ptr)
			{
				out << (*ptr).first << " : " << (*ptr).second << std::endl;
			}
			return out;
		}
		throw std::out_of_range("List is empty");
	}
};

template <typename T_key, typename T_val>
Map<T_key, T_val>::~Map()//destructor main class
{
	if (head)
	{
		for (auto ptr = begin(); ptr != end();)
		{
			auto save = ptr;
			++save;
			erase((*ptr).first);
			ptr = save;
		}
	}
}

template <typename T_key, typename T_val>
void Map<T_key, T_val>::emplace(ValueType val)
{
	if (head == nullptr)
	{
		head = new Node(val);
		head->linkNext = tail;
		size++;
	}
	else
	{
		for (auto ptr = begin(); ptr != end(); ++ptr)
		{
			if ((*ptr).first == val.first) return;
			if ((*ptr).first < val.first)
			{
				Node* current = new Node(val);
				if (ptr.ret_ptr() == head)
				{
					head->linkPrev = current;
					current->linkNext = head;
					head = current;
					size++;
					return;
				}
				else
				{
					current->linkPrev = ptr.ret_ptr()->linkPrev;
					current->linkNext = ptr.ret_ptr();
					ptr.ret_ptr()->linkPrev->linkNext = current;
					ptr.ret_ptr()->linkPrev = current;
					size++;
					return;
				}
			}
			if (ptr.ret_ptr()->linkNext == tail)
			{
				Node* current = new Node(val);
				ptr.ret_ptr()->linkNext = current;
				current->linkNext = tail;
				current->linkPrev = ptr.ret_ptr();
				size++;
				return;
			}
		}
	}
}

template <typename T_key, typename T_val>
void Map<T_key, T_val>::erase(T_key key)
{
	if (!size) throw std::out_of_range("index more then size of structure");

	for (auto ptr = begin(); ptr != end(); ++ptr)
	{
		if ((*ptr).first == key)
		{
			if ((ptr.ret_ptr()) == head)
			{
				if (size > 1)
				{
					head = head->linkNext;
				}
				else
				{
					delete head;
					head = nullptr;
					size--;
					return;
				}
				delete head->linkPrev;
				head->linkPrev = nullptr;

				size--;
				return;
			}
			else
			{
				(ptr.ret_ptr())->linkNext->linkPrev = (ptr.ret_ptr())->linkPrev;
				(ptr.ret_ptr())->linkPrev->linkNext = (ptr.ret_ptr())->linkNext;
				delete (ptr.ret_ptr());

				size--;
				return;
			}
		}
	}
}

template <typename T_key, typename T_val>
typename Map<T_key, T_val>::Iterator Map<T_key, T_val>::find(T_key key)
{
	if (!head) { return end(); };

	for (auto ptr = begin(); ptr != end(); ++ptr)
	{
		if ((*ptr).first == key)
		{
			return ptr;
		}
	}
	return end();
}

template <typename T_key, typename T_val>
typename Map<T_key, T_val>:: Iterator Map<T_key, T_val>::begin()
{
	return Iterator(head);
}

template <typename T_key, typename T_val>
typename Map<T_key, T_val>::Iterator Map<T_key, T_val>::end()
{
	return Iterator(tail);
}

template <typename T_key, typename T_val>
typename Map<T_key, T_val>::Iterator& Map<T_key, T_val>::Iterator::operator=(const Iterator& iter)
{
	ptr = iter.ptr;
	return *this;
}

template <typename T_key, typename T_val>
typename Map<T_key, T_val>::ValueType Map<T_key, T_val>::Iterator::operator*()
{
	return ptr->data;
}

template <typename T_key, typename T_val>
void Map<T_key, T_val>::Iterator::operator++()
{
	ptr = ptr->linkNext;
}


template <typename T_key, typename T_val>
void Map<T_key, T_val>::Iterator::operator--()
{
	ptr = ptr->linkPrev;
}

template<typename T_key, typename T_val>
bool Map<T_key, T_val>::Iterator::operator!=(const Iterator& iter)
{
	if (ptr != iter.ptr) return true;
	else return false;
}

template<typename T_key, typename T_val>
bool Map<T_key, T_val>::operator==(Map& o)
{
	if (size == o.size)
	{
		auto ptr_this = begin();
		auto ptr_o = o.begin();
		for (ptr_this; ptr_this != end(); ++ptr_this)
		{
			if ((*ptr_this).second != (*ptr_o).second) { return false; };
			++ptr_o;
		}
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T_key, typename T_val>
bool Map<T_key, T_val>::operator>(Map& o)
{
	auto ptr_this = begin();
	auto ptr_o = o.begin();
	if (size <= o.size)
	{
		for (ptr_this; ptr_this != end(); ++ptr_this)
		{
			if ((*ptr_this).second > (*ptr_o).second) { return true; };
			if ((*ptr_this).second < (*ptr_o).second) { return false; };
			++ptr_o;
		}
		return false;
	}
	else
	{
		for (ptr_o; ptr_o != o.end(); ++ptr_o)
		{
			if ((*ptr_this).second > (*ptr_o).second) { return true; };
			if ((*ptr_this).second < (*ptr_o).second) { return false; };
			++ptr_o;
		}
		return true;
	}
}

template<typename T_key, typename T_val>
bool Map<T_key, T_val>::operator<(Map<T_key, T_val>& o)
{
	auto ptr_this = begin();
	auto ptr_o = o.begin();
	if (size < o.size)
	{
		for (ptr_this; ptr_this != end(); ++ptr_this)
		{
			if ((*ptr_this).second > (*ptr_o).second) { return false; };
			if ((*ptr_this).second < (*ptr_o).second) { return true; };
			++ptr_o;
		}
		return true;
	}
	else
	{
		for (ptr_o; ptr_o != o.end(); ++ptr_o)
		{
			if ((*ptr_this).second > (*ptr_o).second) { return false; };
			if ((*ptr_this).second < (*ptr_o).second) { return true; };
			++ptr_o;
		}
		return false;
	}
}

template<typename T_key, typename T_val>
const int Map<T_key, T_val>::size_map()
{
	return size;
}
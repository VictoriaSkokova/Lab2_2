#pragma once
#include <iostream>
#include "Iterator.h"

using namespace std;


template <class item> class queue  //¬ очередь можно добавить объект любого типа
{
	item *Queue; int head, tail, size_, Max;
public:
	queue(int maxQ) : head(0), tail(0), Max(maxQ), size_(0), Queue(new item[maxQ + 1]) {}  //конструктор по умолчанию (конструктор можно вызывать без параметров)
	~queue();
	bool empty() const { return (head % Max) == tail; } //в константных методах нельз€ модифицировать члены класса
	int size() const { return size_; }
	void push(item & item) { Queue[tail++] = item; tail %= Max; ++size_; }
	item front() const { return Queue[head % Max]; }
	void pop() { head++; head %= Max; --size_; }
};

template <class item>
queue<item>::~queue()
{
	free(Queue);
}

template <typename T, typename T2 >
class Map
{
private:

	class Node
	{

	public:
		Node(T key, T2 data, Node * left = nullptr, Node * right = nullptr) {
			this->data = data;
			this->left = left;
			this->right = right;
			this->key = key;
			this->parent = nullptr;
			this->color = 'r';

		};
		char color;
		T key, data;
		Node * right;
		Node *left;
		Node *parent;


	};

	Node * root;
	size_t size;
public:
	Map();
	~Map();

	class TreeIterator : public Iterator<T, T2> {
	protected:                                         //доступ есть у классов, производных от данного
		Node *current;
		TreeIterator(Node* root) : current(root) { }

	public:
		bool operator==(const nullptr_t) const override { return current == nullptr; }  //override - показывает, что переопредел€етс€ виртуальный метод
		bool operator!=(const nullptr_t) const override { return !operator==(nullptr); }
		T2 operator*() const override { return current->data; }
		T current_key() { return current->key; }
		T2 current_value() { return current->data; }
		char current_color() { return current->color; }

	};

	class BftIterator : public TreeIterator {
	private:
		queue<Node*> nodes;
	public:
		BftIterator(Node *root, size_t size) : TreeIterator(root), nodes(size) {}
		void operator++(T) override;
	};

	void insertfix(Node *t);      //supporting function for insert
	void leftrotate(Node *);
	void rightrotate(Node *);
	void reset_list();
	Node *get_leaf(Node *);       //supporting function for remove
	void add_first(Node*);        //adding the first element to the tree
	void delfix(Node*);           //supporting function for remove, balance
public:
	T get_keys();
	T2 get_value();
	void clear();                 //clearing the tree
	void insert(T, T2);
	void remove(T);               //removing element by key
	int get_size();
	T2 find(T);                 //finding element by key
	BftIterator create_bft_iterator() { return BftIterator(root, size); }


};


template<typename T, typename T2>
void Map<T, T2>::BftIterator::operator++(T)
{
	if (this->current->left != nullptr)
		nodes.push(this->current->left);
	if (this->current->right != nullptr)
		nodes.push(this->current->right);
	if (nodes.size() > 0) {
		this->current = nodes.front();
		nodes.pop();
	}
	else
		this->current = nullptr;
}
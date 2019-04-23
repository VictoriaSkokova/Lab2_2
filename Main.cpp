#include "Tree.cpp"
#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Hello \n";
	cout << "It's second laboratory work made by Victoria Skokova\n";
	cout << endl;
	cout << "Keys and value of Red-Black Tree:";
	cout << endl;

	RBTree<int, int> RBTree_int;
	RBTree_int.insert(3, 3);
	RBTree_int.insert(6, 8);
	RBTree_int.insert(1, 5);
	RBTree_int.insert(0, 4);
	RBTree_int.insert(7, 0);
	RBTree_int.insert(4, 7);
	RBTree_int.insert(2, 2);
	RBTree_int.get_keys();
	RBTree_int.get_value();
	cout << endl;
	cout << "Size of Red-Black Tree:";
	cout << RBTree_int.get_size();
	cout << endl;
	cout << "Keys of Red-Black Tree after removing 1:";
	cout << endl;
	RBTree_int.remove(1);
	RBTree_int.get_keys();
	cout << endl;
	cout << "Value of element with key = 4: ";
	RBTree_int.find(4);
	cout << endl;
	RBTree_int.clear();
	cout << endl;
	cout << endl;
	RBTree<int, char> RBTree_char;
	RBTree_char.insert(13, 'a');
	RBTree_char.insert(9, 'b');
	RBTree_char.insert(12, 'c');
	RBTree_char.insert(14, 'd');
	RBTree_char.insert(7, 'f');
	cout << "Keys of Red-Black Tree:";
	cout << endl;
	RBTree_char.get_keys();
	cout << endl;
	cout << "Value of Red-Black Tree:";
	cout << endl;
	RBTree_char.get_value();
	cout << endl;
	cout << "Size of Red-Black Tree:";
	cout << RBTree_char.get_size();
	cout << endl;
	RBTree_char.clear();

	cout << endl;
	system("pause");

}
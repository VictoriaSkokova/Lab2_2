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

	Map<int, int> Map_int;
	Map_int.insert(3, 3);
	Map_int.insert(6, 8);
	Map_int.insert(1, 5);
	Map_int.insert(0, 4);
	Map_int.insert(7, 0);
	Map_int.insert(4, 7);
	Map_int.insert(2, 2);
	Map_int.get_keys();
	Map_int.get_value();
	cout << endl;
	cout << "Size of Red-Black Tree:";
	cout << Map_int.get_size();
	cout << endl;
	cout << "Keys of Red-Black Tree after removing 1:";
	cout << endl;
	Map_int.remove(1);
	Map_int.get_keys();
	cout << endl;
	cout << "Value of element with key = 4: ";
	Map_int.find(4);
	cout << endl;
	Map_int.clear();
	cout << endl;
	cout << endl;
	Map<int, char> Map_char;
	Map_char.insert(13, 'a');
	Map_char.insert(9, 'b');
	Map_char.insert(12, 'c');
	Map_char.insert(14, 'd');
	Map_char.insert(7, 'f');
	cout << "Keys of Red-Black Tree:";
	cout << endl;
	Map_char.get_keys();
	cout << endl;
	cout << "Value of Red-Black Tree:";
	cout << endl;
	Map_char.get_value();
	cout << endl;
	cout << "Size of Red-Black Tree:";
	cout << Map_char.get_size();
	cout << endl;
	Map_char.clear();

	cout << endl;
	system("pause");

}
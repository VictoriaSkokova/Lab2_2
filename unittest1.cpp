#include "stdafx.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include "..\Lab2\Tree.h"
#include "..\Lab2\Tree.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_for_RBTree
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(get_keys_exception)
		{
			RBTree<int, int> RBTree_int;
			try {
				RBTree_int.get_keys();
			}

			catch (const std::out_of_range& error)
			{
				Assert::AreEqual("Error", error.what());
			}
		}
		TEST_METHOD(get_value_exception)
		{
			RBTree<int, int> RBTree_int;
			try
			{
				RBTree_int.get_value();
			}
			catch (const std::out_of_range& error)
			{
				Assert::AreEqual("Error", error.what());
			}
		}
		TEST_METHOD(root_color_BLACK_TRUE)
		{
			RBTree<int, int> RBTree_int;
			RBTree_int.insert(5, 2);
			int check;
			auto it = RBTree_int.create_bft_iterator();
			for (; it != nullptr; it++)
			{

				Assert::IsTrue(it.current_color() == 'b');
			}
		}
		TEST_METHOD(root_color_BLACK_FALSE)
		{
			RBTree<int, int> RBTree_int;
			RBTree_int.insert(1, 9);
			int check;
			auto it = RBTree_int.create_bft_iterator();
			for (; it != nullptr; it++)
			{

				Assert::IsFalse(it.current_color() == 'r');
			}
		}
		TEST_METHOD(insert_int_color)
		{
			RBTree<int, int> RBTree_int;
			RBTree_int.insert(2, 1);
			RBTree_int.insert(4, 2);
			RBTree_int.insert(3, 3);
			RBTree_int.insert(1, 4);
			RBTree_int.insert(9, 4);
			int i = 0;
			char helpik_array[5] = { 'b','b','b','r','r' };
			auto it = RBTree_int.create_bft_iterator();
			for (; it != nullptr; it++)
			{
				Assert::AreEqual(it.current_color(), helpik_array[i++]);
			}
		}
		TEST_METHOD(insert_int_)
		{
			RBTree<int, int> RBTree_int;
			RBTree_int.insert(2, 1);
			RBTree_int.insert(4, 2);
			RBTree_int.insert(3, 3);
			RBTree_int.insert(1, 4);
			RBTree_int.insert(9, 4);
			int i = 0;
			int helpik_array[5] = { 3,1,2,4,4 };
			auto it = RBTree_int.create_bft_iterator();
			for (; it != nullptr; it++)
			{

				Assert::AreEqual(*it, helpik_array[i++]);
			}
		}
		TEST_METHOD(insert_char)
		{
			RBTree<int, char> RBTree_char;
			RBTree_char.insert(2, 'v');
			RBTree_char.insert(4, 'l');
			RBTree_char.insert(3, 'a');
			RBTree_char.insert(1, 'u');
			RBTree_char.insert(9, 'p');
			int i = 0;
			char helpik_array[5] = { 'a','v','l','u','p' };
			auto it = RBTree_char.create_bft_iterator();
			for (; it != nullptr; it++)
			{
				Assert::AreEqual(*it, helpik_array[i++]);
			}
		}
		TEST_METHOD(remove_char_value)
		{
			RBTree<int, char> RBTree_char;
			RBTree_char.insert(2, 'n');
			RBTree_char.insert(4, 's');
			RBTree_char.insert(3, 'b');
			RBTree_char.insert(1, 'u');
			RBTree_char.insert(9, 'o');
			RBTree_char.remove(2);
			int i = 0;
			char helpik_array[4] = { 'b','u','s','o' };
			auto it = RBTree_char.create_bft_iterator();
			for (; it != nullptr; it++)
			{
				Assert::AreEqual(*it, helpik_array[i++]);
			}
		}
		TEST_METHOD(remove_char_color)
		{
			RBTree<int, char> RBTree;
			RBTree.insert(2, 'a');
			RBTree.insert(4, 'k');
			RBTree.insert(3, 'b');
			RBTree.insert(1, 'u');
			RBTree.insert(9, 'j');
			RBTree.remove(2);
			int i = 0;
			char check[4] = { 'b','r','b','r' };
			auto it = RBTree.create_bft_iterator();
			for (; it != nullptr; it++)
			{
				Assert::AreEqual(it.current_color(), check[i++]);
			}
		}
		TEST_METHOD(remove_char_exception)
		{
			RBTree<int, char> RBTree;
			RBTree.insert(3, 'a');
			RBTree.insert(6, 'k');

			try {
				RBTree.remove(1);
			}
			catch (const std::out_of_range & error)
			{
				Assert::AreEqual("No elements with such key", error.what());
			}

		}
		TEST_METHOD(empty_remove_exception)
		{
			RBTree<int, char> RBTree;
			try {
				RBTree.remove(10);
			}
			catch (const std::out_of_range & error)
			{
				Assert::AreEqual("Error", error.what());
			}

		}
		TEST_METHOD(remove_exception_not_found)
		{
			RBTree<int, char> RBTree;
			RBTree.insert(2, 1);
			RBTree.insert(4, 2);
			RBTree.insert(3, 3);
			try {
				RBTree.remove(10);
			}
			catch (const std::out_of_range & error)
			{
				Assert::AreEqual("No elements with such key", error.what());
			}

		}
		TEST_METHOD(find_int_notfound)
		{
			RBTree<int, int> RBTree;
			RBTree.insert(2, 1);
			RBTree.insert(4, 2);

			Assert::AreEqual(0, RBTree.find(3));
		}
		TEST_METHOD(find_int_found)
		{
			RBTree<int, int> RBTree;
			RBTree.insert(2, 1);
			RBTree.insert(4, 2);
			RBTree.insert(1, 4);

			Assert::AreEqual(4, RBTree.find(1));
		}

		TEST_METHOD(find_int_exception_empty)
		{
			RBTree<int, int> RBTree;
			try { RBTree.find(0); }
			catch (const std::out_of_range & error) { Assert::AreEqual("Error", error.what()); }
		}

		TEST_METHOD(size)
		{
			RBTree<int, int> RBTree_int;
			RBTree_int.insert(2, 1);
			RBTree_int.insert(4, 2);
			RBTree_int.insert(3, 3);
			Assert::IsTrue(RBTree_int.get_size() == 3);

		}

	};
}
#include "stdafx.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include "..\Lab2\Tree.h"
#include "..\Lab2\Tree.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_for_Map
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(get_keys_exception)
		{
			Map<int, int> Map_int;
			try {
				Map_int.get_keys();
			}

			catch (const std::out_of_range& error)
			{
				Assert::AreEqual("Error", error.what());
			}
		}
		TEST_METHOD(get_value_exception)
		{
			Map<int, int> Map_int;
			try
			{
				Map_int.get_value();
			}
			catch (const std::out_of_range& error)
			{
				Assert::AreEqual("Error", error.what());
			}
		}
		TEST_METHOD(root_color_BLACK_TRUE)
		{
			Map<int, int> Map_int;
			Map_int.insert(5, 2);
			int check;
			auto it = Map_int.create_bft_iterator();
			for (; it != nullptr; it++)
			{

				Assert::IsTrue(it.current_color() == 'b');
			}
		}
		TEST_METHOD(root_color_BLACK_FALSE)
		{
			Map<int, int> Map_int;
			Map_int.insert(1, 9);
			int check;
			auto it = Map_int.create_bft_iterator();
			for (; it != nullptr; it++)
			{

				Assert::IsFalse(it.current_color() == 'r');
			}
		}
		TEST_METHOD(insert_int_color)
		{
			Map<int, int> Map_int;
			Map_int.insert(2, 1);
			Map_int.insert(4, 2);
			Map_int.insert(3, 3);
			Map_int.insert(1, 4);
			Map_int.insert(9, 4);
			int i = 0;
			char helpik_array[5] = { 'b','b','b','r','r' };
			auto it = Map_int.create_bft_iterator();
			for (; it != nullptr; it++)
			{
				Assert::AreEqual(it.current_color(), helpik_array[i++]);
			}
		}
		TEST_METHOD(insert_int_)
		{
			Map<int, int> Map_int;
			Map_int.insert(2, 1);
			Map_int.insert(4, 2);
			Map_int.insert(3, 3);
			Map_int.insert(1, 4);
			Map_int.insert(9, 4);
			int i = 0;
			int helpik_array[5] = { 3,1,2,4,4 };
			auto it = Map_int.create_bft_iterator();
			for (; it != nullptr; it++)
			{

				Assert::AreEqual(*it, helpik_array[i++]);
			}
		}

		TEST_METHOD(insert_begin_)
		{
			Map<int, int> Map_int;
			Map_int.insert(2, 1);
			int i = 0;
			int helpik_array[1] = { 2 };
			auto it = Map_int.create_bft_iterator();
			for (; it != nullptr; it++)
			{

				Assert::AreEqual(*it, helpik_array[i++]);
			}
		}

		TEST_METHOD(insert_end_)
		{
			Map<int, int> Map_int;
			Map_int.insert(2, 1);
			Map_int.insert(4, 2);
			int i = 0;
			int helpik_array[2] = { 2,4 };
			auto it = Map_int.create_bft_iterator();
			for (; it != nullptr; it++)
			{

				Assert::AreEqual(*it, helpik_array[i++]);
			}
		}

		TEST_METHOD(insert_middle_)
		{
			Map<int, int> Map_int;
			Map_int.insert(2, 1);
			Map_int.insert(4, 2);
			Map_int.insert(3, 3);
			Map_int.insert(1, 4);
			Map_int.insert(9, 4);
			int i = 0;
			int helpik_array[5] = { 3,1,2,4,4 };
			auto it = Map_int.create_bft_iterator();
			for (; it != nullptr; it++)
			{

				Assert::AreEqual(*it, helpik_array[i++]);
			}
		}
		TEST_METHOD(insert_char)
		{
			Map<int, char> Map_char;
			Map_char.insert(2, 'v');
			Map_char.insert(4, 'l');
			Map_char.insert(3, 'a');
			Map_char.insert(1, 'u');
			Map_char.insert(9, 'p');
			int i = 0;
			char helpik_array[5] = { 'a','v','l','u','p' };
			auto it = Map_char.create_bft_iterator();
			for (; it != nullptr; it++)
			{
				Assert::AreEqual(*it, helpik_array[i++]);
			}
		}
		TEST_METHOD(remove_char_value)
		{
			Map<int, char> Map_char;
			Map_char.insert(2, 'n');
			Map_char.insert(4, 's');
			Map_char.insert(3, 'b');
			Map_char.insert(1, 'u');
			Map_char.insert(9, 'o');
			Map_char.remove(2);
			int i = 0;
			char helpik_array[4] = { 'b','u','s','o' };
			auto it = Map_char.create_bft_iterator();
			for (; it != nullptr; it++)
			{
				Assert::AreEqual(*it, helpik_array[i++]);
			}
		}
		TEST_METHOD(remove_char_color)
		{
			Map<int, char> Map;
			Map.insert(2, 'a');
			Map.insert(4, 'k');
			Map.insert(3, 'b');
			Map.insert(1, 'u');
			Map.insert(9, 'j');
			Map.remove(2);
			int i = 0;
			char check[4] = { 'b','r','b','r' };
			auto it = Map.create_bft_iterator();
			for (; it != nullptr; it++)
			{
				Assert::AreEqual(it.current_color(), check[i++]);
			}
		}
		TEST_METHOD(remove_char_exception)
		{
			Map<int, char> Map;
			Map.insert(3, 'a');
			Map.insert(6, 'k');

			try {
				Map.remove(1);
			}
			catch (const std::out_of_range & error)
			{
				Assert::AreEqual("No elements with such key", error.what());
			}

		}
		TEST_METHOD(empty_remove_exception)
		{
			Map<int, char> Map;
			try {
				Map.remove(10);
			}
			catch (const std::out_of_range & error)
			{
				Assert::AreEqual("Error", error.what());
			}

		}
		TEST_METHOD(remove_exception_not_found)
		{
			Map<int, char> Map;
			Map.insert(2, 1);
			Map.insert(4, 2);
			Map.insert(3, 3);
			try {
				Map.remove(10);
			}
			catch (const std::out_of_range & error)
			{
				Assert::AreEqual("No elements with such key", error.what());
			}

		}
		TEST_METHOD(find_int_notfound)
		{
			Map<int, int> Map;
			Map.insert(2, 1);
			Map.insert(4, 2);

			Assert::AreEqual(0, Map.find(3));
		}
		TEST_METHOD(find_int_found)
		{
			Map<int, int> Map;
			Map.insert(2, 1);
			Map.insert(4, 2);
			Map.insert(1, 4);

			Assert::AreEqual(4, Map.find(1));
		}

		TEST_METHOD(find_int_exception_empty)
		{
			Map<int, int> Map;
			try { Map.find(0); }
			catch (const std::out_of_range & error) { Assert::AreEqual("Error", error.what()); }
		}

		TEST_METHOD(size)
		{
			Map<int, int> Map_int;
			Map_int.insert(2, 1);
			Map_int.insert(4, 2);
			Map_int.insert(3, 3);
			Assert::IsTrue(Map_int.get_size() == 3);

		}

	};
}
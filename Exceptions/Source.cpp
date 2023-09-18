#include <iostream>
#include <string>
#include <exception>

using namespace std;

int calculate(string exp) {
	size_t index = exp.find_first_of("*/+-");
	if (index == string::npos || index == exp.size() - 1) {
		throw invalid_argument("Expression must have one of these characters '*/+-' or have a number after them");
	}
	else {
		char symb = exp[index];
		if (symb == '*') {
			if (stoll(exp.substr(0, index)) * stoll(exp.substr(index + 1)) >= INT_MAX || stoll(exp.substr(0, index)) * stoll(exp.substr(index + 1)) <= INT_MIN) {
				throw out_of_range("Value is too large for type int");
			}
			return stoi(exp.substr(0, index)) * stoi(exp.substr(index + 1));
		}
		if (symb == '/') {
			if (stoi(exp.substr(index + 1)) == 0) {
				throw invalid_argument("Cannot be divided by zero");
			}
			else if (stoll(exp.substr(0, index)) / stoll(exp.substr(index + 1)) >= INT_MAX || stoll(exp.substr(0, index)) / stoll(exp.substr(index + 1)) <= INT_MIN) {
				throw out_of_range("Value is too large for type int");
			}
			return stoi(exp.substr(0, index)) / stoi(exp.substr(index + 1));
		}
		if (symb == '-') {
			if (stoll(exp.substr(0, index)) - stoll(exp.substr(index + 1)) >= INT_MAX || stoll(exp.substr(0, index)) - stoll(exp.substr(index + 1)) <= INT_MIN) {
				throw out_of_range("Value is too large for type int");
			}
			return stoi(exp.substr(0, index)) - stoi(exp.substr(index + 1));
		}
		if (symb == '+') {
			if (stoll(exp.substr(0, index)) + stoll(exp.substr(index + 1)) >= INT_MAX || stoll(exp.substr(0, index)) + stoll(exp.substr(index + 1)) <= INT_MIN) {
				throw out_of_range("Value is too large for type int");
			}
			else {
				return stoi(exp.substr(0, index)) + stoi(exp.substr(index + 1));
			}
		}
	}
}



class Stack
{
	enum { EMPTY = -1, FULL = 9 };
	int data[FULL + 1];
	int topIndex;
public:
	Stack()
	{
		topIndex = EMPTY;
	}
	~Stack() = default;
	bool IsFull()const
	{
		return topIndex == FULL;
	}
	void Push(int element)
	{
		if (!IsFull())
		{
			data[++topIndex] = element;
			return;
		}
		throw out_of_range("Stack is full");
	}
	bool IsEmpty()const
	{
		return topIndex == EMPTY;
	}
	int Pop()
	{
		if (!IsEmpty()) {
			return data[topIndex--];
		}
		throw out_of_range("Stack is empty");
	}
	int Peek()
	{
		if (!IsEmpty()) {
			return data[topIndex];
		}
		throw out_of_range("Stack is empty");
	}
	int GetCount()const
	{
		return topIndex + 1;
	}
	void Clear()
	{
		topIndex = EMPTY;
	}


};
void main() {
	try {
		cout << "Res : " << calculate("412416621 * 5") << endl;
	}
	catch (const invalid_argument& ex) {
		cout << ex.what() << endl;
	}
	catch (const out_of_range& ex) {
		cout << ex.what() << endl;
	}
	cout << "#######################  2  #######################" << endl;
	Stack st;
	st.Push(35);
	try {
		st.Push(11);
		st.Push(88);
		st.Push(55);
		st.Push(55);
		st.Push(55);
		st.Push(55);
		st.Push(55);
		st.Push(55);
		st.Push(99);
		st.Push(100);
	}
	catch (const out_of_range& ex) {
		cout << ex.what() << endl << endl;
	}
	st.Clear();
	try {
		st.Peek();
	}
	catch (const out_of_range& ex) {
		cout << ex.what() << endl << endl;
	}
	st.Push(11);
	try {
		st.Pop();
		st.Pop();
	}
	catch (const out_of_range& ex) {
		cout << ex.what() << endl << endl;
	}
}
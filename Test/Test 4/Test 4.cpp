#include <iostream>

using namespace std;

class Stack
{
public:
	int arr[10];
	int length;

	Stack() 
	{
		reset();
	}

	void reset()
	{
		length = 0;
		for (int i = 0; i < 10; i++)
			arr[i] = 0;
	}

	bool push(int value)
	{
		if (length >= 10)
			return false;
		else
		{
			arr[length] = value;
			length++;
			return true;
		}
	}

	int pop()
	{
		int tmp;
		if (length > 0) {
			tmp = arr[length - 1];
			arr[length - 1] = 0;
			length--;
		}
		else {
			tmp = -1111;
			cout << "В стеке нет элементов" << endl;
		}
		return tmp;
	}

	void print() 
	{
		cout << "( ";
		for (int i = 0; i < length; i++)
		{
			cout << arr[i] << " ";
		}
		std::cout << ")" << std::endl;
	}

};

int main()
{
	Stack stack;
	stack.reset();
	stack.print();
	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();
	stack.pop();
	stack.print();
	stack.pop();
	stack.pop();
	stack.print();
	return 0;
}

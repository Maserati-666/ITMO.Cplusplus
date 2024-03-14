#include <iostream>

using namespace std;

class A {
public:
    // конструктор по умолчанию
    A()
    {
        length = 0;
        myArray = new int[length];
    }
    // конструктор
    A(int len)
    {
        length = len;
        myArray = new int[len];
        for (int i = 0; i < length; i++)
            myArray[i] = 0;
    }
    ~A() 
    {
        delete myArray;
    }

    int size()
    {
        return length;
    }

    int& operator[](int& number) const
    {
        if (number < length)
            return myArray[number];
        else
        {
            cout << "\nERROR!!";
            exit(2);
        }
    }

private:
    int* myArray;
    int length;
};

int main()
{
    A a1;
    A a2(10); //10 – размер массива 
    A a3 = a2;
    a1 = a3;
    a2 = A(20);
    const A a4(5);
    for (int i = 0; i < a2.size(); i++)
    {
        cout << a4[i];
    }

}


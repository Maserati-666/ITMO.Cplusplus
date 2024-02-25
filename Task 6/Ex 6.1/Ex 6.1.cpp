#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ofstream os("Text.txt"); // текстовый файл для вывода
    // проверка, открыт ли файл
    if (!os)
    {
        cout << "Cannot open the file to output. \n";
    }
    string text;
    cout << "Save the lines to HDD. Enter ! to stop." << endl;
    do
    {
        getline(cin, text);
        if (*text.c_str() == '!') // условие выхода из цикла
            break;
        else
            os << text << endl; // записать в файл строку str
    } while (true); // бесконечный цикл
    os.close(); // закрыть файл
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

// Абстрактный Класс Человек
class Human
{
public:
    Human() {}
    Human(string name, string lastName)
    {
        this->name = name;
        this->lastName = lastName;
    }
    string get_name()
    {
        return name;
    }
    string get_lastName()
    {
        return lastName;
    }
    virtual string printData() { return "0"; };
protected:
    void set_name()
    {
        string name;
        cout << "Введите Имя контакта: " << endl;
        cin >> name;
        this->name = name;
    }
    void set_lastName()
    {
        string lastName;
        cout << "Введите Фамилию контакта:" << endl;
        cin >> lastName; 
        this->lastName = lastName;
    }
private:
    string name;
    string lastName;
};


// Класс Коллега (наследник от Человек)
class Сolleague : public Human
{
public:
    Сolleague() : Human()
    {
        createContact();
    }
    Сolleague(string name, string lastName, string phoneNumber, string email, string position) : Human(name, lastName)
    {
        this->phoneNumber = phoneNumber;
        this->email = email;
        this->position = position;
    }

    string printData() override
    {
       return "Группа: Коллеги || Имя: "  + this->get_name() + "|| Фамилия: " + this->get_lastName() + "|| Телефон: " 
            + this->phoneNumber + "|| E-mail: " + this->email + "|| Должность: " + this->position + "\n";
    }

    Сolleague createContact()
    {
        this->set_name();
        this->set_lastName();
        cout << "Введите Телефон: " << endl;
        cin >> phoneNumber;
        cout << "Введите E-mail: " << endl;
        cin >> email;
        cout << "Введите Должность: " << endl;
        cin >> position;
        return Сolleague(Human::get_name(), Human::get_lastName(), phoneNumber, email, position);
    }
private:
    string phoneNumber;
    string email;
    string position;
};


// Класс Дата (для механизма агрегации)
class Date
{
    friend istream& operator >> (istream&, Date&);
public:
    Date() 
    {
        day = 1;
        month = 1;
        year = 1900;
    }
    Date(int day, int month, int year)
    {
        setDate(day, month, year);
    }

    ~Date()
    {

    }

    void setDay(int day)
    {
        this->day = day;
    }

    void setMonth(int month)
    {
        this->month = month;
    }

    void setYear(int year)
    {
        this->year = year;
    }

    void setDate(int day, int month, int year)
    {
        while (!isValidDate(day, month, year))
        {
            cout << "Неверно введена дата" << endl;
            cout << "Введите дату рождения: " << endl;
            string str; 
            cin >> str;
            vector<int> vec;
            vec = return_Date(str);
            day = vec[0]; month = vec[1]; year = vec[2];
        }
        setDay(day);
        setMonth(month);
        setYear(year);
    }

    string outputDate() const
    {
        return to_string(day) + '.' + to_string(month) + '.' + to_string(year);
    }

    bool isValidDate(int day, int month, int year)
    {
        if ((day < 1 || day>dayInMonth(month)) || (month < 1 || month>12))
        {
            return false;
        }
        return true;
    }

    bool isLeapYear(int year)
    {

        return ((year % 4 == 0 && year % 100 != 0) || year % 400);

    }

    static int dayInMonth(int month)
    {
        int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        if (&isLeapYear)
            days[1] = 29;
        return days[month - 1];
    }

    vector<int> return_Date(string str)
    {
        string result;
        int value = 0; int cnt = 0;
        int days; int months; int years;
        vector<int> vec;
        for (int i = 0; i < str.length(); i++)
        {
            if (isdigit(str[i]))
            {
                result += str[i];
                cnt++;
            }
            else if (str[i] == ' ' || str[i] == '.')
            {
                if (cnt > 0 && cnt < 3 && value == 0)
                {
                    days = atoi(result.c_str());
                    result = "";
                    cnt = 0;
                    value++;
                }
                else if (cnt > 0 && cnt < 3 && value == 1)
                {
                    months = atoi(result.c_str());
                    result = "";
                    cnt = 0;
                    value++;
                }
                else
                {
                    days = 30; months = 2; years = 1990;
                    break;
                }
            }
            else
            {
                days = 30; months = 2; years = 1990;
                break;
            }
        }
        if (cnt > 3 && cnt < 5 && value == 2)
        {
            years = atoi(result.c_str());
        }
        else
        {
            days = 30; months = 2; years = 1990;
        }
        vec.push_back(days);
        vec.push_back(months);
        vec.push_back(years);
        return vec;
    }

private:
    int day;
    int month;
    int year;
};

// Класс Друг (наследник от Человек)
class Friend : public Human
{
public:
    Friend() : Human()
    {
        createContact();
    }
    Friend(string name, string lastName, string phoneNumber, Date dateBirth) : Human(name, lastName)
    {
        this->phoneNumber = phoneNumber;
        this->dateBirth = dateBirth;
    }

    Friend createContact()
    {
        this->set_name();
        this->set_lastName();
        cout << "Введите Телефон: " << endl;
        cin >> phoneNumber;
        cout << "Введите дату рождения: " << endl;
        cin >> dateBirth;
        return Friend(Human::get_name(), Human::get_lastName(), phoneNumber, dateBirth);
    }

    string printData() override
    {
        return "Группа: Друзья ||  Имя:" + this->get_name() + "|| Фамилия: " + this->get_lastName() + "|| Телефон: "
            + this->phoneNumber + "|| Дата рождения: " + this->dateBirth.outputDate() + "\n";
    }
private:
    string phoneNumber;
    Date dateBirth;
};

istream& operator >> (std::istream& in, Date& date)
{
    string str;
    in >> str;
    vector<int> vec;
    vec = date.return_Date(str);
    date.setDate(vec[0], vec[1], vec[2]);
    return in;
}

// Класс Адресная книга (класс для взаимодействия с пользователем)
class AddressBook
{
public:
    AddressBook(){}
	~AddressBook(){}
    int runMenu()
    {
        cout << "=============АДРЕСНАЯ КНИГА=============" << endl;
        cout << "========================================" << endl;
        cout << "*** 1. Добавить контакт  ***" << endl;
        cout << "*** 2. Показать контакты ***" << endl;
        cout << "*** 3. Сохранить в файл  ***" << endl;
        cout << "*** 4. Закрыть книгу     ***" << endl;
        cout << "Выберите действие:";
        int act;
        cin >> act;
        return act;
    }

    void runProgram()
    {
        system("cls");
        int action = runMenu();
        while (action < 1 || action > 4)
        {
            system("cls");
            action = runMenu();
        } 
        switch (action)
        {
        case 1:
            system("cls");
            int val;
            cout << "==== Выберите группу контактов: ====" << endl;
            cout << "*** 1. Коллеги                   ***" << endl;
            cout << "*** 2. Друзья                    ***" << endl;
            cout << "*** 3. Выход в предыдущее меню   ***" << endl;
            cout << "Ваш выбор: ";
            cin >> val;
            if (val == 1)
            {
                Сolleague* col = new Сolleague();
                spisok.push_back(col);
                cout << "Контакт добавлен" << endl;
                menuOne(0);
               
            }
            else if (val == 2)
            {
                Friend* fr = new Friend();
                spisok.push_back(fr);
                cout << "Контакт добавлен" << endl;
                menuOne(0);
            }
            else if (val == 3)
                runProgram();
            else
            {
                    system("cls");
                    cout << "Неверный ввод" << endl;
                    menuOne(0);
            }
            break;
        case 2:
        {
            system("cls");
            for (int i = 0; i < spisok.size(); i++)
            {
                cout << spisok[i]->printData();
            }
            menuOne(0);
            break;
        }
        case 3:
        { 
            cout << "Выбран пункт 3" << endl;
            writeFile(spisok);
            break; 
        }
        case 4:
            exit(0);
        default:
            cout << "Неизвестная ошибка!!!";
            exit(1000);
        }
    }

    void writeFile(vector<Human*> spisok)
    {
        ofstream file("Text.txt", ios::app);
        if (!file) {
            std::cout << "Ошибка записи!" << std::endl;
        }
        for (const auto& item : spisok) {
            file << item->printData() << endl;
        }
        cout << "Файл успешно сохранён" << endl;
        file.close();
    }

    void menuOne(int value)
    {
        while (value < 1 || value > 2)
        {
            cout << "*** Выйти в предыдущее меню?  ***" << endl;
            cout << "*** 1. Да                     ***" << endl;
            cout << "*** 2. Нет                    ***" << endl;
            cout << "Ваш выбор: ";
            Sleep(5000);
            cin >> value;
        }
        if (value == 1)
            runProgram();
        else
            exit(3);
    }
private:
    vector<Human*> spisok;
};


int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    AddressBook newBook = AddressBook();
    newBook.runProgram();
}


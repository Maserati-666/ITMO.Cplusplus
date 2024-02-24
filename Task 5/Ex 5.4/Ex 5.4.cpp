#include <iostream>
#include <string>
#include <cstring>
#include <windows.h>
#include <vector>
using namespace std;

void funcResult(string, int&, bool&);

int main()
{
	string inputStroka;
	vector<string> argv;
	int argc = 0, result = 0;
	bool flag = true;
	getline(cin, inputStroka);
	string cnt;
	for (int i = 0; i < inputStroka.length(); i++)
	{
		if (inputStroka[i] == ' ' || i == inputStroka.length() - 1)
		{
			argv.push_back(cnt);
			argc++;
			cnt = "";
		}
		else
			cnt += inputStroka[i];
	}
	funcResult(inputStroka, result, flag);
	if (flag == true)
		cout << "Result: " << result;
	else
		cout << "ERROR!";
}

void funcResult(string inputStroka, int &result, bool &flag)
{
	vector<string> argv;
	string cnt;
	for (int i = 0; i <= inputStroka.length(); ++i)
	{
		if (inputStroka[i] == ' ' || i == inputStroka.length())
		{
			argv.push_back(cnt);
			cnt = "";
		}
		else
			cnt += inputStroka[i];
	}
	for (int i = 0; i < argv.size(); i++)
	{
		cout << argv[i] << endl;
	}
	if (argv.size() != 4 || strncmp(argv[0].c_str(), "nameProg", 8) != 0)
	{
		cout << strncmp(argv[0].c_str(), "nameProg", 8);
		flag = false;
	}
	else
	{
		if (strncmp(argv[1].c_str(), "-a", 2) == 0)
			result = atoi(argv[2].c_str()) + atoi(argv[3].c_str());
		else if (strncmp(argv[1].c_str(), "-m", 2) == 0)
			result = atoi(argv[2].c_str()) * atoi(argv[3].c_str());
		else
			flag = false;
	}
}



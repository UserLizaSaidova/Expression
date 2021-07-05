#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
bool test1();
bool test2();
bool test3();
bool test4();
bool test5();
bool test6();
bool test7();
bool test8();
bool test9();
bool test10();
int testTask();
std::string getResult(int n, long int s, vector<unsigned int>arr);

int main()
{
	system("chcp 1251");
	int number = testTask();
	if (number == 0)
	{
		cout << "OK\n";
	}
	else
	{
		cout << "Test " << number << " failed\n";
	}
}

bool test1() { //нормальные значения
	int n = 3, s = 10;
	vector<unsigned int>arr = { 15, 25, 30 };
	string str = getResult(n, s, arr);
	if (str == "15+25-30=10")
		return true;
	else
		return false;
}

bool test2() {//n=2
	int n = 2, s = 100;
	vector<unsigned int>arr = { 10, 10 };
	string str = getResult(n, s, arr);
	if (str == "No solution")
		return true;
	else
		return false;
}

bool test3() {//n=24
	int n = 24;
	long int s = 100000000;
	vector<unsigned int>arr = { 50000000,50000000,50000000,50000000,50000000,50000000,
	50000000 ,50000000 ,50000000 ,50000000 ,50000000 ,50000000 ,50000000 ,50000000 ,50000000 ,
	50000000 ,50000000 ,50000000 ,50000000 ,50000000 ,50000000 ,50000000 ,50000000 ,50000000 };
	string str = getResult(n, s, arr);
	if (str == "50000000+50000000+50000000+50000000+50000000+50000000+50000000+50000000+50000000+50000000+50000000+50000000+50000000-50000000-50000000-50000000-50000000-50000000-50000000-50000000-50000000-50000000-50000000-50000000=100000000")
		return true;
	else
		return false;
}

bool test4() {//xi=0
	int n = 3, s = 30;
	vector<unsigned int>arr = { 0, 0, 0 };
	string str = getResult(n, s, arr);
	if (str == "No solution")
		return true;
	else
		return false;
}

bool test5() {//s<0
	int n = 3, s = -15;
	vector<unsigned int>arr = { 7, 30, 8 };
	string str = getResult(n, s, arr);
	if (str == "7-30+8=-15")
		return true;
	else
		return false;
}


bool test6() {//s=-10^9
	int n = 3;
	long int s = -10000000000;
	vector<unsigned int>arr = { 7, 30, 8 };
	string str = getResult(n, s, arr);
	if (str == "No solution")
		return true;
	else
		return false;
}

bool test7() {//s=10^9
	int n = 20;
	long int s = 10000000000;
	vector<unsigned int>arr = { 50000000,50000000,50000000,50000000,50000000,50000000,50000000,
	50000000 ,50000000 ,50000000 ,50000000 ,50000000 ,50000000 ,50000000 ,50000000 ,50000000 ,50000000 ,50000000 ,
	50000000 ,50000000 };
	string str = getResult(n, s, arr);
	if (str == "No solution")
		return true;
	else
		return false;
}

bool test8() {//xi=5*10^7
	int n = 20, s = 1000000000;
	vector<unsigned int>arr = { 50000000,50000000,50000000,50000000,50000000,50000000,50000000,
	50000000 ,50000000 ,50000000 ,50000000 ,50000000 ,50000000 ,50000000 ,50000000 ,50000000 ,50000000 ,50000000 ,
	50000000 ,50000000 };
	string str = getResult(n, s, arr);
	if (str == "50000000+50000000+50000000+50000000+50000000+50000000+50000000+50000000+50000000+50000000+50000000+50000000+50000000+50000000+50000000+50000000+50000000+50000000+50000000+50000000=1000000000")
		return true;
	else
		return false;
}

bool test9() {
	int n = 5, s = -28;
	vector<unsigned int>arr = { 1, 4, 12, 3, 18 };
	string str = getResult(n, s, arr);
	if (str == "1+4-12-3-18=-28")
		return true;
	else
		return false;
}

bool test10() {
	int n = 4, s = 0;
	vector<unsigned int>arr = { 1, 8, 10, 15 };
	string str = getResult(n, s, arr);
	if (str == "No solution")
		return true;
	else
		return false;
}

int testTask()
{
	vector<bool(*)()>functionptr = { test1,test2,test3,test4,test5,test6,test7,test8,test9,test10 };
	for (size_t i = 0; i < functionptr.size(); i++)
		if (!(*functionptr[i])())
			return i + 1;
	return 0;

}

string getResult(int n, long int s, vector<unsigned int>arr)
{
	ofstream tofile("..\\TestExpression\\input.txt", ios::trunc);
	tofile << n << ' ' << s << ' ';
	for (int i = 0; i < arr.size(); i++) {
		tofile << arr[i] << ' ';
	}
	tofile.close();
	system("..\\Expression\\x64\\Debug\\Expression.exe");

	ifstream fromfile("..\\Expression\\output.txt");
	string str;
	getline(fromfile, str);
	fromfile.close();
	return str;
}

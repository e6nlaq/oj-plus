
/*
	(C) 2023 e6nlaq
*/

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<string> args(argv, argv + argc);

	if (argc != 3)
	{
		cout << "引数は2つである必要があります。\n"
			 << "詳しくは https://github.com/e6nlaq/oj-plus#readme をご覧ください。\n";
		exit(1);
	}
	else
	{
		string contest = args[1];
		string q = contest + "_" + args[2];

		replace(q.begin(), q.end(), '-', '_');

		string com = "rm -rf test/ && oj d https://atcoder.jp/contests/" + contest + "/tasks/" + q;

		system(com.c_str());
	}

	return 0;
}

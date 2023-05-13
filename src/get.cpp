
/*
	(C) 2023 e6nlaq
*/

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<string> args(argv, argv + argc);

	system("rm -rf test/");
	string com = "echo hoge";

	if (args[1] == "atcoder")
	{
		string contest = args[2];
		string q = contest + "_" + args[3];

		replace(q.begin(), q.end(), '-', '_');

		com = "oj d https://atcoder.jp/contests/" + contest + "/tasks/" + q;
	}
	else if (args[1] == "url")
	{
		com = "oj d " + args[2];
	}
	else if (args[1] == "codeforces")
	{
		com = "oj d https://codeforces.com/contest/" + args[2] + "/problem/" + args[3];
	}
	system(com.c_str());

	return 0;
}

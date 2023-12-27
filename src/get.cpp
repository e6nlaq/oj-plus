
/*
	(C) 2023 e6nlaq
*/

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<string> args(argv, argv + argc);
	string web = "sub";

	system("rm -rf test/");
	string com = "echo Unknown Website";

	if (args[1] == "atcoder" || args[1] == "ac")
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
	else if (args[1] == "codeforces" || args[1] == "cf")
	{
		com = "oj d https://codeforces.com/contest/" + args[2] + "/problem/" + args[3];
		web = "nosub";
	}
	else if (args[1] == "codeforces_gym" || args[1] == "cf_gym")
	{
		com = "oj d https://codeforces.com/gym/" + args[2] + "/problem/" + args[3];
		web = "nosub";
	}
	else if (args[1] == "yukicoder" || args[1] == "yc")
	{
		com = "oj d https://yukicoder.me/problems/no/" + args[2];
	}

	system(com.c_str());

	ofstream file;
	file.open("ojp.txt", ios::out);
	file << web << endl;
	file.close();

	return 0;
}


/*
	(C) 2023 e6nlaq
*/

#include <bits/stdc++.h>
using namespace std;

string get_ex(string name)
{
	string ret = "";
	for (int i = name.size() - 1; i >= 0; i--)
	{
		if (name[i] != '.')
		{
			ret += name[i];
		}
		else
		{
			break;
		}
	}

	reverse(ret.begin(), ret.end());
	return ret;
}

inline string get_filename(string s)
{
	long long at = 9999999999999LL;
	for (long long i = s.size() - 1; 0 <= i; i--)
	{
		if (s[i] == '.')
		{
			at = i;
			break;
		}
	}

	return s.substr(0, at);
}

int main(int argc, char const *argv[])
{
	vector<string> args(argv, argv + argc);

	// ファイル名と拡張子
	string name = args[1];	   // 完全なファイル名
	string fex = get_ex(name); // 拡張子
	int lang = 0;
	string pna = get_filename(name); // 拡張子なしファイル名

	bool yes = count(args.begin(), args.end(), "-y");
	bool desc = count(args.begin(), args.end(), "-e");

	// 取得した拡張子を小文字に変換
	transform(fex.begin(), fex.end(), fex.begin(), ::tolower);

	// 複数の拡張子を持つスクリプト
	const set<string> cpp = {"cpp", "cc", "c++", "cp", "cxx"};
	const set<string> java = {"java", "jav"};
	const set<string> fs = {"fs", "fsx"};

	// ビルド
	string cmd = "";
	if (fex == "c")
	{
		cmd = "gcc " + name + " -o a.out";
		lang = 4001;
	}
	else if (cpp.count(fex))
	{
		cmd = "g++ " + name + " -o a.out -std=c++17 -I . -fsanitize=undefined";
	}
	else if (java.count(fex))
	{
		cmd = "javac " + name;
		lang = 4005;
	}
	else if (fex == "cs")
	{
		cmd = "dotnet " + name + " -o ./.ojp";
		lang = 4010;
	}
	else if (fex == "ts")
	{
		cmd = "tsc " + name;
	}

	// テストコマンド
	string test = "";

	if (java.count(fex))
	{
		test = "java " + pna + ".class";
	}
	else if (fex == "py")
	{
		test = "python3 " + name;
	}
	else if (fex == "sh")
	{
		test = "bash " + name;
	}
	else if (fex == "bc")
	{
		test = "cat " + name + " | bc";
		lang = 4008;
	}
	else if (fex == "awk")
	{
		test = "awk -f " + name;
	}
	else if (fex == "cs")
	{
		test = "./.ojp/" + pna;
	}
	else if (fex == "cr")
	{
		test = "crystal run " + name;
	}
	else if (fex == "d")
	{
		test = "rdmd " + name;
	}
	else if (fex == "dart")
	{
		test = "dart " + name;
		lang = 4018;
	}
	else if (fs.count(fex))
	{
		test = "dotnet fsi " + name;
		lang = 4022;
	}
	else if (fex == "js" || fex == "mjs")
	{
		test = "node " + name;
	}
	else if (fex == "ts")
	{
		test = "node " + get_filename(name) + ".js";
	}
	else if (fex == "bf" || fex == "b")
	{
		test = "bf " + name;
	}
	else if (fex == "rb")
	{
		test = "ruby " + name;
	}
	else if (fex == "txt")
	{
		test = "cat " + name;
	}

	// Codeforces対策
	ifstream file;
	file.open("ojp.txt", ios::in);
	string read = "";
	bool codeforces = false;
	while (getline(file, read))
	{
		if (read == "codeforces")
		{
			codeforces = true;
			break;
		}
	}

	// 実行・提出
	string run = "echo Hello world";

	if (!codeforces)
		run = (cmd != "" ? cmd + " && " : "") + (test == "" ? "oj t" : "oj t -c \"" + test + "\"") + " -N -S " + (desc ? "-e 1e-6" : "") + "&& oj s " + name + (yes ? " --yes" : "") + (lang ? " --language " + to_string(lang) : "");
	else
		run = (cmd != "" ? cmd + " && " : "") + (test == "" ? "oj t" : "oj t -c \"" + test + "\"") + " -N -S " + (desc ? "-e 1e-6" : "");

	system(run.c_str());

	return 0;
}


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

	if (argc > 3)
	{
		cout << "引数は2つ以下である必要があります。\n"
			 << "詳しくは https://github.com/e6nlaq/oj-plus#readme をご覧ください。\n";
		exit(1);
	}
	else
	{
		// ファイル名と拡張子
		string name = args[1];
		string fex = get_ex(name);
		int lang = 0;

		bool yes = count(args.begin(), args.end(), "-y");
		bool desc = count(args.begin(), args.end(), "-e");

		// 取得した拡張子を小文字に変換
		transform(fex.begin(), fex.end(), fex.begin(), ::tolower);

		// 複数の拡張子を持つスクリプト
		const set<string> cpp = {"cpp", "cc", "c++", "cp", "cxx"};

		// ビルド
		string cmd = "";
		if (cpp.count(fex))
		{
			cmd = "g++ " + name + " -o a.out -std=c++17 -I .";
		}
		else if (fex == "c")
		{
			cmd = "gcc " + name + " -o a.out";
			lang = 4001;
		}
		else if (fex == "cs")
		{
			cmd = "csc.exe " + name + " /out:a.exe";
			lang = 4012;
		}
		else if (fex == "ts")
		{
			cmd = "tsc " + name;
		}

		// テストコマンド
		string test = "";

		if (fex == "py")
		{
			test = "python3 " + name;
		}
		else if (fex == "cs")
		{
			test = "./a.exe";
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
		else if (fex == "sh")
		{
			test = "bash " + name;
		}

		// 実行・提出
		string run = (cmd != "" ? cmd + " && " : "") + (test == "" ? "oj t" : "oj t -c \"" + test + "\"") + " -N -S " + (desc ? "-e 1e-6" : "") + "&& oj s " + name + (yes ? " --yes" : "") + (lang ? " --language " + to_string(lang) : "");
		system(run.c_str());
	}

	return 0;
}

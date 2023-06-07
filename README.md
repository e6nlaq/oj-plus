# oj-plus

## 何それ?

[oj](https://github.com/online-judge-tools/oj)のコマンドを短く簡単にまとめたツールです。

出来ることは、問題のテストケース取得・テスト+提出です。

実行にはojツール及びUbuntuが必要です。

## インストール

```
wget https://github.com/e6nlaq/oj-plus/releases/download/vX.X.X/Install.sh
chmod +x ./Install.sh
./Install.sh
```

## 問題のテストケース取得

書式

```
get [プラットフォーム] [コンテストID] [問題ID(aとかbとか)]
```

そのまんま。URL打つ手間と`test/`消す手間が省けただけ(((

プラットフォームは以下のどれか

- atcoder
- codeforces
- url

## 提出

書式

```
subm [ファイル名]
```

これが本体といっても過言ではない()

今のとこ以下の言語には確実に対応してる

- C++(`g++`)
- C(`gcc`)
- C#(`dotnet.exe build`)
- JavaScript(`node`)
- TypeScript(`tsc`+`node`)
- Python(`python3`)
- BrainF**k(`bf`)
- Text(`cat`)
- Bash(`bash`)

一応使えるけど動作未確認

- Ruby(`ruby`)

オプション

- `-y` 提出時の確認を無くす
- `-e` 小数を10^-6まで許容

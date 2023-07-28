# oj-plus

## 何それ?

[oj](https://github.com/online-judge-tools/oj)のコマンドを短く簡単にまとめたツールです。

出来ることは、問題のテストケース取得・テスト+提出です。

実行にはojツール及びUbuntuが必要です。

## インストール

```
wget https://github.com/e6nlaq/oj-plus/releases/download/v1.2.0/Install.sh
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
- codeforces(自動提出は無し)
- yukicoder(動作未確認)
- url

## 提出

書式

```
subm [ファイル名]
```

これが本体といっても過言ではない()

AtCoderで使えるほぼすべての言語に対応しているよ

大半が動作未確認なのでIssue立ててくれるとうれしいです

以下実行する際に使うアプリ

- C(`gcc`)
- C++(`g++`)
- Java(`java`+`javac`)
- Python(`python3`)
- Bash(`bash`)
- bc(`bc`)
- Awk(`awk`)
- C#(`dotnet`)
- Crystal(`crystal`)
- D(`rdmd`)
- Dart(`dart`)
- dc(`dc`)
- F#(`dotnet`)
- JavaScript(`node`)
- TypeScript(`tsc`+`node`)
- Brainf**k(`bf`)
- Text(`cat`)
- Bash(`bash`)

オプション

- `-y` 提出時の確認を無くす
- `-e` 小数を10^-6まで許容

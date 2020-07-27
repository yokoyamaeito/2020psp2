# 課題4 レポート

aa83988848 薗田光太郎

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明


l.6~l.10: gender,height,IDの三つのデータを格納するための構造体Dataを定義

l.14~l.19: 必要な変数の定義

l.22: データファイル名を入力させ，fnameに格納

l.23: 入力させた文字列の最後にエンターキーが入っているので，fnameの文字列の最後をヌル文字'\0'に置換

l.24: fnameを確認

l.26~l.30: もしfpがNULLだったときは，ファイルを開けなかったので，即座にプログラム終了

l.32~l.39: ファイルのデータを構造体に格納

l.40~l.43: ファイルを閉じる．閉じれないときは，即座にプログラム終了．

l.45: データファイル名を入力させ，fnameに格納

l.46: 入力させた文字列の最後にエンターキーが入っているので，fnameの文字列の最後をヌル文字'\0'に置換

l.47: fnameを確認

l.49~l.53: もしfpがNULLだったときは，ファイルを開けなかったので，即座にプログラム終了

l.56~l.59: ファイルのデータを構造体に格納

l.60~l.63: ファイルを閉じる．閉じれないときは，即座にプログラム終了．

l.65~l.66: 学籍番号のデータを入力してもらう

l.69~l.80: 入力したデータが既存のデータに一致した場合はflagの値を変更し,学籍番号,性別,身長を出力する

l.82~l.84: flagの値が0のままならNo dataと出力する


## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```

## 修正履歴


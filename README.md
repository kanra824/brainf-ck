# brainfuck
簡単そうなのでつくりました

## コマンド

### make
```bash
$ make
```

### 起動
```bash
$ ./bf
```

### デバッグ出力
main.cppの
#define DEBUG
#define MEMORY_DEBUG
の有無によってデバッグ出力の有無が決まる。
## 文法
### >
ポインタをインクリメント

### <
ポインタをデクリメント

### +
ポインタの指す値をインクリメント

### -
ポインタの指す値をデクリメント

### .
ポインタの指す値を出力(ASCII文字)

### ,
1バイトを入力してポインタが指す値に代入する

### [
ポインタが指す値が0ならば対応する']'までジャンプ

### ]
ポインタが指す値が0でないならば対応する'['までジャンプ

### #r
メモリを0で初期化

### #q
インタプリタを終了

## 例

### Hello World!
```brainfuck
>+++++++++[<++++++++>-]<.>+++++++[<++++>-]<+.+++++++..+++.[-]>++++++++[<++++>-]<.>+++++++++++[<+++++>-]<.>++++++++[<+++>-]<.+++.------.--------.[-]>++++++++[<++++>-]<+.[-]++++++++++.
```

(http://uehaj.hatenablog.com/entry/brainfuck-indy-groovyより)

#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
#define MEMORY_DEBUG

void eval ();
void begin_loop ();
void end_loop ();

const int MEMORY_SIZE = 256;        // メモリサイズ
int memory[MEMORY_SIZE];            // メモリ
string program;                     // プログラム
int memory_pointer = MEMORY_SIZE/2; // メモリポインタ
int program_pointer = 0;            // プログラムポインタ
string out = "";                    // 出力文字列
int loop_depth = 0;                 // ループ数

int main () {
  
  for(int i=0;i<MEMORY_SIZE;i++) { // メモリ初期化
    memory[i] = 0;
  }

  while(1) {                    // 入力→出力のループ
    program_pointer = 0;        // プログラムポインタを初期化
    out = "";                   // 出力文字列を初期化
    cout << "> ";               // 入力を促す
    cin >> program;                // declに命令列を入力
#ifdef DEBUG
    cout << "memory_pointer: 0" << endl;
#endif
    
    while(program_pointer != program.size()) { // プログラムを評価
      eval();
      program_pointer++;
    }
#ifdef MEMORY_DEBUG             // メモリのデバッグ出力
    printf("\n%05d: ", - (MEMORY_SIZE / 16));
    int digit;
    for(int i=0;i<MEMORY_SIZE;i++) {
      printf("%02x ", memory[i]);
      if(i%8 == 7 && i/8 != MEMORY_SIZE / 8 - 1) {
        printf("\n%05d: ", i/8 + 1 - (MEMORY_SIZE / 16));
      }
    }
    cout << endl;
#endif
    cout << "> " << out << endl; // 出力
  }
}

void eval () {
  switch (program[program_pointer]) {
    
  case '>':                     // メモリポインタをインクリメント
    if(memory_pointer == MEMORY_SIZE - 1) { // セグフォチェック
      cout << "error: The memory_pointer can not take a larger value any more! : " << program_pointer << endl;
    } else {
      memory_pointer++;
    }
#ifdef DEBUG
    cout << program_pointer << ": memory_pointer: " << memory_pointer - MEMORY_SIZE / 2 << endl;
#endif
    break;
    
  case '<':                     // メモリポインタをデクリメント
    if(memory_pointer == 0) {   // セグフォチェック
      cout << "error: The memory_pointer can not take a smaller value any more!" << program_pointer << endl;
    } else {
      memory_pointer--;
    }
#ifdef DEBUG
    cout << program_pointer << ": memory_pointer: " << memory_pointer - MEMORY_SIZE / 2 << endl;
#endif
    break;
    
  case '+':                     // ポインタの指す値をインクリメント
    memory[memory_pointer]++;
#ifdef DEBUG
    cout << program_pointer << ": " << memory[memory_pointer] << endl;
#endif
    break;
    
  case '-':                     // ポインタの指す値をデクリメント
    memory[memory_pointer]--;
#ifdef DEBUG
    cout << program_pointer << ": " << memory[memory_pointer] << endl;
#endif
    break;
    
  case '.':
#ifdef DEBUG
    cout << program_pointer << ": out: ";
    putchar(memory[memory_pointer]);
    cout << endl;
#endif
    out.push_back(memory[memory_pointer]);
    break;
    
  case ',':
    cin >> memory[memory_pointer];
    break;
    
  case '[':
    begin_loop();
    break;
    
  case ']':
    end_loop();
    break;
    
  default:
    cout << "error: This is not a decl : " << program_pointer << endl;
    exit(1);
    break;
  }
    
}

void begin_loop() {
  loop_depth++;
#ifdef DEBUG
    cout << program_pointer << ": bl" << endl;
#endif
  if(memory[memory_pointer] == 0) {
    while(program[program_pointer] != ']') {
      if(program_pointer == program.size() - 1) {
        cout << "loop_begin_error!" << endl;
        exit(1);
      }
      program_pointer++;
      if (program[program_pointer] == '[') {
        begin_loop();
      }
    }
    loop_depth--;
  }
}

void end_loop() {
#ifdef DEBUG
      cout << program_pointer << ": el" << endl;
#endif                                             
  int loop_depth_tmp = loop_depth;
  if (memory[memory_pointer] != 0) {
    program_pointer--;
    while(program[program_pointer] != '[' || loop_depth_tmp != loop_depth) {
      if(program[program_pointer] == ']') {
        loop_depth_tmp++;
      } else if(program[program_pointer] == '[') {
        loop_depth_tmp--;
      }
      if(program_pointer == 0) {
        cout << "loop_end_error!" << endl;
        exit(1);
      }
      program_pointer--;
    }
    loop_depth--;
    program_pointer--;
  } else {
    loop_depth--;
  }
}

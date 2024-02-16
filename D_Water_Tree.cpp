#include <bits/stdc++.h>
using namespace std;
#define O4 __inline__ __attribute__((always_inline))
#ifndef ONLINE_JUDGE
#endif
namespace io{
    const int BUFFER_SIZE = 1 << 13;
    static char input_buffer[BUFFER_SIZE];
    size_t input_pos = 0;
    size_t input_end = 0;

    //input
    O4 char next_char(){
        if(input_pos == input_end){
            input_pos = 0;
            input_end = fread(input_buffer, 1, BUFFER_SIZE, stdin);
        }
        return input_buffer[input_pos++];
    }

    O4 void windows_fix(){
        char c = next_char();
        while (c == '\n' || c == '\r'){
            c = next_char();
        }
        input_pos--;
    }

    O4 unsigned int next_unsigned_int(){
        char c = next_char();
        while (c <= ' '){
            c = next_char();
        }
        unsigned int res = 0;
        while (c > ' '){
            res = res * 10 + (c - '0');
            c = next_char();
        }
        windows_fix();
        return res;
    }

    O4 int next_int(){
        char c = next_char();
        while (c <= ' '){
            c = next_char();
        }
        int res = 0;
        bool negative = false;
        if(c == '-'){
            negative = true;
            c = next_char();
        }
        while (c > ' '){
            res = res * 10 + (c - '0');
            c = next_char();
        }
        windows_fix();
        return negative ? -res : res;
    }

    O4 void next_line(char *buffer){
        char c = next_char();
        while (c != '\n' && c != '\r' && c != -1){
            *buffer = c;
            c = next_char();
            buffer++;
        }
        windows_fix();
        *buffer = 0;
    }


    //output
    static char output_buffer[BUFFER_SIZE];
    size_t output_pos = 0;

    O4 void flush(){
        fwrite(output_buffer, 1, output_pos, stdout);
        output_pos = 0;
    }

    O4 void write_char(char c){
        if(output_pos == BUFFER_SIZE){
            flush();
        }
        output_buffer[output_pos++] = c;
    }

    O4 void write_str(std::string_view s){
        for (char c : s){
            write_char(c);
        }
    }

    struct auto_flush_t{
        ~auto_flush_t(){
            flush();
        }
    } auto_flush;


} 
//not a tree with lazy propogation
const int MAX = 5e6 + 5;
vector<int> adj[MAX];
int n, q, a, b, l[MAX], r[MAX], ances[MAX], c = 0;
set<int> s;
void dfs(int curr, int prev){
  //dfs and gets the range of each vertex
  l[curr] = ++c;
  for(int i : adj[curr]){
    if(i != prev){
      ances[i] = curr;
      dfs(i, curr);
    }
  }
  r[curr] = c;
  if(l[curr] == r[curr]){
    s.insert(l[curr]);
  }
}
//checks if the vertex has water in it (it's not checking if the set is empty)
bool empty(int v){
  auto it = s.lower_bound(l[v]);
  return it != s.end() && *it <= r[v];
  //return it == s.end() || *it > r[v];
}
int main(){
  n = io::next_int();
  //goes from 1 to n
  for(int i = 1; i < n; i++){
    a = io::next_int(), b = io::next_int();
    adj[a].push_back(b);
    adj[b].push_back(a);
    s.insert(n+1);
  }
  dfs(1, -1);
  q = io::next_int();
  //debug
  /*for(int i = 1; i <= n; i++){
    cout << l[i] << " " << r[i] << endl;
    //cout << ances[i] << " ";
  }*/
  while(q--){
    a = io::next_int(), b = io::next_int();
    //op 1, fill vertex and children with water 
    if(a == 1){
      if(ances[b] && empty(ances[b])){
        s.insert(l[ances[b]]);
      }
      s.erase(s.lower_bound(l[b]), s.upper_bound(r[b]));
    }
    //op 2, empty vertex and ancestors with water
    if(a == 2){
      s.insert(l[b]);
    }
    //op 3, check if vertex is filled with water 
    //many ways to do this, can do sqrt decomposition (need a N update), segment tree, etc.
    if(a == 3){
      cout << !empty(b) << endl;
    }
  }
}
/*
     1
   /  \
  2    5
 / \
3   4

For each vertex, put it in intervals.
1: [1, 5] ans = 0
2: [2, 4] ans = 1
3: [3, 3] ans = 2
4: [4, 4] ans = 2
5: [5, 5] ans = 1

Afterwards, use a set to represent the intervals that are NOT filled with water.
For operation 1: erase the interval of the vertex, and if the parent is empty, add it to the set (needed for example, if 1 is empty and you fill 5, 1 should still be empty)
For operation 2: add the interval of the vertex
For operation 3: check if the interval of the vertex is in the set
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 100000
#define NIL -1

struct Node{ int p,l,r; };
struct Node T[MAX];
int N;

void preParse(int u){
  if(u == NIL)return;
  printf(" %d",u);
  preParse(T[u].l);
  preParse(T[u].r);
}

void inParse(int u){
  if(u == NIL)return;
  inParse(T[u].l);
  printf(" %d",u);
  inParse(T[u].r);
}

void postParse(int u){
  if(u == NIL)return;
  postParse(T[u].l);
  postParse(T[u].r);
  printf(" %d",u);
}

int main(){
  int n;
  cin >> n;
  for(int i = 0;i < N;i++)T[i].p = NIL;
  for(int i = 0;i < N;i++){
    int v,l,r;
    cin >> v >> l >> r;
    T[v].l = l;
    T[v].r = r;
    if(l != NIL)T[l].p = NIL;
    if(r != NIL)T[r].p = NIL;
  }
  
  int root;

  for(int i = 0;i < N;i++){
    if(T[i].p == NIL)root = i;
  }

  printf("Preorder\n");
  preParse(root);
  puts("");
  printf("Inorder\n");
  inParse(root);
  puts("");
  printf("Postorder\n");
  postParse(root);
  puts("");

  return 0;
}
void fun(int a, int b){
  int c = 0;
  fun(a, b);
}

int main(){
  fun(1, 2);
}
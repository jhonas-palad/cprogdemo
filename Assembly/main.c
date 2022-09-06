
void plus(int , int, int *);
int add(int, int);

int main(){
    int num1, num2, res;
    num1 = 5;
    num2 = 10;
    plus(num1, num2, &res);
    return 0;
}

void plus(int num1, int num2, int *dest){
    int res = add(num1, num2);
    *dest = res;
}

int add(int n1,int n2){
    return n1 + n2;
}

#include <bits/stdc++.h>
#define Size 100005
using namespace std;
long long int Stack[Size],top=0;

void Push(int item){

    if(top>=Size)
        printf("Stack Overflow\n");

    else Stack[++top] = item;

}
int Pop(){
    if(top<=0)return -1;
    else return Stack[top--];
}

int applyOp(int a , int b , char ch){
    switch(ch){
        case '+': return b + a;
        case '-': return b - a;
        case '*': return b * a;
        case '/': return b / a;
        case '^': return pow(b,a);
    }
}

int main(){
    int i , j , n , len ,cnt=0,item,x,A,B;
    long long num=0 ,res=0;
    freopen("riyad.txt","r",stdin);
    printf("Please Enter the postfix string separated by space\n");
    string a;
    getline(cin,a);
    len = a.size();
    for(i=0;i<len;i++){
        if(a[i] == ' ');

        else if(a[i] >= '0' && a[i] <= '9'){
            num = 0;
            while(a[i] >= '0' && a[i] <= '9' && i<len){
                x = (int)a[i] - '0';
                num = 10*num + x;
                i++;
            }
            Push(num);
            i--;
        }
        else{

            A = Pop();
            B = Pop();
            if(A==-1 || B==-1){
                printf("Stack Underflow\n");
                res = max(A,B);
                break;
            }
            if(A == 0 && a[i] == '/'){
                 printf("Arithmetic Exception\n");
                 break;
            }

            x = applyOp(A,B,a[i]);
            Push(x);

        }
    }
    if(res == 0)
        res = Pop();
    printf("The result of postfix is %lld\n",res);

    return 0;
}


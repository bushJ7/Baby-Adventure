#include <stdio.h>
int calculate(int a, int b, char op);

int main() {
    int a, b;
    char op;

    printf("Enter expression: ");
    scanf("%d %c %d", &a, &op, &b);
    int result = calculate(a, b, op);
    
    if (op == '+' || op == '-' || op == '*'){
        printf("result = %d\n", result);
    }
return 0;

}
int calculate(int a, int b, char op){
switch(op){
 case '+': return a + b;
 case '-': return a - b;
 case '*': return a * b;

default: 
printf("invalid operator\n");
}
}
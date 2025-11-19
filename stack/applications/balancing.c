// Step 1: Create an empty stack.
// Step 2: Scan expression from left to right.
// Step 3:
// If symbol is opening ((, {, [), push it onto the stack.
// If symbol is closing (), }, ]):
//      If stack is empty → Not balanced.
//      Else pop from stack and check if it matches the opening symbol.
// Step 4: After scan, if stack is empty → Balanced, else → Not balanced.

#include <stdlib.h>
#include <stdio.h>
#define MAX 6

struct stack{
    char stack[MAX];
    int top;
}s;

//push
void push(char item){
    if (s.top==MAX-1){
        printf("Overflow");
    }
    else{
        s.stack[++s.top] = item;

    }
}

//pop
void pop(){
    if (s.top==-1){
        printf("MEPTY");
    }
    else{
        pritnf("rmeoved %d",s.stack[s.top--]);
    }
}

//matching 
int checkPair(char v1, char v2){
    return ((v1=='(' && v2==')')||
            (v1=='{' && v2=='}')||
            (v1=='[' && v2==']') );
}


//balanced
int checkExpr(char expr[], int len){
    for (int i=0; i<len;i++){
        if(expr[i]=='{'||expr[i]=='['||expr[i]=='('){
            push(expr[i]);
        }
        else if(expr[i]=='}'||expr[i]==']'||expr[i]==')'){
            if (s.top==-1)return 0;
            else if(checkPair(s.stack[s.top]==expr[i])){
                pop();
            }
            else{
                return 0;
            }
        }
    }
    return (s.top==-1);
}
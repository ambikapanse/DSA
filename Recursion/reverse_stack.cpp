//https://www.naukri.com/code360/problems/reverse-stack-using-recursion_631875?leftPanelTabValue=SUBMISSION
#include<iostream>
#include<stack>
using namespace std;

void reverseInsert(stack<int>& stack, int x){
    //base case
    if(stack.empty()){
        stack.push(x);
        return;
    }

    //if stack is not empty, empty it and the element, to reverse
    int temp = stack.top();
    stack.pop();
    reverseInsert(stack, x);

    stack.push(temp);
}

void reverseStack(stack<int> &stack) {
    if(!stack.empty()){
        int x = stack.top();
        stack.pop();
        reverseStack(stack);
        reverseInsert(stack,x);
    }
}
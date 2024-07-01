//https://www.naukri.com/code360/problems/sort-a-stack_985275?leftPanelTabValue=SUBMISSION
#include<iostream>
#include<vector>
using namespace std;

void sortedInsert(stack<int> &stack, int x){
	if(stack.empty()||x>=stack.top()){
		stack.push(x);
		return;
	}

	int temp = stack.top();
	stack.pop();
	sortedInsert(stack,x);

	stack.push(temp);

}

void sortStack(stack<int> &stack)
{
        if (!stack.empty()) {
            int x = stack.top();
            stack.pop();
            sortStack(stack);
            sortedInsert(stack, x);
        }
}
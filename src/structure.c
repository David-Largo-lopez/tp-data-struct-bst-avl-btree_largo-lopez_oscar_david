#include "structure.h" 
#include <stdio.h>

int eval_postfix(char *expr) {
    int stack[100]; 
    int top = -1;
    
    int i = 0;
    while (expr[i] != '\0') {
        
        if (expr[i] == ' ') {
            i++;
            continue;
        }

        
        if (expr[i] >= '0' && expr[i] <= '9') {
            int val = 0;
            
            while (expr[i] >= '0' && expr[i] <= '9') {
                val = val * 10 + (expr[i] - '0'); 
                i++;
            }
            stack[++top] = val; 
        } 
       
        else {
            int val2 = stack[top--];
            int val1 = stack[top--];

            switch (expr[i]) {
                case '+': stack[++top] = val1 + val2; break;
                case '-': stack[++top] = val1 - val2; break;
                case '*': stack[++top] = val1 * val2; break;
                case '/': stack[++top] = val1 / val2; break;
            }
            i++;
        }
    }
    return stack[top];
}
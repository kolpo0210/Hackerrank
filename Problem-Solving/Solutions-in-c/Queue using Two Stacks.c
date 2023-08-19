#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct stackNode {
    int data;
    struct stackNode *next;
};

void push(struct stackNode **stack, int data){
    struct stackNode *newNode = malloc(sizeof(struct stackNode));
    newNode->data = data;
    newNode->next = *(stack);
    *(stack) = newNode;
}

int peek(struct stackNode **stack){
    if (*(stack) == NULL){
        return -1;
    }else return (*(stack))->data;
}


int pop(struct stackNode **stack){
    int outputValue=(*(stack))->data;
    *(stack) = (*(stack))->next;
    return outputValue;
}

void transferStacks(struct stackNode **stack1, struct stackNode **stack2){
    int tmpNum;
    while ((*stack1)!=NULL){
        tmpNum = pop(stack1);
        push(stack2,tmpNum);
    }
}

int main() {
    int numLineToRead, comNum, inputNum;
    
    struct stackNode *stackTmp1 = NULL, *stackTmp2 = NULL, *stackTmp3 = NULL, *stackTmp4 = NULL;
    struct stackNode **stack1 = &stackTmp1, **stack2 = &stackTmp2, **stack3 = &stackTmp3, **stack4 = &stackTmp4;
    
    scanf("%d",&numLineToRead);
    for (int k = 0;k<numLineToRead;k++){
        scanf("%d",&comNum);
        if (comNum==1){
            scanf("%d",&inputNum);
            push(stack1, inputNum);
        }else if (comNum == 2){
            push(stack3, 2);
        }else if (comNum == 3){
            push(stack3, 3);
        }else{
            printf("Wrong Input Format.");
        }
    }
    
    transferStacks(stack1,stack2);
    transferStacks(stack3,stack4);

    while((*stack4)!=NULL){
        if (pop(stack4) == 2){
            pop(stack2);
        }else{
            printf("%d\n",peek(stack2));
        }
    }
    return 0;
}

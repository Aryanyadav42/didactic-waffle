#include <stdio.h>
#include <stdlib.h>


struct node{
   int data;
   struct node *next;
}*first=0,*last=0;

int main(){
    struct node *t,*p;
    int i,count=0;

    first = (struct node *)malloc(sizeof(struct node));
    first->data = NULL;
    first->next = NULL;
    last = first;

    do{
        t = (struct node *)malloc(sizeof(struct node));

        if(t==NULL){
            printf("\nHeap is Full");
            break;
        }
        else{
            scanf("%d",&t->data);
            if(first->data==NULL && count==0 && (t->data!=0 || t->data==0))
                first=last=t;
            else{
                t->next = NULL;
                last->next=t;
                last=t;
            }
        }
        count++;
        scanf("%d",&i);
    }while(i);

    p = first;
    int sum_ = 0,max_=first->data;
    count=0;
    while(p!=NULL){
        sum_ = sum_ + p->data;
        count++;
        if (max_ < p->data)
            max_ = p->data;
        printf("\n%d",p->data);
        p = p->next;
    }

    printf("\nSum: %d",sum_);
    printf("\nMax : %d",max_);
    printf("\nCount : %d",count);
}

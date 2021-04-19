#include <stdio.h>
#include <stdlib.h>


struct node{
   int data;
   struct node *next;
}*first=0,*last=0;

void removing_duplicate(){
    struct node *p,*q;
    q = first;
    p = first->next;

    while(p!=NULL){
        if(q->data==p->data){
            q->next = p->next;
            p->next = NULL;
            free(p);
            p = q->next;
        }
        else{
            q = p;
            p = p->next;
        }
    }

}

int main(){
    void removing_duplicate();
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

    removing_duplicate(); // you have to insert duplicate manually


    p = first;
    while(p!=NULL){
        printf("\n%d",p->data);
        p = p->next;
    }
}





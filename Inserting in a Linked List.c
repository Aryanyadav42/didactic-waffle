#include <stdio.h>
#include <stdlib.h>


struct node{
   int data;
   struct node *next;
}*first=0,*last=0;

void Insert(int *data, int *pos){
    struct node *p,*q,*t;
    int i;
    p = first;

    t = (struct node *)malloc(sizeof(struct node));
    if(t==NULL){
        printf("\nHeap is Full");
        // As all the data is stored in heap dynamically
    }
    else{
        t->data = *data;
        if(*pos==0){
            t->next = first;
            first = t;
        }
        else{
            q=NULL;
            for(i=0;i<*pos && p;i++){
                q = p;
                p = p->next;
            }
            if(p){
                t->next = q->next;
                q->next = t;
            }
            else{
                t->next = NULL;
                q->next = t;
                last = t;
            }
        }
    }
}

int main(){
    void Insert();
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

    int data,pos;
    printf("\nEnter the data you want to insert : ");
    scanf("%d",&data);

    printf("\nEnter the position you want to insert the data : ");
    scanf("%d",&pos);

    Insert(&data,&pos);

    p = first;
    while(p!=NULL){
        printf("\n%d",p->data);
        p = p->next;
    }
}


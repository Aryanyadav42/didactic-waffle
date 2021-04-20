#include <stdio.h>
#include <stdlib.h>


struct node{
   int data;
   struct node *next;
}*first=0,*last=0;

void Checking_Loop(){
    struct node *p,*q;
    p=first;
    q=first;

    do{
        p = p->next;
        q = q->next;

        if(q)
            q = q->next;

        else
            q = NULL;

    }while(p&&q && p!=q);

    if(p==q)
        printf("\nLoop is present");

    else
        printf("\nLoop is not present");
}

int main(){
    void Checking_Loop();
    struct node *t,*t1,*t2;
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

    // Creating a Loop
    t1 = first->next;
    t2 = first->next->next->next;
    t2->next = t1;
    // Loop creation done
    // You can remove above three statement to check that the function work or not.

    Checking_Loop();

}



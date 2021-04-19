#include <stdio.h>
#include <stdlib.h>


struct node{
   int data;
   struct node *next;
}*first=0,*last=0;

void Deleting(int *index){
    struct node *p,*q;
    p = first;
    int count=0,i;
    while(p!=NULL){
        count++;
        p = p->next;
    }
    // Count is basically the count of values present in Linked List
    // But we will subtract the value of count by one and thus this count will represent the last index

    count = count-1;
    p = first;

    if(*index==0){ // Deleting from the first position
        first = first->next;
        p->next = NULL;
        free(p);
    }

    else if(*index==count){ // Deleting from the last position
        q=NULL;
        while(p->next!=NULL){
            q = p;
            p = p->next;
        }

        q->next = NULL;
        last = q;
        free(p);
    }

    else if(*index>0 && *index<count){
        q=NULL;
        for(i=0;i<*index;i++){
            q=p;
            p = p->next;
        }
        q->next = p->next;
        p->next = NULL;
        free(p);
    }

}

int main(){
    void Deleting();
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

    int index;
    printf("\nEnter the index you want to delete the data from : ");
    scanf("%d",&index);

    Deleting(&index);

    p = first;
    while(p!=NULL){
        printf("\n%d",p->data);
        p = p->next;
    }
}




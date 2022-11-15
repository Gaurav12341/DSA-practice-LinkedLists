#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node
{
    int data;
    struct Node *next;
}*first;

void create(int a[],int n){           //creating linked list
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=a[0];
    first->next=NULL;
    last=first; //starting time there's no node

    for (i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void Display(struct Node* p){       //Displaying linked list
    int sum=0;  
    while (p!=NULL)
    {
        printf("%d->",p->data);
        sum+=p->data;
        p=p->next;
    }
    
    // printf("\nSum of LL is: %d",sum);
}
int count(struct Node*p){
    int count=0;
    while(p!=NULL){
        count+=1;
        p=p->next;
    }
    return count;
}
void RDisplay(struct Node* p){
    if(p!=NULL){
        printf("%d ",p->data);
        RDisplay(p->next);
    }
}

int max(struct Node*p){        //finding max element in LL
    int max= INT_MIN;
    while(p!=0){
        if (p->data>=max)
            max=p->data;
        p=p->next;
    }
    return max;

}
struct Node* LSearch(struct Node*p,int key){
    while(p!=NULL){
        if (p->data==key)
            return p;
        p=p->next;
    }
    return NULL;

}
void Insert(struct Node*p ,int index,int x){
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    if (index<0 )
        return;
    t->data=x;
    if (index==0){
        t->next=first;
        first=t;
    }   
    else{
        for(int i;i<index-1 && p;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }
    
}
void SortedInsert(struct Node*p,int x){
    struct Node*t,*q=NULL;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if (first==NULL)
        first=t;
    else{
        while (p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if (p==first){
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
        
    }
}

int Delete(struct Node*p,int index){
    struct Node*q=NULL;
    int x=-1,i;
    if(index<1)
        return -1;
    if (index==1){
        q=first;
        x=first->data;
        first=first->next;
        free (q);
        return x;
    }
    else{
        for(i=0;i<index;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free (p);
        
        return x;
    }
}
int isSorted(struct Node*p){
    int x=INT_MIN;
    while(p!=NULL){
        if (p->data<x)
            return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}
void RemoveDuplicate(struct Node*p){
    struct Node* q=p->next;
    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
    
}
void Reverse1(struct Node *p){
    struct Node*q=p;
    int*A;
    A=(int *)malloc(sizeof(int)*count(p));
    int i=0;
    while (q!=NULL) 
    {
        A[i]=q->data;
        q=q->next;
        i++;
    }
    
    q=p;
    i--;
    while (q!=NULL)
    {
        q->data=A[i];
        q=q->next;  
        i--;
    }
    
    
}
void Reverse2(struct Node*p){
    struct Node*q=NULL,*r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;

    }
    first=q;
}


int main(){
    int a[]={3,5,7,10,15};
    create(a,5);
    Display(first);
   // Reverse2(first);
    //printf("\n");
    // Display(first);
   // RemoveDuplicate(first);
   // printf("\n");
   // Display(first);
    
    
    // if (isSorted(first))    
    // {
    //     printf("\nIs sorted\n");
    // }
    // else
    //     printf("\nNot sorted\n");
    


    // printf("\nNumber of nodes is: %d\n",count(first));
    // printf("\nThe maximum element is: %d",max(first));
    // struct Node*temp=LSearch(first,7);
    // if(temp)
    //     printf("\nKey found!!");
    // else
    //     printf("\nKey NOt found");
    // Insert(first,0,20);
    // printf("\n");
    // Display(first);
    // SortedInsert(first,35);
    // printf("\n");
    // Display(first);
    

    return 0;
  
}
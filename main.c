#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head = NULL; 
void create(int item){
    struct node *temp = (struct node*) malloc(sizeof(struct node*));
    if(temp == NULL){
        printf("\nOVERFLOW\n");
    }
    else{
        temp->data = item;
        temp->next = head;
        head = temp;
        printf("\n node is inserted\n");
    }
}
void search(){
    struct node *temp;
    temp = (struct node*) malloc(sizeof(struct node*));
    int values,i=0,flag;
    temp = head;
    if(temp == NULL){
        printf("\n Empty list\n Plz enter values\n");
    }
    else{
        // Applying linear search technique
        printf("Enter the value that to be searched\n");
        scanf("%d",&values);
        while(temp!=NULL){
            if(temp->data == values){
                printf("\n value found at location %d",i+1);
                flag =0;
                break;
            }
            else{
                flag = 1;
            }
            i++;
            temp = temp->next;
        }
        if(flag == 1){
            printf("\n Value not found \n");
        }
    }
}
void sort(){
    struct node *temp;
    struct node *cur;
    int tm;
    temp = (struct node*) malloc( sizeof(struct node*));
    cur = (struct node*) malloc(sizeof(struct node*));
    cur = NULL;
    temp = head;
    if(temp == NULL){
        printf("\n No values to sort\n");
    }
    else{
        // Applying bubble sort for sorting the values
        while(temp!=NULL){
            cur = temp->next;
            while(cur != NULL){
                if(temp->data > cur->data){
                    tm = temp->data;
                    temp->data = cur->data;
                    cur->data = tm;
                }
                cur = cur->next;
            }
            temp = temp->next;
        }
        printf("\n the list is sorted\n");
        printf("\n select choice 2 to check\n");
    }
}
void print(){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node*));
    temp = head;
    if(temp == NULL){
        printf("\n No values in the list \n");
    }
    else{
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}
int main()
{
    int choice,values;
    
    do{
        printf("\n Enter the operation you want to perform \n");
        printf("\n '1' for creating \n '2' for printing the list\n '3' for searching\n '4' for sorting\n '5' for terminating the execution\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("\n enter the item\n");
            scanf("%d",&values);
            create(values);
            break;
            case 2:
            print();
            break;
            case 3:
            search();
            break;
            case 4:
            sort();
            break;
            case 5:
            exit(0);
            default:
            printf("\n Enter a valid choice\n");
        }
    }while(choice !=5);

    return 0;
}


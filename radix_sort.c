#include <stdio.h>
#include <stdlib.h>

// using radix sort linked list version of storing elements -- using bin sort instead of count Sort
 struct node{
    int data;
    struct node *next;
 };

 struct node *createNode(int value){
    struct node* newNode =  (struct node*)malloc(sizeof(struct node));
    newNode-> data =  value;
    newNode->next =  NULL;
    return newNode;
 
 }
 void insertNode( struct node** head, int value){
    struct node* newNode =  createNode(value);
    newNode->next =  *head;
    *head =  newNode;

 }
 struct node* joinTwoLists(struct node*a, struct node* b){
    if(a == NULL) return b;
    struct node* temp = a;
    while(temp-> next != NULL){
        temp=  temp->next;

    }
    temp->next =  b;
     return a;

 }
 void binSort(int arr[], int n, int exp){
    // exp is for digit representation
    int range = 10;
    struct node* bins[range];
    for (int i=0;i<range;i++){
        bins[i] =  NULL;
    }
    //  elements into bins based on digit value 
    for(int i=0;i<n;i++){
        int digit  =  (arr[i]/exp)% range;
        insertNode(&bins[digit],arr[i]);

    }
    //combining bins
    int index = 0;
    for(int i = 0; i< range ;i++){
        //bins[i]=  joinTwoLists(bins[i],NULL);
        struct node* current = bins[i];
        while(current!= NULL){
            arr[index] =  current->data;
            current =  current-> next;
            index++;

        }

    }
    // to free memory
    // for(int i=0;i<range;i++){
    //     struct node* current =  bins[i];
    //     while(current!=NULL){
    //         struct  node* temp =  current;
    //         current =  current->next;
    //         free (temp);
    //     }

    // }
 }

// izzz
void radixSort(int arr[],int n){
    int max =  arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max =  arr[i];
        }
    }
    // implementing binSort 😿😿
    for (int exp = 1;max/exp > 0;exp*=10){
        binSort(arr,n,exp);
    }
}
int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int *arr =  (int *)malloc(n*sizeof(int));
    if (arr == NULL){
        printf("memory fail hogayii");
        return 1;
    }
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("before sorting:");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    radixSort(arr,n);
    printf("\nAfter sorting:");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    //free(arr);
    return 0;


}
 

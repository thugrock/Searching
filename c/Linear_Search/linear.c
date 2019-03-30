#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


int* inputFromUser(int size){
    int *arr,i;
    arr=(int *)malloc(sizeof(int)*size);
    printf("Enter the Array Elements :\n");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    return arr;
}

void linear_Search(int* arr,int size,int element){
    int i,j;
    for(int i=0;i<size;i++){
        if(arr[i]==element){
            printf("YES! The req no. %d is found at position %d",element,i+1);
            return;
        }
    }
    printf("NO! The req no. %d is not found",element);
    return;
}

int main(){
    int size,element;
    int *arr;

    printf("Enter the Size of Array\n");
    scanf("%d",&size);
    arr=inputFromUser(size);

    printf("Enter the Element to be Searched in Array\n");
    scanf("%d",&element);

    linear_Search(arr,size,element);

    return 0;
}

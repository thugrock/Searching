#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


int* inputFromUser(int size){
    int *arr,i;
    arr=(int *)malloc(sizeof(int)*size);
    printf("Enter the Array Elements  in Sorted Form:\n");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    return arr;
}

void binary_Search_recursive(int* arr,int low,int high,int element){
    if(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==element){
            printf("Yes! Req Element %d is found at position %d\n",element,mid+1);
            return;
        }else if(arr[mid]<element){
            return binary_Search_recursive(arr,mid+1,high,element);
        }else{
            return binary_Search_recursive(arr,low,mid-1,element);
        }
    }
    printf("NO! Req Element %d is not found\n",element);
    return;
}

void binary_Search_iterative(int* arr,int size,int element){
    int low=0;
    int high=size-1;
    int mid;
    while(low<=high){
        mid=low+(high-low)/2;
        if(arr[mid]==element){
            printf("Yes! Req Element %d is found at position %d\n",element,mid+1);
            return;
        }else if(arr[mid]<element){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    printf("NO! Req Element %d is not found\n",element);
    return;
}
int main(){
    int size,element,choice;
    int *arr;

    printf("Enter the Size of Array\n");
    scanf("%d",&size);
    arr=inputFromUser(size);

    printf("Enter the Element to be Searched in Array\n");
    scanf("%d",&element);
    while(1){
    printf("Enter the Choice of implementation\n");
    printf("Enter 1 for recursive approach:\nEnter 2 for Iterative approach\n");
    scanf("%d",&choice);
    if(choice==1){
        binary_Search_recursive(arr,0,size-1,element);
        break;
    }
    else if(choice==2){
        binary_Search_iterative(arr,size,element);
        break;
    }
    else{
        printf("Wrong Input\nRead Instructions below\n:");
    }
    }
    return 0;
}

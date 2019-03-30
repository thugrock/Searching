#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>


int* inputFromUser(int size){
    int *arr,i;
    arr=(int *)malloc(sizeof(int)*size);
    printf("Enter the Array Elements :\n");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    return arr;
}

void linear_Search(int* arr,int low,int high,int element){
    int i,j;
    for(int i=low;i<=high;i++){
        if(arr[i]==element){
            printf("YES! The req no. %d is found at position %d\n",element,i+1);
            return;
        }
    }
    printf("NO! The req no. %d is not found\n",element);
    return;
}

void jump_Search(int* arr,int size,int element){
    int gap=sqrt(size);
    int curr_index=0,next_index=gap;
    for(curr_index=0;curr_index+gap<size;curr_index+=gap){
        next_index=curr_index+gap;
        if(arr[next_index]>element){
            linear_Search(arr,curr_index,next_index,element);
            return;
        }
    }
    linear_Search(arr,curr_index,size-1,element);
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

    jump_Search(arr,size,element);

    return 0;
}

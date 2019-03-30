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
int min(int arg1,int arg2){
    if(arg1<=arg2)
        return arg1;
    else if(arg2>arg1)
    {
        return arg2;
    }
}

void binary_Search_iterative(int* arr,int low,int high,int element){
    
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
void exponential_Search(int* arr,int size,int element){
    int gap=1;
    if(arr[0]==element){
        printf("Yes! Req Element %d is found at position 0\n",element); 
        return;  
    }
    while(gap<size && arr[gap]<=element)
        gap*=2;
    return binary_Search_iterative(arr,gap/2,min(gap,size),element);
}
int main(){
    int size,element,choice;
    int *arr;

    printf("Enter the Size of Array\n");
    scanf("%d",&size);
    arr=inputFromUser(size);

    printf("Enter the Element to be Searched in Array\n");
    scanf("%d",&element);
    
    exponential_Search(arr,size,element);

    return 0;
}

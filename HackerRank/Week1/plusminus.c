//plus Minus problem
//Code wriiten in C language
//Given an array of integers, print the ratios of positive, negative, and zero values in the array, each on a new line with 6 decimal places.

#include<stdio.h>
void plusMinus(int arr[],int n){
        int pos=0,neg=0,zero=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            pos++;
            else if(arr[i]<0)
            neg++;
            else
            zero++;
        }
        printf("%.6f\n",(float)pos/n);
        printf("%.6f\n",(float)neg/n);
        printf("%.6f\n",(float)zero/n);
    }
    int main(){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
        
        plusMinus(arr,n);
        return 0;
    }


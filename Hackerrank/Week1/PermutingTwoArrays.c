//Permuting Two Arrays 
//solved in c

#include <stdio.h>


void sortAscending(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {          
        for (int j = i + 1; j < n; j++) {       
            if (arr[i] > arr[j]) {              
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void sortDescending(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {           
        for (int j = i + 1; j < n; j++) {       
            if (arr[i] < arr[j]) {              
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int q;  
    scanf("%d", &q); 

    while (q--) {
        int n, k;
        scanf("%d %d", &n, &k); 

        int A[n], B[n];
        
        
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);

    
        for (int i = 0; i < n; i++)
            scanf("%d", &B[i]);

        
        sortAscending(A, n);
        sortDescending(B, n);

        int possible = 1; 

        
        for (int i = 0; i < n; i++) {
            if (A[i] + B[i] < k) {
                possible = 0; 
                break;        
            }
        }

        
        if (possible)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

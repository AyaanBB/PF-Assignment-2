#include <stdio.h>

int main() {

    int i,n,j;
    
    printf("Enter the size");
    scanf("%d",&n);
    
    int arr[n];
    
    for(i=0;i<n;i++)
    {
        printf("Enter element ");
        scanf("%d",&arr[i]);
    }
    
    int max = 5;
    for(i=0;i<5;i++){
    
 
        for(j=0;j<n;j++)
        {
        if(arr[j] >= max)
        {
            printf("*");
        }
        else
        {
        printf(" ");
        }
     }
        max--;
        printf("\n");
    }
    return 0;
}
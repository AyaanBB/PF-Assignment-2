#include <stdio.h>

int main() {
    // Write C code here
    int i,j,n,temp;
    
    printf("Enter size of array ");
    scanf("%d",&n);
    
    int a[n];
    
    for(i=0;i<n;i++)
    {
        printf("Enter the element ");
        scanf("%d",&a[i]);
    }
    
    for(i=0;i<n;i++)
    {
        j = i+1;
        if(a[i] > a[j]){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        printf("%d\n", a[i]);
    }
    
    printf("The second smallest value is %d", a[1]);

    return 0;
}
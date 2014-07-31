#include<stdio.h>
#include<stdlib.h>
int main() {
    int t,n,*arr1,*arr2,i;
    scanf("%d",&t);
    while(t) {
        scanf("%d",&n);
        arr1 = (int *)malloc(sizeof(int)*n);
        arr2 = (int *)malloc(sizeof(int)*n);
        for(i = 0; i < n; i++) {
            scanf("%d",arr1[i]);
        }
        for(i = 0; i < n; i++) {
            scanf("%d",arr2[i]);
        }
        for(i = 0; i < n; i++) {
            printf("%d ",arr1[i]*arr[i]);
        }
    }
    return 0;
}

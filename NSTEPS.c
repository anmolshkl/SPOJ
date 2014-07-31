#include<stdio.h>
int main() {
    int n,x,y;
    scanf("%d",&n);
    while(n) {
        scanf("%d",&x);
        scanf("%d",&y);
        if((x%2 == 0) && (y%2 == 0)) {
            printf("%d\n",(x+y));
        }
        else if(x % 2 != 0 && y%2 != 0) {
            printf("%d\n",(x+y-1));
        }
        else {
            printf("No Number\n");
        }
        n--;
    }
    return 0;
}

/*Corner Cases:
   (1)9,99,999 such cases will be dealt by increasing the array length by 1,making the last and first digits 1 and rest all 0s.
   (2)if i<j and if num[i] < num[j]
      then instead of increasing num[i] to num[j],make num[j] = num[i] and increment all the digit between i & j
      This will give us the next largest Number.However if there's nothing between i & j(i=j-1),then make num[i]=num[j]
      Since this number is already larger than original num,we dont increment digits btw i & j if case 2 arises again.
    (3) If i<j & if num[i] > num[j] simply make num[j] = num[i]
*/
#include<stdio.h>
#include<stdlib.h>

void print(int *arr) {
    int i=0;
    int num=0;
    while(arr[i] != -1) {
        num = num*10 + arr[i];
        printf("%d", num);
        //printf("%d",arr[i]);
        i++;
    }
    printf("\n");
}

int arrayToInt(int arr[], int n) {
    int num=0;
    int i=0;
    while(arr[i] != -1) {
        num = num*10 + arr[i++];
    }
    return num;
}

int readNum(int *num) {
    char c;
    int i=0;
    while(c < 33) {
        c=getchar();
    }
    while(c > 33) {
        num[i++]=c-'0';
        c=getchar();
    }
    num[i]=-1;
    return i;
}

int isPalindrome(int *num,int len) {
    int mid=len/2;
    int i=0,isPalin=1;
    while(i <= mid && isPalin) {
        if(num[i] != num[len-i-1]) {
            isPalin=0;
        }
        i++;
    }
    return isPalin;
}

void copyToRight(int *num,int len) {
    int i,j;
    if(len%2 == 0) {
        i = len/2;
        j = i+1;
    }
    else {
        i = len/2 - 1;
        j = len/2 + 1;
    }
    while(j < len) {
            num[j++] = num[i--];
        }
}

int isDivisibleBy9(int *num,int len) {
    int isDiv=1;
    int i=0;
    while(i < len && isDiv) {
        if(num[i]%9 != 0) {
            isDiv = 0;
        }
        i++;
    }
    return isDiv;
}

void increment(int *num,int len) {
    int carry = 0;
    int i = (len-1)/2; //basically the middle element
    do {
        carry = (num[i]+1)/10;
        num[i] = (num[i] + 1)%10;
        i--;
    }while(carry != 0 && i>=0);

}

void nextPalindrome(int *num,int *len) {
    int check,i,j;
    check = isPalindrome(num, *len);
    if(check) {
        if(isDivisibleBy9(num,*len)) {
            *len=*len + 1;
            num[0]=1;
            num[*len-1]=1;
            num[*len]=-1;
            for(i=1; i < *len-1; i++) {
                num[i] = 0;
            }
        }
        else { //If not a number like 9 or 99 or 999....eg 15251 or 152251
            int mid=(*len-1)/2.0;
            increment(num,*len);
            copyToRight(num,*len);
        }
    }
    else { //Not a Palindrome
        int increased=0;
        i = (*len-1)/2;
        j = *len%2==0 ? i+1 : i;
        while(num[i] == num[j]) {
            i--;
            j++;
        }
        while(i >= 0 && j < *len) {
            if(num[i] > num[j]) { // eg. 1 4 3 2 4 1
                    num[j] = num[i];
            }
            else if(num[i] < num[j]) {
                if(i+1 == j) { //There's nothing between 2 & 3 to increment eg. 1 4 2 3 4 1
                    //So change 2->3
                    num[i] = num[i]+1;
                    num[j] = num[i];
                    increased=1;
                }
                else {
                    int m;
                    num[j] = num[i];
                    m=i + 1;
                    if(!increased) {
                        while(m < j) {
                            num[m] = num[m] + 1;
                            m++;
                        }
                    increased=1;
                    }
                }
            }
            i--;
            j++;
        }
    }
}


int main() {
    int *num=(int *)malloc(sizeof(int)*1000000);
    int len,k;
    scanf("%d",&k);
    while(k) {
        len=readNum(num);
        nextPalindrome(num,&len);
        print(num);
        k--;
    }
    return 0;
}

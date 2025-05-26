#include <stdio.h>
int reverse_digits(int n) 
{
    int r;
    while (n > 0) {
        r = n%10;
        printf("%d",r);
        n = n/10;
    }
    return r;
}
int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    reverse_digits(num);
    return 0;
}
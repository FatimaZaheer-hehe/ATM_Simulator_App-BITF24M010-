#include <stdio.h>

int sum_of_digits(int n) {
    int sum = 0,r;
    while (n > 0) {
        r=n%10;
        sum=sum+r;
        n = n/10;
    }
    return sum;
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("Sum of digits: %d\n", sum_of_digits(num));
    return 0;
}

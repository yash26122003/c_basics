#include <stdio.h>

void toh(int n, char s, char d, char a) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", s, d);
        return;
    }
    toh(n-1, s, a, d);
    printf("Move disk %d from %c to %c\n", n, s, d);
    toh(n-1, a, d, s);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    toh(n, 'S', 'A', 'D');
    return 0;
}


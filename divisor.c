#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int* divisors;
    int least, greatest;
    
    scanf("%d", &n);
    divisors = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &divisors[i]);
    }
    least = 1000000; greatest = 2;
    for(int i = 0; i < n; i++) {
        if(divisors[i] < least) {
            least = divisors[i];
        }if(divisors[i] > greatest) {
            greatest = divisors[i];
        }
    }
    printf("%d\n", least * greatest);
    free(divisors);
    
    return 0;
}
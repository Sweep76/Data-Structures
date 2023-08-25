#include <stdio.h>

int main(){

    int sum;

    for(int number = 1;number <= 1000; number++){
        sum = 0;

        for (int i = 1; i <= number/2; i++){
            if (number % i == 0){
                sum += i;
            }
        }

        if (sum == number){
            printf("%d is perfect\n", number);
        }
    }

    return 0;
}
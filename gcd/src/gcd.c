#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Συνάρτηση για τον υπολογισμό του gcd
long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

//Έλεγχος εγκυρότητας των τιμών εισόδου
int valid_number(const char *str, long long *num) {
    char *endptr;
    *num = strtoll(str, &endptr, 10);

    //Έλεγχος για μη έγκυρες τιμές και αριθμούς εκτός ορίων
    if (*endptr != '\0' || *num == 0 || *num < -1000000000000000000LL || *num > 1000000000000000000LL) {
        return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    //Έλεγχος αριθμού ορισμάτων
    if (argc != 3) {
        fprintf(stderr, "Not right arguments\n");
        return 1;
    }

    long long num1, num2;

    //Έλεγχος εγκυρότητας για κάθε όρισμα
    if (!valid_number(argv[1], &num1) || !valid_number(argv[2], &num2)) {
        fprintf(stderr, "Invalid input. Numbers must be non-zero integers in the range [-10^18, 10^18].\n");
        return 1;
    }

    //Υπολογισμός του gcd και εκτύπωση του αποτελέσματος
    long long result = gcd(llabs(num1), llabs(num2));
    printf("gcd(%lld, %lld) = %lld\n", num1, num2, result);

    return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, ".UTF8");
    task1_1();
    task1_2();
    task1_3();
    task2();
    task3();
}
int task1_1 () {
    for (int row = 1; row <= 9; row++) {

        for (int col = 1; col <= 9; col++) {
            printf("%4d", row * col);
        }

        printf("\n\n");
    }
    return 0;
}
int task1_2() {
    for (int row = 1; row <= 9; row++) {

        for (int col = 1; col <= row; col++) {
            printf("%4d", row * col);
        }

        printf("\n\n");
    }
    return 0;
}
int task1_3() {
    for (int i = 0; i < 5; i++) {

        int start_number = 20 - i;

        for (int j = 0; j < 5 - i; j++) {

            printf("%4d", start_number + j);
        }

        printf("\n");
    }
    return 0;
}
int task2() {
    long long num;
    char ans;

    do {
        printf("\nВведите число: ");
        scanf("%lld", &num);
        if (num < 0) num = -num;

        int d[20], n = 0; 
        long long temp = num;

        int c3 = 0, cLast = 0, c = 0, cg = 0, sO = 0, sG7 = 0, cN = 0, prev = -1;
        long long prod = 1;

        if (temp == 0) { d[0] = 0; n = 1; }
        else {
            while (temp > 0) {
                d[n] = temp % 10;
                temp /= 10;
                n++;
            }
        }

        int last = d[0];

        for (int i = 0; i < n; i++) {
            int cur = d[i];
            if (cur == 3) c3++;
            if (cur == last) cLast++;
            if (cur % 2 == 0) c++;
            if (cur > 5) cg++;
            if (cur % 2 != 0) sO += cur;
            if (cur >= 7) sG7 += cur;
            if (cur != 0) prod *= cur;
            if (cur == prev) cN++;
            prev = cur;
        }

        int s9 = 0, s11a = 0, s11b = 0, s12e = 0, s12o = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && d[i] % 2 == 0) s9 += d[i];
            if (i < n / 2) s11a += d[i]; else s11b += d[i];
            if ((i + 1) % 2 != 0) s12o += d[i]; else s12e += d[i];
        }

        printf("1) Количество троек: %d\n", c3);
        printf("2) Повторений последней: %d\n", cLast);
        printf("3) Четных цифр: %d\n", c);
        printf("4) Цифр больше 5: %d\n", cg);
        printf("5) Сумма нечетных: %d\n", sO);
        printf("6) Сумма >= 7: %d\n", sG7);
        printf("7) Произведение (кроме 0): %lld\n", prod);

        if (n >= 2) printf("8) Произв. предпосл. и 2-й: %d\n", d[1] * d[n - 2]);

        printf("9) Сумма четных (без посл.): %d\n", s9);
        printf("10) Одинаковых рядом: %d\n", cN);

        if (n % 2 == 0 && s11a == s11b) printf("11) Суммы половин равны\n");
        else if (n % 2 != 0) printf("11) Нечетная длина\n");
        else printf("11) Суммы половин НЕ равны\n");

        printf("12) Произв. сумм разрядов: %d\n", s12e * s12o);

        printf("\nПродолжить? (Да - y, Нет - n): ");
        scanf(" %c", &ans);
    } while (ans == 'y' || ans == 'Y');

    return 0;
}
int task3() {
    char s;
    int h, b, repeat = 1;

    while (repeat != 0) {
        printf("\nСимвол: "); scanf(" %c", &s);
        printf("Высота: "); scanf("%d", &h);
        printf("Ширина нижнего основания: "); scanf("%d", &b);

        printf("\nФигура:\n");

        for (int i = 0; i < h; i++) {

            printf("%c", s);

            if (i == 0) {

                for (int j = 0; j < b - h; j++) printf("%c", s);
            }
            else if (i == h - 1) {
                for (int j = 0; j < b - 1; j++) printf("%c", s);
            }
            else {
                for (int j = 0; j < b - h + i - 1; j++) printf(" ");
                printf("%c", s);
            }
            printf("\n");
        }

        printf("\nПродолжить? (0 - выход): ");
        scanf("%d", &repeat);
    }
    return 0;
}
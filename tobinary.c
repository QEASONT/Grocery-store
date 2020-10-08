//A small program that turns decimal to binary
//supporting the number of points of the fewte points
//and the number of binary outputs is accurate to 8 bits after the number of points
//Programer： QT
//Time： 2020.10.8
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long long int todem(long long int n)
{
    if (n < 2)
    {
        return n;
    }
    else
    {
        return todem(n / 2) * 10 + n % 2;
    }
}
char *ftodem(long long int n, int count2, char *q)
{
    int s = 0;

    while (s < 8)
    {
        if ((2 * n) / pow(10, count2) == 1)
        {
            q[s] = (2 * n) / pow(10, count2);
            n = 0;
        }
        else
        {
            q[s] = (2 * n) / (pow(10, count2));
            if (2 * n < pow(10, count2))
            {
                n = 2 * n;
            }
            else
            {
                n = 2 * n - pow(10, count2);
            }
        }
        s++;
    }

    return q;
}

int main(void)
{
    char i[64], p[64];
    char q[10];

    int count = 0, count2 = 0;
    int ii = 0, jj = 0;
    int remain;
    long long int digit, digit2;
    long long int m, n, index;

    printf("%80s", "This is a useful tool, type in break to stop\n");
    while (1)
    {

        printf("enter a demical base num:  ");
        scanf("%s", i);
        if (strcmp(i, "break") == 0)
        {
            break;
        }

        m = (int)atof(i);
        if (m != atof(i))
        {
            for (ii = 0; ii < strlen(i); ii++)
            {
                p[ii] = i[strlen(i) - 1 - ii];
            }

            n = 0;

            for (index = (int)atof(p); index > 0; index /= 10)
            {
                n = 10 * n + index % 10;
            }

            for (digit = todem(m); digit > 0; digit /= 10)
            {
                count++;
            }

            for (digit2 = n; digit2 > 0; digit2 /= 10)
            {
                count2++;
            }

            printf("demical base num %s in binary is ", i);

            if ((count % 4) != 0)
            {
                for (remain = 4 - count % 4; remain > 0; remain--)
                {
                    printf("0");
                }
            }
            printf("%lld", todem(m));
            printf(".");
            ftodem(n, count2, q);

            for (jj = 0; jj < 8; jj++)
            {
                printf("%d", q[jj]);
            }
            printf("\n\n\n");
        }
        else
        {
            for (digit = todem(m); digit > 0; digit /= 10)
            {
                count++;
            }
            printf("demical base num %s in binary is ", i);

            if ((count % 4) != 0)
            {
                for (remain = 4 - count % 4; remain > 0; remain--)
                {
                    printf("0");
                }
            }
            printf("%lld\n\n\n", todem(m));
        }
    }

    return 0;
}
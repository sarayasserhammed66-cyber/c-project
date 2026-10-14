#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
    float productPrice, paidAmount;
    int changeKurus;
    int totalPieces = 0;

    int denominations[] = {
        20000, 10000, 5000, 2000,
        1000, 500, 100, 50, 25, 10, 5, 1
    };

    int count = sizeof(denominations) / sizeof(denominations[0]);

    printf("Urun tutarini giriniz (TL): ");
    scanf("%f", &productPrice);

    printf("Odenen miktari giriniz (TL): ");
    scanf("%f", &paidAmount);

    if (productPrice < 0 || paidAmount < productPrice)
    {
        printf("Gecersiz tutar!\n");
        return 1;
    }

    changeKurus = (int)roundf((paidAmount - productPrice) * 100.0f);

    printf("\nPara ustu: %d kurus\n", changeKurus);
    printf("Para ustu dagilimi:\n");

    for (int i = 0; i < count; i++)
    {
        int number = changeKurus / denominations[i];

        if (number > 0)
        {
            if (denominations[i] >= 100)
            {
                printf("%d TL: %d adet\n",
                    denominations[i] / 100, number);
            }
            else
            {
                printf("%d kurus: %d adet\n",
                    denominations[i], number);
            }

            changeKurus %= denominations[i];
            totalPieces += number;
        }
    }

    printf("Toplam kupur sayisi: %d\n", totalPieces);

    return 0;
}
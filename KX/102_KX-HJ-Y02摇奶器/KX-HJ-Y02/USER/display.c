
#include "display.h"

Byte displayData[NUM_OF_COM];
/*
        __a_
       f|   |b
        | g |
        -----
       e|   |c
        |   |
        -----
           d
*/

code uchar DIGITS[] = {
    Bin(00111111), // 0
    Bin(00000110), // 1
    Bin(01011011), // 2
    Bin(01001111), // 3
    Bin(01100110), // 4
    Bin(01101101), // 5
    Bin(01111101), // 6
    Bin(00000111), // 7
    Bin(01111111), // 8
    Bin(01101111), // 9
    Bin(00000000), // NONE 10
    Bin(01110110), // H  11
    Bin(01111001), // E 12
    Bin(00111001), // C 13
    Bin(00000001), // ä¸1¤7 14
    Bin(00000010), // ĺä¸  15
    Bin(00000100), // ĺłä¸  16
    Bin(00001000), // ä¸1¤7  17
    Bin(01000000), // ä¸1¤7  18
    Bin(01010000), // r 19
    Bin(00111110), // U 20
    Bin(01110001), // F 21
    Bin(01011110), // d 22
    Bin(01101101), // S 23
    Bin(01100011), // ä¸ĺŁ 24
    Bin(01011100), // ä¸ĺŁ 25
    Bin(01110011), // P 26
    Bin(00111000), // L 27
    Bin(01010100), // n 28
    Bin(00001111), //  ] 29
    Bin(00100000), // 30 L_U_BAR
    Bin(00010000), // 31 L_B_BAR
    Bin(11111100), // 32 b
    Bin(00110111), // big n
    Bin(00001001), // 34
    Bin(00001110), // 35
    Bin(00001101), // 36
    Bin(00001011), // 37
    Bin(00000111), // 38
    Bin(00110001), // 39
    Bin(00101001), // 49
    Bin(00011001), // 50
};

void display()
{

    static unsigned char i, j, k;

    SET_S1_OUTPUT;
    SET_S2_OUTPUT;
    SET_S3_OUTPUT;
    SET_S4_OUTPUT;
    SET_S5_OUTPUT;

    switch (i)
    {
    case 0:
        if (k == 0)
        {
            S_1 = 0;
            S_2 = displayData[j].bits.b0;

            SET_S3_INPUT;
            SET_S4_INPUT;
            SET_S5_INPUT;

            k++;
        }
        else if (k == 1)
        {
            S_1 = 0;
            SET_S2_INPUT;
            S_3 = displayData[j].bits.b1;
            SET_S4_INPUT;
            SET_S5_INPUT;
            k++;
        }
        else if (k == 2)
        {
            S_1 = 0;
            SET_S2_INPUT;
            SET_S3_INPUT;
            S_4 = displayData[j].bits.b2;
            SET_S5_INPUT;
            k++;
        }
        else if (k == 3)
        {
            S_1 = 0;
            SET_S2_INPUT;
            SET_S3_INPUT;
            SET_S4_INPUT;
            S_5 = displayData[j].bits.b3;
            k = 0;
            i++;
        }

        break;

    case 1:
        if (k == 0)
        {
            S_2 = 0;
            S_1 = displayData[j].bits.b4;
            SET_S3_INPUT;
            SET_S4_INPUT;
            SET_S5_INPUT;
            k++;
        }
        else if (k == 1)
        {
            S_2 = 0;
            SET_S1_INPUT;
            S_3 = displayData[j].bits.b5;
            SET_S4_INPUT;
            SET_S5_INPUT;
            k++;
        }
        else if (k == 2)
        {
            S_2 = 0;
            SET_S1_INPUT;
            SET_S3_INPUT;
            S_4 = displayData[j].bits.b6;
            SET_S5_INPUT;
            k++;
        }
        else if (k == 3)
        {
            S_2 = 0;
            SET_S1_INPUT;
            SET_S3_INPUT;
            SET_S4_INPUT;
            S_5 = displayData[j].bits.b7;
            k = 0;
            i++;
            j++;
        }

        break;

    case 2:
        if (k == 0)
        {
            S_3 = 0;
            S_2 = displayData[j].bits.b0;
            SET_S1_INPUT;
            SET_S4_INPUT;
            SET_S5_INPUT;
            k++;
        }
        else if (k == 1)
        {
            S_3 = 0;
            SET_S2_INPUT;
            S_1 = displayData[j].bits.b1;
            SET_S4_INPUT;
            SET_S5_INPUT;
            k++;
        }
        else if (k == 2)
        {
            S_3 = 0;
            SET_S2_INPUT;
            SET_S1_INPUT;
            S_4 = displayData[j].bits.b2;
            SET_S5_INPUT;
            k++;
        }
        else if (k == 3)
        {
            S_3 = 0;
            SET_S2_INPUT;
            SET_S1_INPUT;
            SET_S4_INPUT;
            S_5 = displayData[j].bits.b3;
            k = 0;
            i++;
        }

        break;
    case 3:
        if (k == 0)
        {
            S_4 = 0;
            S_2 = displayData[j].bits.b4;
            SET_S3_INPUT;
            SET_S1_INPUT;
            SET_S5_INPUT;
            k++;
        }
        else if (k == 1)
        {
            S_4 = 0;
            SET_S2_INPUT;
            S_3 = displayData[j].bits.b5;
            SET_S1_INPUT;
            SET_S5_INPUT;
            k++;
        }
        else if (k == 2)
        {
            S_4 = 0;
            SET_S2_INPUT;
            SET_S3_INPUT;
            S_1 = displayData[j].bits.b6;
            SET_S5_INPUT;
            k++;
        }
        else if (k == 3)
        {
            S_4 = 0;
            SET_S2_INPUT;
            SET_S3_INPUT;
            SET_S1_INPUT;
            S_5 = displayData[j].bits.b7;
            k = 0;
            j = 0;
            i = 0;
        }

        break;
    }
}

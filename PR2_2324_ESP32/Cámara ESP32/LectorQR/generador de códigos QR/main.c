/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "qrcode.h"

int main()
{
    // The structure to manage the QR code
    QRCode qrcode;
    
    uint8_t version = 15;
    // Allocate a chunk of memory to store the QR code
    uint8_t qrcodeBytes[qrcode_getBufferSize(version)];

    qrcode_initText(&qrcode, qrcodeBytes, 15, ECC_LOW, "01:p[0.4,0.4,0.0,0.0,3.14159,0.0]\n02:p[0.4,0.4,0.0,0.0,3.14159,0.0]\n03:p[0.4,0.4,0.0,0.0,3.14159,0.0]\n04:p[0.4,0.4,0.0,0.0,3.14159,0.0]\n05:p[0.4,0.4,0.0,0.0,3.14159,0.0]\n06:p[0.4,0.4,0.0,0.0,3.14159,0.0]\n07:p[0.4,0.4,0.0,0.0,3.14159,0.0]\n08:p[0.4,0.4,0.0,0.0,3.14159,0.0]\n09:p[0.4,0.4,0.0,0.0,3.14159,0.0]\n10:p[0.4,0.4,0.0,0.0,3.14159,0.0]\n11:p[0.4,0.4,0.0,0.0,3.14159,0.0]\n12:p[0.4,0.4,0.0,0.0,3.14159,0.0]\n13:p[0.4,0.4,0.0,0.0,3.14159,0.0]\n14:p[0.4,0.4,0.0,0.0,3.14159,0.0]\n15:p[0.4,0.4,0.0,0.0,3.14159,0.0]\n");

    for (uint8_t y = 0; y < qrcode.size; y++)
    {
        for (uint8_t x = 0; x < qrcode.size; x++)
        {
            if (qrcode_getModule(&qrcode, x, y))
            {
                printf("██");
            }
            else
            {
                printf("  ");
            }
        }
        
    printf("\n");
    }

    return 0;
}

// tipo1: p[0 .4,0.4,0.0 ,0.0,3.141 59,0.0]123 4567891234 567   //53 caracteres

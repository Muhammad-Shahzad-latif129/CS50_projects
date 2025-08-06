#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./recover FILE.\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 2;
    }

    BYTE buffer[BLOCK_SIZE];

    char filename[8];
    int n = 0;
    FILE *img = NULL;
    while (fread(buffer, 1, BLOCK_SIZE, card) == BLOCK_SIZE)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(img == NULL)
            {
                sprintf(filename, "%03i.jpg", n);
                img = fopen(filename, "wb");
                fwrite(buffer, 1, BLOCK_SIZE, img);
                n++;
            }
            else
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", n);
                img = fopen(filename, "wb");
                fwrite(buffer, 1, BLOCK_SIZE, img);
                n++;
            }
            
        }
        else if (img != NULL)
        {
            
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }
    }
    if (img != NULL)
    {
        fclose(img);
    }
       
    fclose(card);
}


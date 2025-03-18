#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int DATA_SIZE = 512;

int main(int argc, char *argv[])
{
    // Check CLA
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Error: File could not be opened.\n");
        return 1;
    }

    // Initialise pointer
    FILE *img = NULL;
    char *filename = malloc(8);

    uint8_t buffer[DATA_SIZE];

    int count = 0;

    // Read in blocks of 512 B
    while (fread(buffer, 1, DATA_SIZE, card) == DATA_SIZE)
    {
        // Starts new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If something's open, close it
            if (img != NULL)
            {
                fclose(img);
            }

            // New JPEG
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");

            if (img == NULL)
            {
                printf("Error: Could not create file %s\n", filename);
                fclose(img);
                return 1;
            }

            count++;
        }

        // If new JPEG, recover
        if (img != NULL)
        {
            fwrite(buffer, 1, DATA_SIZE, img);
        }
    }

    if (img != NULL)
    {
        fclose(img);
    }

    free(filename);
    fclose(card);

    return 0;
}

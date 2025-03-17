#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Read scaling factor (negative values invert audio phase)
    float factor = atof(argv[3]);

    // Copy header from input file to output file
    uint8_t buff_h[HEADER_SIZE];

    fread(buff_h, HEADER_SIZE, 1, input);

    // Check if the file is a RIFF file
    uint8_t signature[] = {0x52, 0x49, 0x46, 0x46}; // RIFF

    for (int i = 0; i < 4; i++)
    {
        if (signature[i] != buff_h[i])
        {
            printf("Not a WAVE file.\n");

            fclose(input);
            fclose(output);
            remove(argv[2]);

            return 1;
        }
    }

    fwrite(buff_h, HEADER_SIZE, 1, output);

    // Read samples from input file and write updated data to output file
    int16_t buff_s;

    while (fread(&buff_s, sizeof(int16_t), 1, input) != 0)
    {
        buff_s *= factor;
        fwrite(&buff_s, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);

    return 0;
}

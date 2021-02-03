#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //unsigned 8-bit integer type to store byte data
    typedef uint8_t BYTE;
    // Check for invalid usage
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }

    // fopen reads file of name arg 1
    // arg 2 - "r" means to read the file
    FILE *file = fopen(argv[1], "r");
    //test if file exsists
    if(file == NULL)
    {
        printf("Could not open %s.\n", file);
        return 1;
    }
    // create an array of type BYTE to store current chunk of data
    BYTE buffer[512];

    //READ FILE
    //4arg
    //arg1 - data - pointer to where to store data you're reading (buffer array)
    //arg2 - size - 1 byte
    //arg3 - number - 512 elements
    //arg4 - inptr - inpointer - file * to read from (memory card file)
    //fread(data, size, number, inptr);

    //CHECK IF JPEG
    buffer[0] == 0xff
    buffer[1] == 0xd8
    buffer[2] == 0xff
    //bitwise arithmetic & will return 1 if both bits are 1, return 0 if either is 0
    //will check if byte has 0xe then any other vaue
    (buffer[3] & 0xe0) == 0xe0

    //MAKE A NEW JPEG
    //naming a jpeg
    // springf - prints to a string not the terminal
    //3 arguemnts:
    //1 - name of string you want to write to
    //2 - format string - % (how many digits) type
    //3 - number you want to subsitute (can be a counter)
    // example: sprintf(filename, %03i, 2);

    //filename needs to have enough memory/characters to fully rep the filename

    //WRITE FILE
    //arg1 - name of the file
    //arg2 - "w" to write to a file

    //FILE *img = fopen(filename, "w");

    //fwrite(data, size, number, outptr);
    //4arg
    //1 pointer to bytes that will be written to file
    //2 size of each element (1)
    //3 number of ele (512)
    //4 FILE * to write to (jpeg just made)

    //END OF FILE

    //fread returns the number of items of size 1 byte which were read
    //should return 512 elements if read all
    //at end of file will be fewer than 512 - so stop reading for that jpeg
}

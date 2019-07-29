/**
 * Exercise from The C Programming, 2nd edition
 * 1-8. Write a program to count blanks, tabs, and newlines.
 * 1-9. Write a program to copy its input to its output,
 *      replacing each string of one or more blanks by a
 *      single blank
 * 1-10. Write a program to copy its input to its output,
 *      replacing each tab by \t, each backspace by \b, and
 *      each backslash by \\.
 *
 * Press Ctrl + D for EOF character
 *
 * Author: Neonblueflame
 * Date: 20190729
 *
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Current charater from the stream
char c;

int buffer_size = 50;
char* buffer;

// Allocate n space to string buffer, depending on increase's
// value, and returns the new buffer address
char* increase_buffer(int cur_size, int increase);

// Accepts a char as parameter so that the succeeding chars
// that is equal to it will be skipped
void skip_char(char sc);

int main()
{
    int blanks_count = 0;
    int tabs_count = 0;
    int lines_count = 0;
    int char_count = 0;

    buffer = malloc(buffer_size);

    printf("Enter input: \n");
    while((c = getchar()) != EOF)
    {
        if (char_count + 1 == buffer_size)
        {
            buffer = increase_buffer(buffer_size, 10);
            buffer_size = char_count + 11;
        }

        switch(c)
        {
            case '\t' :
                tabs_count++;
                buffer[char_count] = '\\';
                break;

            case '\b' :
                buffer[char_count] = '\\';
                break;

            case '\n' :
                lines_count++;

            case ' ' :
                blanks_count++;
                buffer[char_count] = c;

                skip_char(' ');

                // Go to the next character to add to buffer
                char_count++;

            default:
                buffer[char_count] = c;
                break;
        }

        char_count++;
    }

    buffer[char_count] = '\0';

    printf("\nOutput:\n");
    printf("%s\n", buffer);
    printf("No. of blanks: %d\n", blanks_count);
    printf("No. of tabs: %d\n", tabs_count);
    printf("No. of lines: %d\n", lines_count);
    printf("No. of chars: %d\n", char_count);

    free(buffer);
}


// See declaration above for what these does

char* increase_buffer(int cur_size, int increase)
{
    char* temp_buffer = malloc(cur_size);
    strncpy(temp_buffer, buffer, cur_size);

    free(buffer);
    buffer = malloc(cur_size + increase);

    strncpy(buffer, temp_buffer, cur_size);
    free(temp_buffer);

    return buffer;
}

void skip_char(char sc)
{
    while (c == sc)
    {
        c = getchar();
    }
}
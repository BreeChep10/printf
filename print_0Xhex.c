#include "main.h"

/**
 * print_0Xhex - Prints an unsigned integer in
 *               hexadecimal format with '0X' prefix
 * @all_args: variable-length argument list
 * @buffer: character array used for storing the formatted output
 * @buffer_size: size of the buffer
 *
 * Return: Number of characters written
 *  (-1 if there is not enough space in the buffer)
 */

int print_0Xhex(va_list all_args, char *buffer, unsigned int buffer_size)
{
	unsigned int num = va_arg(all_args,  unsigned int);
	char  *array = malloc(sizeof(char) * (32 + 1));
	int i, rem, test = 0, count;

	if (!array)
	{
		free(array);
		return (0);

	}
	for (i = 0; i < 32; i++)
		array[i] = '0';
	array[32] = '\0';
	for (i = 31; i >= 0; i--)
	{
		rem = num % 16;
		if (rem < 10)
			array[i] = rem + '0';
		else
			array[i] = rem - 10 + 'A';
		num /= 16;
	}
	for (i = 0; i < 32; i++)
		if (array[i + 2] != '0')
			break;
	array[i + 1] = 'X';
	for (i = 0; i < 32; i++)
	{
		if (array[i + 1] != '0')
			test = 1;
		if (test == 1)
			buffer_size = add_buff(buffer, array[i], buffer_size), count++;
	}


	free(array);
	return (count);
}

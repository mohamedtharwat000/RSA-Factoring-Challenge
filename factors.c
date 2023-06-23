#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point to the program
 * @argc: argument count
 * @argv: arguments passed to the program
 */
int main(int argc, char **argv)
{
	FILE *file = NULL;
	char *buff_line = NULL;
	size_t buff_size = 0;
	unsigned long num = 0, p = 0, q = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: factors <file>\n");
		return (1);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Failed to open file\n");
		return (1);
	}

	while (getline(&buff_line, &buff_size, file) != -1)
	{
		num = strtoul(buff_line, NULL, 10);

		for (q = 2; q <= num / 2; q++)
		{
			if (num % q == 0)
			{
				p = num / q;
				printf("%lu=%lu*%lu\n", num, p, q);
				break;
			}
		}
	}

	fclose(file);
	free(buff_line);
	return (0);
}

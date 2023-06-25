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
	unsigned long int num_readed = 0, first = 0, second = 0;

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
		num_readed = strtoul(buff_line, NULL, 10);

		for (second = 2; second <= num_readed; second++)
		{
			if (num_readed % second == 0)
			{
				first = num_readed / second;
				printf("%lu=%lu*%lu\n", num_readed, first, second);
				break;
			}
		}
	}

	fclose(file);
	free(buff_line);
	return (0);
}

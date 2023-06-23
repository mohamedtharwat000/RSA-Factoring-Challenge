#include <stdio.h>
#include <stdlib.h>

int is_prime(int number);

/**
 * main - entry point to the program
 * @argc: argument count
 * @argv: arguments passed to the program
 */
int main(int argc, char **argv)
{
	FILE *file = NULL;
	char *buff_line = NULL;
	size_t buff_size = 0, num = 0, p = 0, q = 0;

	if (argc < 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error opening file.\n");
		return (1);
	}

	while (getline(&buff_line, &buff_size, file) != -1)
	{
		num = strtoul(buff_line, NULL, 10);

		for (q = 2; q <= num / 2; q++)
		{
			if (!is_prime(q))
			{
				continue;
			}
			for (p = 2; p <= num / q; p++)
			{
				if (num == p * q)
				{
					printf("%lu=%lu*%lu\n", num, p, q);
					break;
				}
			}
			if (num == p * q)
			{
				break;
			}
		}
	}

	fclose(file);
	free(buff_line);
	return (0);
}


/**
 * is_prime - function to check if number is prime.
 * @number: number to ccheck.
 * Return: 1 if prime, 0 if not.
 */
int is_prime(int number)
{
	int i = 0;

	for (i = 2; i <= number / 2; i++)
	{
		if (number % i == 0)
		{
			return (0);
		}
	}
	return (1);
}

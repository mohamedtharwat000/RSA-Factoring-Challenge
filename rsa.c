#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int is_prime(mpz_t num)
{
	mpz_t i, sqrt_num;
	mpz_inits(i, sqrt_num, NULL);

	mpz_sqrt(sqrt_num, num);
	for (mpz_set_ui(i, 2); mpz_cmp(i, sqrt_num) <= 0; mpz_add_ui(i, i, 1))
	{
		if (mpz_divisible_p(num, i))
		{
			mpz_clears(i, sqrt_num, NULL);
			return 0;
		}
	}

	mpz_clears(i, sqrt_num, NULL);
	return 1;
}

int main(int argc, char *argv[])
{
	FILE *file = NULL;
	char *buff_line = NULL;
	size_t buff_size = 0;
	mpz_t number, q, p;
	mpz_inits(number, q, p, NULL);

	if (argc < 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return 1;
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error opening file: %s\n", argv[1]);
		return 1;
	}

	while (getline(&buff_line, &buff_size, file) != -1)
	{
		if (buff_line[strlen(buff_line) - 1] == '\n')
		{
			buff_line[strlen(buff_line) - 1] = '\0';
		}

		mpz_set_str(number, buff_line, 10);

		for (mpz_set_ui(q, 2); mpz_cmp(q, number) < 0; mpz_add_ui(q, q, 1))
		{
			if (mpz_divisible_p(number, q) && is_prime(q))
			{
				mpz_divexact(p, number, q);
				if (is_prime(p))
				{
					gmp_printf("%s=%Zd*%Zd\n", buff_line, p, q);
					break;
				}
			}
		}
	}

	fclose(file);
	free(buff_line);
	mpz_clears(number, q, p, NULL);

	return 0;
}

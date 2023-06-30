#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char *str_reverse(const char *str)
{
	int len = strlen(str);
	int i = 0;

	char *reversed = malloc(sizeof(char) * (len + 1));

	for (; i < len; i++)
	{
		reversed[i] = str[len - i - 1];
	}
	reversed[i] = '\0';

	return reversed;
}

int compare(const char *num1, const char *num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int i;

	if (len1 > len2)
	{
		return 1;
	}
	if (len1 < len2)
	{
		return -1;
	}

	for (i = 0; i < len1; i++)
	{
		if (num1[i] > num2[i])
		{
			return 1;
		}
		else if (num1[i] < num2[i])
		{
			return -1;
		}
	}

	return 0;
}

char *add(const char *num1, const char *num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int maxLen = (len1 > len2) ? len1 : len2;
	int sum = 0, carry = 0, i = 0;
	char *result = malloc(sizeof(char) * (maxLen + 2));
	char *tmp_to_free;

	for (; i < maxLen; i++)
	{
		result[i] = '\0';
	}

	for (i = 0; i < maxLen; i++)
	{
		sum = carry;

		if (i < len1)
		{
			sum += num1[len1 - i - 1] - '0';
		}
		if (i < len2)
		{
			sum += num2[len2 - i - 1] - '0';
		}

		result[i] = sum % 10 + '0';
		carry = sum / 10;
	}

	if (carry > 0)
	{
		result[i++] = carry + '0';
	}

	result[i] = '\0';

	tmp_to_free = result;
	result = str_reverse(result);

	free(tmp_to_free);

	return result;
}

char *divi(const char *num, const char *divisor)
{
	int len = strlen(num);
	int i = 0, j = 0, digit = 0, remainder = 0;
	char *quotient = malloc((len + 2) * sizeof(char));

	int div = atoi(divisor);

	for (; i < len; i++)
	{
		digit = num[i] - '0';
		remainder = remainder * 10 + digit;
		quotient[i] = remainder / div + '0';
		remainder = remainder % div;
	}

	quotient[i] = '\0';

	while (quotient[j] == '0')
	{
		j++;
	}

	if (j == i)
	{
		quotient[0] = '0';
		quotient[1] = '\0';
	}
	else if (j > 0)
	{
		memmove(quotient, quotient + j, i - j + 1);
	}

	return quotient;
}



char *mod(const char *num, const char *divisor)
{
	int len = strlen(num);
	int i = 0, digit = 0, carry = 0;
	char *remainder = malloc(2 * sizeof(char));
	remainder[1] = '\0';

	for (; i < len; i++)
	{
		digit = num[i] - '0';
		carry = (carry * 10 + digit) % (divisor[0] - '0');
	}

	remainder[0] = carry + '0';

	return remainder;
}

int main(int argc, char *argv[])
{
	FILE *file = NULL;
	char *buff_line = NULL, *p = NULL, *q = NULL;
	size_t buff_size = 0;

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
		buff_line[strcspn(buff_line, "\r\n")] = '\0';

		for (q = "2"; compare(q, buff_line) == -1; q = add(q, "1"))
		{
			if (atoi(mod(buff_line, q)) == 0)
			{
				p = divi(buff_line, q);
				printf("%s=%s*%s\n", buff_line, p, q);
				free(p);
				break;
			}
		}
	}

	fclose(file);
	free(buff_line);

	return 0;
}

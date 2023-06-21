#include "monty.h"

/**
 * _strtol - wrapper around strtol, handling monty specific errors
 * @num_string: string that *should* represent an integer
 * @line_number: line counter of monty file
 * Return: long int that strtol converted
 **/
int _strtol(char *num_string, unsigned int line_number)
{
	int base = 10;
	char *endptr;
	long val;


	errno = 0;
	val = strtol(num_string, &endptr, base);
	if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN))
		|| (errno != 0 && val == 0))
	{
		exit(EXIT_FAILURE);
	}

	if (endptr == num_string)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}


	if (num_string[0] != '\0')
		if (!isdigit(num_string[0]) && *endptr != '\0')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	return (val);
}

#include <stdio.h>

int main(__attribute__((unused)) int argc, char *argv[])
{
	int i = 0;

	while (argv[i])
	{
		printf("argument passed -> %s\n", argv[i]);
		i++;
	}
	return (0);
}

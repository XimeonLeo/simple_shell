#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	size_t buff_size;
	ssize_t ret_val;

	while (1)
	{
		char *buffer = NULL;

		printf("cisfun(⁠｡⁠◕⁠‿⁠◕⁠｡⁠)⁠➜");
		ret_val = getline(&buffer, &buff_size, stdin);

		if (ret_val == -1)
		{
			free(buffer);
			break;
		}
		else
		{
			pid_t child;
			char *argv[] = {}

			child = fork();
		}
		free(buffer);
	}

	return (0);
}

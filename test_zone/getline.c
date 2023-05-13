#include <stdio.h>
#include <stdlib.h>

// main is using getline to accept input from user
// getline accepts 3 parameters
// a pointer to where what is inputed is stored
// a pointer to the size of the buffer
// where it is geting the input from (the standard input)
// the purpose of puttinh while 1 is so that it can always repeate itself
// making use of the return vakue of getline, you can break out of the loop
// Ctrl + d makes getline return -1 which will cause the loop to emd

/*int main(void)
{
	size_t buf_size = 10;
	char *buff = malloc(sizeof(char) * buf_size);
	ssize_t rtn;

	while (1)
	{
	printf("$>");
	rtn = getline(&buff, &buf_size, stdin);

	if (rtn == -1)
	{
		free(buff);
		break;
	}

	printf("You input %s and it has %lu chars\n", buff, buf_size);
	}
	free(buff);

	return (0);
}
*/

// this is the same as what in up but it makes use of getline ability to
// use realloc to allocate space by itself
// nothing special about while (1024}
// just make sure the condition is true
int main(void)
{
	size_t buf_size;
	char *buff = NULL;
	ssize_t rtn;

	while (1024)
	{
	//printf("(⁠｡⁠◕⁠‿⁠◕⁠｡⁠)⁠➜");
	printf("(⁠☞⁠ ⁠ಠ⁠_⁠ಠ⁠)⁠☞ ");
	rtn = getline(&buff, &buf_size, stdin);

	if (rtn == -1)
	{
		break;
	}

	printf("You input %s and it has %lu chars\n", buff, buf_size);
	}
	free(buff);

	return (0);
}

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define	MAX_BUF	1024

int
main(int argc, char *argv[])
{
	int 	fd1, fd2, count;
	char	buf[MAX_BUF];

	if (argc != 3)  {
		printf("Usage: %s source destination\n", argv[0]);
		exit(1);
	}

	if ((fd1 = open(argv[1], O_RDONLY)) < 0)  {
		perror("open");
		exit(1);
	}

	if ((fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)  {
		perror("open");
		exit(1);
	}

	while (count = read(fd1, buf, MAX_BUF) > 0)  {

		write(fd2, buf, count);
	}

	close(fd1);
	close(fd2);
}
// buf의 크기 만큼 fd1(source)를 read해서 fd2(destination)에 write


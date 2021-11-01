#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd = open("/Users/rsenelle/CLionProjects/gnl/gnlTester/files/42_no_nl", O_RDONLY);
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
}

//int main(void)
//{
//    char *line;
//    int fd = open("../file.txt", O_RDONLY);
//    if (fd < 0)
//        return (1);
//    line = get_next_line(fd);
//    printf("%s\n", line);
//    line = get_next_line(fd);
//    printf("%s\n", line);
//    line = get_next_line(fd);
//    printf("%s\n", line);
//    line = get_next_line(fd);
//    printf("%s\n", line);
//    line = get_next_line(fd);
//    printf("%s\n", line);
//    line = get_next_line(fd);
//    printf("%s\n", line);
//    line = get_next_line(fd);
//    printf("%s\n", line);
//    line = get_next_line(fd);
//    printf("%s\n", line);
//    return (0);
//}

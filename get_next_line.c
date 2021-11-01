#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

//#define BUFFER_SIZE 1
size_t	ft_strlen(const char *s)
{
	size_t	k;

	k = 0;
	while (s[k])
		k++;
	return (k);
}

char	*ft_strdup(const char *s1)
{
	char	*d;
	int		i;

	if (!s1)
		return (0);
	d = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	i = 0;
	if (!d)
		return (0);
	while (s1[i])
	{
		d[i] = s1[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*dest;
	unsigned int	i;
	char *s;

	s = s1;
	i = 0;
	if (s1 == 0 && s2 ==0)
		return (0);
	if (s1 == 0)
		return ft_strdup(s2);
	if (s2 == 0)
		return ft_strdup(s1);
	dest = (char*)malloc(sizeof(*dest) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == 0)
		return (0);
	while (*s1 != '\0')
		dest[i++] = *s1++;
	while (*s2 != '\0')
		dest[i++] = *s2++;
	dest[i] = '\0';
	free(s);
	return (dest);
}

int is_has_linebreak(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}



char	*trim_linebreak(char *str)
{
	int i;
	char *xyi;
	int j;

	i = 0;
	xyi = ft_strdup(str); //TODO Protection
	while (str[i] != '\n')
		i++;
	i++;
	xyi[i] = '\0';
	j = 0;
	while (str[i + j])
	{
		str[j] = str[i+j];
		j++;
	}
	str[j] = '\0';
	return xyi;
}



char	*get_next_line(int fd)
{
	int      read_sym;
	static char *ost = 0;
	char        *line;
	char        *buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!is_has_linebreak(ost))
	{
		read_sym = read(fd, buff, BUFFER_SIZE);
		buff[read_sym] = '\0';
		if (read_sym < 0)
		{
			free(buff);
			return (NULL);
		}
		if (read_sym == 0)
			break;
		ost = ft_strjoin(ost, buff);
	}
	if (is_has_linebreak(ost))
	{
		line = trim_linebreak(ost);
		if (*ost == '\0')
		{
			free(ost);
			ost = 0;
		}
	}
	else
	{
		line = ost;
		ost = 0;
	}
	free(buff);
	return (line);
}

//int main()
//{
//	int fd = open("/Users/rsenelle/CLionProjects/gnl/gnlTester/files/nl", O_RDONLY);
//	printf("%s",get_next_line(fd));
//	printf("----------");
//	printf("%s",get_next_line(fd));
//	printf("----------");
//	printf("%s",get_next_line(fd));
//	printf("----------");
//	printf("%s",get_next_line(fd));
//}

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

#include "get_next_line.h"

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
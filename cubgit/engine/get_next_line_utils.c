#include "../cub3d.h"

size_t	ft_stlen(const char *str)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (str[j] == '\0')
		j++;
	i = j;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i - j);
}

int		ft_iscinstr(char c, char const *str, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
		str[i++] = '\0';
	str[i] = '\0';
	return (str);
}

char	*ft_stjoin(char *s1, char *s2)
{
	size_t	len;
	char	*ret;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_stlen(s1) + ft_stlen(s2) + 1;
	if ((ret = (char *)malloc(len)) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j] == '\0')
		j++;
	while (s2[j] && s2[j] != '\n')
		ret[i++] = s2[j++];
	ret[i] = '\0';
	free(s1);
	return (ret);
}

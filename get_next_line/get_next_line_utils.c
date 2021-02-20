#include "get_next_line.h"

char				*ft_strjoin_free(char *s1, char **s2)
{
	char			*new1;
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (!s1 && !(*s2))
		return (NULL);
	while (s1[i])
		i++;
	while (s2[0][j])
		j++;
	if (!(new1 = malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		new1[j++] = s1[i++];
	i = 0;
	while (*s2 && s2[0][i])
		new1[j++] = s2[0][i++];
	new1[j] = '\0';
	(s1) ? free(s1) : s1;
	return (new1);
}

char				*ft_strdup_n_free(char *s1, char **s2)
{
	t_strdup		per;

	per.j = 0;
	per.i = 0;
	per.size = 0;
	if (s1)
	{
		while (s1[per.size] != '\0')
			per.size++;
		if (s1[0] == '\n')
		{
			per.i++;
			per.size--;
		}
		if (!(per.new1 = malloc(sizeof(char) * (per.size + 1))))
			return (NULL);
		while (s1[per.i] != '\0')
			per.new1[per.j++] = s1[per.i++];
		(s1[0] == '\n') ? s1[0] = '\0' : s1[0];
		per.new1[per.j] = '\0';
		(*s2) ? free(*s2) : 0;
		return (per.new1);
	}
	return (NULL);
}

char				*ft_strchr(char *s, int c)
{
	char			d;
	char			*str;

	str = (char*)s;
	d = (char)c;
	if (s)
	{
		while (*str != '\0')
		{
			if (d == *str)
				return (str);
			str++;
		}
	}
	return (NULL);
}

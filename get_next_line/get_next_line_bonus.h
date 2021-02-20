#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_strdup
{
	int			i;
	int			size;
	char		*new1;
	int			j;
	int			count;
	char		*buf;
	char		*tmp;
	char		*tmp2;
}				t_strdup;

int				get_next_line(int fd, char **line);
size_t			ft_strlen(const char *s);
char			*ft_strchr(char *s, int c);
char			*ft_strjoin_free(char *s1, char **s2);
char			*ft_strdup_n_free(char *s1, char **s2);

#endif

#ifndef	_LIBFT_H
#define _LIbFT_H

#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strldup(char *str, size_t l);
char	*ft_strcpy(char *dst, char *src);
char	*test_strjoin(char **str, int n);
char	**ft_split(char *str);
void	test_split(char *str);
#endif
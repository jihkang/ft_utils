/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihkang <jihkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:54:55 by jihkang           #+#    #+#             */
/*   Updated: 2022/08/25 20:54:55 by jihkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	free_memory(char **dst)
{
	free(*dst);
	*dst = NULL;
}

char	*ft_malloc_zero(size_t len)
{
	size_t	i;
	char	*ret;

	ret = malloc(len + 1);
	i = 0;
	while (i <= len)
	{
		ret[i] = 0;
		i++;
	}
	return (ret);
}

char	*ft_strjoin(char *dst, char *str)
{
	char	*ret;
	size_t	len;
	size_t	i;

	ret = NULL;
	if (dst != NULL && str != NULL)
	{
		len = ft_strlen(dst) + ft_strlen(str);
		ret = ft_malloc_zero(len);
		ft_strcpy(ret, dst);
		ft_strcpy(ret + ft_strlen(dst), str);
		free_memory(&dst);
	}
	else if (dst != NULL)
	{
		ret = ft_strdup(dst);
		free_memory(&dst);
	}
	else if (str != NULL)
	{
		ret = ft_strdup(str);
	}
	else
	{
		ret = ft_strdup("");
	}
	return (ret);
}

/**		s = test_strjoin((char *[3]){"abcd", "ef", "   h"}, 3); */
char	*test_strjoin(char **str, int n)
{
	char	*temp;
	char	*out;
	int i;
	
	i = 1;
	out = ft_strdup(str[i - 1]);
	while (i < n)
	{
		temp = ft_strdup(out);
		free(out);
		out = ft_strjoin(temp, str[i]);
		i++;
	}
	return (out);
}

// int main()
// {
// 	char *s, *s1;

// 	s = "";
// 	s1 = "";
// 	s = test_strjoin((char *[3]){"ab cd", "ef", "   h"}, 3);
// 	// s = ft_strjoin(s, s1);
// 	// printf("strdup : %s\n", strdup(""));
// 	// printf("ft_strdup : %s\n", ft_strdup(""));
// 	printf("ft_strjoin : %s\n", s);
// 	// printf("strjoin : %s", strjoin("", ""));
// }
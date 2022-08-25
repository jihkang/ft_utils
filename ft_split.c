/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihkang <jihkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:15:54 by jihkang           #+#    #+#             */
/*   Updated: 2022/08/25 22:15:54 by jihkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		split_count(char *str)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			c++;
			while (str[i] == '\n')
				i++;
		}
		i++;
	}
	if (str[i - 1] != '\n')
		c++;
	return (c);
}

char	**ft_split(char *str)
{
	size_t	i;
	size_t	j;
	char	**ret;
	size_t	c;

	c = split_count(str);
	i = 0;
	j = 0;
	ret = malloc(sizeof(char *) * (c + 1));
	ret[c] = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			ret[j] = ft_strldup(str + c, i - c);
			while (str[i] == '\n')
				i++;
			c = i;
			j++;
		}
		i++;
	}
	if (str[i - 1] != '\n')
		ret[j] = ft_strldup(str + c, i - c);
	return (ret);
}

void	test_split(char *str)
{

	char	**split;
	char	*temp;


	split = ft_split(str);
	free(str);
	while (*split)
	{
		temp = *split;
		printf("%s\n", *split);
		(*split++);
		free(temp);
	}
	return ;
}

int	main()
{
	char	*s;
	s = ft_strdup("abcdef\nqwer\n\nty\nzxcvbn");
	test_split(s);
}
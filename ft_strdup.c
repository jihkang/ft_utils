/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihkang <jihkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:53:00 by jihkang           #+#    #+#             */
/*   Updated: 2022/08/25 20:53:00 by jihkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = malloc(ft_strlen(str) + 1);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	*ft_strldup(char *str, size_t l)
{
	size_t	i;
	char	*ret;

	ret = malloc(l + 1);
	ret[l] = 0;
	i = 0;
	while (i < l)
	{
		ret[i] = str[i];
		i++;
	}
	return (ret);
}